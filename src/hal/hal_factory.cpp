#include "hal/hal_factory.h"
#include <Arduino.h>

// Static member initialization
std::unique_ptr<IDisplay> HALFactory::display_instance;
std::unique_ptr<ITouch> HALFactory::touch_instance;
std::unique_ptr<IStorage> HALFactory::storage_instance;

// Factory methods
std::unique_ptr<IDisplay> HALFactory::createDisplay(TFT_eSPI& tft) {
    Serial.println("HALFactory: Creating TFT display implementation");
    return std::unique_ptr<IDisplay>(new TFTDisplayImpl(tft));
}

std::unique_ptr<ITouch> HALFactory::createTouch(XPT2046_Touchscreen& touch) {
    Serial.println("HALFactory: Creating XPT2046 touch implementation");
    return std::unique_ptr<ITouch>(new XPT2046TouchImpl(touch));
}

std::unique_ptr<IStorage> HALFactory::createStorage() {
    Serial.println("HALFactory: Creating SD storage implementation");
    return std::unique_ptr<IStorage>(new SDStorageImpl());
}

// Singleton access methods
IDisplay* HALFactory::getDisplay() {
    return display_instance.get();
}

ITouch* HALFactory::getTouch() {
    return touch_instance.get();
}

IStorage* HALFactory::getStorage() {
    return storage_instance.get();
}

bool HALFactory::initializeAll(TFT_eSPI& tft, XPT2046_Touchscreen& touch) {
    Serial.println("HALFactory: Initializing all HAL components...");
    
    bool success = true;
    
    // Create and initialize display
    display_instance = createDisplay(tft);
    if (!display_instance || !display_instance->init()) {
        Serial.println("HALFactory: Display initialization failed");
        success = false;
    }
    
    // Create and initialize touch
    touch_instance = createTouch(touch);
    if (!touch_instance || !touch_instance->init()) {
        Serial.println("HALFactory: Touch initialization failed");
        success = false;
    }
    
    // Create and initialize storage
    storage_instance = createStorage();
    if (!storage_instance || storage_instance->init() != StorageError::SUCCESS) {
        Serial.println("HALFactory: Storage initialization failed");
        success = false;
    }
    
    if (success) {
        Serial.println("HALFactory: All HAL components initialized successfully");
    } else {
        Serial.println("HALFactory: Some HAL components failed to initialize");
    }
    
    return success;
}

void HALFactory::cleanup() {
    Serial.println("HALFactory: Cleaning up HAL components...");
    storage_instance.reset();
    touch_instance.reset();
    display_instance.reset();
}

bool HALFactory::detectHardware() {
    // Future enhancement: auto-detect hardware and create appropriate implementations
    Serial.println("HALFactory: Hardware detection not yet implemented");
    return true;
}

void HALFactory::setMockDisplay(std::unique_ptr<IDisplay> mock) {
    display_instance = std::move(mock);
}

void HALFactory::setMockTouch(std::unique_ptr<ITouch> mock) {
    touch_instance = std::move(mock);
}

void HALFactory::setMockStorage(std::unique_ptr<IStorage> mock) {
    storage_instance = std::move(mock);
}

// HardwareManager implementation
HardwareManager::HardwareManager(IDisplay* disp, ITouch* tch, IStorage* stor)
    : display(disp), touch(tch), storage(stor) {
}

bool HardwareManager::init() {
    if (initialized) return true;
    
    Serial.println("HardwareManager: Initializing...");
    
    if (!display || !touch || !storage) {
        Serial.println("HardwareManager: Missing HAL components");
        return false;
    }
    
    // All components should already be initialized by the factory
    // This is just verification
    initialized = true;
    Serial.println("HardwareManager: Initialization complete");
    return true;
}

void HardwareManager::cleanup() {
    Serial.println("HardwareManager: Cleaning up...");
    initialized = false;
}

bool HardwareManager::displayBootScreen() {
    if (!initialized || !display) return false;
    
    Serial.println("HardwareManager: Displaying boot screen...");
    
    display->fillScreen(0x0000); // Black
    display->setTextColor(0xFFFF); // White
    display->setTextSize(2);
    display->setCursor(50, 100);
    display->print("Game Boy Emulator");
    display->setCursor(80, 130);
    display->print("HAL Initialized");
    
    return true;
}

bool HardwareManager::handleTouch() {
    if (!initialized || !touch || !display) return false;
    
    if (touch->touched()) {
        TouchPoint point = touch->getPoint();
        if (point.pressed) {
            Serial.printf("HardwareManager: Touch detected at (%d, %d)\n", point.x, point.y);
            
            // Visual feedback
            display->drawPixel(point.x, point.y, 0xF800); // Red dot
            return true;
        }
    }
    
    return false;
}

bool HardwareManager::loadConfiguration() {
    if (!initialized || !storage) return false;
    
    Serial.println("HardwareManager: Loading configuration...");
    
    if (!storage->exists("/config.bin")) {
        Serial.println("HardwareManager: No configuration file found");
        return false;
    }
    
    uint8_t config_buffer[256];
    size_t config_size = sizeof(config_buffer);
    
    StorageError result = storage->readFile("/config.bin", config_buffer, config_size);
    if (result == StorageError::SUCCESS) {
        Serial.printf("HardwareManager: Configuration loaded (%d bytes)\n", config_size);
        return true;
    } else {
        Serial.println("HardwareManager: Failed to load configuration");
        return false;
    }
}

bool HardwareManager::saveConfiguration() {
    if (!initialized || !storage) return false;
    
    Serial.println("HardwareManager: Saving configuration...");
    
    // Example configuration data
    uint8_t config_data[] = {0x01, 0x02, 0x03, 0x04}; // Placeholder
    
    StorageError result = storage->writeFile("/config.bin", config_data, sizeof(config_data));
    if (result == StorageError::SUCCESS) {
        Serial.println("HardwareManager: Configuration saved");
        return true;
    } else {
        Serial.println("HardwareManager: Failed to save configuration");
        return false;
    }
}

void HardwareManager::printStatus() {
    Serial.println("=== Hardware Manager Status ===");
    Serial.printf("Initialized: %s\n", initialized ? "Yes" : "No");
    Serial.printf("Display: %s\n", display ? "Available" : "NULL");
    Serial.printf("Touch: %s\n", touch ? "Available" : "NULL");
    Serial.printf("Storage: %s\n", storage ? "Available" : "NULL");
    
    if (initialized && display) {
        Serial.printf("Display size: %dx%d\n", display->width(), display->height());
    }
    
    Serial.println("===============================");
}
