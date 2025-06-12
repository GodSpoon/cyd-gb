#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "menu.h"

// External references to display objects
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;

static const char* rompath_c = nullptr;
static int selected_option = 0;
static const int num_options = 2;

// Menu options
static const char* menu_options[] = {
    "Start Pokemon Red",
    "Settings (Coming Soon)"
};

void menu_init(void)
{
    Serial.println("Menu system initialized - preparing to show menu");
    
    // Clear any existing display state
    tft.fillScreen(TFT_BLACK);
    
    // Reset to known good text settings
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.setTextDatum(TL_DATUM); // Top-left alignment
    tft.setTextWrap(true);
    
    Serial.println("Menu initialization complete");
}

void draw_menu() {
    Serial.println("=== Drawing menu ===");
    
    // Clear screen with black background
    tft.fillScreen(TFT_BLACK);
    delay(100); // Longer delay for stability
    
    // Test basic drawing first with shapes
    tft.drawRect(10, 10, 300, 220, TFT_WHITE);
    tft.fillRect(15, 15, 290, 25, TFT_BLUE); // Blue background for title area
    
    // Try drawing simple colored rectangles to test basic display functions
    tft.fillRect(50, 20, 200, 20, TFT_YELLOW); // Yellow bar where title should be
    tft.fillRect(80, 55, 160, 10, TFT_GREEN);  // Green bar where subtitle should be
    
    // Force TFT_eSPI to use basic text settings
    tft.setTextFont(1); // Built-in font
    tft.setTextWrap(false);
    tft.setTextDatum(TL_DATUM);
    tft.setTextSize(2); // Start with smaller size
    
    // Draw title using multiple methods for testing
    tft.setTextColor(TFT_BLACK); // Black text on yellow background
    tft.setCursor(55, 22);
    tft.print("JOLTEON");
    Serial.println("Title drawn: JOLTEON");
    
    // Try alternative text drawing method
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.setCursor(85, 57);
    tft.print("Game Boy Emulator");
    Serial.println("Subtitle drawn");
    
    // Draw a border around menu area
    tft.drawRect(15, 85, 290, 100, TFT_CYAN);
    
    // Draw menu options using drawString instead of print
    tft.setTextSize(2);
    Serial.printf("Drawing %d menu options\n", num_options);
    
    for (int i = 0; i < num_options; i++) {
        int y = 100 + (i * 45); // Menu item Y position
        
        Serial.printf("Drawing option %d: '%s' at y=%d\n", i, menu_options[i], y);
        
        // Draw selection highlight and set text color
        if (i == selected_option) {
            tft.fillRect(20, y - 8, 280, 35, TFT_YELLOW);
            tft.setTextColor(TFT_BLACK, TFT_YELLOW); // Black text on yellow background
            Serial.printf("Option %d highlighted\n", i);
        } else {
            tft.fillRect(20, y - 8, 280, 35, TFT_BLACK);
            tft.setTextColor(TFT_WHITE, TFT_BLACK); // White text on black background
        }
        
        // Draw menu text using print with cursor positioning for better control
        tft.setCursor(25, y);
        tft.print(menu_options[i]);
        Serial.printf("Text drawn for option %d\n", i);
    }
    
    // Draw instructions at bottom
    tft.setTextColor(TFT_CYAN, TFT_BLACK);
    tft.setTextSize(1);
    tft.setCursor(60, 210);
    tft.print("Touch a menu item to select");
    Serial.println("Instructions drawn");
    
    // Force display update
    delay(10);
    
    Serial.println("=== Menu drawing complete ===");
}

menu_result_t menu_loop(void)
{
    static bool menu_drawn = false;
    static unsigned long last_touch_time = 0;
    static unsigned long last_redraw_time = 0;
    static unsigned long last_debug_time = 0;
    
    unsigned long current_time = millis();
    
    // Force redraw every 5 seconds or if not drawn yet
    if (!menu_drawn || (current_time - last_redraw_time > 5000)) {
        Serial.println("Drawing/Redrawing menu");
        draw_menu();
        menu_drawn = true;
        last_redraw_time = current_time;
    }
    
    // Debug touch status every 2 seconds
    if (current_time - last_debug_time > 2000) {
        // Try both IRQ-based and direct polling
        bool irq_touched = touch.touched();
        
        // Also try direct SPI polling
        TS_Point p = touch.getPoint();
        bool direct_touched = (p.x > 100 && p.x < 4000 && p.y > 100 && p.y < 4000);
        
        Serial.printf("Touch status: IRQ=%s, Direct=%s, Raw x=%d, y=%d\n", 
                     irq_touched ? "TOUCHING" : "not touching",
                     direct_touched ? "TOUCHING" : "not touching",
                     p.x, p.y);
        
        // If we detect touch via direct polling but not IRQ, use direct method
        if (direct_touched && !irq_touched) {
            Serial.println("Using direct touch polling (IRQ not working)");
            // Process the touch
            if (current_time - last_touch_time > 500) {
                Serial.println("=== DIRECT TOUCH DETECTED ===");
                Serial.printf("Raw coordinates: x=%d, y=%d\n", p.x, p.y);
                
                // Map coordinates using board calibration values
                int screen_x = map(p.x, 200, 3900, 0, 320);
                int screen_y = map(p.y, 200, 3900, 0, 240);
                
                screen_x = constrain(screen_x, 0, 319);
                screen_y = constrain(screen_y, 0, 239);
                
                Serial.printf("Mapped coordinates: x=%d, y=%d\n", screen_x, screen_y);
                
                // Show visual feedback
                tft.fillCircle(screen_x, screen_y, 8, TFT_RED);
                tft.fillCircle(screen_x, screen_y, 4, TFT_WHITE);
                delay(300);
                draw_menu();
                
                // For now, any touch starts the game
                Serial.println("Starting game from direct touch!");
                last_touch_time = current_time;
                return MENU_RESULT_START_GAME;
            }
        }
        
        last_debug_time = current_time;
    }
    
    // Check for IRQ-based touch input
    if (touch.touched()) {
        Serial.println("=== IRQ TOUCH DETECTED ===");
        
        // Shorter debounce for better responsiveness
        if (current_time - last_touch_time > 200) {
            TS_Point p = touch.getPoint();
            
            Serial.printf("Raw touch coordinates: x=%d, y=%d\n", p.x, p.y);
            
            // Validate coordinates
            if (p.x > 100 && p.x < 4000 && p.y > 100 && p.y < 4000) {
                // Map coordinates
                int screen_x = map(p.x, 200, 3900, 0, 320);
                int screen_y = map(p.y, 200, 3900, 0, 240);
                
                screen_x = constrain(screen_x, 0, 319);
                screen_y = constrain(screen_y, 0, 239);
                
                Serial.printf("Mapped coordinates: x=%d, y=%d\n", screen_x, screen_y);
                
                // Show visual feedback
                tft.fillCircle(screen_x, screen_y, 8, TFT_RED);
                tft.fillCircle(screen_x, screen_y, 4, TFT_WHITE);
                delay(300);
                draw_menu();
                
                Serial.println("Starting game from IRQ touch!");
                last_touch_time = current_time;
                return MENU_RESULT_START_GAME;
            } else {
                Serial.println("Invalid touch coordinates");
            }
        }
    }
    
    return MENU_RESULT_CONTINUE;
}

const char* menu_get_rompath(void)
{
    // Return NULL to use the compiled-in ROM
    return nullptr;
}

// Touch calibration helper function
void touch_calibration_test() {
    Serial.println("=== STARTING TOUCH CALIBRATION TEST ===");
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.print("Touch Calibration");
    tft.setTextSize(1);
    tft.setCursor(10, 40);
    tft.print("Touch the screen and check");
    tft.setCursor(10, 60);
    tft.print("Serial Monitor for coordinates");
    
    // Draw touch target areas
    tft.drawRect(50, 100, 50, 30, TFT_GREEN);  // Left target
    tft.drawRect(200, 100, 50, 30, TFT_GREEN); // Right target
    tft.drawRect(125, 150, 50, 30, TFT_GREEN); // Center target
    
    tft.setCursor(55, 110);
    tft.print("LEFT");
    tft.setCursor(205, 110);
    tft.print("RIGHT");
    tft.setCursor(130, 160);
    tft.print("CENTER");
    
    unsigned long start_time = millis();
    int touch_count = 0;
    
    while (millis() - start_time < 15000 && touch_count < 10) { // 15 seconds or 10 touches
        if (touch.touched()) {
            TS_Point p = touch.getPoint();
            touch_count++;
            
            Serial.printf("Touch #%d - Raw: x=%d, y=%d\n", touch_count, p.x, p.y);
            
            // Show different mapping attempts
            int map1_x = map(p.x, 300, 3800, 0, 320);
            int map1_y = map(p.y, 300, 3800, 0, 240);
            int map2_x = map(p.x, 200, 3900, 0, 320);
            int map2_y = map(p.y, 200, 3900, 0, 240);
            int map3_x = map(p.x, 400, 3600, 0, 320);
            int map3_y = map(p.y, 400, 3600, 0, 240);
            
            Serial.printf("  Map1 (300-3800): x=%d, y=%d\n", map1_x, map1_y);
            Serial.printf("  Map2 (200-3900): x=%d, y=%d\n", map2_x, map2_y);
            Serial.printf("  Map3 (400-3600): x=%d, y=%d\n", map3_x, map3_y);
            
            // Draw touch indicator
            tft.fillCircle(constrain(map1_x, 0, 319), constrain(map1_y, 0, 239), 5, TFT_RED);
            
            delay(800); // Delay between touches
        }
        delay(50);
    }
    
    Serial.println("=== TOUCH CALIBRATION TEST COMPLETE ===");
    delay(2000);
}
