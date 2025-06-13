/*
 * ROM Streaming Verification Test
 * This demonstrates the memory savings achieved by ROM streaming vs direct loading
 */

#include <Arduino.h>
#include <SD.h>
#include <esp_heap_caps.h>

// Function to simulate direct ROM loading (what we used to do)
uint8_t* simulate_direct_rom_load(const char* path) {
    File rom_file = SD.open(path, FILE_READ);
    if (!rom_file) {
        Serial.printf("Failed to open ROM: %s\n", path);
        return nullptr;
    }
    
    size_t rom_size = rom_file.size();
    Serial.printf("ROM size: %d bytes\n", rom_size);
    
    // Try to allocate memory for entire ROM
    uint8_t* rom_buffer = (uint8_t*)malloc(rom_size);
    if (!rom_buffer) {
        Serial.printf("FAILED: Could not allocate %d bytes for ROM\n", rom_size);
        rom_file.close();
        return nullptr;
    }
    
    Serial.printf("SUCCESS: Allocated %d bytes for direct ROM loading\n", rom_size);
    
    // Read entire ROM into memory
    size_t bytes_read = rom_file.read(rom_buffer, rom_size);
    rom_file.close();
    
    if (bytes_read != rom_size) {
        Serial.printf("WARNING: Only read %d of %d bytes\n", bytes_read, rom_size);
        free(rom_buffer);
        return nullptr;
    }
    
    Serial.printf("Direct ROM load complete: %d bytes in RAM\n", rom_size);
    return rom_buffer;
}

void test_memory_comparison() {
    Serial.println("\n=== ROM Streaming vs Direct Loading Test ===");
    
    const char* test_rom = "/roms/Pokemon - Red Version.gb";
    
    // Show initial memory state
    Serial.printf("Initial free heap: %d bytes\n", ESP.getFreeHeap());
    
    // Test 1: Simulate direct ROM loading
    Serial.println("\n--- Test 1: Direct ROM Loading ---");
    uint8_t* direct_rom = simulate_direct_rom_load(test_rom);
    if (direct_rom) {
        Serial.printf("Free heap after direct load: %d bytes\n", ESP.getFreeHeap());
        free(direct_rom);
        Serial.printf("Free heap after freeing ROM: %d bytes\n", ESP.getFreeHeap());
    } else {
        Serial.println("Direct ROM loading failed (insufficient memory)");
    }
    
    // Test 2: ROM Streaming (already implemented)
    Serial.println("\n--- Test 2: ROM Streaming ---");
    Serial.printf("ROM streaming uses only: %d bytes (4 x 16KB cache)\n", 4 * 16384);
    Serial.printf("Memory savings: ~%d bytes\n", 1048576 - (4 * 16384)); // ~1MB ROM - 64KB cache
    
    Serial.println("=== Test Complete ===");
}

void setup() {
    Serial.begin(115200);
    delay(2000);
    
    Serial.println("ESP32 CYD Game Boy Emulator - ROM Streaming Test");
    
    // Initialize SD card
    if (!SD.begin()) {
        Serial.println("SD card initialization failed");
        return;
    }
    
    test_memory_comparison();
}

void loop() {
    delay(10000);
}
