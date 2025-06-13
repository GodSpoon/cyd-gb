#ifndef TOUCH_INTERFACE_H
#define TOUCH_INTERFACE_H

#include <cstdint>

struct TouchPoint {
    int16_t x;
    int16_t y;
    bool pressed;
};

class ITouch {
public:
    virtual ~ITouch() = default;
    virtual bool init() = 0;
    virtual bool touched() = 0;
    virtual TouchPoint getPoint() = 0;
    virtual void setRotation(uint8_t rotation) = 0;
};

#endif
