#include <Arduino.h>
#include "menu.h"
#include <SD.h>
#include <vector>
#include <string>

// Menu state
static bool menu_initialized = false;
static unsigned long last_update = 0;
static int menu_selection = 0;
static String selected_rom_path = "";
static std::vector<String> rom_files;

// Menu colors (RGB565 values)
#define MENU_BG_COLOR     0x0000  // Black
#define MENU_TEXT_COLOR   0xFFFF  // White
#define MENU_SELECT_COLOR 0xFFE0  // Yellow
#define MENU_TITLE_COLOR  0x07FF  // Cyan

void menu_init(IDisplay& display, ITouch& touch) {
    Serial.println("Menu: Initializing...");
    
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
    display.fillScreen(MENU_BG_COLOR);
    
    // Draw title
    display.setTextColor(MENU_TITLE_COLOR);
    display.setTextSize(3);
    display.setCursor(60, 20);
    display.print("CYD-GB");
    
    display.setTextColor(MENU_TEXT_COLOR);
    display.setTextSize(2);
    display.setCursor(40, 60);
    display.print("Game Boy Emulator");
    
    // Draw menu options
    display.setTextSize(2);
    int y = 120;
    for (size_t i = 0; i < rom_files.size(); ++i) {
        display.setCursor(40, y);
        display.setTextColor(menu_selection == (int)i ? MENU_SELECT_COLOR : MENU_TEXT_COLOR);
        const char* prefix = menu_selection == (int)i ? "> " : "  ";
        display.print(prefix);
        display.print(rom_files[i].c_str());
        y += 30;
    }
    
    // Instructions
    display.setTextColor(0x8410); // Light grey (RGB565)
    display.setTextSize(1);
    display.setCursor(40, 220);
    display.print("Touch to select, tap highlighted item to choose");
    
    menu_initialized = true;
    last_update = millis();
    Serial.println("Menu: Initialized successfully");
}

menu_result_t menu_update(IDisplay& display, ITouch& touch) {
    if (!menu_initialized) {
        menu_init(display, touch);
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

    bool touching = touch.touched();
    TouchPoint tp = touch.getPoint();

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
        menu_init(display, touch); // Redraw menu only if selection changed
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