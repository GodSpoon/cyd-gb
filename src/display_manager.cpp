#include "display_manager.h"
#include <esp_heap_caps.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

DisplayManager::DisplayManager(TFT_eSPI& display) : tft(display) {
}

bool DisplayManager::init() {
    if (initialized) return true;
    
    Serial.println("DisplayManager: Initializing...");
    
    // Clear screen and set rotation
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(1); // Landscape mode
    
    // Test basic display functionality
    Serial.println("DisplayManager: Testing display...");
    tft.drawPixel(160, 120, TFT_WHITE);
    delay(100);
    tft.drawPixel(160, 120, TFT_BLACK); // Clear test pixel
    
    // Draw border around Game Boy area
    draw_gameboy_border();
    
    // Allocate back buffer for double buffering
    if (!allocate_back_buffer()) {
        Serial.println("DisplayManager: Warning - Could not allocate back buffer, using direct rendering");
    }
    
    // Check if DMA is available
    #ifdef TFT_eSPI_DMA
    dma_enabled = true;
    Serial.println("DisplayManager: DMA enabled for non-blocking transfers");
    #else
    dma_enabled = false;
    Serial.println("DisplayManager: DMA not available, using blocking transfers");
    #endif
    
    initialized = true;
    Serial.println("DisplayManager: Initialized successfully");
    return true;
}

// Single, reliable rendering method - using the most reliable approach
void DisplayManager::render_gameboy_frame(const uint16_t* pixels) {
    if (!pixels || !initialized) {
        Serial.println("DisplayManager: Cannot render - invalid state");
        return;
    }
    
    // Wait for any pending DMA transfer to complete
    if (dma_enabled) {
        wait_for_dma();
    }
    
    // Use setAddrWindow + pushImageDMA for atomic DMA update
    tft.setAddrWindow(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    
    if (dma_enabled) {
        dma_busy = true;
        tft.pushImageDMA(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, (uint16_t*)pixels);
        // Note: TFT_eSPI's pushImageDMA is blocking, so we set dma_busy to false immediately
        dma_busy = false;
    } else {
        tft.pushImage(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, (uint16_t*)pixels);
    }
}

void DisplayManager::clear_screen() {
    if (!initialized) return;
    tft.fillScreen(TFT_BLACK);
    draw_gameboy_border();
}

void DisplayManager::draw_gameboy_border() {
    if (!initialized) return;
    
    // Draw a subtle border around the Game Boy screen area
    tft.drawRect(CENTER_X - 1, CENTER_Y - 1, GAMEBOY_WIDTH + 2, GAMEBOY_HEIGHT + 2, TFT_DARKGREY);
    
    // Fill the border area with black
    tft.fillRect(0, 0, CENTER_X - 1, CYD_HEIGHT, TFT_BLACK); // Left border
    tft.fillRect(CENTER_X + GAMEBOY_WIDTH + 1, 0, CENTER_X, CYD_HEIGHT, TFT_BLACK); // Right border
    tft.fillRect(0, 0, CYD_WIDTH, CENTER_Y - 1, TFT_BLACK); // Top border
    tft.fillRect(0, CENTER_Y + GAMEBOY_HEIGHT + 1, CYD_WIDTH, CENTER_Y, TFT_BLACK); // Bottom border
}

void DisplayManager::display_debug_info(float fps, uint32_t free_heap) {
    if (!initialized) return;
    
    // Display debug info in the border area
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextSize(1);
    
    // FPS display (top-left)
    tft.setCursor(5, 5);
    tft.printf("FPS: %.1f", fps);
    
    // Memory display (top-right)
    tft.setCursor(260, 5);
    tft.printf("MEM: %luK", free_heap / 1024);
    
    // Game Boy area indicator (bottom)
    tft.setCursor(CENTER_X + 10, CENTER_Y + GAMEBOY_HEIGHT + 15);
    tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
    tft.print("Game Boy Display");
}

void DisplayManager::display_error(const char* message) {
    if (!initialized) return;
    
    // Clear screen
    tft.fillScreen(TFT_RED);
    
    // Display error message
    tft.setTextColor(TFT_WHITE, TFT_RED);
    tft.setTextSize(2);
    tft.setCursor(20, 100);
    tft.print("ERROR:");
    tft.setCursor(20, 130);
    tft.print(message);
}

void DisplayManager::display_test_pattern() {
    if (!initialized) return;
    
    Serial.println("DisplayManager: Drawing test pattern");
    
    // Create a simple test pattern
    static uint16_t test_pattern[GAMEBOY_WIDTH * GAMEBOY_HEIGHT];
    
    for (int y = 0; y < GAMEBOY_HEIGHT; y++) {
        for (int x = 0; x < GAMEBOY_WIDTH; x++) {
            int index = y * GAMEBOY_WIDTH + x;
            
            // Create a gradient pattern
            uint8_t red = (x * 255) / GAMEBOY_WIDTH;
            uint8_t green = (y * 255) / GAMEBOY_HEIGHT;
            uint8_t blue = ((x + y) * 255) / (GAMEBOY_WIDTH + GAMEBOY_HEIGHT);
            
            // Convert to RGB565
            test_pattern[index] = ((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3);
        }
    }
    
    render_gameboy_frame(test_pattern);
}

bool DisplayManager::allocate_back_buffer() {
    if (back_buffer_allocated) return true;
    
    size_t buffer_size = GAMEBOY_WIDTH * GAMEBOY_HEIGHT * sizeof(uint16_t);
    Serial.printf("DisplayManager: Allocating back buffer (%d bytes)...\n", buffer_size);
    
    // CYD boards don't have PSRAM - use internal RAM only
    back_buffer = (uint16_t*)malloc(buffer_size);
    
    if (back_buffer) {
        // Clear the buffer
        memset(back_buffer, 0, buffer_size);
        back_buffer_allocated = true;
        Serial.printf("DisplayManager: Back buffer allocated at %p\n", back_buffer);
        return true;
    }
    
    Serial.println("DisplayManager: Failed to allocate back buffer");
    return false;
}

void DisplayManager::deallocate_back_buffer() {
    if (back_buffer_allocated && back_buffer) {
        free(back_buffer);
        back_buffer = nullptr;
        back_buffer_allocated = false;
        Serial.println("DisplayManager: Back buffer deallocated");
    }
}

void DisplayManager::swap_buffers() {
    if (!back_buffer || !initialized) {
        Serial.println("DisplayManager: Cannot swap buffers - invalid state");
        return;
    }
    
    // Wait for any pending DMA transfer to complete
    if (dma_enabled) {
        wait_for_dma();
    }
    
    // Atomic frame update using DMA
    tft.setAddrWindow(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    
    if (dma_enabled) {
        dma_busy = true;
        tft.pushImageDMA(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, back_buffer);
        // Note: TFT_eSPI's pushImageDMA is blocking, so we set dma_busy to false immediately
        dma_busy = false;
    } else {
        tft.pushImage(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, back_buffer);
    }
}

bool DisplayManager::try_swap_buffers() {
    if (!back_buffer || !initialized) {
        Serial.println("DisplayManager: Cannot swap buffers - invalid state");
        return false;
    }
    
    // Check if DMA is busy - if so, skip this frame (though in this implementation DMA is blocking)
    if (dma_enabled && dma_busy) {
        return false; // Skip frame, DMA still busy
    }
    
    // Atomic frame update using DMA
    tft.setAddrWindow(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    
    if (dma_enabled) {
        dma_busy = true;
        tft.pushImageDMA(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, back_buffer);
        // Note: TFT_eSPI's pushImageDMA is blocking, so we set dma_busy to false immediately
        dma_busy = false;
    } else {
        tft.pushImage(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, back_buffer);
    }
    
    return true;
}

void DisplayManager::wait_for_dma() {
    if (!dma_enabled) return;
    
    // Since TFT_eSPI's pushImageDMA is blocking in this version, 
    // we don't need to wait - but keep this for future compatibility
    while (dma_busy) {
        vTaskDelay(1); // Yield to other tasks
    }
}

DisplayManager::~DisplayManager() {
    deallocate_back_buffer();
}
