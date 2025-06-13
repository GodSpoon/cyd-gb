#ifndef HAL_INTEGRATION_EXAMPLE_H
#define HAL_INTEGRATION_EXAMPLE_H

#include "hal/display_interface.h"
#include "hal/touch_interface.h"
#include "hal/storage_interface.h"
#include <cstdint>

/**
 * Enhanced Display Manager using HAL
 * 
 * This class demonstrates how the existing DisplayManager can be refactored
 * to use the HAL interfaces instead of direct hardware dependencies.
 * This provides better testability and hardware abstraction.
 */
class HALDisplayManager {
private:
    IDisplay* display;
    bool initialized = false;
    
    // Game Boy display constants
    static const int GAMEBOY_WIDTH = 160;
    static const int GAMEBOY_HEIGHT = 144;
    
    // Buffer for double buffering
    uint16_t* back_buffer = nullptr;
    bool back_buffer_allocated = false;
    
    // Helper methods
    bool allocateBackBuffer();
    void deallocateBackBuffer();
    int getCenterX() const;
    int getCenterY() const;

public:
    explicit HALDisplayManager(IDisplay* disp);
    virtual ~HALDisplayManager();
    
    // Initialization
    bool init();
    void cleanup();
    
    // Display operations using HAL
    bool renderGameBoyFrame(const uint16_t* pixels);
    void clearScreen();
    void drawGameBoyBorder();
    void displayError(const char* message);
    void displayDebugInfo(float fps, uint32_t free_heap);
    
    // Back buffer operations
    uint16_t* getBackBuffer() { return back_buffer; }
    bool swapBuffers();
    
    // Status
    bool isInitialized() const { return initialized; }
    IDisplay* getDisplay() const { return display; }
};

/**
 * Enhanced Touch Manager using HAL
 * 
 * This class shows how to abstract touch functionality using the HAL interface.
 */
class HALTouchManager {
private:
    ITouch* touch;
    bool initialized = false;
    
    struct TouchState {
        TouchPoint last_point;
        unsigned long last_touch_time;
        bool was_pressed;
    } state;

public:
    explicit HALTouchManager(ITouch* tch);
    virtual ~HALTouchManager() = default;
    
    // Initialization
    bool init();
    
    // Touch operations using HAL
    bool isTouched();
    TouchPoint getCurrentTouch();
    bool waitForTouch(unsigned long timeout_ms = 5000);
    void setRotation(uint8_t rotation);
    
    // Event handling
    typedef void (*TouchCallback)(const TouchPoint& point);
    void handleTouchEvents(TouchCallback callback);
    
    // Status
    bool isInitialized() const { return initialized; }
    ITouch* getTouch() const { return touch; }
};

/**
 * Enhanced Storage Manager using HAL
 * 
 * This class demonstrates storage operations abstracted through the HAL interface.
 */
class HALStorageManager {
private:
    IStorage* storage;
    bool initialized = false;

public:
    explicit HALStorageManager(IStorage* stor);
    virtual ~HALStorageManager() = default;
    
    // Initialization
    bool init();
    
    // ROM operations using HAL
    bool loadROM(const char* path, uint8_t* buffer, size_t& size);
    bool saveState(const char* path, const uint8_t* state, size_t size);
    bool loadState(const char* path, uint8_t* state, size_t& size);
    
    // File management
    bool listROMs(std::vector<std::string>& roms);
    bool romExists(const char* path);
    size_t getROMSize(const char* path);
    
    // SRAM operations
    bool saveSRAM(const char* rom_name, const uint8_t* sram, size_t size);
    bool loadSRAM(const char* rom_name, uint8_t* sram, size_t& size);
    
    // Status
    bool isInitialized() const { return initialized; }
    IStorage* getStorage() const { return storage; }
};

/**
 * Complete HAL Integration Example
 * 
 * This class shows how all HAL components work together in a real application.
 */
class HALIntegrationExample {
private:
    HALDisplayManager* display_mgr;
    HALTouchManager* touch_mgr;
    HALStorageManager* storage_mgr;
    bool initialized = false;

public:
    HALIntegrationExample(IDisplay* display, ITouch* touch, IStorage* storage);
    virtual ~HALIntegrationExample();
    
    // Initialization
    bool init();
    void cleanup();
    
    // Example operations
    bool runBootSequence();
    bool showROMSelection();
    bool loadAndRunROM(const char* rom_path);
    bool handleUserInput();
    
    // Status
    bool isInitialized() const { return initialized; }
};

#endif // HAL_INTEGRATION_EXAMPLE_H
