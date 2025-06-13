#include "core/emulator_context.h"
#include <Arduino.h>

// Splash screen timing constants
static constexpr unsigned long SPLASH_DISPLAY_TIME_MS = 2000;

// Menu constants
static constexpr uint16_t MENU_BACKGROUND_COLOR = 0x0000;  // Black
static constexpr uint16_t MENU_TEXT_COLOR = 0xFFFF;       // White
static constexpr uint16_t MENU_HIGHLIGHT_COLOR = 0xF800;  // Red

EmulatorContext::EmulatorContext(
    std::unique_ptr<IDisplay> display,
    std::unique_ptr<ITouch> touch,
    std::unique_ptr<IStorage> storage
) : display_(std::move(display)),
    touch_(std::move(touch)), 
    storage_(std::move(storage)),
    current_state_(EmulatorState::UNINITIALIZED),
    last_error_(EmulatorError::SUCCESS),
    initialized_(false),
    state_start_time_(0)
{
    Serial.println("EmulatorContext: Created with injected hardware dependencies");
    
    // Validate all dependencies were provided
    if (!display_ || !touch_ || !storage_) {
        Serial.println("EmulatorContext: ERROR - Null hardware dependency detected");
        current_state_ = EmulatorState::ERROR;
        last_error_ = EmulatorError::HARDWARE_ERROR;
    }
}

Result<void> EmulatorContext::initialize() {
    Serial.println("EmulatorContext: Initializing hardware components...");
    
    if (initialized_) {
        Serial.println("EmulatorContext: Already initialized");
        return Result<void>::ok();
    }
    
    // Validate dependencies again
    if (!display_ || !touch_ || !storage_) {
        Serial.println("EmulatorContext: Initialization failed - missing dependencies");
        last_error_ = EmulatorError::HARDWARE_ERROR;
        transitionToState(EmulatorState::ERROR);
        return Result<void>::err(EmulatorError::HARDWARE_ERROR);
    }
    
    // Initialize display
    Serial.println("EmulatorContext: Initializing display...");
    if (!display_->init()) {
        Serial.println("EmulatorContext: Display initialization failed");
        last_error_ = EmulatorError::DISPLAY_INIT_FAILED;
        transitionToState(EmulatorState::ERROR);
        return Result<void>::err(EmulatorError::DISPLAY_INIT_FAILED);
    }
    
    // Initialize touch
    Serial.println("EmulatorContext: Initializing touch...");
    if (!touch_->init()) {
        Serial.println("EmulatorContext: Touch initialization failed");
        last_error_ = EmulatorError::TOUCH_INIT_FAILED;
        transitionToState(EmulatorState::ERROR);
        return Result<void>::err(EmulatorError::TOUCH_INIT_FAILED);
    }
    
    // Initialize storage
    Serial.println("EmulatorContext: Initializing storage...");
    StorageError storage_result = storage_->init();
    if (storage_result != StorageError::SUCCESS) {
        Serial.printf("EmulatorContext: Storage initialization failed with error %d\n", (int)storage_result);
        last_error_ = EmulatorError::SD_CARD_ERROR;
        transitionToState(EmulatorState::ERROR);
        return Result<void>::err(EmulatorError::SD_CARD_ERROR);
    }
    
    // All hardware initialized successfully
    initialized_ = true;
    transitionToState(EmulatorState::SPLASH);
    
    Serial.println("EmulatorContext: All hardware components initialized successfully");
    return Result<void>::ok();
}

Result<void> EmulatorContext::run() {
    // State machine implementation
    switch (current_state_) {
        case EmulatorState::UNINITIALIZED:
            // Shouldn't call run() before initialize(), but handle gracefully
            Serial.println("EmulatorContext: run() called before initialize()");
            return Result<void>::err(EmulatorError::INVALID_STATE);
            
        case EmulatorState::SPLASH:
            return runSplash();
            
        case EmulatorState::MENU:
            return runMenu();
            
        case EmulatorState::RUNNING_ROM:
            return runEmulator();
            
        case EmulatorState::ERROR:
            return handleError();
            
        default:
            Serial.printf("EmulatorContext: Unknown state %d\n", (int)current_state_);
            last_error_ = EmulatorError::INVALID_STATE;
            transitionToState(EmulatorState::ERROR);
            return Result<void>::err(EmulatorError::INVALID_STATE);
    }
}

Result<void> EmulatorContext::runSplash() {
    static bool splash_displayed = false;
    
    if (!splash_displayed) {
        Serial.println("EmulatorContext: Displaying splash screen");
        
        // Clear screen and show splash
        display_->fillScreen(0x0000);  // Black background
        display_->setTextColor(0xFFFF);  // White text
        display_->setTextSize(3);
        
        // Center the title
        int16_t title_x = (display_->width() - 12 * 8 * 3) / 2;  // Approximate centering
        int16_t title_y = display_->height() / 2 - 20;
        display_->setCursor(title_x, title_y);
        display_->print("Game Boy");
        
        display_->setTextSize(2);
        int16_t subtitle_x = (display_->width() - 8 * 8 * 2) / 2;  // Approximate centering
        int16_t subtitle_y = title_y + 40;
        display_->setCursor(subtitle_x, subtitle_y);
        display_->print("Emulator");
        
        display_->setTextSize(1);
        display_->setTextColor(0x7BEF);  // Gray
        display_->setCursor(10, display_->height() - 20);
        display_->print("Loading...");
        
        splash_displayed = true;
    }
    
    // Check if splash time has elapsed
    unsigned long current_time = millis();
    if (current_time - state_start_time_ >= SPLASH_DISPLAY_TIME_MS) {
        Serial.println("EmulatorContext: Splash screen timeout, transitioning to menu");
        splash_displayed = false;  // Reset for next time
        transitionToState(EmulatorState::MENU);
    }
    
    return Result<void>::ok();
}

Result<void> EmulatorContext::runMenu() {
    static bool menu_displayed = false;
    static std::vector<std::string> rom_files;
    static int selected_index = 0;
    
    if (!menu_displayed) {
        Serial.println("EmulatorContext: Displaying ROM selection menu");
        
        // List ROM files from storage
        rom_files.clear();
        StorageError list_result = storage_->listFiles("/", ".gb", rom_files);
        
        if (list_result != StorageError::SUCCESS) {
            Serial.printf("EmulatorContext: Failed to list ROM files, error %d\n", (int)list_result);
            last_error_ = EmulatorError::SD_CARD_ERROR;
            transitionToState(EmulatorState::ERROR);
            return Result<void>::err(EmulatorError::SD_CARD_ERROR);
        }
        
        // Display menu
        display_->fillScreen(MENU_BACKGROUND_COLOR);
        display_->setTextSize(2);
        display_->setTextColor(MENU_TEXT_COLOR);
        display_->setCursor(10, 10);
        display_->print("Select ROM:");
        
        // Show ROM list
        display_->setTextSize(1);
        for (size_t i = 0; i < rom_files.size() && i < 8; ++i) {  // Limit to 8 visible items
            display_->setCursor(10, 40 + i * 20);
            if (i == selected_index) {
                display_->setTextColor(MENU_HIGHLIGHT_COLOR);
                display_->print("> ");
            } else {
                display_->setTextColor(MENU_TEXT_COLOR);
                display_->print("  ");
            }
            
            // Truncate long filenames
            const char* filename = rom_files[i].c_str();
            if (strlen(filename) > 30) {
                char truncated[31];
                strncpy(truncated, filename, 27);
                strcpy(truncated + 27, "...");
                display_->print(truncated);
            } else {
                display_->print(filename);
            }
        }
        
        if (rom_files.empty()) {
            display_->setCursor(10, 40);
            display_->setTextColor(MENU_HIGHLIGHT_COLOR);
            display_->print("No ROM files found!");
            display_->setCursor(10, 60);
            display_->setTextColor(MENU_TEXT_COLOR);
            display_->print("Add .gb files to SD card");
        }
        
        menu_displayed = true;
    }
    
    // Handle touch input
    if (touch_->touched()) {
        TouchPoint point = touch_->getPoint();
        if (point.pressed) {
            Serial.printf("EmulatorContext: Touch detected at (%d, %d)\n", point.x, point.y);
            
            if (!rom_files.empty()) {
                // Calculate which ROM was selected based on touch Y coordinate
                if (point.y >= 40 && point.y < 40 + rom_files.size() * 20) {
                    int touch_index = (point.y - 40) / 20;
                    if (touch_index >= 0 && touch_index < (int)rom_files.size()) {
                        selected_index = touch_index;
                        Serial.printf("EmulatorContext: Selected ROM: %s\n", rom_files[selected_index].c_str());
                        
                        // TODO: Load and start the ROM
                        // For now, just transition to running state
                        menu_displayed = false;  // Reset for next time
                        transitionToState(EmulatorState::RUNNING_ROM);
                    }
                }
            }
            
            // Add some debouncing
            delay(200);
        }
    }
    
    return Result<void>::ok();
}

Result<void> EmulatorContext::runEmulator() {
    static bool emulator_displayed = false;
    
    if (!emulator_displayed) {
        Serial.println("EmulatorContext: Starting Game Boy emulator");
        
        // Display placeholder for now
        display_->fillScreen(0x001F);  // Blue background
        display_->setTextColor(0xFFFF);
        display_->setTextSize(2);
        
        int16_t text_x = (display_->width() - 10 * 8 * 2) / 2;
        int16_t text_y = display_->height() / 2;
        display_->setCursor(text_x, text_y);
        display_->print("ROM Running");
        
        display_->setTextSize(1);
        display_->setCursor(10, display_->height() - 40);
        display_->print("Touch screen to return to menu");
        
        emulator_displayed = true;
    }
    
    // Handle touch to return to menu (temporary)
    if (touch_->touched()) {
        TouchPoint point = touch_->getPoint();
        if (point.pressed) {
            Serial.println("EmulatorContext: Touch detected, returning to menu");
            emulator_displayed = false;  // Reset for next time
            transitionToState(EmulatorState::MENU);
            delay(200);  // Debouncing
        }
    }
    
    return Result<void>::ok();
}

Result<void> EmulatorContext::handleError() {
    static bool error_displayed = false;
    
    if (!error_displayed) {
        Serial.printf("EmulatorContext: Displaying error state (error: %s)\n", 
                     error_to_string(last_error_));
        
        // Display error screen
        display_->fillScreen(0xF800);  // Red background
        display_->setTextColor(0xFFFF);  // White text
        display_->setTextSize(2);
        
        int16_t title_x = (display_->width() - 5 * 8 * 2) / 2;
        display_->setCursor(title_x, 20);
        display_->print("ERROR");
        
        display_->setTextSize(1);
        display_->setCursor(10, 60);
        
        // Display specific error message
        switch (last_error_) {
            case EmulatorError::DISPLAY_INIT_FAILED:
                display_->print("Display initialization failed");
                break;
            case EmulatorError::TOUCH_INIT_FAILED:
                display_->print("Touch initialization failed");
                break;
            case EmulatorError::SD_CARD_ERROR:
                display_->print("SD card error");
                display_->setCursor(10, 80);
                display_->print("Check SD card connection");
                break;
            case EmulatorError::HARDWARE_ERROR:
                display_->print("Hardware error");
                break;
            case EmulatorError::INVALID_STATE:
                display_->print("Invalid state error");
                break;
            default:
                display_->print("Unknown error occurred");
                break;
        }
        
        display_->setCursor(10, display_->height() - 20);
        display_->print("Touch to retry initialization");
        
        error_displayed = true;
    }
    
    // Handle touch to retry initialization
    if (touch_->touched()) {
        TouchPoint point = touch_->getPoint();
        if (point.pressed) {
            Serial.println("EmulatorContext: Touch detected, retrying initialization");
            error_displayed = false;  // Reset for next time
            initialized_ = false;     // Force re-initialization
            
            // Attempt to re-initialize
            Result<void> init_result = initialize();
            if (init_result.is_err()) {
                // Stay in error state
                return init_result;
            }
            
            delay(200);  // Debouncing
        }
    }
    
    return Result<void>::ok();
}

void EmulatorContext::transitionToState(EmulatorState new_state) {
    EmulatorState old_state = current_state_;
    current_state_ = new_state;
    state_start_time_ = millis();
    
    logStateTransition(old_state, new_state);
}

const char* EmulatorContext::stateToString(EmulatorState state) const {
    switch (state) {
        case EmulatorState::UNINITIALIZED: return "UNINITIALIZED";
        case EmulatorState::SPLASH: return "SPLASH";
        case EmulatorState::MENU: return "MENU";
        case EmulatorState::RUNNING_ROM: return "RUNNING_ROM";
        case EmulatorState::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void EmulatorContext::logStateTransition(EmulatorState from, EmulatorState to) {
    Serial.printf("EmulatorContext: State transition: %s -> %s\n", 
                 stateToString(from), stateToString(to));
}

unsigned long EmulatorContext::getStateUptime() const {
    return millis() - state_start_time_;
}
