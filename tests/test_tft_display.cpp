#include "hardware/tft_display.h"
#include "hal/display_interface.h"
#include <cassert>
#include <iostream>

/**
 * @brief Simple test for TFTDisplay dependency injection pattern
 * 
 * This test demonstrates how the TFTDisplay class can be used
 * with the IDisplay interface for dependency injection.
 */

// Mock test function that accepts any IDisplay implementation
void testDisplayInterface(IDisplay& display) {
    std::cout << "Testing display interface..." << std::endl;
    
    // Test initialization
    bool init_result = display.init();
    std::cout << "Display init: " << (init_result ? "SUCCESS" : "FAILED") << std::endl;
    
    if (!init_result) {
        return;
    }
    
    // Test basic operations
    std::cout << "Display dimensions: " << display.width() << "x" << display.height() << std::endl;
    
    // Test drawing operations
    display.fillScreen(0x0000);  // Black
    display.setRotation(1);
    
    display.setTextColor(0xFFFF);  // White
    display.setTextSize(2);
    display.setCursor(10, 10);
    display.print("Test Display");
    
    display.setCursor(10, 40);
    display.print("Width: ");
    display.print((int)display.width());
    
    display.setCursor(10, 70);
    display.print("Height: ");
    display.print((int)display.height());
    
    // Test pixel drawing
    for (int i = 0; i < 10; i++) {
        display.drawPixel(i, 100, 0xF800);  // Red pixels
    }
    
    std::cout << "Display test completed successfully!" << std::endl;
}

// Test factory pattern
std::unique_ptr<IDisplay> createTestDisplay() {
    auto display = std::make_unique<TFTDisplay>(21);
    return display;
}

// Main test function
void runDisplayTests() {
    std::cout << "=== TFTDisplay Dependency Injection Test ===" << std::endl;
    
    // Test 1: Direct instantiation
    {
        std::cout << "\nTest 1: Direct instantiation" << std::endl;
        TFTDisplay tft_display(21);
        testDisplayInterface(tft_display);
    }
    
    // Test 2: Factory pattern
    {
        std::cout << "\nTest 2: Factory pattern" << std::endl;
        auto display = createTestDisplay();
        if (display) {
            testDisplayInterface(*display);
        } else {
            std::cout << "Failed to create display instance" << std::endl;
        }
    }
    
    // Test 3: Move semantics
    {
        std::cout << "\nTest 3: Move semantics" << std::endl;
        TFTDisplay display1(21);
        TFTDisplay display2 = std::move(display1);
        testDisplayInterface(display2);
    }
    
    // Test 4: Polymorphic usage
    {
        std::cout << "\nTest 4: Polymorphic usage" << std::endl;
        std::unique_ptr<IDisplay> display = std::make_unique<TFTDisplay>(21);
        testDisplayInterface(*display);
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
}

#ifdef UNIT_TESTING
int main() {
    runDisplayTests();
    return 0;
}
#endif
