#include <Arduino.h>
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
#include "pokemon_red_rom.h"

// Touch pin definitions (TFT pins are configured via build flags)
#define TOUCH_CS  33
#define TOUCH_IRQ 36

// Display and touch objects
TFT_eSPI tft = TFT_eSPI();
XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

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
    touch.begin();
    Serial.println("Touch initialized.");
    
    Serial.println("Initializing Game Boy emulator...");
    
    // Direct ROM loading from PROGMEM (no SD card, no menu system)
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
    
    Serial.println("Game Boy emulator setup complete! Starting main loop...");
}

void loop() {
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
    delay(1);
}
