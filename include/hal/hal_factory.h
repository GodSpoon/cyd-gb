#ifndef HAL_FACTORY_H
#define HAL_FACTORY_H

#include "hal/display_interface.h"
#include "hal/touch_interface.h"
#include "hal/storage_interface.h"
#include "hal/tft_display_impl.h"
#include "hal/xpt2046_touch_impl.h"
#include "hal/sd_storage_impl.h"
#include <memory>

/**
 * Hardware Abstraction Layer Factory
 * 
 * This factory class demonstrates dependency injection and provides a clean way
 * to create and manage HAL implementations. It follows the Factory pattern and
 * supports dependency injection for better testability and flexibility.
 * 
 * Benefits:
 * - Decouples hardware-specific implementations from business logic
 * - Enables easy testing with mock implementations
 * - Supports runtime hardware detection and selection
 * - Provides a single point of configuration for hardware abstraction
 */
class HALFactory {
private:
    static std::unique_ptr<IDisplay> display_instance;
    static std::unique_ptr<ITouch> touch_instance;
    static std::unique_ptr<IStorage> storage_instance;

public:
    // Factory methods for creating HAL implementations
    static std::unique_ptr<IDisplay> createDisplay(TFT_eSPI& tft);
    static std::unique_ptr<ITouch> createTouch(XPT2046_Touchscreen& touch);
    static std::unique_ptr<IStorage> createStorage();
    
    // Singleton access methods (optional convenience)
    static IDisplay* getDisplay();
    static ITouch* getTouch();
    static IStorage* getStorage();
    
    // Configuration and cleanup
    static bool initializeAll(TFT_eSPI& tft, XPT2046_Touchscreen& touch);
    static void cleanup();
    
    // Hardware detection (future enhancement)
    static bool detectHardware();
    
    // Testing support
    static void setMockDisplay(std::unique_ptr<IDisplay> mock);
    static void setMockTouch(std::unique_ptr<ITouch> mock);
    static void setMockStorage(std::unique_ptr<IStorage> mock);
};

/**
 * Hardware Manager - Demonstrates dependency injection usage
 * 
 * This class shows how to use the HAL interfaces with dependency injection.
 * It can work with any implementation of the HAL interfaces, making it
 * testable and flexible.
 */
class HardwareManager {
private:
    IDisplay* display;
    ITouch* touch;
    IStorage* storage;
    bool initialized = false;

public:
    // Constructor with dependency injection
    HardwareManager(IDisplay* disp, ITouch* tch, IStorage* stor);
    
    // Initialization and cleanup
    bool init();
    void cleanup();
    
    // High-level operations that use multiple HAL components
    bool displayBootScreen();
    bool handleTouch();
    bool loadConfiguration();
    bool saveConfiguration();
    
    // Status and diagnostics
    bool isInitialized() const { return initialized; }
    void printStatus();
};

#endif // HAL_FACTORY_H
