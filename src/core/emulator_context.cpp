#include "core/emulator_context.h"
#include "core/memory_utils.h"
#include <Arduino.h>

// Game Boy emulator includes
extern "C" {
    #include "cpu.h"
    #include "lcd.h"
    #include "rom.h"
    #include "timer.h"
}
#include "mbc.h"
#include "jolteon.h"  // For jolteon_set_display()
#include "rom_streamer.h"  // C++ class, include outside extern "C"

// Forward declaration for cpu_set_framebuffer_manager
class FramebufferManager;

// Temporary implementation to resolve linkage issue
void cpu_set_framebuffer_manager(FramebufferManager* fbmgr) {
    // TODO: Implement CPU framebuffer dependency injection
    // For now, this is a stub to allow compilation
    static_cast<void>(fbmgr); // Suppress unused parameter warning
}

// Splash screen timing constants
static constexpr unsigned long SPLASH_DISPLAY_TIME_MS = 2000;  // 2 seconds (reduced for testing)

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
    framebuffer_manager_(make_unique<FramebufferManager>()),
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
    
    // Set the global display reference for jolteon_end_frame()
    Serial.println("EmulatorContext: Setting global display reference...");
    jolteon_set_display(display_.get());
    
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
    
    // Initialize framebuffer manager for Game Boy LCD output
    Serial.println("EmulatorContext: Initializing framebuffer manager...");
    if (!framebuffer_manager_->init()) {
        Serial.println("EmulatorContext: Framebuffer manager initialization failed");
        last_error_ = EmulatorError::HARDWARE_ERROR;
        transitionToState(EmulatorState::ERROR);
        return Result<void>::err(EmulatorError::HARDWARE_ERROR);
    }
    
    // Inject framebuffer manager into Game Boy modules
    Serial.println("EmulatorContext: Injecting framebuffer manager into Game Boy modules...");
    lcd_set_framebuffer_manager(framebuffer_manager_.get());
    cpu_set_framebuffer_manager(framebuffer_manager_.get());
    mbc_set_framebuffer_manager(framebuffer_manager_.get());
    jolteon_set_framebuffer_manager(framebuffer_manager_.get());
    Serial.println("EmulatorContext: Framebuffer manager dependency injection complete");
    
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
        
        // Draw splash screen with logo
        Serial.println("EmulatorContext: Drawing splash screen with logo");
        jolteon_display_splash_screen(*display_);
        
        Serial.println("EmulatorContext: Splash screen displayed successfully");
        
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
        
        // Add a delay after splash screen to ensure display is ready
        delay(100);
        
        // List ROM files from storage
        rom_files.clear();
        StorageError list_result = storage_->listFiles("/", ".gb", rom_files);
        
        if (list_result != StorageError::SUCCESS) {
            Serial.printf("EmulatorContext: Failed to list ROM files, error %d\n", (int)list_result);
            last_error_ = EmulatorError::SD_CARD_ERROR;
            transitionToState(EmulatorState::ERROR);
            return Result<void>::err(EmulatorError::SD_CARD_ERROR);
        }
        
        Serial.printf("EmulatorContext: Found %d ROM files, clearing display for menu\n", rom_files.size());
        
        // Display menu
        display_->fillScreen(MENU_BACKGROUND_COLOR);
        delay(200); // Longer delay after clear
        
        // Reset text settings completely after splash screen
        Serial.println("EmulatorContext: Resetting all text settings after splash");
        display_->setTextSize(1);  // Reset to basic size first
        display_->setTextColor(0xFFFF);  // Reset to white
        display_->setCursor(0, 0);  // Reset cursor to origin
        
        Serial.println("EmulatorContext: Setting up menu text");
        display_->setTextSize(2);  // Larger text size for better visibility
        display_->setTextColor(0xFFFF);  // Force white color
        display_->setCursor(10, 10);
        Serial.println("EmulatorContext: About to print 'Select ROM:'");
        display_->print("Select ROM:");
        
        Serial.println("EmulatorContext: Menu header displayed - verifying with test text");
        
        // Force additional test text to ensure display is working
        display_->setTextColor(0xF800);  // Force red color
        display_->setTextSize(2);
        display_->setCursor(10, 45);
        display_->print("MENU TEST");
        delay(500); // Brief pause to ensure text is rendered
        
        // Show ROM list
        Serial.println("EmulatorContext: Displaying ROM list");
        display_->setTextSize(1);  // Smaller text for ROM list to fit more items
        for (size_t i = 0; i < rom_files.size() && i < 8; ++i) {  // Limit to 8 visible items
            display_->setCursor(10, 80 + i * 15);  // Tighter spacing for smaller text
            if (i == selected_index) {
                display_->setTextColor(0xF800);  // Force red color for selection
                display_->print("> ");
            } else {
                display_->setTextColor(0xFFFF);  // Force white color
                display_->print("  ");
            }
            
            // Truncate long filenames
            const char* filename = rom_files[i].c_str();
            if (strlen(filename) > 40) {  // Increased limit for smaller text
                char truncated[41];
                strncpy(truncated, filename, 37);
                strcpy(truncated + 37, "...");
                display_->print(truncated);
                Serial.printf("EmulatorContext: Displayed ROM %d: %s\n", (int)i, truncated);
            } else {
                display_->print(filename);
                Serial.printf("EmulatorContext: Displayed ROM %d: %s\n", (int)i, filename);
            }
        }
        
        if (rom_files.empty()) {
            Serial.println("EmulatorContext: No ROM files found, displaying error message");
            display_->setCursor(10, 80);
            display_->setTextColor(0xF800);  // Force red color
            display_->setTextSize(1);
            display_->print("No ROM files found!");
            display_->setCursor(10, 100);
            display_->setTextColor(0xFFFF);  // Force white color
            display_->print("Add .gb files to SD card");
        }
        
        // Force a test pattern to ensure text is visible
        Serial.println("EmulatorContext: Adding forced test text to verify display");
        display_->setCursor(10, 200);
        display_->setTextColor(0x07E0);  // Force green color
        display_->setTextSize(1);
        display_->print("TEXT TEST - VISIBLE?");
        
        Serial.println("EmulatorContext: Menu display completed");
        menu_displayed = true;
        
        // Give the display time to render all text
        delay(100);
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
                        
                        // Load and start the ROM
                        std::string rom_path = "/" + rom_files[selected_index];
                        
                        // Check if ROM file exists
                        if (!storage_->exists(rom_path.c_str())) {
                            Serial.printf("EmulatorContext: ROM file does not exist: %s\n", rom_path.c_str());
                            last_error_ = EmulatorError::ROM_LOAD_FAILED;
                            transitionToState(EmulatorState::ERROR);
                            return Result<void>::err(EmulatorError::ROM_LOAD_FAILED);
                        }
                        
                        Serial.printf("EmulatorContext: Initializing ROM streamer with %s\n", rom_path.c_str());
                        
                        // Initialize ROM streamer with the ROM file path
                        if (!rom_streamer.init(rom_path.c_str())) {
                            Serial.printf("EmulatorContext: Failed to initialize ROM streamer with %s\n", rom_path.c_str());
                            last_error_ = EmulatorError::ROM_LOAD_FAILED;
                            transitionToState(EmulatorState::ERROR);
                            return Result<void>::err(EmulatorError::ROM_LOAD_FAILED);
                        }
                        
                        // Initialize Game Boy ROM (using ROM streamer)
                        if (!rom_init(nullptr)) {  // ROM streamer is used instead of direct bytes
                            Serial.println("EmulatorContext: Failed to initialize Game Boy ROM");
                            rom_streamer.cleanup();
                            last_error_ = EmulatorError::ROM_LOAD_FAILED;
                            transitionToState(EmulatorState::ERROR);
                            return Result<void>::err(EmulatorError::ROM_LOAD_FAILED);
                        }
                        
                        Serial.println("EmulatorContext: Game Boy ROM initialized successfully");
                        
                        // Initialize Game Boy CPU
                        cpu_init();
                        Serial.println("EmulatorContext: Game Boy CPU initialized");
                        
                        // Initialize Game Boy LCD
                        if (!lcd_init()) {
                            Serial.println("EmulatorContext: Failed to initialize Game Boy LCD");
                            rom_streamer.cleanup();
                            last_error_ = EmulatorError::HARDWARE_ERROR;
                            transitionToState(EmulatorState::ERROR);
                            return Result<void>::err(EmulatorError::HARDWARE_ERROR);
                        }
                        Serial.println("EmulatorContext: Game Boy LCD initialized");
                        
                        Serial.println("EmulatorContext: Game Boy emulator fully initialized - starting execution");
                        
                        // Transition to running state
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
    static bool emulator_started = false;
    static bool test_pattern_created = false;
    
    if (!emulator_started) {
        Serial.println("EmulatorContext: Game Boy emulator running state entered");
        emulator_started = true;
        
        // Clear screen to prepare for Game Boy output
        display_->fillScreen(0x0000);  // Black background
        
        // Create a test pattern to verify the display pipeline is working
        if (!test_pattern_created) {
            framebuffer_manager_->create_test_pattern();
            test_pattern_created = true;
        }
    }
    
    // Run Game Boy CPU, LCD, and Timer cycles
    // This is the main emulation loop
    static uint32_t frame_counter = 0;
    uint32_t cycles = cpu_cycle();
    if (cycles > 0) {
        lcd_cycle(cycles);
        timer_cycle(cycles);
        
        // Debug output every 1000 frames
        frame_counter++;
        if (frame_counter % 1000 == 0) {
            Serial.printf("EmulatorContext: Emulation running - frame %d, cycles: %d\n", 
                         frame_counter, cycles);
        }
        
        // Check if framebuffer is ready for display
        if (framebuffer_manager_->is_ready()) {
            const uint16_t* fb = framebuffer_manager_->get_front_buffer();
            if (fb) {
                // Calculate scaling and positioning for Game Boy screen on TFT display
                int scale_x = display_->width() / FramebufferManager::FB_WIDTH;
                int scale_y = display_->height() / FramebufferManager::FB_HEIGHT;
                int scale = (scale_x < scale_y) ? scale_x : scale_y;
                
                // Center the Game Boy screen on the TFT display
                int offset_x = (display_->width() - FramebufferManager::FB_WIDTH * scale) / 2;
                int offset_y = (display_->height() - FramebufferManager::FB_HEIGHT * scale) / 2;
                
                // Draw Game Boy framebuffer to TFT display with scaling
                for (int y = 0; y < FramebufferManager::FB_HEIGHT; y++) {
                    for (int x = 0; x < FramebufferManager::FB_WIDTH; x++) {
                        uint16_t pixel = fb[y * FramebufferManager::FB_WIDTH + x];
                        
                        // Draw scaled pixel block
                        for (int dy = 0; dy < scale; dy++) {
                            for (int dx = 0; dx < scale; dx++) {
                                int screen_x = offset_x + x * scale + dx;
                                int screen_y = offset_y + y * scale + dy;
                                if (screen_x < display_->width() && screen_y < display_->height()) {
                                    display_->drawPixel(screen_x, screen_y, pixel);
                                }
                            }
                        }
                    }
                }
                
                framebuffer_manager_->mark_displayed();
            }
        }
    }
    
    // Handle touch to return to menu (for now - later this will be for controls)
    if (touch_->touched()) {
        TouchPoint point = touch_->getPoint();
        if (point.pressed) {
            Serial.println("EmulatorContext: Touch detected, returning to menu");
            
            // Clean up ROM streamer
            rom_streamer.cleanup();
            
            emulator_started = false;  // Reset for next time
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
