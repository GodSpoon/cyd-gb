#include "display_manager.h"

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
    // Use setAddrWindow + pushImageDMA for atomic, non-blocking DMA update
    tft.setAddrWindow(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    tft.pushImageDMA(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, (uint16_t*)pixels);
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
