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
#include "display_manager.h"
#include "interrupt.h"
#include "mbc.h"
#include "rom.h"
#include <SD.h>
#include "jolteon_splash_landscape.h"
#include "core/framebuffer_manager.h"
#include "rom_streamer.h"
#include "error_handler.h"

// External reference to TFT display and touch objects from main.cpp
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;
extern FramebufferManager framebuffer_manager;

// Display manager instance
static DisplayManager* display_mgr = nullptr;

// Function to provide access to display manager for other modules
DisplayManager* get_display_manager() {
    return display_mgr;
}

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
    
    // PSRAM is disabled for CYD boards - skipping PSRAM status check
    Serial.println("PSRAM not available - using internal RAM only");
    Serial.println("----------------------------------------");
}

// Try smaller buffer allocation with fragmentation handling
bool allocate_buffers_optimized() {
    Serial.println("\nTrying optimized memory allocation...");
    if (!framebuffer_manager.init()) {
        Serial.println("  Failed to allocate double framebuffers");
        return false;
    }
    pixels = framebuffer_manager.get_back_buffer();
    // Set back buffer in DisplayManager if available
    if (display_mgr) {
        display_mgr->set_back_buffer(pixels);
    }
    Serial.printf("  Framebuffer (back) at: %p\n", pixels);
    return true;
}

void jolteon_init(void)
{
    Serial.println("===============================");
    Serial.println("Initializing Jolteon Game Boy emulator...");
    Serial.println("===============================");
    
    // Early memory optimization to reduce fragmentation
    heap_caps_check_integrity_all(true);
    
    // Analyze memory state first
    analyze_memory_fragmentation();
    
    size_t fb_size = GAMEBOY_HEIGHT * GAMEBOY_WIDTH * sizeof(fbuffer_t);
    
    Serial.printf("\nMemory allocation requirements:\n");
    Serial.printf("  Framebuffer: %d bytes\n", fb_size);
    Serial.printf("  Total needed: %d bytes\n", fb_size);
    
    // Check if we have enough memory before starting
    size_t free_heap = ESP.getFreeHeap();
    size_t min_required = fb_size + 100 * 1024; // Framebuffer + 100KB overhead
    
    if (free_heap < min_required) {
        char error_msg[128];
        snprintf(error_msg, sizeof(error_msg), 
            "Insufficient memory: %d KB free, need %d KB", 
            (int)(free_heap/1024), (int)(min_required/1024));
        jolteon_faint(error_msg);
        return;
    }
    
    // Try optimized allocation strategy
    if (!allocate_buffers_optimized()) {
        jolteon_faint("Failed to allocate required buffers!");
        return;
    }
    
    // Initialize display manager EARLY - before framebuffer operations
    Serial.println("Initializing DisplayManager...");
    display_mgr = new DisplayManager(tft);
    if (!display_mgr->init()) {
        jolteon_faint("Display initialization failed");
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
    
    // Display error on screen using DisplayManager if available
    if (display_mgr) {
        display_mgr->display_error(msg);
    } else {
        // Fallback to direct TFT display
        tft.fillScreen(TFT_RED);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.setTextSize(2);
        tft.setCursor(20, 100);
        tft.print("ERROR:");
        tft.setCursor(20, 130);
        tft.print(msg);
    }
    
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
    if (display_mgr) {
        display_mgr->clear_screen();
    } else {
        tft.fillScreen(col);
    }
}

void jolteon_set_palette(const uint32_t* col)
{
    /* RGB888 -> RGB565 - Fixed to use correct RGB565 format instead of BGR565 */
    for (int i = 0; i < 4; ++i) {
        uint8_t r = (col[i] >> 16) & 0xFF;  // Extract red from bits 23-16
        uint8_t g = (col[i] >> 8) & 0xFF;   // Extract green from bits 15-8
        uint8_t b = (col[i] >> 0) & 0xFF;   // Extract blue from bits 7-0
        
        // Convert to RGB565: RRRRR GGGGGG BBBBB
        palette[i] = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
    }
}

void jolteon_end_frame(void)
{
    // Handle SRAM save if requested
    if (spi_lock) {
        const s_rominfo* rominfo = rom_get_info();
        if (rominfo->has_battery && rom_get_ram_size())
            jolteon_save_sram(mbc_get_ram(), rom_get_ram_size());
        spi_lock = 0;
    }
    
    // Render the framebuffer to the display using DisplayManager
    if (display_mgr && pixels) {
        display_mgr->render_gameboy_frame(pixels);
        
        // Optional: Display debug info periodically
        static int debug_counter = 0;
        debug_counter++;
        
        if (debug_counter % 180 == 0) { // Every 3 seconds at 60fps
            display_mgr->display_debug_info(jolteon_get_fps(), ESP.getFreeHeap());
        }
    } else {
        Serial.println("ERROR: DisplayManager or framebuffer is NULL in jolteon_end_frame()");
        if (!display_mgr) {
            Serial.println("  DisplayManager is NULL");
        }
        if (!pixels) {
            Serial.println("  Framebuffer is NULL");
        }
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
    // Remove old allocation-based loading
    static uint8_t* last_rombuf = nullptr;
    if (last_rombuf) {
        free(last_rombuf);
        last_rombuf = nullptr;
    }
    
    if (!path || strlen(path) == 0) {
        Serial.println("No ROM path provided to jolteon_load_rom");
        return nullptr;
    }
    
    Serial.printf("Loading ROM via streaming: %s\n", path);
    
    if (!rom_streamer.init(path)) {
        Serial.println("ROM streaming initialization failed");
        return nullptr;
    }
    
    Serial.printf("ROM streaming ready: %s (%u bytes)\n", path, rom_streamer.get_size());
    return (const uint8_t*)0x1; // Non-null success indicator
}

void jolteon_display_splash_screen(void)
{
    Serial.println("Displaying Jolteon splash screen...");
    
    // Clear screen first
    tft.fillScreen(TFT_BLACK);
    
    // Show initial loading message
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(85, 100);
    tft.print("Loading...");
    
    // Draw loading bar background
    const int bar_x = 60;
    const int bar_y = 130;
    const int bar_width = 200;
    const int bar_height = 10;
    
    tft.drawRect(bar_x - 2, bar_y - 2, bar_width + 4, bar_height + 4, TFT_WHITE);
    tft.fillRect(bar_x, bar_y, bar_width, bar_height, TFT_BLACK);
    
    // Allocate buffer for the splash image (if we have enough memory)
    uint16_t* image_buffer = nullptr;
    const int total_pixels = JOLTEON_SPLASH_LANDSCAPE_WIDTH * JOLTEON_SPLASH_LANDSCAPE_HEIGHT;
    const size_t buffer_size = total_pixels * sizeof(uint16_t);
    
    Serial.printf("Attempting to allocate %d bytes for splash buffer...\n", buffer_size);
    
    // Try to allocate buffer (prefer internal RAM for CYD boards without PSRAM)
    image_buffer = (uint16_t*)malloc(buffer_size);
    
    if (image_buffer) {
        Serial.println("Splash buffer allocated successfully - copying image data...");
        
        // Copy image data from PROGMEM to RAM with progress updates
        const int progress_steps = 10;
        const int pixels_per_step = total_pixels / progress_steps;
        
        for (int step = 0; step < progress_steps; step++) {
            // Update loading bar
            int progress_width = (bar_width * (step + 1)) / progress_steps;
            tft.fillRect(bar_x, bar_y, progress_width, bar_height, TFT_GREEN);
            
            // Copy a chunk of pixels
            int start_pixel = step * pixels_per_step;
            int end_pixel = (step == progress_steps - 1) ? total_pixels : (step + 1) * pixels_per_step;
            
            for (int i = start_pixel; i < end_pixel; i++) {
                image_buffer[i] = pgm_read_word(&jolteon_splash_landscape_data[i]);
            }
            
            // Small delay to show progress
            delay(50);
        }
        
        // Clear the loading screen
        tft.fillScreen(TFT_BLACK);
        
        Serial.println("Drawing buffered splash screen...");
        
        // Draw the entire image at once (no flicker)
        tft.pushImage(0, 0, JOLTEON_SPLASH_LANDSCAPE_WIDTH, JOLTEON_SPLASH_LANDSCAPE_HEIGHT, image_buffer);
        
        // Free the buffer
        free(image_buffer);
        Serial.println("Splash buffer freed");
        
    } else {
        Serial.println("Failed to allocate splash buffer - using direct PROGMEM rendering...");
        
        // Fallback: render directly from PROGMEM with progress
        tft.fillRect(bar_x, bar_y, bar_width, bar_height, TFT_YELLOW);
        delay(200);
        
        // Clear loading screen
        tft.fillScreen(TFT_BLACK);
        
        // Use the original method as fallback
        tft.pushImage(0, 0, JOLTEON_SPLASH_LANDSCAPE_WIDTH, JOLTEON_SPLASH_LANDSCAPE_HEIGHT, jolteon_splash_landscape_data);
    }
    
    Serial.println("Splash screen displayed!");
    
    // Show splash screen for 3 seconds
    delay(3000);
}

void jolteon_display_test_pattern(void)
{
    if (display_mgr) {
        display_mgr->display_test_pattern();
    } else {
        Serial.println("DisplayManager not initialized - cannot show test pattern");
    }
}

// Phase 2: Display Pipeline Optimization
// 2.1 Simplified Framebuffer Management
class DisplayPipeline {
private:
    uint16_t* framebuffer = nullptr;
    bool use_dma = false;
public:
    bool init() {
        // Allocate framebuffer for 160x144 Game Boy screen (internal RAM only)
        if (!framebuffer) {
            framebuffer = (uint16_t*)malloc(160 * 144 * sizeof(uint16_t));
        }
        use_dma = false; // Set true if DMA is available and desired
        return framebuffer != nullptr;
    }
    void render_scanline(uint8_t line, const uint8_t* pixel_data) {
        if (!framebuffer || line >= 144) return;
        uint16_t* fb_line = framebuffer + (line * 160);
        for (int x = 0; x < 160; ++x) {
            // Convert 8-bit pixel data to RGB565 (assume pixel_data[x] is palette index)
            // You may want to use a palette lookup here
            fb_line[x] = pixel_data[x];
        }
    }
    void present_frame() {
        // Present the framebuffer to the display
        // Example: tft.pushImage(CENTER_X, CENTER_Y, 160, 144, framebuffer);
        if (framebuffer) {
            tft.pushImage(CENTER_X, CENTER_Y, 160, 144, framebuffer);
        }
    }
    void clear() {
        if (framebuffer) {
            memset(framebuffer, 0, 160 * 144 * sizeof(uint16_t));
        }
    }
    uint16_t* get_framebuffer() { return framebuffer; }
    ~DisplayPipeline() {
        if (framebuffer) free(framebuffer);
    }
};

// 2.2 Optimized LCD Rendering
// Remove complex queue system
// Direct scanline rendering to framebuffer
void lcd_render_scanline_direct(uint8_t line, const uint8_t* pixel_data, DisplayPipeline& pipeline) {
    pipeline.render_scanline(line, pixel_data);
}

// Phase 3: Architecture Improvements
// 3.2 Configuration Management
struct EmulatorConfig {
    bool use_streaming;  // Use streaming from SD instead of PSRAM
    bool enable_sound;
    uint8_t frameskip;
    bool debug_mode;

    static EmulatorConfig detect_optimal() {
        EmulatorConfig cfg;
        cfg.use_streaming = true;  // Always use streaming for CYD boards without PSRAM
        cfg.enable_sound = true; // Could check hardware
        cfg.frameskip = 0; // Default, could tune based on performance
        cfg.debug_mode = false;
        return cfg;
    }
};

// 3.3 Task Coordination
class TaskManager {
private:
    TaskHandle_t emulation_task_handle = nullptr;
    TaskHandle_t display_task_handle = nullptr;
    QueueHandle_t frame_queue = nullptr;
public:
    bool init() {
        // Create a queue for frame pointers (or frame numbers)
        frame_queue = xQueueCreate(2, sizeof(void*));
        return frame_queue != nullptr;
    }
    static void emulation_task(void* param) {
        // Main emulation loop (stub)
        while (1) {
            // Emulate CPU, run frame, etc.
            vTaskDelay(1);
        }
    }
    static void display_task(void* param) {
        // Main display loop (stub)
        while (1) {
            // Handle display refresh, etc.
            vTaskDelay(1);
        }
    }
    // 4.1 CPU Core Affinity
    // Core 0: System tasks, WiFi, display
    // Core 1: Game Boy CPU emulation
    void setup_core_affinity() {
        // Correct usage: pass function pointer as first argument, TaskHandle_t* as sixth argument
        xTaskCreatePinnedToCore(TaskManager::emulation_task, "GB_CPU", 8192, NULL, 5, &emulation_task_handle, 1);
        xTaskCreatePinnedToCore(TaskManager::display_task, "Display", 4096, NULL, 4, &display_task_handle, 0);
    }
    void start_emulation() {
        setup_core_affinity();
        Serial.println("Emulation and display tasks started with core affinity");
    }
    void stop_emulation() {
        // Stop tasks (stub)
        Serial.println("Emulation task stopped (stub)");
    }
};

// 4.2 Memory Access Optimization
// Use IRAM for frequently called functions
extern "C" {
    IRAM_ATTR uint8_t cpu_cycle_fast();
    IRAM_ATTR void lcd_write_pixel_fast(uint16_t x, uint16_t y, uint16_t color);
}

// 4.3 Frame Timing
class FrameTimer {
private:
    uint32_t target_frame_time_us = 16742; // 59.7 FPS
    uint32_t last_frame_time = 0;
    float fps = 0.0f;
    uint32_t frame_count = 0;
    uint32_t last_fps_update = 0;
public:
    FrameTimer() {
        last_frame_time = micros();
        last_fps_update = millis();
    }
    void wait_for_next_frame() {
        uint32_t now = micros();
        uint32_t elapsed = now - last_frame_time;
        if (elapsed < target_frame_time_us) {
            ets_delay_us(target_frame_time_us - elapsed);
        }
        last_frame_time = micros();
        frame_count++;
        uint32_t ms_now = millis();
        if (ms_now - last_fps_update >= 1000) {
            fps = (float)frame_count * 1000.0f / (ms_now - last_fps_update);
            frame_count = 0;
            last_fps_update = ms_now;
        }
    }
    float get_fps() {
        return fps;
    }
};
