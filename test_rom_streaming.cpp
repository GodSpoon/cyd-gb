/*
 * Test script to verify ROM streaming functionality
 * This can be run on the ESP32 to test ROM streaming vs direct loading
 */

#include <Arduino.h>
#include <SD.h>
#include "rom_streamer.h"

// External ROM streamer instance
extern ROMStreamer rom_streamer;

void test_rom_streaming() {
    Serial.println("=== ROM Streaming Test ===");
    
    // Test with Pokemon Red ROM
    const char* test_rom = "/roms/Pokemon - Red Version.gb";
    
    // Print memory before initialization
    Serial.printf("Free heap before ROM init: %d bytes\n", ESP.getFreeHeap());
    
    // Initialize ROM streaming
    if (!rom_streamer.init(test_rom)) {
        Serial.println("FAIL: ROM streaming initialization failed");
        return;
    }
    
    // Print memory after initialization
    Serial.printf("Free heap after ROM init: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("ROM size: %d bytes\n", rom_streamer.get_size());
    
    // Test reading from different ROM areas
    Serial.println("Testing ROM reads...");
    
    // Test reading from ROM bank 0 (0x0000-0x3FFF)
    uint8_t byte_0 = rom_streamer.read_byte(0x0100); // Entry point
    uint8_t byte_1 = rom_streamer.read_byte(0x0134); // Game title start
    
    // Test reading from ROM bank 1 (0x4000-0x7FFF)  
    uint8_t byte_2 = rom_streamer.read_byte(0x4000); // Start of bank 1
    uint8_t byte_3 = rom_streamer.read_byte(0x7FFF); // End of bank 1
    
    Serial.printf("ROM bytes read - 0x0100: 0x%02X, 0x0134: 0x%02X, 0x4000: 0x%02X, 0x7FFF: 0x%02X\n",
                  byte_0, byte_1, byte_2, byte_3);
    
    // Test bank switching
    Serial.println("Testing bank switching...");
    rom_streamer.set_bank(2);
    uint8_t bank2_byte = rom_streamer.read_byte(0x4000);
    
    rom_streamer.set_bank(1);
    uint8_t bank1_byte = rom_streamer.read_byte(0x4000);
    
    Serial.printf("Bank 1 byte at 0x4000: 0x%02X\n", bank1_byte);
    Serial.printf("Bank 2 byte at 0x4000: 0x%02X\n", bank2_byte);
    
    if (bank1_byte != bank2_byte) {
        Serial.println("PASS: Bank switching works correctly");
    } else {
        Serial.println("WARNING: Bank switching may not be working (bytes are same)");
    }
    
    // Performance test - read 1KB of data
    Serial.println("Performance test: reading 1KB of ROM data...");
    unsigned long start_time = micros();
    
    for (int i = 0; i < 1024; i++) {
        rom_streamer.read_byte(i);
    }
    
    unsigned long end_time = micros();
    Serial.printf("Time to read 1KB: %lu microseconds\n", end_time - start_time);
    Serial.printf("Average per byte: %lu microseconds\n", (end_time - start_time) / 1024);
    
    Serial.println("=== ROM Streaming Test Complete ===");
}

void setup() {
    Serial.begin(115200);
    delay(2000); // Wait for serial monitor
    
    // Initialize SD card
    if (!SD.begin()) {
        Serial.println("SD card initialization failed");
        return;
    }
    
    test_rom_streaming();
}

void loop() {
    delay(10000);
}
