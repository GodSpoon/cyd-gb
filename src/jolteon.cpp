#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <esp_heap_caps.h>
#include <esp_system.h>
#include <esp_heap_caps.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "jolteon.h"
#include "interrupt.h"
#include "mbc.h"
#include "rom.h"
#include "pokemon_red_rom.h"
#include "jolteon_splash.h"

// External reference to TFT display and touch objects from main.cpp
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;

#define GAMEBOY_WIDTH 160
#define GAMEBOY_HEIGHT 144

// CYD display is 320x240, center the Game Boy screen
#define CENTER_X ((320 - GAMEBOY_WIDTH) >> 1)
#define CENTER_Y ((240 - GAMEBOY_HEIGHT) >> 1)

static fbuffer_t* pixels = nullptr;

volatile int spi_lock = 0;
volatile bool sram_modified = false;

uint16_t palette[] = { 0xFFFF, 0xAAAA, 0x5555, 0x2222 };

void jolteon_render_border(const uint8_t* img, uint32_t size)
{
    // Clear the screen with a dark background using TFT_eSPI
    tft.fillScreen(TFT_BLACK); // Black
    Serial.println("Border rendered (simple dark background)");
}

static void jolteon_request_sd_write()
{
    spi_lock = 1;
}

// Memory defragmentation and optimization
void jolteon_optimize_memory_early() {
    // No-op for now, or implement ESP32-specific heap optimization if needed
}

// Memory fragmentation analysis
void analyze_memory_fragmentation() {
    Serial.println("\n--- Memory Fragmentation Analysis ---");
    multi_heap_info_t info;
    heap_caps_get_info(&info, MALLOC_CAP_DEFAULT);
    
    Serial.printf("Total free bytes: %d\n", info.total_free_bytes);
    Serial.printf("Total allocated bytes: %d\n", info.total_allocated_bytes);
    Serial.printf("Largest free block: %d\n", info.largest_free_block);
    Serial.printf("Minimum free bytes: %d\n", info.minimum_free_bytes);
    Serial.printf("Allocated blocks: %d\n", info.allocated_blocks);
    Serial.printf("Free blocks: %d\n", info.free_blocks);
    Serial.printf("Total blocks: %d\n", info.total_blocks);
    
    // Check PSRAM if available
    if (heap_caps_get_free_size(MALLOC_CAP_SPIRAM) > 0) {
        heap_caps_get_info(&info, MALLOC_CAP_SPIRAM);
        Serial.println("\nPSRAM status:");
        Serial.printf("  Free PSRAM: %d bytes\n", info.total_free_bytes);
        Serial.printf("  Largest PSRAM block: %d bytes\n", info.largest_free_block);
    } else {
        Serial.println("PSRAM not available or not configured");
    }
    Serial.println("----------------------------------------");
}

// Try smaller buffer allocation with fragmentation handling
bool allocate_buffers_optimized() {
    size_t fb_size = GAMEBOY_HEIGHT * GAMEBOY_WIDTH * sizeof(fbuffer_t);
    
    Serial.println("\nTrying optimized memory allocation...");
    
    // Force garbage collection
    Serial.println("Attempting heap defragmentation...");
    
    // Only allocate framebuffer
    pixels = (fbuffer_t*)heap_caps_malloc(fb_size, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (!pixels) {
        pixels = (fbuffer_t*)malloc(fb_size);
    }
    if (!pixels) {
        Serial.println("  Failed to allocate framebuffer");
        return false;
    }
    Serial.printf("  Framebuffer at: %p\n", pixels);
    return true;
}

void jolteon_init(void)
{
    Serial.println("===============================");
    Serial.println("Initializing Jolteon Game Boy emulator...");
    Serial.println("===============================");
    
    // Analyze memory state first
    analyze_memory_fragmentation();
    
    size_t fb_size = GAMEBOY_HEIGHT * GAMEBOY_WIDTH * sizeof(fbuffer_t);
    
    Serial.printf("\nMemory allocation requirements:\n");
    Serial.printf("  Framebuffer: %d bytes\n", fb_size);
    Serial.printf("  Total needed: %d bytes\n", fb_size);
    
    // Try optimized allocation strategy
    if (!allocate_buffers_optimized()) {
        jolteon_faint("Failed to allocate required buffers!");
        return;
    }
    
    // Verify framebuffer allocation and add test pattern
    Serial.printf("Framebuffer test: writing test pattern...\n");
    if (pixels) {
        Serial.printf("Framebuffer allocated successfully at: %p\n", pixels);
        // Fill with a test pattern to verify display output
        for (int i = 0; i < GAMEBOY_WIDTH * GAMEBOY_HEIGHT; i++) {
            pixels[i] = palette[i % 4]; // Test pattern using palette colors
        }
        Serial.println("Test pattern written to framebuffer");
    } else {
        Serial.println("ERROR: Framebuffer is NULL after allocation!");
    }
    
    // Set up default Game Boy green palette
    Serial.println("Setting up Game Boy palette...");
    const uint32_t pal[] = {0xEFFFDE, 0xADD794, 0x525F73, 0x183442};
    jolteon_set_palette(pal);
    
    // Initialize button states
    btn_directions = 0xFF;
    btn_faces = 0xFF;
    
    // Final memory analysis
    analyze_memory_fragmentation();
    
    Serial.println("===============================");
    Serial.println("Jolteon initialized successfully!");
    Serial.println("===============================");
}

// Performance monitoring variables
static unsigned long frame_count = 0;
static unsigned long last_fps_time = 0;
static float current_fps = 0.0;
static unsigned long cpu_cycles_start = 0;
static unsigned long frame_time_start = 0;

void jolteon_start_frame_timing() {
    frame_time_start = micros();
    cpu_cycles_start = ESP.getCycleCount();
}

void jolteon_end_frame_timing() {
    unsigned long frame_time = micros() - frame_time_start;
    unsigned long cpu_cycles = ESP.getCycleCount() - cpu_cycles_start;
    
    frame_count++;
    unsigned long current_time = millis();
    
    if (current_time - last_fps_time >= 1000) { // Update FPS every second
        current_fps = (float)frame_count * 1000.0 / (current_time - last_fps_time);
        frame_count = 0;
        last_fps_time = current_time;
        
        // Print performance stats every few seconds
        static int perf_counter = 0;
        if (++perf_counter >= 3) {
            perf_counter = 0;
            // Serial.printf("\n--- Performance Stats ---\n");
            // Serial.printf("FPS: %.2f\n", current_fps);
            // Serial.printf("Frame time: %lu μs\n", frame_time);
            // Serial.printf("CPU cycles/frame: %lu\n", cpu_cycles);
            // Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
            // Serial.printf("------------------------\n");
        }
    }
}

float jolteon_get_fps() {
    return current_fps;
}

void jolteon_update(void)
{
    // Default to all buttons released (Game Boy uses inverted logic - 1 = released, 0 = pressed)
    btn_directions = 0xFF;
    btn_faces = 0xFF;
    
    // Check for touch input
    if (touch.touched()) {
        TS_Point p = touch.getPoint();
        
        // Convert touch coordinates (touchscreen coordinates need to be mapped to display coordinates)
        // CYD touchscreen typically needs coordinate mapping
        int16_t x = map(p.x, 200, 3700, 0, 320);  // Approximate mapping - may need calibration
        int16_t y = map(p.y, 240, 3800, 0, 240);  // Approximate mapping - may need calibration
        
        // Define virtual button areas (simple layout)
        // D-pad on left side
        if (x < 80) {
            if (y < 80) {
                // Up-Left area - treat as UP
                btn_directions &= ~0x04; // UP pressed
            } else if (y > 160) {
                // Down-Left area - treat as DOWN  
                btn_directions &= ~0x08; // DOWN pressed
            } else {
                // Middle-Left area - treat as LEFT
                btn_directions &= ~0x02; // LEFT pressed
            }
        } 
        // Right side for action buttons and right direction
        else if (x > 240) {
            if (y < 80) {
                // Up-Right area - treat as UP or B button
                btn_faces &= ~0x02; // B pressed
            } else if (y > 160) {
                // Down-Right area - treat as A button
                btn_faces &= ~0x01; // A pressed
            } else {
                // Middle-Right area - treat as RIGHT
                btn_directions &= ~0x01; // RIGHT pressed
            }
        }
        // Center area for START/SELECT
        else if (x > 120 && x < 200) {
            if (y < 120) {
                btn_faces &= ~0x08; // SELECT pressed
            } else {
                btn_faces &= ~0x04; // START pressed
            }
        }
    }
}

void jolteon_faint(const char* msg)
{
    Serial.println("===============================");
    Serial.print("JOLTEON FAINTED! ");
    Serial.println(msg);
    Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("Largest free block: %d bytes\n", ESP.getMaxAllocHeap());
    Serial.printf("Min free heap: %d bytes\n", ESP.getMinFreeHeap());
    Serial.println("===============================");
    // TODO: Draw error message on screen using smartdisplay
    // smartdisplay_lcd_draw_text(..., "Jolteon fainted! ...");
    while(true) {
        delay(1000);
    }
}

fbuffer_t* jolteon_get_framebuffer(void)
{
    Serial.printf("jolteon_get_framebuffer: returning pixels=%p\n", pixels);
    return pixels;
}

void jolteon_clear_framebuffer(fbuffer_t col)
{
    if (pixels) {
        for (int i = 0; i < GAMEBOY_WIDTH * GAMEBOY_HEIGHT; i++) {
            pixels[i] = col;
        }
    }
}

void jolteon_clear_screen(uint16_t col)
{
    tft.fillScreen(col);
}

void jolteon_set_palette(const uint32_t* col)
{
    /* RGB888 -> RGB565 */
    for (int i = 0; i < 4; ++i) {
        palette[i] = ((col[i]&0xFF)>>3)+((((col[i]>>8)&0xFF)>>2)<<5)+((((col[i]>>16)&0xFF)>>3)<<11);
    }
}

void jolteon_end_frame(void)
{
    if (spi_lock) {
        const s_rominfo* rominfo = rom_get_info();
        if (rominfo->has_battery && rom_get_ram_size())
            jolteon_save_sram(mbc_get_ram(), rom_get_ram_size());
        spi_lock = 0;
    }
    
    // Convert framebuffer to display
    if (pixels) {
        // Debug: Check if framebuffer has valid data
        static int debug_counter = 0;
        debug_counter++;
        
        if (debug_counter % 300 == 0) { // Debug every 5 seconds at 60fps
            Serial.printf("Frame buffer check: first pixel = 0x%04X, last pixel = 0x%04X\n", 
                         pixels[0], pixels[GAMEBOY_WIDTH * GAMEBOY_HEIGHT - 1]);
            
            // Check for actual variation in framebuffer
            uint16_t min_val = 0xFFFF, max_val = 0;
            for (int i = 0; i < GAMEBOY_WIDTH * GAMEBOY_HEIGHT; i += 100) {
                if (pixels[i] < min_val) min_val = pixels[i];
                if (pixels[i] > max_val) max_val = pixels[i];
            }
            Serial.printf("Framebuffer variation: min=0x%04X, max=0x%04X\n", min_val, max_val);
        }
        
        // Clear the area around the Game Boy screen
        tft.fillRect(CENTER_X - 2, CENTER_Y - 2, GAMEBOY_WIDTH + 4, GAMEBOY_HEIGHT + 4, TFT_BLACK);
        
        // Draw a border around the Game Boy screen
        tft.drawRect(CENTER_X - 1, CENTER_Y - 1, GAMEBOY_WIDTH + 2, GAMEBOY_HEIGHT + 2, TFT_GREEN);
        
        // Try multiple rendering methods
        static int render_method = 0;
        static int method_counter = 0;
        method_counter++;
        
        if (method_counter % 180 == 0) { // Switch methods every 3 seconds
            render_method = (render_method + 1) % 3;
            Serial.printf("Switching to render method %d\n", render_method);
        }
        
        switch (render_method) {
            case 0: // Method 1: pushColors
                tft.setAddrWindow(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
                tft.pushColors((uint16_t*)pixels, GAMEBOY_WIDTH * GAMEBOY_HEIGHT);
                break;
                
            case 1: // Method 2: pushImage
                tft.pushImage(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, (uint16_t*)pixels);
                break;
                
            case 2: // Method 3: Pixel by pixel (slow but guaranteed to work)
                if (debug_counter % 60 == 0) { // Only do this occasionally as it's slow
                    for (int y = 0; y < GAMEBOY_HEIGHT; y += 2) { // Skip every other line for speed
                        for (int x = 0; x < GAMEBOY_WIDTH; x += 2) { // Skip every other pixel for speed
                            uint16_t pixel = pixels[y * GAMEBOY_WIDTH + x];
                            tft.drawPixel(CENTER_X + x, CENTER_Y + y, pixel);
                            // Also draw the skipped pixel to fill gaps
                            if (x + 1 < GAMEBOY_WIDTH) {
                                tft.drawPixel(CENTER_X + x + 1, CENTER_Y + y, pixel);
                            }
                            if (y + 1 < GAMEBOY_HEIGHT) {
                                tft.drawPixel(CENTER_X + x, CENTER_Y + y + 1, pixel);
                            }
                        }
                    }
                }
                break;
        }
        
        // Test pattern overlay for debugging
        if (debug_counter % 600 == 300) { // Every 10 seconds, show a test pattern briefly
            Serial.println("Drawing test pattern overlay");
            tft.fillRect(CENTER_X + 10, CENTER_Y + 10, 50, 30, TFT_RED);
            tft.setTextColor(TFT_WHITE, TFT_RED);
            tft.setTextSize(1);
            tft.setCursor(CENTER_X + 15, CENTER_Y + 20);
            tft.print("TEST");
        }
        
    } else {
        Serial.println("ERROR: pixels framebuffer is NULL in jolteon_end_frame()");
    }
    
    // End frame timing for performance monitoring
    jolteon_end_frame_timing();
}

void jolteon_save_sram(uint8_t* ram, uint32_t size)
{
    // For now, just store in memory - could implement EEPROM/Flash storage later
    Serial.println("SRAM save requested (not implemented)");
}

void jolteon_load_sram(uint8_t* ram, uint32_t size)
{
    // For now, just clear RAM - could implement EEPROM/Flash storage later
    if (ram) {
        memset(ram, 0, size);
    }
    // Note: SRAM load requested (not implemented) - removed Serial.println to avoid spinlock issue
}

const uint8_t* jolteon_load_bootrom(const char* path)
{
    // Return NULL to use built-in boot ROM bypass
    Serial.println("Boot ROM load requested (using built-in bypass)");
    return nullptr;
}

const uint8_t* jolteon_load_rom(const char* path)
{
    // Return the compiled-in Pokemon Red ROM
    Serial.println("Loading Pokemon Red ROM...");
    return src_roms_Pokemon___Red_Version_gb;
}

void jolteon_display_splash_screen(void)
{
    Serial.println("Displaying Jolteon splash screen...");
    
    // The splash image is 240x320 (portrait), but CYD is 320x240 (landscape)
    // We need to rotate the image 90 degrees or adjust the display
    
    // Clear screen first
    tft.fillScreen(TFT_BLACK);
    
    // For now, let's display it rotated to fit the landscape orientation
    // We'll draw it pixel by pixel, rotating 90 degrees clockwise
    
    Serial.println("Drawing splash screen (this may take a moment)...");
    
    // Draw the splash screen data
    // Original image: 240 width x 320 height
    // Rotated: 320 width x 240 height (fits landscape)
    
    for (int y = 0; y < JOLTEON_SPLASH_HEIGHT; y++) {
        for (int x = 0; x < JOLTEON_SPLASH_WIDTH; x++) {
            // Read pixel from PROGMEM
            uint16_t pixel = pgm_read_word(&jolteon_splash_data[y * JOLTEON_SPLASH_WIDTH + x]);
            
            // Rotate 90 degrees clockwise: (x,y) -> (y, width-1-x)
            int new_x = y;
            int new_y = JOLTEON_SPLASH_WIDTH - 1 - x;
            
            // Draw the pixel
            tft.drawPixel(new_x, new_y, pixel);
        }
        
        // Print progress every 32 lines to avoid flooding serial
        if (y % 32 == 0) {
            Serial.printf("Drawing progress: %d/%d lines\n", y, JOLTEON_SPLASH_HEIGHT);
        }
    }
    
    Serial.println("Splash screen displayed!");
    
    // Show splash screen for 3 seconds
    delay(3000);
}
