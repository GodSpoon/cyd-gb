#ifndef XPT2046_TOUCH_IMPL_H
#define XPT2046_TOUCH_IMPL_H

#include "hal/touch_interface.h"
#include <XPT2046_Touchscreen.h>
#include <Arduino.h>

/**
 * Concrete implementation of ITouch interface using XPT2046_Touchscreen library
 * This class wraps the XPT2046 functionality to conform to the HAL interface
 */
class XPT2046TouchImpl : public ITouch {
private:
    XPT2046_Touchscreen& touch_controller;
    bool initialized = false;
    unsigned long last_touch_time = 0;
    uint8_t current_rotation = 1;
    
    // Calibration constants for CYD boards
    static constexpr unsigned long DEBOUNCE_MS = 250;
    static constexpr int RAW_X_MIN = 200;
    static constexpr int RAW_X_MAX = 3900;
    static constexpr int RAW_Y_MIN = 200;
    static constexpr int RAW_Y_MAX = 3900;
    static constexpr int SCREEN_WIDTH = 320;
    static constexpr int SCREEN_HEIGHT = 240;

    // Helper methods
    TouchPoint mapRawToScreen(const TS_Point& raw);
    bool isValidTouch(const TS_Point& raw);

public:
    explicit XPT2046TouchImpl(XPT2046_Touchscreen& touch);
    virtual ~XPT2046TouchImpl() = default;

    // ITouch interface implementation
    bool init() override;
    bool touched() override;
    TouchPoint getPoint() override;
    void setRotation(uint8_t rotation) override;

    // Additional methods
    XPT2046_Touchscreen& getTouchController() { return touch_controller; }
    bool isInitialized() const { return initialized; }
};

#endif // XPT2046_TOUCH_IMPL_H
