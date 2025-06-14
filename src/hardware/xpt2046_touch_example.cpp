// Example usage of XPT2046Touch class with pImpl pattern
// This file demonstrates how to use the XPT2046Touch class for touch input

#include "hardware/xpt2046_touch.h"
#include <Arduino.h>

// Forward declarations
void handleTouchRegion(const TouchPoint& point);

void demonstrateXPT2046Touch() {
    // Example 1: Create with default pins (CS=33, IRQ=36)
    XPT2046Touch touch1;
    
    // Example 2: Create with custom pins
    XPT2046Touch touch2(25, 27); // Custom CS and IRQ pins
    
    // Initialize the touchscreen
    if (!touch1.init()) {
        Serial.println("Failed to initialize touchscreen");
        return;
    }
    
    Serial.println("XPT2046Touch initialized successfully");
    
    // Configure for specific hardware if needed
    touch1.setCalibration(200, 3900, 200, 3900); // Set calibration values
    touch1.setScreenSize(320, 240);              // Set screen dimensions
    touch1.setDebouncing(true, 200);             // Enable debouncing with 200ms delay
    
    // Set rotation for landscape flipped mode (default is already 3)
    touch1.setRotation(3); // 0=Portrait, 1=Landscape, 2=Portrait flipped, 3=Landscape flipped
    
    Serial.printf("Touch initialized - Rotation: %d\n", touch1.getCurrentRotation());
    
    // Main touch handling loop
    while (true) {
        // Check if screen is being touched
        if (touch1.touched()) {
            // Get the touch point with automatic coordinate transformation
            TouchPoint point = touch1.getPoint();
            
            if (point.pressed) {
                Serial.printf("Touch detected at: (%d, %d)\n", point.x, point.y);
                
                // Example: Handle different screen regions
                handleTouchRegion(point);
            }
        }
        
        delay(50); // Small delay to prevent overwhelming the serial output
    }
}

/**
 * Example function to handle different touch regions
 */
void handleTouchRegion(const TouchPoint& point) {
    // Define screen regions for a 320x240 landscape display
    const int SCREEN_WIDTH = 320;
    const int SCREEN_HEIGHT = 240;
    
    // Define button regions
    const int BUTTON_SIZE = 60;
    const int MARGIN = 20;
    
    // Left side buttons (D-pad area)
    if (point.x < SCREEN_WIDTH / 3) {
        if (point.y < SCREEN_HEIGHT / 3) {
            Serial.println("Action: UP button pressed");
        } else if (point.y > 2 * SCREEN_HEIGHT / 3) {
            Serial.println("Action: DOWN button pressed");
        } else {
            if (point.x < BUTTON_SIZE) {
                Serial.println("Action: LEFT button pressed");
            } else {
                Serial.println("Action: RIGHT button pressed");
            }
        }
    }
    // Right side buttons (Action buttons)
    else if (point.x > 2 * SCREEN_WIDTH / 3) {
        if (point.y < SCREEN_HEIGHT / 2) {
            Serial.println("Action: A button pressed");
        } else {
            Serial.println("Action: B button pressed");
        }
    }
    // Center area (Game screen)
    else {
        Serial.printf("Action: Screen touch at game area (%d, %d)\n", point.x, point.y);
    }
}

/**
 * Example of using multiple touch instances (for multi-touch scenarios)
 */
void demonstrateMultipleTouch() {
    // Create multiple touch instances with different configurations
    XPT2046Touch primaryTouch(33, 36);   // Primary touchscreen
    XPT2046Touch secondaryTouch(25, 27); // Secondary touchscreen (if available)
    
    // Initialize both
    bool primary_ok = primaryTouch.init();
    bool secondary_ok = secondaryTouch.init();
    
    if (primary_ok) {
        // Configure primary touch for landscape gaming
        primaryTouch.setRotation(3);
        primaryTouch.setScreenSize(320, 240);
        primaryTouch.setCalibration(200, 3900, 200, 3900);
        Serial.println("Primary touch configured for gaming");
    }
    
    if (secondary_ok) {
        // Configure secondary touch for portrait UI
        secondaryTouch.setRotation(0);
        secondaryTouch.setScreenSize(240, 320);
        secondaryTouch.setCalibration(150, 3950, 150, 3950);
        Serial.println("Secondary touch configured for UI");
    }
    
    // Use the appropriate touch interface based on current mode
    XPT2046Touch* activeTouch = primary_ok ? &primaryTouch : (secondary_ok ? &secondaryTouch : nullptr);
    
    if (activeTouch) {
        Serial.printf("Using %s touch interface\n", 
                     (activeTouch == &primaryTouch) ? "primary" : "secondary");
    }
}

/**
 * Example of advanced touch features
 */
void demonstrateAdvancedFeatures() {
    XPT2046Touch touch;
    
    if (!touch.init()) {
        Serial.println("Touch initialization failed");
        return;
    }
    
    // Example: Dynamic calibration based on hardware detection
    // In a real application, you might detect the specific CYD board model
    // and set appropriate calibration values
    
    // Example calibration values for different CYD models:
    // CYD 2.8": X(200-3900), Y(200-3900)
    // CYD 3.5": X(150-3950), Y(150-3950)
    touch.setCalibration(200, 3900, 200, 3900);
    
    // Example: Adaptive debouncing based on touch frequency
    unsigned long touch_count = 0;
    unsigned long last_stats_time = millis();
    
    while (true) {
        if (touch.touched()) {
            TouchPoint point = touch.getPoint();
            if (point.pressed) {
                touch_count++;
                
                // Log detailed touch information
                Serial.printf("Touch #%lu: (%d,%d) at rotation %d\n", 
                             touch_count, point.x, point.y, touch.getCurrentRotation());
            }
        }
        
        // Print statistics every 10 seconds
        if (millis() - last_stats_time > 10000) {
            Serial.printf("Touch statistics: %lu touches in 10 seconds\n", touch_count);
            
            // Adaptive debouncing: if too many touches, increase debounce time
            if (touch_count > 50) {
                touch.setDebouncing(true, 400); // Increase debounce time
                Serial.println("High touch frequency detected - increased debounce time");
            } else if (touch_count < 5) {
                touch.setDebouncing(true, 100); // Decrease debounce time for responsiveness
                Serial.println("Low touch frequency detected - decreased debounce time");
            }
            
            touch_count = 0;
            last_stats_time = millis();
        }
        
        delay(10);
    }
}

/**
 * Calibration helper function
 * This can be used to help users calibrate their touchscreen
 */
void runTouchCalibration() {
    XPT2046Touch touch;
    
    if (!touch.init()) {
        Serial.println("Touch initialization failed for calibration");
        return;
    }
    
    Serial.println("=== Touch Calibration Mode ===");
    Serial.println("Touch the corners of the screen when prompted:");
    
    // Disable debouncing for calibration
    touch.setDebouncing(false);
    
    // Set initial values for raw coordinate collection
    touch.setCalibration(0, 4095, 0, 4095); // Full ADC range
    
    struct CalibrationPoint {
        const char* name;
        int screen_x, screen_y;
        int raw_x, raw_y;
    };
    
    CalibrationPoint points[] = {
        {"Top-Left", 0, 0, 0, 0},
        {"Top-Right", 319, 0, 0, 0},
        {"Bottom-Left", 0, 239, 0, 0},
        {"Bottom-Right", 319, 239, 0, 0}
    };
    
    for (int i = 0; i < 4; i++) {
        Serial.printf("Touch %s corner and hold...\n", points[i].name);
        
        // Wait for touch
        while (!touch.touched()) {
            delay(100);
        }
        
        // Get raw coordinates (we'll need to access raw values somehow)
        TouchPoint point = touch.getPoint();
        Serial.printf("%s: Screen(%d,%d)\n", points[i].name, point.x, point.y);
        
        // Wait for release
        while (touch.touched()) {
            delay(100);
        }
        
        delay(1000); // Wait before next point
    }
    
    Serial.println("Calibration complete!");
    Serial.println("Use the collected values to set proper calibration in your code.");
}
