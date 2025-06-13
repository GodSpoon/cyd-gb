#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <Arduino.h>
#include "mem.h"
#include "rom.h"
#include "lcd.h"
#include "mbc.h"
#include "interrupt.h"
#include "timer.h"
#include "cpu.h"
#include "core/framebuffer_manager.h"
#include "jolteon.h"
#include "rom_streamer.h"

void analyze_memory_fragmentation();

bool usebootrom = false;
uint8_t *mem = nullptr;

// External declaration for MBC allocated RAM size
extern size_t allocated_ram_size;

// Always use segmented memory for ESP32 constraints
uint8_t* mem_segments[16] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

static uint8_t *echo;
static uint32_t DMA_pending;
static uint8_t joypad_select_buttons, joypad_select_directions;
uint8_t btn_directions, btn_faces;
static const s_rominfo *rominfo;
static const uint8_t *rom;

// Segmented memory access functions with null protection
uint8_t segmented_read_byte(uint16_t addr) {
    uint8_t segment = addr >> 12;  // 4KB segments  
    uint16_t offset = addr & 0x0FFF;  // 4KB (4096 bytes = 0x1000) mask
    
    // CRITICAL: Add bounds and null checking
    if (segment >= 16 || !mem_segments[segment]) {
        Serial.printf("[ERROR] segmented_read_byte: Invalid access - segment %d, addr 0x%X\n", segment, addr);
        return 0xFF; // Return safe default value
    }
    
    return mem_segments[segment][offset];
}

void segmented_write_byte(uint16_t addr, uint8_t value) {
    uint8_t segment = addr >> 12;  // 4KB segments
    uint16_t offset = addr & 0x0FFF;  // 4KB mask
    
    // CRITICAL: Add bounds and null checking
    if (segment >= 16 || !mem_segments[segment]) {
        Serial.printf("[ERROR] segmented_write_byte: Invalid access - segment %d, addr 0x%X\n", segment, addr);
        return; // Safely ignore write to invalid memory
    }
    
    mem_segments[segment][offset] = value;
}

uint8_t mem_get_byte(uint16_t i)
{
	if(DMA_pending && i < 0xFF80)
	{
		uint32_t elapsed = cpu_get_cycles() - DMA_pending;
		if(elapsed >= 160) {
			DMA_pending = 0;
		} else {
			return segmented_read_byte(0xFE00+elapsed);
		}
	}

	// ROM areas (0x0000-0x7FFF) - use streamer for all ROM access
	if (i < 0x8000) {
		return rom_streamer.read_byte(i);
	}

	else if (i >= 0xA000 && i < 0xC000)
		return mbc_read_ram(i);
	
	else if (i >= 0xE000 && i < 0xFE00) {
		// CRITICAL: Echo area maps to Work RAM - use direct segment access instead of pointer arithmetic
		uint16_t echo_offset = i - 0xE000; // Convert echo address to offset
		uint8_t segment = (echo_offset >> 12) + 12; // Start at segment 12 (0xC000)
		uint16_t seg_offset = echo_offset & 0x0FFF;
		
		if (segment >= 16 || !mem_segments[segment]) {
			Serial.printf("[ERROR] mem_get_byte: Invalid echo segment %d for address 0x%X\n", segment, i);
			return 0xFF;
		}
		return mem_segments[segment][seg_offset];
	}

	else switch(i)
	{
		case 0xFF00: {	/* Joypad */
			uint8_t mask = 0;
			if(!joypad_select_buttons)
				mask = btn_faces;
			if(!joypad_select_directions)
				mask = btn_directions;
			return (0xC0) | (joypad_select_buttons | joypad_select_directions) | (mask);
		}
		case 0xFF04: return timer_get_div();
		case 0xFF0F: return 0xE0 | IF;
		case 0xFF41: return lcd_get_stat();
		case 0xFF44: return lcd_get_line();
		case 0xFF4D: return 0xFF; /* GBC speed switch */
		case 0xFFFF: return IE;
	}

	return segmented_read_byte(i);
}

void mem_write_byte(uint16_t d, uint8_t i)
{
	/* ROM */
	if (d < 0x8000)
		mbc_write_rom(d, i);
	
	/* SRAM */
	else if (d >= 0xA000 && d < 0xC000)
		mbc_write_ram(d, i);
	
	/* ECHO */
	else if (d >= 0xE000 && d < 0xFE00) {
		// CRITICAL: Echo area maps to Work RAM - use direct segment access instead of pointer arithmetic
		uint16_t echo_offset = d - 0xE000; // Convert echo address to offset
		uint8_t segment = (echo_offset >> 12) + 12; // Start at segment 12 (0xC000)
		uint16_t seg_offset = echo_offset & 0x0FFF;
		
		if (segment >= 16 || !mem_segments[segment]) {
			Serial.printf("[ERROR] mem_write_byte: Invalid echo segment %d for address 0x%X\n", segment, d);
			return;
		}
		mem_segments[segment][seg_offset] = i;
	}

	else switch(d)
	{
		case 0xFF00:	/* Joypad */
			joypad_select_buttons = i&0x20;
			joypad_select_directions = i&0x10;
		break;
		case 0xFF04: timer_reset_div(); break;
		case 0xFF07: 
			timer_set_tac(i); 
			segmented_write_byte(d, i);
			break;
		case 0xFF0F: IF = i; break;
		case 0xFF40: lcd_write_control(i); break;
		case 0xFF41: lcd_write_stat(i); break;
		case 0xFF42: lcd_write_scroll_y(i); break;
		case 0xFF43: lcd_write_scroll_x(i); break;
		case 0xFF44: lcd_reset(); break;
		case 0xFF45: lcd_set_ly_compare(i); break;
		case 0xFF46: { /* OAM DMA */
			/* Check if address overlaps with RAM or ROM */
			uint16_t addr = i * 0x100;
			const uint8_t* src = nullptr;
			if (addr >= 0x4000 && addr < 0x8000) {
				// ROM area - copy via ROM streaming (slower but saves memory)
				for (int j = 0; j < 0x100; j++) {
					segmented_write_byte(0xFE00 + j, rom_streamer.read_byte(addr + j));
				}
				DMA_pending = cpu_get_cycles();
				break; // Skip the memcpy below
			}
			else if (addr >= 0xA000 && addr < 0xC000) {
				// CRITICAL: Add null check for rambank
				if (!rambank) {
					Serial.println("[ERROR] DMA: rambank is null, skipping DMA transfer");
					break;
				}
				src = rambank;
				addr -= 0xA000;
			}
			else {
				// Use segmented memory for other addresses
				for (int j = 0; j < 0xA0; j++) {
					segmented_write_byte(0xFE00 + j, segmented_read_byte(addr + j));
				}
				DMA_pending = cpu_get_cycles();
				break;
			}
			
			/* Copy 0xA0 bytes from source to OAM */
			// CRITICAL: Add null check and bounds check
			if (src && allocated_ram_size > 0) {
				for (int j = 0; j < 0xA0; j++) {
					if (addr + j < allocated_ram_size) {
						segmented_write_byte(0xFE00 + j, src[addr + j]);
					} else {
						segmented_write_byte(0xFE00 + j, 0xFF); // Fill with default
					}
				}
			}
			DMA_pending = cpu_get_cycles();
			break;
		}
		case 0xFF47: lcd_write_bg_palette(i); break;
		case 0xFF48: lcd_write_spr_palette1(i); break;
		case 0xFF49: lcd_write_spr_palette2(i); break;
		case 0xFF4A: lcd_set_window_y(i); break;
		case 0xFF4B: lcd_set_window_x(i); break;
		case 0xFF50: /* Lock bootROM */
			// CRITICAL: Add null check for rom pointer
			if (!rom) {
				Serial.println("[ERROR] mem_write_byte: rom pointer is null, cannot unlock boot ROM");
				break;
			}
			for (int i = 0; i < 0x100; i++) {
				segmented_write_byte(i, rom[i]);
			}
			break;
		case 0xFFFF: IE = i; break;

		default: 
			segmented_write_byte(d, i);
			break;
	}
}

bool mmu_init(const uint8_t* bootrom)
{
	Serial.printf("mmu_init: Free heap before allocation: %d bytes\n", ESP.getFreeHeap());
	Serial.printf("mmu_init: Largest free block: %d bytes\n", ESP.getMaxAllocHeap());
	
	// Always use segmented memory for ESP32 constraints
	Serial.println("mmu_init: Using segmented memory allocation for ESP32...");
	
	// Allocate 16 segments of 4KB each (total 64KB)
	for (int i = 0; i < 16; i++) {
		// Feed watchdog during memory allocation to prevent timeout
		yield(); // Reset watchdog and allow other tasks to run
		
		mem_segments[i] = (uint8_t*)calloc(1, 0x1000); // 4KB per segment
		if (!mem_segments[i]) {
			Serial.printf("[ERROR] mmu_init: Failed to allocate segment %d\n", i);
			analyze_memory_fragmentation(); // Log detailed memory fragmentation
			// Clean up previously allocated segments
			for (int j = 0; j < i; j++) {
				if (mem_segments[j]) {
					free(mem_segments[j]);
					mem_segments[j] = nullptr;
				}
			}
			return false;
		}
		Serial.printf("mmu_init: Segment %d allocated at %p\n", i, mem_segments[i]);
	}
	
	if (!mbc_init()) {
		Serial.println("mmu_init: mbc_init failed");
		// Clean up segments
		for (int i = 0; i < 16; i++) {
			if (mem_segments[i]) {
				free(mem_segments[i]);
				mem_segments[i] = nullptr;
			}
		}
		return false;
	}
	
	// Initialize ROM access
	rom = rom_getbytes();
	
	// Don't copy ROM to memory - use streamer
	if (bootrom) {
		// Only copy bootrom if provided
		memcpy(&mem_segments[0][0x0000], &bootrom[0x0000], 0x100);
		
		// Check if we have enough memory for ROM copying
		size_t free_heap = ESP.getFreeHeap();
		if (free_heap > 100 * 1024) { // Only copy if we have >100KB free		// Copy first ROM bank via streamer (spans segments 0-3)
		// Serial.println("mmu_init: Copying ROM banks to memory (sufficient memory available)");
		for (int i = 0x100; i < 0x1000; i++) {
				uint8_t byte = rom_streamer.read_byte(i);
				if (byte == 0xFF && !rom_streamer.is_valid()) {
					Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
					break;
				}
				mem_segments[0][i] = byte;
			}
			for (int i = 0x1000; i < 0x2000; i++) {
				uint8_t byte = rom_streamer.read_byte(i);
				if (byte == 0xFF && !rom_streamer.is_valid()) {
					Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
					break;
				}
				mem_segments[1][i - 0x1000] = byte;
			}
			for (int i = 0x2000; i < 0x3000; i++) {
				uint8_t byte = rom_streamer.read_byte(i);
				if (byte == 0xFF && !rom_streamer.is_valid()) {
					Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
					break;
				}
				mem_segments[2][i - 0x2000] = byte;
			}
			for (int i = 0x3000; i < 0x4000; i++) {
				uint8_t byte = rom_streamer.read_byte(i);
				if (byte == 0xFF && !rom_streamer.is_valid()) {
					Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
					break;
				}
				mem_segments[3][i - 0x3000] = byte;
			}
		} else {
			Serial.println("mmu_init: Skipping ROM copy to save memory - using pure streaming");
			// Fill with default pattern to indicate streaming-only mode
			for (int i = 0x100; i < 0x1000; i++) {
				mem_segments[0][i] = 0x00; // Will be read via streaming in mem_get_byte
			}
			for (int i = 0; i < 0x1000; i++) {
				mem_segments[1][i] = 0x00;
				mem_segments[2][i] = 0x00;  
				mem_segments[3][i] = 0x00;
			}
		}
		usebootrom = true;
		Serial.println("mmu_init: Boot ROM loaded successfully");
		return true;
	}
	
	// Check if we have enough memory for ROM copying
	size_t free_heap = ESP.getFreeHeap();
	// OPTIMIZE: Force streaming mode for CYD boards to avoid watchdog timeout
	// ROM copying takes too long and causes watchdog timer issues
	if (false && free_heap > 150 * 1024) { // Disabled - always use streaming
		// Copy first ROM bank via streamer (spans segments 0-3)
		Serial.println("mmu_init: Copying ROM banks to memory (sufficient memory available)");
		
		// Feed watchdog during ROM copying to prevent timeout
		for (int i = 0; i < 0x1000; i++) {
			// Feed watchdog every 256 bytes to prevent timeout
			if (i % 256 == 0) {
				yield(); // Allow other tasks to run and reset watchdog
			}
			
			uint8_t byte = rom_streamer.read_byte(i);
			if (byte == 0xFF && !rom_streamer.is_valid()) {
				Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
				break;
			}
			mem_segments[0][i] = byte;
		}
		
		for (int i = 0x1000; i < 0x2000; i++) {
			// Feed watchdog every 256 bytes to prevent timeout
			if (i % 256 == 0) {
				yield(); // Allow other tasks to run and reset watchdog
			}
			
			uint8_t byte = rom_streamer.read_byte(i);
			if (byte == 0xFF && !rom_streamer.is_valid()) {
				Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
				break;
			}
			mem_segments[1][i - 0x1000] = byte;
		}
		
		for (int i = 0x2000; i < 0x3000; i++) {
			// Feed watchdog every 256 bytes to prevent timeout
			if (i % 256 == 0) {
				yield(); // Allow other tasks to run and reset watchdog
			}
			
			uint8_t byte = rom_streamer.read_byte(i);
			if (byte == 0xFF && !rom_streamer.is_valid()) {
				Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
				break;
			}
			mem_segments[2][i - 0x2000] = byte;
		}
		
		for (int i = 0x3000; i < 0x4000; i++) {
			// Feed watchdog every 256 bytes to prevent timeout
			if (i % 256 == 0) {
				yield(); // Allow other tasks to run and reset watchdog
			}
			
			uint8_t byte = rom_streamer.read_byte(i);
			if (byte == 0xFF && !rom_streamer.is_valid()) {
				Serial.printf("mmu_init: ROM read failed at 0x%X, streamer invalid\n", i);
				break;
			}
			mem_segments[3][i - 0x3000] = byte;
		}
		
		Serial.println("mmu_init: ROM banks copied successfully");
	} else {
		Serial.println("mmu_init: Using pure streaming mode for optimal memory usage and speed");
		// Fill with default pattern to indicate streaming-only mode
		for (int i = 0; i < 0x1000; i++) {
			mem_segments[0][i] = 0x00; // Will be read via streaming in mem_get_byte
			mem_segments[1][i] = 0x00;
			mem_segments[2][i] = 0x00;
			mem_segments[3][i] = 0x00;
		}
	}
	
	// Set default register values in segment 3 (high memory area)
	segmented_write_byte(0xFF10, 0x80);
	segmented_write_byte(0xFF11, 0xBF);
	segmented_write_byte(0xFF12, 0xF3);
	segmented_write_byte(0xFF14, 0xBF);
	segmented_write_byte(0xFF16, 0x3F);
	segmented_write_byte(0xFF19, 0xBF);
	segmented_write_byte(0xFF1A, 0x7F);
	segmented_write_byte(0xFF1B, 0xFF);
	segmented_write_byte(0xFF1C, 0x9F);
	segmented_write_byte(0xFF1E, 0xBF);
	segmented_write_byte(0xFF20, 0xFF);
	segmented_write_byte(0xFF23, 0xBF);
	segmented_write_byte(0xFF24, 0x77);
	segmented_write_byte(0xFF25, 0xF3);
	segmented_write_byte(0xFF26, 0xF1);
	segmented_write_byte(0xFF40, 0x91);
	segmented_write_byte(0xFF47, 0xFC);
	segmented_write_byte(0xFF48, 0xFF);
	segmented_write_byte(0xFF49, 0xFF);
	
	Serial.println("mmu_init: Segmented MMU initialization successful!");
	return true;
}

// Use framebuffer_manager.get_back_buffer() for direct framebuffer access
