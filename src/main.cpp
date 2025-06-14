#include <SPI.h>
#include <Arduino.h>
#include <memory>

// EmulatorContext and hardware abstraction
#include "core/emulator_context.h"
#include "core/memory_utils.h"
#include "hardware/tft_display.h"
#include "hardware/xpt2046_touch.h"
#include "hardware/sd_storage.h"

// Legacy includes (to be removed gradually)
#include "timer.h"
#include "rom.h"
#include "mem.h"
#include "cpu.h"
#include "lcd.h"
#include "jolteon.h"
#include "core/framebuffer_manager.h"
#include "mbc.h"
#include "error_handler.h"
#include "rom_streamer.h"

// Forward declarations for dependency injection
extern "C" {
    void lcd_set_framebuffer_manager(FramebufferManager* fbmgr);
}
void cpu_set_framebuffer_manager(FramebufferManager* fbmgr);
void mbc_set_framebuffer_manager(FramebufferManager* fbmgr);

// Touch pin definitions (TFT pins are configured via build flags)
#define TOUCH_CS  33
#define TOUCH_IRQ 36

// EmulatorContext - main application instance
std::unique_ptr<EmulatorContext> emulator_context;

// Legacy variables (to be removed as refactoring continues)
static bool emulator_initialized = false;

// Legacy FreeRTOS task functions (deprecated - EmulatorContext handles state machine now)
// These functions are kept for reference but will be removed in future refactoring

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 CYD Game Boy Emulator Starting...");
    Serial.println("Using EmulatorContext with Dependency Injection");
    
    // Early memory optimization
    Serial.println("Performing early memory optimization...");
    heap_caps_check_integrity_all(true);
    jolteon_optimize_memory_early();
    
    // Show initial memory state
    Serial.printf("Initial free heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("Largest free block: %d bytes\n", ESP.getMaxAllocHeap());
    
    // Create hardware instances with dependency injection
    Serial.println("Creating hardware abstraction instances...");
    
    // Create display with backlight pin 21 (ESP32 CYD standard)
    auto display = make_unique<TFTDisplay>(21);
    
    // Create touch controller with standard CYD pins
    auto touch = make_unique<XPT2046Touch>(TOUCH_CS, TOUCH_IRQ);
    
    // Pre-configure touch for CYD display
    Serial.println("Pre-configuring touch controller...");
    touch->setScreenSize(320, 240);
    touch->setCalibration(200, 3900, 200, 3900);
    touch->setDebouncing(true, 150);  // Reduced debounce for better responsiveness
    touch->setRotation(1);  // Landscape rotation
    
    // Create SD storage
    auto storage = make_unique<SDStorage>();
    
    // Create EmulatorContext with injected dependencies
    Serial.println("Creating EmulatorContext...");
    emulator_context = make_unique<EmulatorContext>(
        std::move(display),
        std::move(touch), 
        std::move(storage)
    );
    
    // Initialize all hardware through EmulatorContext
    Serial.println("Initializing hardware through EmulatorContext...");
    Result<void> init_result = emulator_context->initialize();
    
    if (init_result.is_err()) {
        Serial.printf("EmulatorContext initialization failed with error: %s\n", 
                     error_to_string(init_result.error()));
        Serial.println("System will continue in error state - check EmulatorContext for recovery options");
        // Note: Don't halt here - let EmulatorContext handle error state
    } else {
        Serial.println("EmulatorContext initialized successfully!");
        Serial.printf("Current state: %d\n", (int)emulator_context->getCurrentState());
    }
    
    Serial.println("Setup complete - entering main loop");
}

void loop() {
    // Check if emulator context exists
    if (!emulator_context) {
        Serial.println("ERROR: EmulatorContext not initialized");
        delay(1000);
        return;
    }
    
    // Run the EmulatorContext state machine
    Result<void> result = emulator_context->run();
    
    // Handle any errors from the state machine
    if (result.is_err()) {
        Serial.printf("EmulatorContext run error: %s\n", error_to_string(result.error()));
        // EmulatorContext will handle error recovery internally
    }
    
    // 60 FPS timing (16.67ms per frame)
    delay(16);
}

// Legacy functions (to be removed as refactoring continues)
void initialize_emulator() {
    // This function is deprecated - EmulatorContext handles initialization now
    Serial.println("WARNING: initialize_emulator() called - this is deprecated");
    Serial.println("Hardware initialization is now handled by EmulatorContext::initialize()");
}

void print_memory_status() {
    Serial.printf("=== Memory Status ===\n");
    Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("Min free heap: %d bytes\n", ESP.getMinFreeHeap());
    Serial.printf("Max alloc: %d bytes\n", ESP.getMaxAllocHeap());
    Serial.printf("PSRAM free: 0 bytes (PSRAM disabled for CYD boards)\n");
    Serial.printf("====================\n");
}
