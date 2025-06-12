#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "menu.h"
#include "touch_manager.h"

// External references to display and touch from main.cpp
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;

// Touch manager instance
static TouchManager* touch_mgr = nullptr;

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
    if (!touch_mgr) {
        touch_mgr = new TouchManager(touch);
    }
    
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
    if (!menu_initialized) {
        menu_init();
        return MENU_RESULT_CONTINUE;
    }
    // Throttle updates
    if (millis() - last_update < 100) {
        return MENU_RESULT_CONTINUE;
    }
    last_update = millis();

    // Static variables to track touch state and selection
    static bool was_touching = false;
    static int last_selection = -1;

    TouchManager::TouchPoint tp = touch_mgr->get_touch();
    bool touching = tp.valid;

    // Determine which menu row is being touched
    int touched_selection = -1;
    if (touching) {
        if (tp.y >= 120 && tp.y < 150) {
            touched_selection = 0; // Start Game
        } else if (tp.y >= 150 && tp.y < 180) {
            touched_selection = 1; // Settings
        } else if (tp.y >= 180 && tp.y < 210) {
            touched_selection = 2; // About
        }
    }

    // Update menu selection if touch is on a menu row
    if (touched_selection != -1 && touched_selection != menu_selection) {
        menu_selection = touched_selection;
        menu_init(); // Redraw menu only if selection changed
    }

    // Detect tap (touch release) on the currently selected item
    if (!touching && was_touching && last_selection == menu_selection && last_selection != -1) {
        // Tap detected on highlighted item
        if (menu_selection == 0) {
            Serial.println("Menu: Starting game selected!");
            return MENU_RESULT_START_GAME;
        } else {
            Serial.printf("Menu: Option %d selected (not implemented yet)\n", menu_selection);
        }
    }

    // Update touch state trackers
    was_touching = touching;
    last_selection = touched_selection != -1 ? touched_selection : last_selection;

    return MENU_RESULT_CONTINUE;
}

const char* menu_get_rompath() {
    return rom_path;
}