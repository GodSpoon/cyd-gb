#ifndef TOUCH_MANAGER_H
#define TOUCH_MANAGER_H

#ifdef __cplusplus
#include <XPT2046_Touchscreen.h>
#include <Arduino.h>

class TouchManager {
private:
    XPT2046_Touchscreen& touch;
    unsigned long last_touch_time = 0;
    static constexpr unsigned long DEBOUNCE_MS = 250;
    static constexpr int RAW_X_MIN = 200;
    static constexpr int RAW_X_MAX = 3900;
    static constexpr int RAW_Y_MIN = 200;
    static constexpr int RAW_Y_MAX = 3900;

public:
    struct TouchPoint {
        int x, y;
        bool valid;
        unsigned long timestamp;
    };

    TouchManager(XPT2046_Touchscreen& ts) : touch(ts) {}

    TouchPoint get_touch() {
        unsigned long now = millis();
        if (now - last_touch_time < DEBOUNCE_MS) {
            return {0, 0, false, now};
        }
        if (!touch.touched()) {
            return {0, 0, false, now};
        }
        TS_Point raw = touch.getPoint();
        if (raw.x < RAW_X_MIN || raw.x > RAW_X_MAX || 
            raw.y < RAW_Y_MIN || raw.y > RAW_Y_MAX) {
            return {0, 0, false, now};
        }
        last_touch_time = now;
        int screen_x = map(raw.x, RAW_X_MIN, RAW_X_MAX, 0, 320);
        int screen_y = map(raw.y, RAW_Y_MIN, RAW_Y_MAX, 0, 240);
        return {
            constrain(screen_x, 0, 319),
            constrain(screen_y, 0, 239),
            true,
            now
        };
    }
};

#endif // __cplusplus

#endif // TOUCH_MANAGER_H
