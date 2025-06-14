#include "core/framebuffer_manager.h"
#include <esp_heap_caps.h>
#include <stdlib.h>
#include <Arduino.h>
#include "jolteon.h"

void analyze_memory_fragmentation(); // Forward declaration

FramebufferManager::FramebufferManager() : front_buffer(nullptr), back_buffer(nullptr), buffer_ready(false) {}

bool FramebufferManager::init() {
    // Try to free up memory before allocation
    heap_caps_check_integrity_all(true);
    
    // For CYD boards without PSRAM, use conservative memory allocation
    // Try double buffering first with regular malloc
    front_buffer = (uint16_t*)malloc(FB_SIZE);
    back_buffer = (uint16_t*)malloc(FB_SIZE);
    
    if (!front_buffer || !back_buffer) {
        // Fallback: try single buffering if double fails
        if (front_buffer) free(front_buffer);
        if (back_buffer) free(back_buffer);
        
        // Single buffer allocation
        front_buffer = (uint16_t*)malloc(FB_SIZE);
        back_buffer = nullptr;
        
        if (front_buffer) {
            Serial.println("[WARN] FramebufferManager: Single buffering only (performance may be reduced)");
        }
    }
    
    if (!front_buffer) {
        Serial.println("[ERROR] FramebufferManager: Failed to allocate framebuffer! Try rebooting or reducing memory usage.");
        analyze_memory_fragmentation(); // Log detailed memory fragmentation
        return false;
    }
    
    Serial.printf("[INFO] FramebufferManager: Allocated %s (%d bytes)\n", 
                  back_buffer ? "double buffers" : "single buffer",
                  back_buffer ? (FB_SIZE * 2) : FB_SIZE);
    
    return true;
}

uint16_t* FramebufferManager::get_back_buffer() { return back_buffer ? back_buffer : front_buffer; }
const uint16_t* FramebufferManager::get_front_buffer() const { return front_buffer; }
void FramebufferManager::swap_buffers() {
    if (back_buffer) {
        uint16_t* tmp = front_buffer;
        front_buffer = back_buffer;
        back_buffer = tmp;
        buffer_ready = true;
    } else {
        buffer_ready = true;
    }
}
bool FramebufferManager::is_ready() const { return buffer_ready; }
void FramebufferManager::mark_displayed() { buffer_ready = false; }

void FramebufferManager::create_test_pattern() {
    // Create a simple test pattern to verify the display pipeline
    if (!front_buffer) return;
    
    // Clear the buffer first
    for (int i = 0; i < FB_WIDTH * FB_HEIGHT; i++) {
        front_buffer[i] = 0x0000; // Black background
    }
    
    // Draw a simple pattern - white border and diagonal lines
    for (int y = 0; y < FB_HEIGHT; y++) {
        for (int x = 0; x < FB_WIDTH; x++) {
            int index = y * FB_WIDTH + x;
            
            // White border around the screen
            if (x == 0 || x == FB_WIDTH-1 || y == 0 || y == FB_HEIGHT-1) {
                front_buffer[index] = 0xFFFF; // White
            }
            // Diagonal lines
            else if ((x + y) % 20 == 0) {
                front_buffer[index] = 0x07E0; // Green
            }
            // Vertical lines every 20 pixels
            else if (x % 20 == 0) {
                front_buffer[index] = 0xF800; // Red
            }
            // Horizontal lines every 20 pixels  
            else if (y % 20 == 0) {
                front_buffer[index] = 0x001F; // Blue
            }
        }
    }
    
    buffer_ready = true;
    Serial.println("FramebufferManager: Test pattern created");
}
