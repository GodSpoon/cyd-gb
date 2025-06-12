#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

// Game Boy emulator headers
#include "timer.h"
#include "rom.h"
#include "mem.h"
#include "cpu.h"
#include "lcd.h"
#include "jolteon.h"
#include "menu.h"
#include "pokemon_red_rom.h"

// Touch pin definitions (TFT pins are configured via build flags)
#define TOUCH_CS  33
#define TOUCH_IRQ 36
#define TOUCH_MOSI 32
#define TOUCH_MISO 39
#define TOUCH_SCK  25

// Display and touch objects
TFT_eSPI tft = TFT_eSPI();
SPIClass touchSPI = SPIClass(HSPI);
XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

// Application state
typedef enum {
    APP_STATE_SPLASH,
    APP_STATE_MENU,
    APP_STATE_EMULATOR
} app_state_t;

static app_state_t current_state = APP_STATE_SPLASH;
static bool emulator_initialized = false;

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 CYD Game Boy Emulator Starting...");
    
    // Initialize TFT display
    Serial.println("Initializing TFT_eSPI display...");
    tft.init();
    tft.setRotation(1); // Landscape mode
    tft.fillScreen(TFT_BLACK);
    Serial.println("Display initialized.");
    
    // Initialize backlight (pin 21)
    pinMode(21, OUTPUT);
    // ESP32 does not support analogWrite; use ledc functions instead
    ledcAttachPin(21, 1); // Channel 1
    ledcSetup(1, 5000, 8); // 5 kHz PWM, 8-bit resolution
    ledcWrite(1, 204); // ~80% brightness (0-255 range)
    Serial.println("Backlight set to 80%");
    
    // Initialize touch
    Serial.println("Initializing XPT2046 touch...");
    
    // Initialize separate SPI for touch
    touchSPI.begin(TOUCH_SCK, TOUCH_MISO, TOUCH_MOSI, TOUCH_CS);
    touch.begin(touchSPI);
    touch.setRotation(1); // Match display rotation
    Serial.println("Touch initialized with separate SPI.");
    
    // Test touch immediately
    Serial.println("Testing touch detection...");
    for (int i = 0; i < 10; i++) {
        if (touch.touched()) {
            TS_Point p = touch.getPoint();
            Serial.printf("Touch test %d: x=%d, y=%d\n", i, p.x, p.y);
        } else {
            Serial.printf("Touch test %d: No touch detected\n", i);
        }
        delay(200);
    }
    Serial.println("Touch test complete.");
    
    // Initialize basic Jolteon system for splash screen
    Serial.println("Initializing Jolteon for splash screen...");
    
    // Show splash screen
    jolteon_display_splash_screen();
    
    // Initialize menu system
    Serial.println("Initializing menu system...");
    menu_init();
    
    // Skip touch calibration test for now - using direct polling
    // touch_calibration_test();
    
    // Move to menu state
    current_state = APP_STATE_MENU;
    
    Serial.println("Setup complete! Showing main menu...");
    
    // Force an immediate menu draw
    delay(100); // Small delay to ensure everything is ready
}

void initialize_emulator() {
    if (emulator_initialized) {
        return; // Already initialized
    }
    
    Serial.println("Initializing Game Boy emulator...");
    
    // Direct ROM loading from PROGMEM (no SD card)
    const uint8_t* rom = src_roms_Pokemon___Red_Version_gb;
    Serial.println("Loading Pokemon Red ROM...");
    
    // Skip boot ROM to save memory
    const uint8_t* bootrom = nullptr;
    Serial.println("Boot ROM skipped (using built-in bypass)");
    
    // Initialize ROM early to avoid fragmentation
    if (!rom_init(rom)) {
        Serial.println("rom_init failed - emulator cannot start");
        while(1) delay(1000);
    }
    
    // Initialize MMU with segmented memory approach
    Serial.println("Pre-allocating MMU memory...");
    if (!mmu_init(bootrom)) {
        Serial.println("mmu_init failed - emulator cannot start");
        while(1) delay(1000);
    }
    
    // Initialize Jolteon system (allocates framebuffer) - after MMU but before LCD
    jolteon_init();
    
    // Initialize LCD AFTER Jolteon and MMU (needs both framebuffer and memory access)
    if (!lcd_init()) {
        Serial.println("lcd_init failed - emulator cannot start");
        while(1) delay(1000);
    }
    
    cpu_init();
    
    emulator_initialized = true;
    Serial.println("Game Boy emulator initialized successfully!");
}

void loop() {
    switch (current_state) {
        case APP_STATE_SPLASH:
            // This state is handled in setup(), should not reach here
            current_state = APP_STATE_MENU;
            break;
            
        case APP_STATE_MENU:
            {
                // Add periodic debug information
                static unsigned long last_menu_debug = 0;
                unsigned long now = millis();
                if (now - last_menu_debug > 3000) {
                    Serial.println("APP_STATE_MENU: Running menu loop...");
                    last_menu_debug = now;
                }
                
                menu_result_t result = menu_loop();
                if (result == MENU_RESULT_START_GAME) {
                    Serial.println("Starting Game Boy emulator...");
                    initialize_emulator();
                    current_state = APP_STATE_EMULATOR;
                }
                // Stay in menu for other results
            }
            break;
            
        case APP_STATE_EMULATOR:
            // Update input state first
            jolteon_update();
            
            // Run Game Boy emulator cycle
            uint32_t cycles = cpu_cycle();
            lcd_cycle(cycles);
            timer_cycle(cycles);
            
            // Force display update every few frames since the LCD task might not be calling jolteon_end_frame()
            static int display_update_counter = 0;
            if (++display_update_counter >= 3) { // Update display every 3 frames (~20 FPS display updates)
                jolteon_end_frame(); // Force framebuffer to display transfer
                display_update_counter = 0;
            }
            
            // Add frame counter for debugging
            static int frame_counter = 0;
            if (++frame_counter % 60 == 0) {
                Serial.printf("Game Boy running: Frame %d, Cycles: %u\n", frame_counter, cycles);
            }
            
            // Print debug info every 10 seconds
            static unsigned long last_debug = 0;
            auto const now = millis();
            if (now - last_debug > 10000) {
                Serial.printf("Free heap: %d bytes, Min free: %d bytes\n", 
                             ESP.getFreeHeap(), ESP.getMinFreeHeap());
                last_debug = now;
            }
            break;
    }
    
    delay(1);
}
