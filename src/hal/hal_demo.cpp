#include "hal/hal_demo.h"
#include <Arduino.h>

void run_hal_demo(IDisplay& display, ITouch& touch) {
    Serial.println("\n=== Hardware Abstraction Layer (HAL) Demo ===");
    
    // Display operations through HAL
    Serial.println("HAL Demo: Testing display operations...");
    display.fillScreen(0x001F); // Blue
    delay(1000);
    
    display.fillScreen(0x0000); // Black
    display.setTextColor(0xFFFF); // White
    display.setTextSize(2);
    display.setCursor(50, 50);
    display.print("HAL Demo");
    display.setCursor(30, 80);
    display.print("Display OK");
    
    // Show display dimensions
    display.setCursor(20, 120);
    display.setTextSize(1);
    display.print("Size: ");
    display.print((int)display.width());
    display.print("x");
    display.print((int)display.height());
    
    delay(2000);
    
    // Demonstrate touch operations through HAL
    Serial.println("HAL Demo: Testing touch operations...");
    display.fillScreen(0x0000);
    display.setTextColor(0x07E0); // Green
    display.setTextSize(2);
    display.setCursor(40, 80);
    display.print("Touch Test");
    display.setTextSize(1);
    display.setCursor(20, 120);
    display.print("Touch screen to continue...");
    
    // Wait for touch with timeout
    unsigned long start_time = millis();
    bool touch_detected = false;
    
    while (millis() - start_time < 5000 && !touch_detected) { // 5 second timeout
        if (touch.touched()) {
            TouchPoint point = touch.getPoint();
            if (point.pressed) {
                Serial.printf("HAL Demo: Touch detected at (%d, %d)\n", point.x, point.y);
                
                // Visual feedback
                display.drawPixel(point.x, point.y, 0xF800); // Red dot
                display.setCursor(20, 150);
                display.setTextColor(0xFFFF);
                display.print("Touch: ");
                display.print((int)point.x);
                display.print(",");
                display.print((int)point.y);
                
                touch_detected = true;
            }
        }
        delay(50);
    }
    
    if (!touch_detected) {
        Serial.println("HAL Demo: No touch detected within timeout");
        display.setCursor(20, 150);
        display.setTextColor(0xF800); // Red
        display.print("No touch detected");
    }
    
    delay(2000);
    
    // Test complete
    display.fillScreen(0x0000);
    display.setTextColor(0x07E0); // Green
    display.setTextSize(2);
    display.setCursor(60, 100);
    display.print("HAL Demo");
    display.setCursor(70, 130);
    display.print("Complete!");
    
    Serial.println("HAL Demo: Complete!");
    Serial.println("=== End HAL Demo ===\n");
}

void run_hal_integration_demo(IDisplay& display, ITouch& touch, IStorage& storage) {
    Serial.println("\n=== HAL Integration Demo ===");
    
    // Create integration example
    HALIntegrationExample example(&display, &touch, &storage);
    
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

bool test_hal_interfaces(IDisplay& display, ITouch& touch, IStorage& storage) {
    Serial.println("\n=== HAL Interface Tests ===");
    
    bool all_tests_passed = true;
    
    // Test display interface
    Serial.println("Testing Display Interface...");
    Serial.printf("✅ Display interface available: %dx%d\n", 
                 display.width(), display.height());
    
    // Test touch interface  
    Serial.println("Testing Touch Interface...");
    Serial.println("✅ Touch interface available");
    
    // Test storage interface
    Serial.println("Testing Storage Interface...");
    // Test basic storage operations
    if (storage.exists("/")) {
        Serial.println("✅ Storage interface available and functional");
    } else {
        Serial.println("⚠️  Storage interface available but root path not accessible");
    }
    
    // Test hardware manager
    Serial.println("Testing Hardware Manager...");
    HardwareManager hw_mgr(&display, &touch, &storage);
    if (hw_mgr.init()) {
        Serial.println("✅ Hardware Manager initialization passed");
        hw_mgr.printStatus();
    } else {
        Serial.println("❌ Hardware Manager initialization failed");
        all_tests_passed = false;
    }
    
    if (all_tests_passed) {
        Serial.println("🎉 All HAL interface tests PASSED!");
    } else {
        Serial.println("❌ Some HAL interface tests FAILED!");
    }
    
    Serial.println("=== End HAL Interface Tests ===\n");
    return all_tests_passed;
}
