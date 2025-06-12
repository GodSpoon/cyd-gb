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

void analyze_memory_fragmentation();

bool usebootrom = false;
uint8_t *mem = nullptr;

// Always use segmented memory for ESP32 constraints
uint8_t* mem_segments[4] = {nullptr, nullptr, nullptr, nullptr};

static uint8_t *echo;
static uint32_t DMA_pending;
static uint8_t joypad_select_buttons, joypad_select_directions;
uint8_t btn_directions, btn_faces;
static const s_rominfo *rominfo;
static const uint8_t *rom;

// Segmented memory access functions
uint8_t segmented_read_byte(uint16_t addr) {
    uint8_t segment = addr >> 14;    
    uint16_t offset = addr & 0x3FFF;    
    return mem_segments[segment][offset];
}

void segmented_write_byte(uint16_t addr, uint8_t value) {
    uint8_t segment = addr >> 14;    
    uint16_t offset = addr & 0x3FFF;    
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

	if(i >= 0x4000 && i < 0x8000)
		return rombank[i - 0x4000];

	else if (i >= 0xA000 && i < 0xC000)
		return mbc_read_ram(i);
	
	else if (i >= 0xE000 && i < 0xFE00)
		return echo[i];

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
	else if (d >= 0xE000 && d < 0xFE00)
		echo[d] = i;

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
				src = rombank;
				addr -= 0x4000;
			}
			else if (addr >= 0xA000 && addr < 0xC000) {
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
			for (int j = 0; j < 0xA0; j++) {
				segmented_write_byte(0xFE00 + j, src[addr + j]);
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
	
	// Allocate 4 segments of 16KB each (total 64KB)
	for (int i = 0; i < 4; i++) {
		mem_segments[i] = (uint8_t*)calloc(1, 0x4000); // 16KB per segment
		if (!mem_segments[i]) {
			Serial.printf("[ERROR] mmu_init: Failed to allocate segment %d\n", i);
			analyze_memory_fragmentation(); // Log detailed memory fragmentation
			return false;
		}
		Serial.printf("mmu_init: Segment %d allocated at %p\n", i, mem_segments[i]);
	}
	
	if (!mbc_init()) {
		Serial.println("mmu_init: mbc_init failed");
		// Clean up segments
		for (int i = 0; i < 4; i++) {
			if (mem_segments[i]) {
				free(mem_segments[i]);
				mem_segments[i] = nullptr;
			}
		}
		return false;
	}
	
	rom = rom_getbytes();
	
	// Initialize echo pointer for segmented memory
	echo = mem_segments[3] - (0xE000 - 0xC000); // Point to segment 3 with offset
	
	if (bootrom) {
		// Copy bootrom to first segment
		memcpy(&mem_segments[0][0x0000], &bootrom[0x0000], 0x100);
		memcpy(&mem_segments[0][0x0100], &rom[0x0100], 0x4000 - 0x100);
		usebootrom = true;
		Serial.println("mmu_init: Boot ROM loaded successfully");
		return true;
	}
	
	// Copy first ROM bank to first segment
	memcpy(&mem_segments[0][0x0000], &rom[0x0000], 0x4000);
	
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
