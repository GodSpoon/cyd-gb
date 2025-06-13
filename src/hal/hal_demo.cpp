#include "hal/hal_demo.h"
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

// External hardware references that would normally be in main.cpp
extern TFT_eSPI tft;
extern XPT2046_Touchscreen touch;

void run_hal_demo() {
    Serial.println("\n=== Hardware Abstraction Layer (HAL) Demo ===");
    
    // Initialize all HAL components using the factory
    if (!HALFactory::initializeAll(tft, touch)) {
        Serial.println("HAL Demo: Failed to initialize HAL components");
        return;
    }
    
    // Get HAL interface pointers
    IDisplay* display = HALFactory::getDisplay();
    ITouch* touch_input = HALFactory::getTouch();
    IStorage* storage = HALFactory::getStorage();
    
    if (!display || !touch_input || !storage) {
        Serial.println("HAL Demo: Missing HAL components");
        return;
    }
    
    Serial.println("HAL Demo: All components initialized successfully");
    
    // Demonstrate display operations through HAL
    Serial.println("HAL Demo: Testing display operations...");
    display->fillScreen(0x001F); // Blue
    delay(1000);
    
    display->fillScreen(0x0000); // Black
    display->setTextColor(0xFFFF); // White
    display->setTextSize(2);
    display->setCursor(50, 50);
    display->print("HAL Demo");
    display->setCursor(30, 80);
    display->print("Display OK");
    
    // Show display dimensions
    display->setCursor(20, 120);
    display->setTextSize(1);
    display->print("Size: ");
    display->print((int)display->width());
    display->print("x");
    display->print((int)display->height());
    
    delay(2000);
    
    // Demonstrate touch operations through HAL
    Serial.println("HAL Demo: Testing touch operations...");
    display->fillScreen(0x0000);
    display->setTextColor(0x07E0); // Green
    display->setTextSize(2);
    display->setCursor(40, 80);
    display->print("Touch Test");
    display->setTextSize(1);
    display->setCursor(20, 120);
    display->print("Touch screen to continue...");
    
    // Wait for touch with timeout
    unsigned long start_time = millis();
    bool touch_detected = false;
    
    while (millis() - start_time < 10000 && !touch_detected) { // 10 second timeout
        if (touch_input->touched()) {
            TouchPoint point = touch_input->getPoint();
            if (point.pressed) {
                Serial.printf("HAL Demo: Touch detected at (%d, %d)\n", point.x, point.y);
                
                // Visual feedback
                display->drawPixel(point.x, point.y, 0xF800); // Red dot
                display->setCursor(20, 150);
                display->setTextColor(0xFFFF);
                display->print("Touch: ");
                display->print((int)point.x);
                display->print(",");
                display->print((int)point.y);
                
                touch_detected = true;
            }
        }
        delay(50);
    }
    
    if (!touch_detected) {
        Serial.println("HAL Demo: No touch detected within timeout");
        display->setCursor(20, 150);
        display->setTextColor(0xF800); // Red
        display->print("No touch detected");
    }
    
    delay(2000);
    
    // Demonstrate storage operations through HAL
    Serial.println("HAL Demo: Testing storage operations...");
    display->fillScreen(0x0000);
    display->setTextColor(0xFFE0); // Yellow
    display->setTextSize(2);
    display->setCursor(30, 50);
    display->print("Storage Test");
    
    // List files
    std::vector<std::string> files;
    StorageError result = storage->listFiles("/", ".gb", files);
    
    display->setTextSize(1);
    display->setCursor(20, 80);
    
    if (result == StorageError::SUCCESS) {
        Serial.printf("HAL Demo: Found %d .gb files\n", files.size());
        display->print("Found ");
        display->print((int)files.size());
        display->print(" ROM files");
        
        // Show first few files
        for (size_t i = 0; i < std::min(files.size(), (size_t)3); ++i) {
            display->setCursor(20, 100 + i * 15);
            display->print(files[i].c_str());
            Serial.printf("HAL Demo: ROM file: %s\n", files[i].c_str());
        }
    } else {
        Serial.println("HAL Demo: Failed to list files");
        display->setTextColor(0xF800); // Red
        display->print("Storage error");
    }
    
    delay(3000);
    
    // Test complete
    display->fillScreen(0x0000);
    display->setTextColor(0x07E0); // Green
    display->setTextSize(2);
    display->setCursor(60, 100);
    display->print("HAL Demo");
    display->setCursor(70, 130);
    display->print("Complete!");
    
    Serial.println("HAL Demo: Complete!");
    Serial.println("=== End HAL Demo ===\n");
}

void run_hal_integration_demo() {
    Serial.println("\n=== HAL Integration Demo ===");
    
    // Initialize HAL factory
    if (!HALFactory::initializeAll(tft, touch)) {
        Serial.println("Integration Demo: HAL initialization failed");
        return;
    }
    
    // Create integration example
    HALIntegrationExample example(
        HALFactory::getDisplay(),
        HALFactory::getTouch(), 
        HALFactory::getStorage()
    );
    
    if (!example.init()) {
        Serial.println("Integration Demo: Example initialization failed");
        return;
    }
    
    // Run boot sequence
    Serial.println("Integration Demo: Running boot sequence...");
    if (example.runBootSequence()) {
        Serial.println("Integration Demo: Boot sequence completed");
        
        // Show ROM selection
        delay(1000);
        example.showROMSelection();
        
        // Handle input for a while
        Serial.println("Integration Demo: Handling user input...");
        unsigned long start_time = millis();
        while (millis() - start_time < 10000) { // 10 seconds
            example.handleUserInput();
            delay(100);
        }
    } else {
        Serial.println("Integration Demo: Boot sequence timed out");
    }
    
    Serial.println("=== End HAL Integration Demo ===\n");
}

bool test_hal_interfaces() {
    Serial.println("\n=== HAL Interface Tests ===");
    
    bool all_tests_passed = true;
    
    // Test HAL Factory
    Serial.println("Testing HAL Factory...");
    if (!HALFactory::initializeAll(tft, touch)) {
        Serial.println("❌ HAL Factory initialization failed");
        all_tests_passed = false;
    } else {
        Serial.println("✅ HAL Factory initialization passed");
    }
    
    // Test display interface
    Serial.println("Testing Display Interface...");
    IDisplay* display = HALFactory::getDisplay();
    if (!display) {
        Serial.println("❌ Display interface is null");
        all_tests_passed = false;
    } else {
        Serial.printf("✅ Display interface available: %dx%d\n", 
                     display->width(), display->height());
    }
    
    // Test touch interface  
    Serial.println("Testing Touch Interface...");
    ITouch* touch_input = HALFactory::getTouch();
    if (!touch_input) {
        Serial.println("❌ Touch interface is null");
        all_tests_passed = false;
    } else {
        Serial.println("✅ Touch interface available");
    }
    
    // Test storage interface
    Serial.println("Testing Storage Interface...");
    IStorage* storage = HALFactory::getStorage();
    if (!storage) {
        Serial.println("❌ Storage interface is null");
        all_tests_passed = false;
    } else {
        // Test basic storage operations
        if (storage->exists("/")) {
            Serial.println("✅ Storage interface available and functional");
        } else {
            Serial.println("⚠️  Storage interface available but root path not accessible");
        }
    }
    
    // Test hardware manager
    Serial.println("Testing Hardware Manager...");
    if (display && touch_input && storage) {
        HardwareManager hw_mgr(display, touch_input, storage);
        if (hw_mgr.init()) {
            Serial.println("✅ Hardware Manager initialization passed");
            hw_mgr.printStatus();
        } else {
            Serial.println("❌ Hardware Manager initialization failed");
            all_tests_passed = false;
        }
    }
    
    if (all_tests_passed) {
        Serial.println("🎉 All HAL interface tests PASSED!");
    } else {
        Serial.println("❌ Some HAL interface tests FAILED!");
    }
    
    Serial.println("=== End HAL Interface Tests ===\n");
    return all_tests_passed;
}
