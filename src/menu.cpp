#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "menu.h"

// External references to display and touch from main.cpp
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;

// Menu state
static bool menu_initialized = false;
static unsigned long last_update = 0;
static int menu_selection = 0;
static const char* rom_path = "pokemon_red"; // Default ROM

// Menu colors
#define MENU_BG_COLOR     TFT_BLACK
#define MENU_TEXT_COLOR   TFT_WHITE
#define MENU_SELECT_COLOR TFT_YELLOW
#define MENU_TITLE_COLOR  TFT_CYAN

void menu_init() {
    Serial.println("Menu: Initializing...");
    
    // Clear screen
    tft.fillScreen(MENU_BG_COLOR);
    
    // Draw title
    tft.setTextColor(MENU_TITLE_COLOR);
    tft.setTextSize(3);
    tft.setCursor(60, 20);
    tft.println("CYD-GB");
    
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.setCursor(40, 60);
    tft.println("Game Boy Emulator");
    
    // Draw menu options
    tft.setTextSize(2);
    tft.setCursor(40, 120);
    tft.setTextColor(menu_selection == 0 ? MENU_SELECT_COLOR : MENU_TEXT_COLOR);
    tft.println("> Start Pokemon Red");
    
    tft.setCursor(40, 150);
    tft.setTextColor(menu_selection == 1 ? MENU_SELECT_COLOR : MENU_TEXT_COLOR);
    tft.println("  Settings");
    
    tft.setCursor(40, 180);
    tft.setTextColor(menu_selection == 2 ? MENU_SELECT_COLOR : MENU_TEXT_COLOR);
    tft.println("  About");
    
    // Instructions
    tft.setTextColor(TFT_LIGHTGREY);
    tft.setTextSize(1);
    tft.setCursor(40, 220);
    tft.println("Touch to select, tap highlighted item to choose");
    
    menu_initialized = true;
    last_update = millis();
    Serial.println("Menu: Initialized successfully");
}

menu_result_t menu_loop() {
    // Throttle updates
    if (millis() - last_update < 100) {
        return MENU_RESULT_CONTINUE;
    }
    last_update = millis();
    
    if (!menu_initialized) {
        menu_init();
        return MENU_RESULT_CONTINUE;
    }
    
    // Check for touch input
    if (touch.touched()) {
        TS_Point p = touch.getPoint();
        
        // Simple touch handling - map touch Y to menu selection
        if (p.y > 1000 && p.y < 2000) {
            menu_selection = 0; // Start Game
        } else if (p.y > 2000 && p.y < 3000) {
            menu_selection = 1; // Settings
        } else if (p.y > 3000 && p.y < 4000) {
            menu_selection = 2; // About
        }
        
        // If touching the selected item, activate it
        static unsigned long last_touch = 0;
        if (millis() - last_touch > 500) { // Debounce
            last_touch = millis();
            
            if (menu_selection == 0) {
                Serial.println("Menu: Starting game selected!");
                return MENU_RESULT_START_GAME;
            } else {
                Serial.printf("Menu: Option %d selected (not implemented yet)\n", menu_selection);
            }
        }
        
        // Redraw menu with new selection
        menu_init();
    }
    
    return MENU_RESULT_CONTINUE;
}

const char* menu_get_rompath() {
    return rom_path;
}