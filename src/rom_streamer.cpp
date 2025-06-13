#include "rom_streamer.h"

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
    
    // Allocate cache banks (16KB each)
    for (int i = 0; i < 4; i++) {
        bank_cache[i] = (uint8_t*)malloc(16384);
        
        if (!bank_cache[i]) {
            Serial.printf("ROMStreamer: Failed to allocate cache bank %d\n", i);
            cleanup();
            return false;
        }
    }
    
    // Pre-cache bank 0 and 1
    cache_bank(0);
    cache_bank(1);
    
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
    
    rom_file.seek(bank_offset);
    size_t bytes_to_read = min((size_t)16384, rom_size - bank_offset);
    size_t bytes_read = rom_file.read(bank_cache[cache_slot], bytes_to_read);
    
    if (bytes_read != bytes_to_read) {
        Serial.printf("ROMStreamer: Failed to read bank %d\n", bank_num);
        return false;
    }
    
    cached_bank_nums[cache_slot] = bank_num;
    return true;
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
            return 0xFF;
        }
        cache_slot = (next_cache_slot + 3) % 4;
        cache_misses++;
    } else {
        cache_hits++;
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
        cache_bank(bank_num);
    }
}

void ROMStreamer::cleanup() {
    if (rom_file) {
        rom_file.close();
    }
    
    for (int i = 0; i < 4; i++) {
        if (bank_cache[i]) {
            free(bank_cache[i]);
            bank_cache[i] = nullptr;
        }
        cached_bank_nums[i] = 0xFF;
    }
    
    rom_size = 0;
}
