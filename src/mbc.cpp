#include <Arduino.h>
#include <esp_heap_caps.h>
#include <stdlib.h>
#include "mbc.h"
#include "rom.h"
#include "jolteon.h"
#include "core/framebuffer_manager.h"
#include "rom_streamer.h"

// Updated to work with ROM streaming - use streaming for bank switching
#define SET_ROM_BANK(n) do { \
    uint32_t bank = (n) & (rom_banks - 1); \
    curr_rom_bank = bank; \
    /* Pre-cache the bank in ROM streamer */ \
    rom_streamer.set_bank(bank); \
    /* rombank pointer not used - access via rom_streamer.read_byte() */ \
} while(0)

#define SET_RAM_BANK(n) do { \
    if (ram && allocated_ram_size > 0) { \
        if (allocated_ram_size >= 0x2000) { \
            /* Full size allocation - use normal bank switching */ \
            uint32_t bank_offset = ((n) & (ram_banks - 1)) * 0x2000; \
            if (bank_offset < allocated_ram_size) { \
                rambank = &ram[bank_offset]; \
            } else { \
                rambank = &ram[0]; /* Fallback to bank 0 */ \
            } \
        } else { \
            /* Reduced allocation - always use bank 0 */ \
            rambank = &ram[0]; \
        } \
    } else { \
        rambank = nullptr; \
    } \
} while(0)

static uint32_t curr_rom_bank = 1;
static uint8_t rom_banks;
static uint32_t curr_ram_bank = 0;
static uint8_t ram_banks;
static bool ram_select;
static bool ram_enabled;
static const uint8_t *rom;
static uint8_t *ram;
uint8_t *rambank;
static const s_rominfo *rominfo;
size_t allocated_ram_size = 0; // Track actual allocated RAM size for bounds checking - NOT static so mem.cpp can access it

MBCReader mbc_read_ram;
MBCWriter mbc_write_rom;
MBCWriter mbc_write_ram;

// Static reference to framebuffer manager (set via mbc_set_framebuffer_manager)
static FramebufferManager* g_framebuffer_manager = nullptr;

// Setter function to inject framebuffer manager dependency
void mbc_set_framebuffer_manager(FramebufferManager* fbmgr) {
    g_framebuffer_manager = fbmgr;
}

bool mbc_init()
{
	Serial.println("mbc_init: Starting MBC initialization...");
	
	// Add yield to ensure any pending operations complete
	yield();
	
	rom = rom_getbytes();
	// In ROM streaming mode, rom can be nullptr since data is accessed via rom_streamer
	if (!rom && !rom_streamer.is_valid()) {
		Serial.println("mbc_init: Failed to get ROM bytes and ROM streamer is invalid");
		return false;
	}
	Serial.printf("mbc_init: ROM pointer at %p (streaming mode: %s)\n", rom, rom_streamer.is_valid() ? "enabled" : "disabled");
	
	rominfo = rom_get_info();
	if (!rominfo) {
		Serial.println("mbc_init: Failed to get ROM info");
		return false;
	}
	
	rom_banks = rominfo->rom_banks;
	ram_banks = rominfo->ram_banks;
	
	Serial.printf("mbc_init: ROM banks: %d, RAM banks: %d\n", rom_banks, ram_banks);
	Serial.printf("mbc_init: ROM mapper: %d\n", rominfo->rom_mapper);
	
	int ram_size = rom_get_ram_size();
	Serial.printf("mbc_init: Required RAM size: %d bytes\n", ram_size);
	Serial.printf("mbc_init: Free heap before RAM allocation: %d bytes\n", ESP.getFreeHeap());
	
	// Allocate minimum 8KB or required size
	int alloc_size = ram_size < 1024*8 ? 1024*8 : ram_size;
	Serial.printf("mbc_init: Attempting to allocate %d bytes for cartridge RAM\n", alloc_size);
	
	// CYD boards don't have PSRAM - use segmented allocation for large RAM
	if (alloc_size <= 8192) {  // 8KB or less - try single allocation
		Serial.println("mbc_init: Using single allocation for small cartridge RAM...");
		ram = (uint8_t*)malloc(alloc_size);
		if (ram) {
			memset(ram, 0, alloc_size); // Zero manually
			allocated_ram_size = alloc_size;
		}
	} else {
		Serial.printf("mbc_init: Large RAM requirement (%d bytes) - using reduced allocation...\n", alloc_size);
		// For Pokemon Yellow (32KB), try to allocate less RAM - many games work with reduced RAM
		int reduced_size = 4096; // Try 4KB first
		Serial.printf("mbc_init: Trying reduced RAM size: %d bytes\n", reduced_size);
		ram = (uint8_t*)malloc(reduced_size);
		if (ram) {
			memset(ram, 0, reduced_size);
			alloc_size = reduced_size;
			allocated_ram_size = reduced_size;
		}
	}
	
	if (!ram) {
		Serial.println("mbc_init: Regular allocation failed, trying aligned memory...");
		// Try aligned allocation as fallback but avoid PSRAM-related caps
		// ESP32 aligned_alloc can be problematic, try regular calloc instead
		ram = (uint8_t*)calloc(1, alloc_size);
		if (ram) {
			allocated_ram_size = alloc_size;
		}
	}
	
	if (!ram) {
		Serial.println("mbc_init: Aligned allocation failed, trying regular calloc...");
		ram = (uint8_t*)calloc(1, alloc_size);
		if (ram) {
			allocated_ram_size = alloc_size;
		}
	}
	
	if (!ram) {
		// Try smaller allocation - Pokemon Red might work with less RAM
		int min_size = 2048; // 2KB minimum
		Serial.printf("mbc_init: Large allocation failed, trying smaller allocation: %d bytes\n", min_size);
		ram = (uint8_t*)malloc(min_size); // Use malloc instead of calloc to save time
		if (ram) {
			memset(ram, 0, min_size); // Zero it manually
			Serial.printf("mbc_init: Using reduced RAM size: %d bytes instead of %d\n", min_size, alloc_size);
			alloc_size = min_size;
			allocated_ram_size = min_size;
			// CRITICAL FIX: For reduced allocations, set ram_banks to 1 and don't use 8KB bank size
			// Instead, treat the entire allocation as bank 0
			ram_banks = 1; // Always 1 bank for reduced allocations
		} else {
			// Final fallback: try 1KB 
			min_size = 1024;
			Serial.printf("mbc_init: 2KB allocation failed, trying final fallback: %d bytes\n", min_size);
			ram = (uint8_t*)malloc(min_size);
			if (ram) {
				memset(ram, 0, min_size);
				Serial.printf("mbc_init: Using minimal RAM size: %d bytes\n", min_size);
				alloc_size = min_size;
				allocated_ram_size = min_size;
				ram_banks = 1;
			}
		}
	}
	// If we succeeded with a smaller allocation above, but not in the previous block, update ram_banks accordingly
	else if (ram && alloc_size != ram_size) {
		// For any allocation that's not the full required size, use 1 bank
		ram_banks = 1; // Simplified: treat entire allocation as bank 0
	}
	
	if (!ram) {
		Serial.printf("mbc_init: Failed to allocate cartridge RAM\n");
		Serial.printf("mbc_init: Free heap: %d bytes, Largest block: %d bytes\n", 
			ESP.getFreeHeap(), ESP.getMaxAllocHeap());
		
		// Print detailed memory analysis
		multi_heap_info_t info;
		heap_caps_get_info(&info, MALLOC_CAP_DEFAULT);
		Serial.printf("mbc_init: Memory analysis - Free blocks: %d, Total free: %d, Largest: %d\n", 
			info.free_blocks, info.total_free_bytes, info.largest_free_block);
		Serial.println("mbc_init: ERROR - Not enough memory for cartridge RAM. Try rebooting or closing other apps.");
		return false;
	}
	
	Serial.printf("mbc_init: Cartridge RAM allocated at %p, size: %d bytes\n", ram, allocated_ram_size);
	
	if (rominfo->has_battery && allocated_ram_size > 0) {
		Serial.printf("mbc_init: Loading SRAM (battery backup) with actual size: %d bytes\n", allocated_ram_size);
		jolteon_load_sram(ram, allocated_ram_size);
	}
	
	// Add yield before bank switching operations
	yield();
	
	SET_ROM_BANK(1);
	
	// CRITICAL FIX: Add null pointer protection for RAM bank switching
	if (ram && ram_banks > 0) {
		SET_RAM_BANK(0);
		Serial.printf("mbc_init: RAM bank set to 0, rambank = %p\n", rambank);
	} else {
		Serial.printf("mbc_init: WARNING - No RAM allocated or ram_banks = 0, skipping RAM bank init\n");
		rambank = nullptr;
	}
	
	// Add yield after bank switching
	yield();
	
	switch(rominfo->rom_mapper)
	{
		case MBC2:
			mbc_write_rom = MBC3_write_ROM;
			mbc_write_ram = MBC1_write_RAM;
			mbc_read_ram = MBC1_read_RAM;
			// Serial.println("mbc_init: Using MBC2 mapper");
		break;
		case MBC3:
			mbc_write_rom = MBC3_write_ROM;
			mbc_write_ram = MBC3_write_RAM;
			mbc_read_ram = MBC3_read_RAM;
			// Serial.println("mbc_init: Using MBC3 mapper");
		break;
		default:
			mbc_write_rom = MBC1_write_ROM;
			mbc_write_ram = MBC1_write_RAM;
			mbc_read_ram = MBC1_read_RAM;
			// Serial.println("mbc_init: Using MBC1 mapper (default)");
		break;
	}
	
	// Serial.println("mbc_init: MBC initialization successful!");
	return true;
}

uint8_t* mbc_get_ram()
{
	return ram;
}


void MBC3_write_ROM(uint16_t d, uint8_t i)
{
	if(d < 0x2000)
		ram_enabled = ((i & 0x0F) == 0x0A);
	
	else if(d < 0x4000) {
		curr_rom_bank = i & 0x7F;

		if(curr_rom_bank == 0)
			curr_rom_bank++;

		SET_ROM_BANK(curr_rom_bank);
	}
	
	else if(d < 0x6000) {
		/* TODO: select RTC */
		curr_ram_bank = i & 0x07;
		SET_RAM_BANK(curr_ram_bank);
	}
}

void MBC3_write_RAM(uint16_t d, uint8_t i)
{
	/* TODO: write to RTC */
	if (!ram_enabled || !rambank)
		return;
		
	// Add bounds checking using actual allocated RAM size
	uint16_t offset = d - 0xA000;
	if (allocated_ram_size > 0 && offset >= allocated_ram_size) {
		// Out of bounds access - some games might try to access more RAM than allocated
		return;
	}
	
	rambank[offset] = i;
	//sram_modified = true;
}

uint8_t MBC3_read_RAM(uint16_t i)
{
	if (!ram_enabled || !rambank) 
		return 0xFF;
		
	// Add bounds checking using actual allocated RAM size
	uint16_t offset = i - 0xA000;  
	if (allocated_ram_size > 0 && offset >= allocated_ram_size) {
		// Out of bounds access - return 0xFF for unmapped memory
		return 0xFF;
	}
	
	return rambank[offset];
}


void MBC1_write_ROM(uint16_t d, uint8_t i)
{
	if(d < 0x2000)
		ram_enabled = ((i & 0x0F) == 0x0A);
	
	else if(d < 0x4000) {
		curr_rom_bank = (curr_rom_bank & 0x60) | (i & 0x1F);

		if(curr_rom_bank == 0 || curr_rom_bank == 0x20 || curr_rom_bank == 0x40 || curr_rom_bank == 0x60)
			curr_rom_bank++;

		SET_ROM_BANK(curr_rom_bank);
	}
	
	else if(d < 0x6000) {
		if (ram_select) {
			curr_ram_bank = i&3;
			SET_RAM_BANK(curr_ram_bank);
		}
		else {
			curr_rom_bank = ((i & 0x3)<<5) | (curr_rom_bank & 0x1F);
			SET_ROM_BANK(curr_rom_bank);
		}
	}
	
	else if(d < 0x8000) {
		ram_select = i&1;
		if (ram_select) {
			curr_rom_bank &= 0x1F;
			SET_ROM_BANK(curr_rom_bank);
		}
		else {
			curr_ram_bank = 0;
			SET_RAM_BANK(curr_ram_bank);
		}
	}
}

void MBC1_write_RAM(uint16_t d, uint8_t i)
{
	if (!ram_enabled || !rambank)
		return;
	
	// Add bounds checking using actual allocated RAM size
	uint16_t offset = d - 0xA000;
	if (allocated_ram_size > 0 && offset >= allocated_ram_size) {
		// Out of bounds access - some games might try to access more RAM than allocated
		return;
	}
	
	rambank[offset] = i;
	//sram_modified = true;
}

uint8_t MBC1_read_RAM(uint16_t i)
{
	if (!ram_enabled || !rambank) 
		return 0xFF;
		
	// Add bounds checking using actual allocated RAM size
	uint16_t offset = i - 0xA000;
	if (allocated_ram_size > 0 && offset >= allocated_ram_size) {
		// Out of bounds access - return 0xFF for unmapped memory
		return 0xFF;
	}
	
	return rambank[offset];
}

// Use framebuffer_manager.get_back_buffer() for direct framebuffer access
