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
#include "core/framebuffer_manager.h"
#include "mbc.h"

// Touch pin definitions (TFT pins are configured via build flags)
#define TOUCH_CS  33
#define TOUCH_IRQ 36

// NOTE: Only one instance of TFT_eSPI and XPT2046_Touchscreen should exist.
// tft.init() and touch.begin() must only be called ONCE in the entire codebase.
TFT_eSPI tft = TFT_eSPI();
XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

// Application state
typedef enum {
    APP_STATE_SPLASH,
    APP_STATE_MENU,
    APP_STATE_EMULATOR
} app_state_t;

static app_state_t current_state = APP_STATE_SPLASH;
static bool emulator_initialized = false;
FramebufferManager framebuffer_manager;

// Forward declaration to resolve order-of-definition error
void initialize_emulator();

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
    // Correct order: ledcSetup -> ledcAttachPin -> ledcWrite
    ledcSetup(1, 5000, 8); // 5 kHz PWM, 8-bit resolution
    ledcAttachPin(21, 1); // Channel 1
    ledcWrite(1, 204); // ~80% brightness (0-255 range)
    Serial.println("Backlight set to 80%");
    
    // Initialize touch
    Serial.println("Initializing XPT2046 touch...");
    touch.begin();
    Serial.println("Touch initialized.");
    
    // Initialize Jolteon system for splash screen
    Serial.println("Initializing Jolteon for splash screen...");
    jolteon_display_splash_screen();
    delay(1500); // Ensure splash screen is visible
    
    // Go directly to emulator
    current_state = APP_STATE_EMULATOR;
    initialize_emulator();
    Serial.println("Setup complete! Entering emulation...");
    delay(100); // Small delay to ensure everything is ready
}

void initialize_emulator() {
    if (emulator_initialized) {
        return;
    }
    Serial.println("Initializing Game Boy emulator...");
    
    // Direct ROM loading from PROGMEM (no SD card)
    const uint8_t* rom = src_roms_Pokemon___Red_Version_gb;
    Serial.println("Loading Pokemon Red ROM...");
    
    // Skip boot ROM to save memory
    const uint8_t* bootrom = nullptr;
    Serial.println("Boot ROM skipped (using built-in bypass)");
    
    // Initialize framebuffer manager BEFORE MMU and ROM allocations
    bool fb_ok = framebuffer_manager.init();
    if (!fb_ok) {
        Serial.println("[FATAL] Could not allocate framebuffer. Halting emulation.");
        tft.fillScreen(TFT_RED);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.setTextSize(2);
        tft.setCursor(20, 100);
        tft.print("ERROR: Out of memory\nFramebuffer");
        tft.setCursor(20, 130);
        tft.print("Try rebooting or closing apps");
        while (1) delay(1000);
    }
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
            current_state = APP_STATE_EMULATOR;
            break;
        case APP_STATE_MENU:
            // Menu state removed: go directly to emulator
            current_state = APP_STATE_EMULATOR;
            break;
        case APP_STATE_EMULATOR:
            // Update input state first
            jolteon_update();
            // Run Game Boy emulator cycle
            uint32_t cycles = cpu_cycle();
            lcd_cycle(cycles);
            timer_cycle(cycles);
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
