#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "menu.h"
#include "touch_manager.h"
#include <SD.h>
#include <vector>
#include <string>

// External references to display and touch from main.cpp
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;

// Touch manager instance
static TouchManager* touch_mgr = nullptr;

// Menu state
static bool menu_initialized = false;
static unsigned long last_update = 0;
static int menu_selection = 0;
static String selected_rom_path = "";
static std::vector<String> rom_files;

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
    // Scan SD card for .gb files
    rom_files.clear();
    File root = SD.open("/");
    if (root) {
        File file = root.openNextFile();
        while (file) {
            String fname = file.name();
            if (!file.isDirectory() && fname.endsWith(".gb")) {
                rom_files.push_back(fname);
            }
            file = root.openNextFile();
        }
        root.close();
    }
    if (rom_files.empty()) {
        rom_files.push_back("No ROMs found");
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
    int y = 120;
    for (size_t i = 0; i < rom_files.size(); ++i) {
        tft.setCursor(40, y);
        tft.setTextColor(menu_selection == (int)i ? MENU_SELECT_COLOR : MENU_TEXT_COLOR);
        tft.printf("%s%s", menu_selection == (int)i ? "> " : "  ", rom_files[i].c_str());
        y += 30;
    }
    
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
    int y = 120;
    for (size_t i = 0; i < rom_files.size(); ++i) {
        if (touching && tp.y >= y && tp.y < y + 30) {
            touched_selection = i;
        }
        y += 30;
    }

    // Update menu selection if touch is on a menu row
    if (touched_selection != -1 && touched_selection != menu_selection) {
        menu_selection = touched_selection;
        menu_init(); // Redraw menu only if selection changed
    }

    // Detect tap (touch release) on the currently selected item
    if (!touching && was_touching && last_selection == menu_selection && last_selection != -1) {
        if (!rom_files.empty() && rom_files[menu_selection] != "No ROMs found") {
            selected_rom_path = "/" + rom_files[menu_selection];
            Serial.printf("Menu: Selected ROM: %s\n", selected_rom_path.c_str());
            return MENU_RESULT_START_GAME;
        }
    }

    // Update touch state trackers
    was_touching = touching;
    last_selection = touched_selection != -1 ? touched_selection : last_selection;

    return MENU_RESULT_CONTINUE;
}

const char* menu_get_rompath() {
    return selected_rom_path.length() > 0 ? selected_rom_path.c_str() : nullptr;
}

void menu_set_rompath(const char* path) {
    if (path) selected_rom_path = path;
}