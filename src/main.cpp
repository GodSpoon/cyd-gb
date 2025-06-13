#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <SD.h> // Add SD card support
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

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
#include "error_handler.h"
#include "rom_streamer.h"

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
void print_memory_status();

// Task handles for core affinity optimization
TaskHandle_t emulationTaskHandle = NULL;
TaskHandle_t renderingTaskHandle = NULL;

// Queue for frame completion signaling
QueueHandle_t frameCompleteQueue = NULL;

// Core 1: Dedicated emulation task (CPU, memory, timers)
void emulation_task(void* pvParameters) {
    Serial.println("Emulation task started on Core 1");
    
    // Wait for emulator to be fully initialized before starting emulation
    while (!emulator_initialized) {
        Serial.println("Emulation task waiting for initialization...");
        vTaskDelay(pdMS_TO_TICKS(100)); // Wait 100ms
    }
    
    Serial.println("Emulation task: Initialization confirmed, starting emulation loop");
    
    // Additional safety: Verify critical components are ready
    if (!rom_streamer.is_valid()) {
        Serial.println("ERROR: ROM streamer not valid in emulation task!");
        vTaskSuspend(NULL); // Suspend this task
        return;
    }
    
    // Wait a bit more to ensure everything is stable
    vTaskDelay(pdMS_TO_TICKS(500));
    
    Serial.println("Emulation task: Starting Game Boy emulation loop");
    
    while (1) {
        if (current_state == APP_STATE_EMULATOR && emulator_initialized) {
            // Core emulation logic - CPU, memory, timers
            jolteon_update();
            uint32_t cycles = cpu_cycle();
            lcd_cycle(cycles);
            timer_cycle(cycles);
            
            static int frame_counter = 0;
            if (++frame_counter % 60 == 0) {
                Serial.printf("Game Boy Core 1: Frame %d, Cycles: %u\n", frame_counter, cycles);
            }
            
            // Signal frame completion to rendering task
            uint32_t frame_signal = frame_counter;
            xQueueSend(frameCompleteQueue, &frame_signal, 0); // Non-blocking
        }
        vTaskDelay(1); // Minimal delay to allow task switching
    }
}

// Core 0: Rendering and system tasks (display, input, WiFi, SD)
void rendering_task(void* pvParameters) {
    Serial.println("Rendering task started on Core 0");
    uint32_t last_frame = 0;
    
    while (1) {
        if (current_state == APP_STATE_EMULATOR) {
            uint32_t frame_signal;
            
            // Check for frame completion signals from emulation core
            if (xQueueReceive(frameCompleteQueue, &frame_signal, pdMS_TO_TICKS(16)) == pdTRUE) {
                // Frame completed, handle any display updates if needed
                if (frame_signal != last_frame) {
                    last_frame = frame_signal;
                    
                    // Optional: Handle any rendering-specific tasks here
                    // The actual LCD rendering is handled in lcd.cpp via DMA
                    
                    static unsigned long last_debug = 0;
                    auto const now = millis();
                    if (now - last_debug > 10000) {
                        Serial.printf("Rendering Core 0: Free heap: %d bytes, Min free: %d bytes\n", 
                                     ESP.getFreeHeap(), ESP.getMinFreeHeap());
                        last_debug = now;
                    }
                }
            }
        }
        vTaskDelay(5); // Longer delay for rendering task
    }
}

void setup() {
    String first_rom_path = "";
    Serial.begin(115200);
    Serial.println("ESP32 CYD Game Boy Emulator Starting...");
    
    // CRITICAL: Early memory optimization before any allocations
    Serial.println("Performing early memory optimization...");
    heap_caps_check_integrity_all(true);
    
    // Call Jolteon early memory optimization
    jolteon_optimize_memory_early();
    
    // Show initial memory state
    Serial.printf("Initial free heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("Largest free block: %d bytes\n", ESP.getMaxAllocHeap());
    
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
        
        // CRITICAL FIX: Initialize emulator BEFORE creating any tasks
        // This ensures all memory allocations happen on Core 0 before Core 1 tasks start
        Serial.println("Initializing emulator before task creation...");
        
        // Additional safety: Ensure all SD card operations are complete
        delay(100);
        
        initialize_emulator();
        
        // Additional safety: Ensure emulator initialization is completely finished
        delay(200);
        
        // Only set state and create tasks AFTER successful initialization
        current_state = APP_STATE_EMULATOR; // Set state AFTER initialization completes
        Serial.printf("Auto-started first ROM: %s\n", first_rom_path.c_str());
        
        Serial.println("Setup complete! Creating tasks...");
        delay(500); // Longer delay to ensure everything is fully ready and stable
        
        // Additional safety: Ensure all initializations are complete
        Serial.println("Verifying emulator initialization state...");
        if (!emulator_initialized) {
            Serial.println("ERROR: Emulator not properly initialized!");
            while(1) delay(1000);
        }
        
        // Final memory check before task creation
        Serial.printf("Free heap before task creation: %d bytes\n", ESP.getFreeHeap());
        Serial.printf("Largest free block: %d bytes\n", ESP.getMaxAllocHeap());

        // Create frame completion queue for inter-task communication
        frameCompleteQueue = xQueueCreate(2, sizeof(uint32_t));
        if (!frameCompleteQueue) {
            Serial.println("Failed to create frame completion queue!");
            while (1) delay(1000);
        }

        // Core affinity optimization - ONLY after successful initialization
        Serial.println("Creating tasks with core affinity optimization...");
        
        // CRITICAL: Create tasks on the same core first to avoid race conditions
        // Core 0: Dedicated to rendering and system tasks
        BaseType_t result2 = xTaskCreatePinnedToCore(
            rendering_task,       // Task function
            "GB_Rendering",       // Name
            4096,                 // Stack size (4KB for rendering)
            NULL,                 // Parameters
            4,                    // Lower priority for rendering
            &renderingTaskHandle, // Task handle
            0                     // Core 0
        );
        
        if (result2 != pdPASS) {
            Serial.println("Failed to create rendering task!");
            while (1) delay(1000);
        }
        
        // Small delay to let first task start completely
        delay(500);
        
        Serial.println("Creating emulation task on Core 1...");
        
        // Core 1: Dedicated to emulation (CPU, memory, timers)
        BaseType_t result1 = xTaskCreatePinnedToCore(
            emulation_task,        // Task function
            "GB_Emulation",       // Name
            8192,                 // Stack size (8KB for emulation)
            NULL,                 // Parameters
            6,                    // High priority for emulation
            &emulationTaskHandle, // Task handle
            1                     // Core 1
        );
        
        if (result1 != pdPASS) {
            Serial.println("Failed to create emulation task!");
            while (1) delay(1000);
        }
        
        // Final verification
        if (result1 == pdPASS && result2 == pdPASS) {
            Serial.println("Core affinity optimization complete:");
            Serial.println("  Core 0: Rendering and system tasks");
            Serial.println("  Core 1: Game Boy emulation (CPU, memory, timers)");
        } else {
            Serial.println("Failed to create tasks with core affinity!");
            while (1) delay(1000);
        }
        
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
}

void initialize_emulator() {
    if (emulator_initialized) {
        return;
    }
    Serial.println("Initializing Game Boy emulator...");

    // Initialize error handler first
    ErrorHandler::init(&tft);

    // Load ROM from SD card using menu selection
    const char* rom_path = menu_get_rompath();
    if (!rom_path) {
        ErrorHandler::handle_error(EmulatorError::ROM_LOAD_FAILED, "No ROM selected");
        return;
    }
    
    Serial.printf("Loading ROM from SD: %s\n", rom_path);
    const uint8_t* rom = jolteon_load_rom(rom_path);
    if (!rom) {
        ErrorHandler::handle_error(EmulatorError::ROM_LOAD_FAILED, "ROM streaming failed");
        return;
    }
    
    // Verify ROM streaming is actually working
    if (!rom_streamer.is_valid()) {
        ErrorHandler::handle_error(EmulatorError::ROM_LOAD_FAILED, "ROM streamer not initialized");
        return;
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
    // For ROM streaming, pass nullptr to rom_init since actual ROM data is accessed via rom_streamer
    if (!rom_init(nullptr)) {
        Serial.println("rom_init failed - emulator cannot start");
        while(1) delay(1000);
    }
    // Initialize MMU with segmented memory approach
    Serial.println("Pre-allocating MMU memory...");
    
    // CRITICAL FIX: Don't disable interrupts during MMU init to prevent watchdog timeout
    // Memory allocation takes time and needs watchdog feeding
    bool mmu_success = mmu_init(bootrom);
    
    if (!mmu_success) {
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
    
    // Additional verification that critical components are ready
    if (!rom_streamer.is_valid()) {
        Serial.println("ERROR: ROM streamer invalid after initialization!");
        emulator_initialized = false;
        return;
    }
    
    // Print memory status to verify reasonable usage
    print_memory_status();
    
    // Print ROM streaming statistics
    rom_streamer.print_cache_stats();
    
    Serial.println("Game Boy emulator initialized successfully!");
    Serial.println("All components verified and ready for emulation tasks");
}

void loop() {
    // Empty: emulation runs in FreeRTOS task
    vTaskDelay(1000);
}

// Memory diagnostic function
void print_memory_status() {
    Serial.printf("=== Memory Status ===\n");
    Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("Min free heap: %d bytes\n", ESP.getMinFreeHeap());
    Serial.printf("Max alloc: %d bytes\n", ESP.getMaxAllocHeap());
    Serial.printf("PSRAM free: 0 bytes (PSRAM disabled for CYD boards)\n");
    
    // Show memory savings from ROM streaming
    if (rom_streamer.is_valid()) {
        size_t rom_size = rom_streamer.get_size();
        size_t cache_size = 4 * 16384; // 4 banks * 16KB each
        Serial.printf("ROM size: %d bytes\n", rom_size);
        Serial.printf("Cache size: %d bytes\n", cache_size);
        Serial.printf("Memory saved: %d bytes (%.1f%%)\n", 
                      rom_size - cache_size,
                      ((float)(rom_size - cache_size) / rom_size) * 100.0f);
    }
    Serial.printf("====================\n");
}
