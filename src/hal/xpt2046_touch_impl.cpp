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
        case 1: // Landscape (90° counter-clockwise) - Inverted landscape
            result.x = SCREEN_HEIGHT - 1 - screen_y;
            result.y = screen_x;
            break;
        case 2: // Portrait flipped (180°)
            result.x = SCREEN_WIDTH - 1 - screen_x;
            result.y = SCREEN_HEIGHT - 1 - screen_y;
            break;
        case 3: // Landscape flipped (270°)
            result.x = screen_y;
            result.y = SCREEN_WIDTH - 1 - screen_x;
            break;
        default:
            result.x = screen_x;
            result.y = screen_y;
            break;
    }
    
    // Constrain to screen bounds (account for rotation affecting dimensions)
    int max_x = (current_rotation == 1 || current_rotation == 3) ? SCREEN_HEIGHT - 1 : SCREEN_WIDTH - 1;
    int max_y = (current_rotation == 1 || current_rotation == 3) ? SCREEN_WIDTH - 1 : SCREEN_HEIGHT - 1;
    
    result.x = constrain(result.x, 0, max_x);
    result.y = constrain(result.y, 0, max_y);
    result.pressed = true;
    
    return result;
}

bool XPT2046TouchImpl::isValidTouch(const TS_Point& raw) {
    return (raw.x >= RAW_X_MIN && raw.x <= RAW_X_MAX && 
            raw.y >= RAW_Y_MIN && raw.y <= RAW_Y_MAX);
}
