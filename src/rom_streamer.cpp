#include "rom_streamer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Debug statistics
static uint32_t cache_hits = 0;
static uint32_t cache_misses = 0;
static uint32_t total_reads = 0;

ROMStreamer rom_streamer;

ROMStreamer::ROMStreamer() : next_cache_slot(0), rom_size(0) {
    for (int i = 0; i < 4; i++) {
        bank_cache[i] = nullptr;
        cached_bank_nums[i] = 0xFF;
    }
}

ROMStreamer::~ROMStreamer() {
    cleanup();
}

bool ROMStreamer::init(const char* path) {
    rom_path = path;
    
    rom_file = SD.open(path, FILE_READ);
    if (!rom_file) {
        Serial.printf("ROMStreamer: Failed to open %s\n", path);
        return false;
    }
    
    rom_size = rom_file.size();
    if (rom_size < 32768 || rom_size > 8 * 1024 * 1024) {
        Serial.printf("ROMStreamer: Invalid ROM size: %u bytes\n", rom_size);
        rom_file.close();
        return false;
    }
    
    // Check available memory before allocating cache
    size_t free_heap = ESP.getFreeHeap();
    size_t cache_needed = 4 * 16384; // 64KB total
    Serial.printf("ROMStreamer: Free heap: %u bytes, need: %u bytes\n", free_heap, cache_needed);
    
    if (free_heap < cache_needed + 50 * 1024) { // Need 50KB overhead
        Serial.println("ROMStreamer: Not enough memory for full cache, using minimal cache");
        // Allocate only 2 banks instead of 4 to save memory
        for (int i = 0; i < 2; i++) {
            bank_cache[i] = (uint8_t*)malloc(16384);
            
            if (!bank_cache[i]) {
                Serial.printf("ROMStreamer: Failed to allocate cache bank %d\n", i);
                cleanup();
                return false;
            }
            // Clear the cache to prevent garbage data
            memset(bank_cache[i], 0xFF, 16384);
            Serial.printf("ROMStreamer: Cache bank %d allocated at %p\n", i, bank_cache[i]);
        }
        
        // Pre-cache bank 0 only
        if (!cache_bank(0)) {
            Serial.println("ROMStreamer: Failed to pre-cache bank 0");
            cleanup();
            return false;
        }
    } else {
        // Allocate cache banks (16KB each)
        for (int i = 0; i < 4; i++) {
            bank_cache[i] = (uint8_t*)malloc(16384);
            
            if (!bank_cache[i]) {
                Serial.printf("ROMStreamer: Failed to allocate cache bank %d\n", i);
                cleanup();
                return false;
            }
            // Clear the cache to prevent garbage data
            memset(bank_cache[i], 0xFF, 16384);
            Serial.printf("ROMStreamer: Cache bank %d allocated at %p\n", i, bank_cache[i]);
        }
        
        // Pre-cache bank 0 and 1
        if (!cache_bank(0) || !cache_bank(1)) {
            Serial.println("ROMStreamer: Failed to pre-cache banks");
            cleanup();
            return false;
        }
    }
    
    Serial.printf("ROMStreamer: Initialized with %u byte ROM\n", rom_size);
    return true;
}

bool ROMStreamer::cache_bank(uint8_t bank_num) {
    uint32_t bank_offset = bank_num * 16384;
    if (bank_offset >= rom_size) {
        return false;
    }
    
    uint8_t cache_slot = next_cache_slot;
    next_cache_slot = (next_cache_slot + 1) % 4;
    
    // Add yield before SD card access to prevent spinlock contention
    yield();
    
    bool success = false;
    if (rom_file.seek(bank_offset)) {
        size_t bytes_to_read = min((size_t)16384, rom_size - bank_offset);
        
        // Read in smaller chunks to avoid blocking for too long
        uint8_t* dest = bank_cache[cache_slot];
        size_t total_read = 0;
        
        while (total_read < bytes_to_read) {
            size_t chunk_size = min((size_t)512, bytes_to_read - total_read); // 512 byte chunks
            size_t chunk_read = rom_file.read(dest + total_read, chunk_size);
            
            total_read += chunk_read;
            
            if (chunk_read != chunk_size) {
                Serial.printf("ROMStreamer: Partial read in bank %d (read %d of %d bytes)\n", bank_num, total_read, bytes_to_read);
                break;
            }
            
            // Yield between chunks to prevent blocking other tasks
            if (total_read < bytes_to_read) {
                yield();
            }
        }
        
        if (total_read == bytes_to_read) {
            cached_bank_nums[cache_slot] = bank_num;
            success = true;
        } else {
            Serial.printf("ROMStreamer: Failed to read bank %d (read %d of %d bytes)\n", bank_num, total_read, bytes_to_read);
        }
    } else {
        Serial.printf("ROMStreamer: Failed to seek to bank %d offset 0x%X\n", bank_num, bank_offset);
    }
    
    return success;
}

uint8_t ROMStreamer::find_cached_bank(uint8_t bank_num) {
    for (int i = 0; i < 4; i++) {
        if (cached_bank_nums[i] == bank_num) {
            return i;
        }
    }
    return 0xFF;
}

uint8_t ROMStreamer::read_byte(uint32_t address) {
    uint8_t bank_num = address / 16384;
    uint16_t bank_offset = address % 16384;
    
    uint8_t cache_slot = find_cached_bank(bank_num);
    total_reads++;
    if (cache_slot == 0xFF) {
        if (!cache_bank(bank_num)) {
            Serial.printf("ROMStreamer: Failed to cache bank %d for address 0x%X\n", bank_num, address);
            return 0xFF;
        }
        cache_slot = (next_cache_slot + 3) % 4;
        cache_misses++;
    } else {
        cache_hits++;
    }
    
    // CRITICAL: Add null pointer protection
    if (cache_slot >= 4 || !bank_cache[cache_slot]) {
        Serial.printf("ROMStreamer: CRITICAL - NULL cache access! slot=%d, address=0x%X, bank=%d\n", 
                     cache_slot, address, bank_num);
        Serial.printf("ROMStreamer: Bank cache states: [%p, %p, %p, %p]\n", 
                     bank_cache[0], bank_cache[1], bank_cache[2], bank_cache[3]);
        
        // Emergency fallback: direct file read
        if (rom_file && rom_file.seek(address)) {
            uint8_t byte = rom_file.read();
            Serial.printf("ROMStreamer: Emergency fallback read: 0x%02X\n", byte);
            return byte;
        }
        Serial.println("ROMStreamer: FATAL - All recovery attempts failed!");
        return 0xFF;
    }
    
    return bank_cache[cache_slot][bank_offset];
}

void ROMStreamer::print_cache_stats() {
    Serial.printf("=== ROM Streamer Cache Statistics ===\n");
    Serial.printf("Total reads: %u\n", total_reads);
    Serial.printf("Cache hits: %u\n", cache_hits);
    Serial.printf("Cache misses: %u\n", cache_misses);
    if (total_reads > 0) {
        Serial.printf("Hit rate: %.1f%%\n", (float)cache_hits * 100.0f / total_reads);
    }
    Serial.printf("Memory used for cache: %d bytes (4 x 16KB banks)\n", 4 * 16384);
    Serial.printf("==================================\n");
}

void ROMStreamer::set_bank(uint8_t bank_num) {
    // Pre-cache the requested bank if not already cached
    if (find_cached_bank(bank_num) == 0xFF) {
        // Add yield to prevent spinlock contention during SD card access
        yield();
        cache_bank(bank_num);
        yield(); // Additional yield after SD card access
    }
}

void ROMStreamer::cleanup() {
    if (rom_file) {
        rom_file.close();
    }
    
    for (int i = 0; i < 4; i++) {
        if (bank_cache[i]) {
            Serial.printf("ROMStreamer: Freeing cache bank %d at %p\n", i, bank_cache[i]);
            free(bank_cache[i]);
            bank_cache[i] = nullptr;
        }
        cached_bank_nums[i] = 0xFF;
    }
    
    rom_size = 0;
    next_cache_slot = 0;
}
