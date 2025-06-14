#include "core/emulator_context.h"
#include "core/memory_utils.h"
#include "hardware/xpt2046_touch.h"  // For touch configuration
#include <Arduino.h>
#include <algorithm>  // For std::sort

// Game Boy emulator includes
extern "C" {
    #include "cpu.h"
    #include "lcd.h"
    #include "rom.h"
    #include "timer.h"
    #include "mem.h"
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
    
    // Configure touch for landscape display (320x240)
    Serial.println("EmulatorContext: Configuring touch for landscape mode...");
    touch_->setRotation(1);  // Landscape rotation
    
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
    static int scroll_offset = 0;
    static bool touch_was_pressed = false;
    static unsigned long last_touch_time = 0;
    static unsigned long selection_time = 0; // Track when item was selected
    static bool show_selection_hint = false;
    static unsigned long last_update_time = 0;
    
    const int MAX_VISIBLE_ITEMS = 8;  // Optimized for better readability
    const int MENU_START_Y = 60;      // Start menu items lower for better layout
    const int ITEM_HEIGHT = 20;       // Larger item height for easier touch
    const int MENU_MARGIN = 20;       // Larger margin for better layout
    const unsigned long TOUCH_DEBOUNCE_MS = 200;  // Reduced debounce for better responsiveness
    const unsigned long SELECTION_HINT_DURATION = 2000; // Show hint for 2 seconds
    const unsigned long UPDATE_THROTTLE_MS = 50; // Throttle updates to 20 FPS
    
    // Throttle menu updates to prevent excessive redrawing
    if (millis() - last_update_time < UPDATE_THROTTLE_MS) {
        return Result<void>::ok();
    }
    last_update_time = millis();
    
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
        
        // Sort ROM files alphabetically for easier navigation
        std::sort(rom_files.begin(), rom_files.end());
        
        Serial.printf("EmulatorContext: Found %d ROM files\n", rom_files.size());
        
        // Clear screen and draw improved menu
        display_->fillScreen(MENU_BACKGROUND_COLOR);
        
        // Draw enhanced title bar with gradient effect
        display_->setTextSize(3);
        display_->setTextColor(0x07FF);  // Cyan title
        int title_x = (display_->width() - 12 * 8 * 3) / 2; // Center "CYD Game Boy"
        display_->setCursor(title_x, 8);
        display_->print("CYD Game Boy");
        
        // Draw subtitle with better positioning
        display_->setTextSize(1);
        display_->setTextColor(0xC618);  // Light purple subtitle  
        int subtitle_x = (display_->width() - 18 * 6) / 2; // Center "Select ROM to play:"
        display_->setCursor(subtitle_x, 35);
        display_->print("Select ROM to play:");
        
        // Draw ROM count with better formatting
        display_->setCursor(10, 45);
        display_->setTextColor(0x8410);  // Gray
        display_->print("Found ");
        display_->print((int)rom_files.size());
        if (rom_files.size() > MAX_VISIBLE_ITEMS) {
            display_->print(" ROMs (scroll available)");
        } else {
            display_->print(" ROMs");
        }
        
        menu_displayed = true;
        selected_index = 0; // Reset selection
        scroll_offset = 0;  // Reset scroll
    }
    
    // Only redraw ROM list when needed (selection changed or scroll changed)
    static int last_selected_index = -1;
    static int last_scroll_offset = -1;
    static bool need_redraw = true;
    
    // Check if we need to redraw
    if (selected_index != last_selected_index || scroll_offset != last_scroll_offset || need_redraw) {
        last_selected_index = selected_index;
        last_scroll_offset = scroll_offset;
        need_redraw = false;
        
        if (!rom_files.empty()) {
            // Clear ROM list area only when redrawing
            for (int y = MENU_START_Y; y < MENU_START_Y + MAX_VISIBLE_ITEMS * ITEM_HEIGHT + 10; y++) {
                for (int x = 0; x < 320; x++) {
                    display_->drawPixel(x, y, MENU_BACKGROUND_COLOR);
                }
            }
        
        // Calculate visible range
        int start_index = scroll_offset;
        int end_index = std::min(start_index + MAX_VISIBLE_ITEMS, (int)rom_files.size());
        
        // Draw visible ROM items with enhanced styling
        for (int i = start_index; i < end_index; i++) {
            int display_index = i - start_index;
            int item_y = MENU_START_Y + display_index * ITEM_HEIGHT;
            
            // Enhanced selection highlighting
            if (i == selected_index) {
                // Draw selection background with rounded corners effect
                uint16_t select_color = 0x2945; // Dark blue-green selection
                for (int y = item_y + 1; y < item_y + ITEM_HEIGHT - 1; y++) {
                    for (int x = MENU_MARGIN - 8; x < 300; x++) {
                        display_->drawPixel(x, y, select_color);
                    }
                }
                
                // Draw selection border
                for (int x = MENU_MARGIN - 8; x < 300; x++) {
                    display_->drawPixel(x, item_y, 0x5ACB); // Lighter border
                    display_->drawPixel(x, item_y + ITEM_HEIGHT - 1, 0x5ACB);
                }
            }
            
            // Draw ROM filename with better formatting
            display_->setCursor(MENU_MARGIN, item_y + 4);
            display_->setTextSize(1);
            
            if (i == selected_index) {
                display_->setTextColor(0xFFE0);  // Yellow for selected
                display_->print("> ");
            } else {
                display_->setTextColor(0xFFFF);  // White for normal
                display_->print("  ");
            }
            
            // Better filename handling with extension removal for cleaner display
            const char* filename = rom_files[i].c_str();
            std::string display_name = filename;
            
            // Remove .gb extension for cleaner look
            if (display_name.length() > 3 && display_name.substr(display_name.length() - 3) == ".gb") {
                display_name = display_name.substr(0, display_name.length() - 3);
            }
            
            // Truncate if too long
            if (display_name.length() > 30) {
                display_name = display_name.substr(0, 27) + "...";
            }
            
            display_->print(display_name.c_str());
        }
        
        // Enhanced scroll indicators
        if (rom_files.size() > MAX_VISIBLE_ITEMS) {
            if (scroll_offset > 0) {
                // Up arrow with better visibility
                display_->setCursor(290, MENU_START_Y - 12);
                display_->setTextColor(0x07E0);  // Green
                display_->setTextSize(2);
                display_->print("^");
            }
            if (scroll_offset + MAX_VISIBLE_ITEMS < (int)rom_files.size()) {
                // Down arrow
                display_->setCursor(290, MENU_START_Y + MAX_VISIBLE_ITEMS * ITEM_HEIGHT + 2);
                display_->setTextColor(0x07E0);  // Green
                display_->setTextSize(2);
                display_->print("v");
            }
            
            // Scroll position indicator
            int total_pages = (rom_files.size() + MAX_VISIBLE_ITEMS - 1) / MAX_VISIBLE_ITEMS;
            int current_page = (scroll_offset / MAX_VISIBLE_ITEMS) + 1;
            display_->setCursor(250, MENU_START_Y - 12);
            display_->setTextColor(0x8410);  // Gray
            display_->setTextSize(1);
            display_->print("Page ");
            display_->print(current_page);
            display_->print("/");
            display_->print(total_pages);
        }
    } else {
        // Enhanced "No ROMs found" message (only draw once)
        static bool no_roms_drawn = false;
        if (!no_roms_drawn) {
            // Create dark red background effect with multiple rectangles
            for (int y = 80; y < 160; y++) {
                for (int x = 50; x < 270; x++) {
                    display_->drawPixel(x, y, 0x2000);  // Dark red background
                }
            }
            
            display_->setCursor(70, 90);
            display_->setTextColor(0xF800);  // Red
            display_->setTextSize(2);
            display_->print("No ROMs Found!");
            
            display_->setCursor(60, 115);
            display_->setTextColor(0xFFFF);  // White
            display_->setTextSize(1);
            display_->print("Please add .gb files to");
            display_->setCursor(60, 130);
            display_->print("your SD card and restart");
            
            display_->setCursor(60, 145);
            display_->setTextColor(0x8410);  // Gray
            display_->print("Supported: Game Boy ROMs");
            
            no_roms_drawn = true;
        }
    }
    
    } // End of redraw condition
    
    // Draw instructions at bottom (only when needed)
    static bool instructions_drawn = false;
    static bool last_hint_state = false;
    static bool hint_was_showing = false;
    
    if (!instructions_drawn || (show_selection_hint != last_hint_state) || hint_was_showing) {
        // Clear instruction area
        for (int y = 210; y < 240; y++) {
            for (int x = 0; x < 320; x++) {
                display_->drawPixel(x, y, MENU_BACKGROUND_COLOR);
            }
        }
        
        display_->setCursor(10, 210);
        display_->setTextColor(0x8410);  // Gray
        display_->setTextSize(1);
        if (rom_files.empty()) {
            // Add a test display option when no ROMs are found
            rom_files.push_back("TEST_DISPLAY_PATTERN.gb");
            selected_index = 0;
            need_redraw = true;
            
            display_->print("No ROMs found - Test Display Pattern available");
        } else {
            display_->print("Touch to select \x7E Touch selected ROM again to play");
            
            // Show selection hint for better UX
            if (show_selection_hint && millis() - selection_time < SELECTION_HINT_DURATION) {
                display_->setCursor(10, 225);
                display_->setTextColor(0xFFE0);  // Yellow
                display_->print("'");
                // Truncate ROM name for hint display
                std::string hint_name = rom_files[selected_index];
                if (hint_name.length() > 20) {
                    hint_name = hint_name.substr(0, 17) + "...";
                }
                display_->print(hint_name.c_str());
                display_->print("' selected - touch again to launch!");
            }
        }
        
        instructions_drawn = true;
        last_hint_state = show_selection_hint;
        hint_was_showing = false; // Reset flag
    }
    
    // Enhanced touch input handling
    bool current_touch = touch_->touched();
    TouchPoint point = touch_->getPoint();
    
    if (current_touch && point.pressed && !touch_was_pressed) {
        // Touch started - check debounce
        if (millis() - last_touch_time > TOUCH_DEBOUNCE_MS) {
            Serial.printf("EmulatorContext: Touch at (%d, %d)\n", point.x, point.y);
            
            if (!rom_files.empty()) {
                // Check if touch is in ROM list area
                if (point.x >= MENU_MARGIN && point.x <= 280 && 
                    point.y >= MENU_START_Y && point.y <= MENU_START_Y + MAX_VISIBLE_ITEMS * ITEM_HEIGHT) {
                    
                    // Calculate touched item
                    int touch_item = (point.y - MENU_START_Y) / ITEM_HEIGHT;
                    int actual_index = scroll_offset + touch_item;
                    
                    if (actual_index >= 0 && actual_index < (int)rom_files.size()) {
                        if (actual_index == selected_index) {
                            // Double-tap on selected item - launch ROM
                            Serial.printf("EmulatorContext: Launching ROM: %s\n", rom_files[selected_index].c_str());
                            
                            // Enhanced loading screen
                            display_->fillScreen(0x0841);  // Dark blue background
                            
                            // Draw loading title
                            display_->setTextColor(0xFFE0); // Yellow
                            display_->setTextSize(3);
                            int loading_x = (display_->width() - 8 * 8 * 3) / 2;
                            display_->setCursor(loading_x, 60);
                            display_->print("Loading");
                            
                            // Show ROM info
                            display_->setTextColor(0xFFFF); // White
                            display_->setTextSize(1);
                            display_->setCursor(20, 100);
                            display_->print("ROM File: ");
                            display_->setTextColor(0x07E0); // Green
                            display_->print(rom_files[selected_index].c_str());
                            
                            display_->setTextColor(0xFFFF); // White
                            display_->setCursor(20, 120);
                            display_->print("Initializing Game Boy hardware...");
                            
                            display_->setCursor(20, 140);
                            display_->print("Setting up ROM streaming...");
                            
                            // Progress indicator
                            for (int i = 0; i < 10; i++) {
                                int bar_x = 60 + i * 20;
                                for (int x = bar_x; x < bar_x + 15; x++) {
                                    for (int y = 160; y < 170; y++) {
                                        display_->drawPixel(x, y, 0x2945); // Blue progress
                                    }
                                }
                                delay(100); // Show progress
                            }
                            
                            // Load the ROM
                            std::string rom_path = "/" + rom_files[selected_index];
                            
                            if (!storage_->exists(rom_path.c_str())) {
                                Serial.printf("EmulatorContext: ROM file does not exist: %s\n", rom_path.c_str());
                                last_error_ = EmulatorError::ROM_LOAD_FAILED;
                                transitionToState(EmulatorState::ERROR);
                                return Result<void>::err(EmulatorError::ROM_LOAD_FAILED);
                            }
                            
                            // Initialize ROM streamer
                            if (!rom_streamer.init(rom_path.c_str())) {
                                Serial.printf("EmulatorContext: Failed to initialize ROM streamer\n");
                                last_error_ = EmulatorError::ROM_LOAD_FAILED;
                                transitionToState(EmulatorState::ERROR);
                                return Result<void>::err(EmulatorError::ROM_LOAD_FAILED);
                            }
                            
                            // Initialize Game Boy components
                            if (!rom_init(nullptr)) {
                                Serial.println("EmulatorContext: Failed to initialize ROM");
                                rom_streamer.cleanup();
                                last_error_ = EmulatorError::ROM_LOAD_FAILED;
                                transitionToState(EmulatorState::ERROR);
                                return Result<void>::err(EmulatorError::ROM_LOAD_FAILED);
                            }
                            
                            cpu_init();
                            
                            if (!lcd_init()) {
                                Serial.println("EmulatorContext: Failed to initialize LCD");
                                rom_streamer.cleanup();
                                last_error_ = EmulatorError::HARDWARE_ERROR;
                                transitionToState(EmulatorState::ERROR);
                                return Result<void>::err(EmulatorError::HARDWARE_ERROR);
                            }
                            
                            // Success message
                            display_->setCursor(20, 180);
                            display_->setTextColor(0x07E0); // Green
                            display_->print("ROM loaded successfully!");
                            display_->setCursor(20, 200);
                            display_->print("Starting emulation...");
                            
                            delay(1000); // Brief pause to show success
                            
                            Serial.println("EmulatorContext: ROM loaded successfully, starting emulation");
                            
                            // Reset state and transition to running
                            menu_displayed = false;
                            transitionToState(EmulatorState::RUNNING_ROM);
                            
                        } else {
                            // Single tap - change selection
                            selected_index = actual_index;
                            selection_time = millis();
                            show_selection_hint = true;
                            
                            // Auto-scroll to keep selection visible
                            if (selected_index < scroll_offset) {
                                scroll_offset = selected_index;
                            } else if (selected_index >= scroll_offset + MAX_VISIBLE_ITEMS) {
                                scroll_offset = selected_index - MAX_VISIBLE_ITEMS + 1;
                            }
                            
                            Serial.printf("EmulatorContext: Selected ROM %d: %s\n", 
                                         selected_index, rom_files[selected_index].c_str());
                        }
                    }
                }
                
                // Enhanced scroll area handling
                if (rom_files.size() > MAX_VISIBLE_ITEMS) {
                    // Up arrow area (larger touch area)
                    if (point.x >= 270 && point.x <= 310 && 
                        point.y >= MENU_START_Y - 20 && point.y <= MENU_START_Y) {
                        if (scroll_offset > 0) {
                            scroll_offset--;
                            if (selected_index >= scroll_offset + MAX_VISIBLE_ITEMS) {
                                selected_index = scroll_offset + MAX_VISIBLE_ITEMS - 1;
                            }
                            Serial.printf("EmulatorContext: Scrolled up, offset: %d\n", scroll_offset);
                        }
                    }
                    
                    // Down arrow area (larger touch area)
                    if (point.x >= 270 && point.x <= 310 && 
                        point.y >= MENU_START_Y + MAX_VISIBLE_ITEMS * ITEM_HEIGHT && 
                        point.y <= MENU_START_Y + MAX_VISIBLE_ITEMS * ITEM_HEIGHT + 20) {
                        if (scroll_offset + MAX_VISIBLE_ITEMS < (int)rom_files.size()) {
                            scroll_offset++;
                            if (selected_index < scroll_offset) {
                                selected_index = scroll_offset;
                            }
                            Serial.printf("EmulatorContext: Scrolled down, offset: %d\n", scroll_offset);
                        }
                    }
                }
            }
            
            last_touch_time = millis();
        }
    }
    
    // Hide selection hint after timeout
    if (show_selection_hint && millis() - selection_time >= SELECTION_HINT_DURATION) {
        show_selection_hint = false;
        hint_was_showing = true; // Force instruction redraw
    }
    
    touch_was_pressed = current_touch && point.pressed;
    
    return Result<void>::ok();
}

Result<void> EmulatorContext::runEmulator() {
    static bool emulator_started = false;
    static bool test_pattern_created = false;
    static unsigned long last_menu_check = 0;
    static bool touch_was_pressed = false;
    static unsigned long touch_start_time = 0;
    
    const unsigned long LONG_TOUCH_DURATION = 2000;  // 2 seconds for menu
    const unsigned long MENU_CHECK_INTERVAL = 100;   // Check every 100ms
    
    // Existing static counters for emulation steps and display timing
    static uint32_t frame_counter = 0; // Note: This counts emulation steps, not full GB frames
    static unsigned long last_frame_display = 0;

    if (!emulator_started) {
        Serial.println("EmulatorContext: Game Boy emulator running state entered");
        emulator_started = true;
        
        // Clear screen to prepare for Game Boy output
        display_->fillScreen(0x0000);  // Black background
        
        // Show brief "ROM Loaded" message
        display_->setTextColor(0x07E0); // Green
        display_->setTextSize(2);
        display_->setCursor(70, 100);
        display_->print("ROM Loaded!");
        
        display_->setTextColor(0xFFFF); // White
        display_->setTextSize(1);
        display_->setCursor(40, 130);
        display_->print("Starting Game Boy emulation...");
        
        display_->setCursor(20, 150);
        display_->setTextColor(0x8410); // Gray
        display_->print("Game Controls:");
        display_->setCursor(20, 165);
        display_->print("- Hold screen for 2 seconds to return to menu");
        
        delay(1500); // Show message briefly
        
        // Clear screen for emulation
        display_->fillScreen(0x0000);
    }
    
    // --- BEGIN MODIFICATION ---
    // Introduce a time-sliced inner loop to run more emulation steps if needed.
    const unsigned long MAX_EMULATION_SLICE_MS = 8; // Max time (ms) to spend in this emulation slice
    unsigned long emulation_slice_start_time = millis();
    uint32_t cycles_in_last_step = 0; // To store cycles from the last cpu_cycle call in the slice

    while (millis() - emulation_slice_start_time < MAX_EMULATION_SLICE_MS) {
        if (framebuffer_manager_->is_ready()) {
            // A frame is ready (or became ready during previous steps).
            // Break from this sub-loop to allow the display logic below to run promptly.
            break;
        }

        uint32_t current_cycles = cpu_cycle();
        if (current_cycles > 0) {
            lcd_cycle(current_cycles);
            timer_cycle(current_cycles);
            
            frame_counter++; // Increment step counter
            cycles_in_last_step = current_cycles; // Store for potential logging
            
            // CRITICAL: Add periodic memory validation to catch corruption early
            if (frame_counter % 1000 == 0) {
                if (!validate_memory_segments()) {
                    Serial.printf("[CRITICAL] Memory segment corruption detected at frame %u!\n", frame_counter);
                    return Result<void>::err(EmulatorError::MEMORY_ERROR);
                }
            }
        } else {
            // cpu_cycle() returned 0 or negative. This might mean CPU is halted or an error.
            // Break to avoid busy loop.
            break; 
        }
        // Consider taskYIELD() or delay(0) if cpu_cycle is extremely fast and non-blocking,
        // though typically cpu_cycle itself has some workload.
    }
    
    // Debug output for overall emulation progress (modified from original)
    // Reports after a slice of emulation if frame_counter hits a multiple of 1000.
    // Ensure we only log if some activity happened in the slice to avoid spam if slice was too short or CPU halted.
    bool slice_had_activity = (millis() - emulation_slice_start_time > 0) || (cycles_in_last_step > 0 && frame_counter % 1000 == (cycles_in_last_step > 0 ? 1 : 0) );
    if (frame_counter % 1000 == 0 && slice_had_activity) {
         Serial.printf("EmulatorContext: Emulation progress - step %u, last_cycles: %u, slice_took_approx: %lu ms\n", 
                         frame_counter, cycles_in_last_step, millis() - emulation_slice_start_time);
    }
    // --- END MODIFICATION ---

    // Check if framebuffer is ready for display (every 16ms for ~60fps)
    unsigned long current_time = millis();
    if (current_time - last_frame_display >= 16) {
        if (framebuffer_manager_->is_ready()) {
            const uint16_t* fb = framebuffer_manager_->get_front_buffer();
            if (fb) {
                // Use efficient buffer rendering instead of pixel-by-pixel
                // Center the Game Boy screen on the TFT display (160x144 centered on 320x240)
                int offset_x = (display_->width() - FramebufferManager::FB_WIDTH) / 2;
                int offset_y = (display_->height() - FramebufferManager::FB_HEIGHT) / 2;
                
                // Draw the entire Game Boy framebuffer at once using drawBuffer
                display_->drawBuffer(fb, offset_x, offset_y, FramebufferManager::FB_WIDTH, FramebufferManager::FB_HEIGHT);
                
                framebuffer_manager_->mark_displayed();
                last_frame_display = current_time;
            }
        } else {
            // DEBUG: Check if we have a framebuffer but it's not ready
            const uint16_t* back_fb = framebuffer_manager_->get_back_buffer();
            // Modified debug log to include slice duration
            if (back_fb && frame_counter % 300 == 0) { // Check every 300 steps
                Serial.printf("EmulatorContext: Framebuffer exists but not ready for display (step %u, slice_ran_for_approx: %lu ms)\n", 
                                frame_counter, millis() - emulation_slice_start_time);
            }
        }
    }
    
    // Handle touch input for menu return (long press) and game controls
    if (millis() - last_menu_check > MENU_CHECK_INTERVAL) {
        bool current_touch = touch_->touched();
        TouchPoint point = touch_->getPoint();
        
        if (current_touch && point.pressed) {
            if (!touch_was_pressed) {
                // Touch started
                touch_start_time = millis();
                Serial.println("EmulatorContext: Touch started - hold for 2 seconds to return to menu");
                
                // Show touch indicator
                for (int i = 0; i < 5; i++) {
                    display_->drawPixel(point.x + i - 2, point.y, 0xF800);  // Red dot
                    display_->drawPixel(point.x, point.y + i - 2, 0xF800);
                }
            } else {
                // Touch continuing - check duration
                unsigned long touch_duration = millis() - touch_start_time;
                
                // Show progress indicator for long touch
                if (touch_duration > 500) {  // After 0.5 seconds, start showing progress
                    int progress = (touch_duration - 500) * 10 / LONG_TOUCH_DURATION;  // 0-10 scale
                    if (progress > 10) progress = 10;
                    
                    // Draw progress bar
                    int bar_x = 10;
                    int bar_y = 10;
                    int bar_width = 100;
                    int bar_height = 8;
                    
                    // Clear previous progress bar
                    for (int y = bar_y; y < bar_y + bar_height; y++) {
                        for (int x = bar_x; x < bar_x + bar_width; x++) {
                            display_->drawPixel(x, y, 0x0000);  // Black
                        }
                    }
                    
                    // Draw progress
                    for (int i = 0; i < progress; i++) {
                        for (int y = bar_y; y < bar_y + bar_height; y++) {
                            for (int x = bar_x + i * (bar_width / 10); x < bar_x + (i + 1) * (bar_width / 10); x++) {
                                display_->drawPixel(x, y, 0xFFE0);  // Yellow progress
                            }
                        }
                    }
                }
                
                if (touch_duration >= LONG_TOUCH_DURATION) {
                    Serial.println("EmulatorContext: Long touch detected, returning to menu");
                    
                    // Clean up ROM streamer
                    rom_streamer.cleanup();
                    
                    // Reset state
                    emulator_started = false;
                    transitionToState(EmulatorState::MENU);
                    return Result<void>::ok();
                }
            }
        } else {
            if (touch_was_pressed) {
                // Touch ended - clear progress bar
                for (int y = 10; y < 18; y++) {
                    for (int x = 10; x < 110; x++) {
                        display_->drawPixel(x, y, 0x0000);  // Black
                    }
                }
            }
        }
        
        touch_was_pressed = current_touch && point.pressed;
        last_menu_check = millis();
    }
    
    return Result<void>::ok();
}

Result<void> EmulatorContext::handleError() {
    static bool error_displayed = false;
    static unsigned long last_touch_time = 0;
    
    const unsigned long TOUCH_DEBOUNCE_MS = 500;  // Debounce touch input
    
    if (!error_displayed) {
        Serial.printf("EmulatorContext: Displaying error state (error: %s)\n", 
                     error_to_string(last_error_));
        
        // Display improved error screen
        display_->fillScreen(0x2000);  // Dark red background (less harsh)
        
        // Draw error header
        display_->setTextColor(0xFFFF);  // White text
        display_->setTextSize(3);
        int16_t title_width = 5 * 8 * 3;  // "ERROR" in size 3
        int16_t title_x = (display_->width() - title_width) / 2;
        display_->setCursor(title_x, 10);
        display_->print("ERROR");
        
        // Draw error icon (simple exclamation mark)
        display_->setTextSize(4);
        display_->setCursor(title_x + title_width + 20, 5);
        display_->setTextColor(0xFFE0);  // Yellow
        display_->print("!");
        
        // Display specific error message
        display_->setTextSize(1);
        display_->setTextColor(0xFFFF);  // White text
        display_->setCursor(10, 50);
        
        const char* error_title = "Unknown Error";
        const char* error_description = "An unexpected error occurred.";
        const char* error_suggestion = "Try touching the screen to retry.";
        
        switch (last_error_) {
            case EmulatorError::DISPLAY_INIT_FAILED:
                error_title = "Display Initialization Failed";
                error_description = "Could not initialize the TFT display.";
                error_suggestion = "Check display connections and power.";
                break;
            case EmulatorError::TOUCH_INIT_FAILED:
                error_title = "Touch Screen Failed";
                error_description = "Could not initialize touch controller.";
                error_suggestion = "Check touch controller connections.";
                break;
            case EmulatorError::SD_CARD_ERROR:
                error_title = "SD Card Error";
                error_description = "Could not access SD card or no ROMs found.";
                error_suggestion = "Insert SD card with .gb ROM files.";
                break;
            case EmulatorError::ROM_LOAD_FAILED:
                error_title = "ROM Load Failed";
                error_description = "Could not load the selected ROM file.";
                error_suggestion = "Check ROM file format and SD card.";
                break;
            case EmulatorError::HARDWARE_ERROR:
                error_title = "Hardware Error";
                error_description = "A hardware component failed to initialize.";
                error_suggestion = "Check all connections and power supply.";
                break;
            case EmulatorError::MEMORY_EXHAUSTED:
                error_title = "Memory Exhausted";
                error_description = "Not enough memory to run emulator.";
                error_suggestion = "This should not happen with ROM streaming.";
                break;
            case EmulatorError::INVALID_STATE:
                error_title = "Invalid State";
                error_description = "The emulator entered an invalid state.";
                error_suggestion = "This indicates a programming error.";
                break;
        }
        
        // Display error title
        display_->setTextColor(0xFFE0);  // Yellow
        display_->setTextSize(2);
        display_->setCursor(10, 50);
        display_->print(error_title);
        
        // Display error description
        display_->setTextColor(0xFFFF);  // White
        display_->setTextSize(1);
        display_->setCursor(10, 75);
        display_->print("Problem:");
        display_->setCursor(10, 90);
        display_->print(error_description);
        
        // Display suggestion
        display_->setCursor(10, 110);
        display_->setTextColor(0x07E0);  // Green
        display_->print("Solution:");
        display_->setCursor(10, 125);
        display_->setTextColor(0xFFFF);  // White
        display_->print(error_suggestion);
        
        // Display instructions
        display_->setCursor(10, 155);
        display_->setTextColor(0x8410);  // Gray
        display_->print("Actions:");
        display_->setCursor(10, 170);
        display_->setTextColor(0xFFFF);  // White
        display_->print("- Touch screen to retry initialization");
        display_->setCursor(10, 185);
        display_->print("- Power cycle device if problem persists");
        
        // Display technical info
        display_->setCursor(10, 210);
        display_->setTextColor(0x8410);  // Gray
        display_->print("Error Code: ");
        display_->print((int)last_error_);
        display_->print(" (");
        display_->print(error_to_string(last_error_));
        display_->print(")");
        
        display_->setCursor(10, 225);
        display_->print("Free Heap: ");
        display_->print((int)ESP.getFreeHeap());
        display_->print(" bytes");
        
        error_displayed = true;
        Serial.printf("EmulatorContext: Error screen displayed for %s\n", error_to_string(last_error_));
    }
    
    // Handle touch to retry initialization
    if (touch_->touched()) {
        TouchPoint point = touch_->getPoint();
        if (point.pressed && millis() - last_touch_time > TOUCH_DEBOUNCE_MS) {
            Serial.println("EmulatorContext: Touch detected, attempting recovery");
            
            // Show recovery message
            display_->fillScreen(0x0000);  // Black background
            display_->setTextColor(0xFFE0);  // Yellow
            display_->setTextSize(2);
            display_->setCursor(50, 100);
            display_->print("Recovering...");
            
            display_->setTextSize(1);
            display_->setTextColor(0xFFFF);  // White
            display_->setCursor(30, 130);
            display_->print("Attempting to reinitialize hardware");
            
            delay(1000);  // Show recovery message
            
            error_displayed = false;  // Reset for next time
            initialized_ = false;     // Force re-initialization
            
            // Attempt to re-initialize
            Serial.println("EmulatorContext: Attempting hardware re-initialization");
            Result<void> init_result = initialize();
            if (init_result.is_err()) {
                Serial.printf("EmulatorContext: Re-initialization failed with error: %s\n", 
                             error_to_string(init_result.error()));
                // Stay in error state but update the error
                last_error_ = init_result.error();
                return init_result;
            }
            
            Serial.println("EmulatorContext: Hardware re-initialization successful!");
            
            // Show success message briefly
            display_->fillScreen(0x0000);  // Black background
            display_->setTextColor(0x07E0);  // Green
            display_->setTextSize(2);
            display_->setCursor(70, 100);
            display_->print("Recovered!");
            
            display_->setTextSize(1);
            display_->setTextColor(0xFFFF);  // White
            display_->setCursor(60, 130);
            display_->print("Hardware reinitialized");
            
            delay(1500);  // Show success message
            
            last_touch_time = millis();
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
