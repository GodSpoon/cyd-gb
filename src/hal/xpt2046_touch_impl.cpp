#include "hal/xpt2046_touch_impl.h"

XPT2046TouchImpl::XPT2046TouchImpl(XPT2046_Touchscreen& touch) 
    : touch_controller(touch) {
}

bool XPT2046TouchImpl::init() {
    if (initialized) return true;
    
    Serial.println("XPT2046TouchImpl: Initializing touch controller...");
    
    // The touch controller is typically initialized externally
    // We just need to mark ourselves as initialized
    initialized = true;
    
    Serial.println("XPT2046TouchImpl: Initialization complete");
    return true;
}

bool XPT2046TouchImpl::touched() {
    if (!initialized) return false;
    
    // Simple debouncing
    unsigned long now = millis();
    if (now - last_touch_time < DEBOUNCE_MS) {
        return false;
    }
    
    return touch_controller.touched();
}

TouchPoint XPT2046TouchImpl::getPoint() {
    TouchPoint result = {0, 0, false};
    
    if (!initialized) return result;
    
    unsigned long now = millis();
    if (now - last_touch_time < DEBOUNCE_MS) {
        return result;
    }
    
    if (!touch_controller.touched()) {
        return result;
    }
    
    TS_Point raw = touch_controller.getPoint();
    
    if (!isValidTouch(raw)) {
        return result;
    }
    
    last_touch_time = now;
    return mapRawToScreen(raw);
}

void XPT2046TouchImpl::setRotation(uint8_t rotation) {
    current_rotation = rotation;
}

TouchPoint XPT2046TouchImpl::mapRawToScreen(const TS_Point& raw) {
    TouchPoint result;
    
    // Map raw coordinates to screen coordinates
    int screen_x = map(raw.x, RAW_X_MIN, RAW_X_MAX, 0, SCREEN_WIDTH);
    int screen_y = map(raw.y, RAW_Y_MIN, RAW_Y_MAX, 0, SCREEN_HEIGHT);
    
    // Apply rotation transformation
    switch (current_rotation) {
        case 0: // Portrait
            result.x = screen_x;
            result.y = screen_y;
            break;
        case 1: // Landscape
            result.x = screen_x;
            result.y = screen_y;
            break;
        case 2: // Portrait flipped
            result.x = SCREEN_WIDTH - screen_x;
            result.y = SCREEN_HEIGHT - screen_y;
            break;
        case 3: // Landscape flipped
            result.x = SCREEN_WIDTH - screen_x;
            result.y = SCREEN_HEIGHT - screen_y;
            break;
        default:
            result.x = screen_x;
            result.y = screen_y;
            break;
    }
    
    // Constrain to screen bounds
    result.x = constrain(result.x, 0, SCREEN_WIDTH - 1);
    result.y = constrain(result.y, 0, SCREEN_HEIGHT - 1);
    result.pressed = true;
    
    return result;
}

bool XPT2046TouchImpl::isValidTouch(const TS_Point& raw) {
    return (raw.x >= RAW_X_MIN && raw.x <= RAW_X_MAX && 
            raw.y >= RAW_Y_MIN && raw.y <= RAW_Y_MAX);
}
