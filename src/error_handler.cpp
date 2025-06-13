#include "error_handler.h"

IDisplay* ErrorHandler::display = nullptr;

void ErrorHandler::init(IDisplay* display_interface) {
    display = display_interface;
}

void ErrorHandler::handle_error(EmulatorError error, const char* context) {
    Serial.printf("ERROR: Code %d", (int)error);
    if (context) {
        Serial.printf(" Context: %s", context);
    }
    Serial.println();
    
    const char* title = "System Error";
    const char* message = "Unknown error";
    const char* suggestion = "Try rebooting";
    
    switch (error) {
        case EmulatorError::MEMORY_EXHAUSTED:
            message = "Out of memory";
            suggestion = "This board needs ROM streaming.\nCheck SD card and reboot.";
            break;
            
        case EmulatorError::ROM_LOAD_FAILED:
            message = "ROM file load failed";
            suggestion = "Check SD card and ROM file.\nEnsure .gb file is valid.";
            break;
            
        case EmulatorError::SD_CARD_ERROR:
            message = "SD card error";
            suggestion = "Insert SD card with .gb files\nand reboot device.";
            break;
    }
    
    display_error_screen(title, message, suggestion);
    
    while (1) {
        delay(1000);
    }
}

void ErrorHandler::display_error_screen(const char* title, const char* message, const char* suggestion) {
    if (!display) return;
    
    display->fillScreen(0xF800); // Red (RGB565)
    display->setTextColor(0xFFFF); // White (RGB565)
    
    display->setTextSize(3);
    display->setCursor(50, 30);
    display->print(title);
    
    display->setTextSize(2);
    display->setCursor(20, 80);
    display->print(message);
    
    if (suggestion) {
        display->setTextSize(1);
        display->setCursor(20, 140);
        display->print(suggestion);
    }
    
    display->setTextSize(1);
    display->setTextColor(0xFFE0); // Yellow (RGB565)
    display->setCursor(20, 220);
    display->print("Press RESET button to restart");
}
