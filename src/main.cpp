#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <SD.h> // Add SD card support

// Game Boy emulator headers
#include "timer.h"
#include "rom.h"
#include "mem.h"
#include "cpu.h"
#include "lcd.h"
#include "jolteon.h"
#include "menu.h"
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

// Emulation task handle
TaskHandle_t emulationTaskHandle = NULL;

// Emulation task function
void emulation_task(void* pvParameters) {
    while (1) {
        if (current_state == APP_STATE_EMULATOR) {
            jolteon_update();
            uint32_t cycles = cpu_cycle();
            lcd_cycle(cycles);
            timer_cycle(cycles);
            static int frame_counter = 0;
            if (++frame_counter % 60 == 0) {
                Serial.printf("Game Boy running: Frame %d, Cycles: %u\n", frame_counter, cycles);
            }
            static unsigned long last_debug = 0;
            auto const now = millis();
            if (now - last_debug > 10000) {
                Serial.printf("Free heap: %d bytes, Min free: %d bytes\n", 
                             ESP.getFreeHeap(), ESP.getMinFreeHeap());
                last_debug = now;
            }
        }
        vTaskDelay(1); // Yield to other tasks
    }
}

void setup() {
    String first_rom_path = "";
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

    // Initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin()) {
        Serial.println("[FATAL] SD card initialization failed. Please check SD card.");
        tft.fillScreen(TFT_RED);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.setTextSize(2);
        tft.setCursor(20, 100);
        tft.print("ERROR: SD card");
        tft.setCursor(20, 130);
        tft.print("Insert or reformat SD");
        while (1) delay(1000);
    }
    Serial.println("SD card initialized.");
    // Diagnostics: Card type
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
        Serial.println("[SD DEBUG] No SD card attached or detected!");
    } else {
        Serial.print("[SD DEBUG] Card type: ");
        if (cardType == CARD_MMC) Serial.println("MMC");
        else if (cardType == CARD_SD) Serial.println("SDSC");
        else if (cardType == CARD_SDHC) Serial.println("SDHC/SDXC");
        else Serial.println("Unknown");
        uint64_t cardSize = SD.cardSize() / (1024 * 1024);
        Serial.printf("[SD DEBUG] Card size: %llu MB\n", cardSize);
        // List files in root
        Serial.println("[SD DEBUG] Listing files in root directory:");
        File root = SD.open("/");
        if (!root) {
            Serial.println("[SD DEBUG] Failed to open root directory!");
        } else {
            File file = root.openNextFile();
            if (!file) Serial.println("[SD DEBUG] (No files found)");
            while (file) {
                Serial.printf("[SD DEBUG]   %s  %s  %llu bytes\n", file.name(), file.isDirectory() ? "<DIR>" : "     ", file.size());
                String fname = file.name();
                if (!file.isDirectory() && fname.endsWith(".gb") && first_rom_path.length() == 0) {
                    first_rom_path = "/" + fname;
                }
                file = root.openNextFile();
            }
            root.close();
        }
    }
    // Initialize Jolteon system for splash screen
    Serial.println("Initializing Jolteon for splash screen...");
    jolteon_display_splash_screen();
    delay(1500); // Ensure splash screen is visible

    // Auto-select first ROM if found, else show error
    if (first_rom_path.length() > 0) {
        extern void menu_set_rompath(const char* path); // Add this function to menu.cpp
        menu_set_rompath(first_rom_path.c_str());
        current_state = APP_STATE_EMULATOR;
        initialize_emulator();
        Serial.printf("Auto-started first ROM: %s\n", first_rom_path.c_str());
    } else {
        tft.fillScreen(TFT_RED);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.setTextSize(2);
        tft.setCursor(20, 100);
        tft.print("ERROR: No ROMs found");
        tft.setCursor(20, 130);
        tft.print("Add .gb files to SD card");
        Serial.println("[FATAL] No .gb ROMs found on SD card.");
        while (1) delay(1000);
    }
    Serial.println("Setup complete! Entering emulation...");
    delay(100); // Small delay to ensure everything is ready

    // Start emulation task on core 1
    xTaskCreatePinnedToCore(
        emulation_task,        // Task function
        "EmulationTask",      // Name
        8192,                 // Stack size
        NULL,                 // Parameters
        5,                    // Priority
        &emulationTaskHandle, // Task handle
        1                     // Core 1
    );
}

void initialize_emulator() {
    if (emulator_initialized) {
        return;
    }
    Serial.println("Initializing Game Boy emulator...");

    // Load ROM from SD card using menu selection
    const char* rom_path = menu_get_rompath();
    if (!rom_path) {
        Serial.println("[FATAL] No ROM selected or found on SD card.");
        tft.fillScreen(TFT_RED);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.setTextSize(2);
        tft.setCursor(20, 100);
        tft.print("ERROR: No ROM found");
        tft.setCursor(20, 130);
        tft.print("Add .gb files to SD card");
        while (1) delay(1000);
    }
    Serial.printf("Loading ROM from SD: %s\n", rom_path);
    const uint8_t* rom = jolteon_load_rom(rom_path);
    if (!rom) {
        Serial.println("[FATAL] Failed to load ROM from SD card.");
        tft.fillScreen(TFT_RED);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.setTextSize(2);
        tft.setCursor(20, 100);
        tft.print("ERROR: ROM load failed");
        tft.setCursor(20, 130);
        tft.print("Check SD or ROM file");
        while (1) delay(1000);
    }
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
    // Empty: emulation runs in FreeRTOS task
    vTaskDelay(1000);
}
