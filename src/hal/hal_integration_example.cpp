#include "hal/hal_integration_example.h"
#include <Arduino.h>
#include <algorithm>

// HALDisplayManager implementation
HALDisplayManager::HALDisplayManager(IDisplay* disp) : display(disp) {
}

HALDisplayManager::~HALDisplayManager() {
    cleanup();
}

bool HALDisplayManager::init() {
    if (initialized || !display) return false;
    
    Serial.println("HALDisplayManager: Initializing...");
    
    // Clear screen and setup
    display->fillScreen(0x0000); // Black
    display->setRotation(3); // Landscape flipped (180° rotated)
    
    // Allocate back buffer
    if (!allocateBackBuffer()) {
        Serial.println("HALDisplayManager: Warning - no back buffer allocated");
    }
    
    // Draw border
    drawGameBoyBorder();
    
    initialized = true;
    Serial.println("HALDisplayManager: Initialization complete");
    return true;
}

void HALDisplayManager::cleanup() {
    deallocateBackBuffer();
    initialized = false;
}

bool HALDisplayManager::renderGameBoyFrame(const uint16_t* pixels) {
    if (!initialized || !display || !pixels) return false;
    
    int center_x = getCenterX();
    int center_y = getCenterY();
    
    display->drawBuffer(pixels, center_x, center_y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    return true;
}

void HALDisplayManager::clearScreen() {
    if (!initialized || !display) return;
    display->fillScreen(0x0000); // Black
}

void HALDisplayManager::drawGameBoyBorder() {
    if (!initialized || !display) return;
    
    int center_x = getCenterX();
    int center_y = getCenterY();
    
    // Draw border (simplified - just set text)
    display->setTextColor(0x7BEF); // Light gray
    display->setTextSize(1);
    display->setCursor(center_x - 30, center_y - 20);
    display->print("Game Boy Display");
}

void HALDisplayManager::displayError(const char* message) {
    if (!initialized || !display || !message) return;
    
    display->fillScreen(0xF800); // Red
    display->setTextColor(0xFFFF); // White
    display->setTextSize(2);
    display->setCursor(20, display->height()/2 - 20);
    display->print("ERROR:");
    display->setCursor(20, display->height()/2);
    display->print(message);
}

void HALDisplayManager::displayDebugInfo(float fps, uint32_t free_heap) {
    if (!initialized || !display) return;
    
    display->setTextColor(0x07E0); // Green
    display->setTextSize(1);
    
    // FPS in top-left
    display->setCursor(5, 5);
    display->print("FPS: ");
    display->print(fps, 1);
    
    // Memory in top-right
    display->setCursor(display->width() - 80, 5);
    display->print("MEM: ");
    display->print((int)(free_heap / 1024));
    display->print("K");
}

bool HALDisplayManager::allocateBackBuffer() {
    if (back_buffer_allocated) return true;
    
    size_t buffer_size = GAMEBOY_WIDTH * GAMEBOY_HEIGHT * sizeof(uint16_t);
    back_buffer = (uint16_t*)malloc(buffer_size);
    
    if (back_buffer) {
        memset(back_buffer, 0, buffer_size);
        back_buffer_allocated = true;
        Serial.printf("HALDisplayManager: Back buffer allocated (%d bytes)\n", buffer_size);
        return true;
    }
    
    Serial.println("HALDisplayManager: Failed to allocate back buffer");
    return false;
}

void HALDisplayManager::deallocateBackBuffer() {
    if (back_buffer_allocated && back_buffer) {
        free(back_buffer);
        back_buffer = nullptr;
        back_buffer_allocated = false;
        Serial.println("HALDisplayManager: Back buffer deallocated");
    }
}

bool HALDisplayManager::swapBuffers() {
    if (!initialized || !display || !back_buffer) return false;
    
    return renderGameBoyFrame(back_buffer);
}

int HALDisplayManager::getCenterX() const {
    if (!display) return 0;
    return (display->width() - GAMEBOY_WIDTH) / 2;
}

int HALDisplayManager::getCenterY() const {
    if (!display) return 0;
    return (display->height() - GAMEBOY_HEIGHT) / 2;
}

// HALTouchManager implementation
HALTouchManager::HALTouchManager(ITouch* tch) : touch(tch) {
    state.last_point = {0, 0, false};
    state.last_touch_time = 0;
    state.was_pressed = false;
}

bool HALTouchManager::init() {
    if (initialized || !touch) return false;
    
    Serial.println("HALTouchManager: Initializing...");
    initialized = true;
    Serial.println("HALTouchManager: Initialization complete");
    return true;
}

bool HALTouchManager::isTouched() {
    if (!initialized || !touch) return false;
    return touch->touched();
}

TouchPoint HALTouchManager::getCurrentTouch() {
    if (!initialized || !touch) {
        return {0, 0, false};
    }
    
    TouchPoint point = touch->getPoint();
    state.last_point = point;
    state.last_touch_time = millis();
    
    return point;
}

bool HALTouchManager::waitForTouch(unsigned long timeout_ms) {
    if (!initialized || !touch) return false;
    
    unsigned long start_time = millis();
    
    while (millis() - start_time < timeout_ms) {
        if (touch->touched()) {
            return true;
        }
        delay(10);
    }
    
    return false;
}

void HALTouchManager::setRotation(uint8_t rotation) {
    if (initialized && touch) {
        touch->setRotation(rotation);
    }
}

void HALTouchManager::handleTouchEvents(TouchCallback callback) {
    if (!initialized || !touch || !callback) return;
    
    bool currently_pressed = touch->touched();
    
    if (currently_pressed && !state.was_pressed) {
        // Touch started
        TouchPoint point = touch->getPoint();
        if (point.pressed) {
            callback(point);
        }
    }
    
    state.was_pressed = currently_pressed;
}

// HALStorageManager implementation
HALStorageManager::HALStorageManager(IStorage* stor) : storage(stor) {
}

bool HALStorageManager::init() {
    if (initialized || !storage) return false;
    
    Serial.println("HALStorageManager: Initializing...");
    initialized = true;
    Serial.println("HALStorageManager: Initialization complete");
    return true;
}

bool HALStorageManager::loadROM(const char* path, uint8_t* buffer, size_t& size) {
    if (!initialized || !storage || !path || !buffer) return false;
    
    StorageError result = storage->readFile(path, buffer, size);
    return result == StorageError::SUCCESS;
}

bool HALStorageManager::saveState(const char* path, const uint8_t* state, size_t size) {
    if (!initialized || !storage || !path || !state) return false;
    
    StorageError result = storage->writeFile(path, state, size);
    return result == StorageError::SUCCESS;
}

bool HALStorageManager::loadState(const char* path, uint8_t* state, size_t& size) {
    if (!initialized || !storage || !path || !state) return false;
    
    StorageError result = storage->readFile(path, state, size);
    return result == StorageError::SUCCESS;
}

bool HALStorageManager::listROMs(std::vector<std::string>& roms) {
    if (!initialized || !storage) return false;
    
    StorageError result = storage->listFiles("/", ".gb", roms);
    return result == StorageError::SUCCESS;
}

bool HALStorageManager::romExists(const char* path) {
    if (!initialized || !storage || !path) return false;
    return storage->exists(path);
}

size_t HALStorageManager::getROMSize(const char* path) {
    if (!initialized || !storage || !path) return 0;
    return storage->getFileSize(path);
}

bool HALStorageManager::saveSRAM(const char* rom_name, const uint8_t* sram, size_t size) {
    if (!initialized || !storage || !rom_name || !sram) return false;
    
    // Create SRAM filename from ROM name
    String sram_path = "/";
    sram_path += rom_name;
    sram_path += ".sav";
    
    StorageError result = storage->writeFile(sram_path.c_str(), sram, size);
    return result == StorageError::SUCCESS;
}

bool HALStorageManager::loadSRAM(const char* rom_name, uint8_t* sram, size_t& size) {
    if (!initialized || !storage || !rom_name || !sram) return false;
    
    // Create SRAM filename from ROM name
    String sram_path = "/";
    sram_path += rom_name;
    sram_path += ".sav";
    
    if (!storage->exists(sram_path.c_str())) {
        return false; // No save file exists
    }
    
    StorageError result = storage->readFile(sram_path.c_str(), sram, size);
    return result == StorageError::SUCCESS;
}

// HALIntegrationExample implementation
HALIntegrationExample::HALIntegrationExample(IDisplay* display, ITouch* touch, IStorage* storage) {
    display_mgr = new HALDisplayManager(display);
    touch_mgr = new HALTouchManager(touch);
    storage_mgr = new HALStorageManager(storage);
}

HALIntegrationExample::~HALIntegrationExample() {
    cleanup();
    delete storage_mgr;
    delete touch_mgr;
    delete display_mgr;
}

bool HALIntegrationExample::init() {
    if (initialized) return true;
    
    Serial.println("HALIntegrationExample: Initializing...");
    
    bool success = true;
    success &= display_mgr->init();
    success &= touch_mgr->init();
    success &= storage_mgr->init();
    
    if (success) {
        initialized = true;
        Serial.println("HALIntegrationExample: All components initialized");
    } else {
        Serial.println("HALIntegrationExample: Some components failed to initialize");
    }
    
    return success;
}

void HALIntegrationExample::cleanup() {
    if (display_mgr) display_mgr->cleanup();
    initialized = false;
}

bool HALIntegrationExample::runBootSequence() {
    if (!initialized) return false;
    
    Serial.println("HALIntegrationExample: Running boot sequence...");
    
    // Show boot screen
    display_mgr->clearScreen();
    display_mgr->displayDebugInfo(60.0f, ESP.getFreeHeap());
    
    // Wait for user interaction
    display_mgr->getDisplay()->setCursor(50, 180);
    display_mgr->getDisplay()->setTextColor(0xFFFF);
    display_mgr->getDisplay()->print("Touch to continue...");
    
    return touch_mgr->waitForTouch(10000); // 10 second timeout
}

bool HALIntegrationExample::showROMSelection() {
    if (!initialized) return false;
    
    Serial.println("HALIntegrationExample: Showing ROM selection...");
    
    // List available ROMs
    std::vector<std::string> roms;
    if (!storage_mgr->listROMs(roms)) {
        display_mgr->displayError("No ROMs found");
        return false;
    }
    
    // Display ROM list
    display_mgr->clearScreen();
    display_mgr->getDisplay()->setTextColor(0xFFFF);
    display_mgr->getDisplay()->setTextSize(1);
    display_mgr->getDisplay()->setCursor(10, 10);
    display_mgr->getDisplay()->print("Available ROMs:");
    
    for (size_t i = 0; i < std::min(roms.size(), (size_t)10); ++i) {
        display_mgr->getDisplay()->setCursor(10, 30 + i * 15);
        display_mgr->getDisplay()->print(roms[i].c_str());
    }
    
    return true;
}

bool HALIntegrationExample::loadAndRunROM(const char* rom_path) {
    if (!initialized || !rom_path) return false;
    
    Serial.printf("HALIntegrationExample: Loading ROM: %s\n", rom_path);
    
    // Check if ROM exists
    if (!storage_mgr->romExists(rom_path)) {
        display_mgr->displayError("ROM not found");
        return false;
    }
    
    // Get ROM size
    size_t rom_size = storage_mgr->getROMSize(rom_path);
    Serial.printf("HALIntegrationExample: ROM size: %d bytes\n", rom_size);
    
    // For demonstration purposes, just show success
    display_mgr->clearScreen();
    display_mgr->getDisplay()->setTextColor(0x07E0); // Green
    display_mgr->getDisplay()->setTextSize(2);
    display_mgr->getDisplay()->setCursor(50, 100);
    display_mgr->getDisplay()->print("ROM Loaded!");
    
    return true;
}

bool HALIntegrationExample::handleUserInput() {
    if (!initialized) return false;
    
    // Simple touch handling
    if (touch_mgr->isTouched()) {
        TouchPoint point = touch_mgr->getCurrentTouch();
        if (point.pressed) {
            Serial.printf("HALIntegrationExample: Touch at (%d, %d)\n", point.x, point.y);
            
            // Visual feedback
            display_mgr->getDisplay()->drawPixel(point.x, point.y, 0xF800); // Red
            return true;
        }
    }
    
    return false;
}
