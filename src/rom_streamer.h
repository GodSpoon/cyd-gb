#ifndef ROM_STREAMER_H
#define ROM_STREAMER_H

#include <Arduino.h>
#include <SD.h>

class ROMStreamer {
private:
    File rom_file;
    uint8_t* bank_cache[4];     // Cache for 4 ROM banks (64KB total)
    uint8_t cached_bank_nums[4];
    uint8_t next_cache_slot;
    String rom_path;
    size_t rom_size;
    
    bool cache_bank(uint8_t bank_num);
    uint8_t find_cached_bank(uint8_t bank_num);
    
public:
    ROMStreamer();
    ~ROMStreamer();
    
    bool init(const char* path);
    uint8_t read_byte(uint32_t address);
    void cleanup();
    void print_cache_stats();  // Debug function to show cache performance
    void set_bank(uint8_t bank_num);  // For bank switching support
    
    // ROM info
    size_t get_size() const { return rom_size; }
    bool is_valid() const { return rom_file && rom_size > 0; }
};

extern ROMStreamer rom_streamer;

#endif
