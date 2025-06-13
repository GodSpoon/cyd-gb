#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#include <cstdint>

class IDisplay {
public:
    virtual ~IDisplay() = default;
    virtual bool init() = 0;
    virtual void setRotation(uint8_t rotation) = 0;
    virtual void fillScreen(uint16_t color) = 0;
    virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;
    virtual void drawBuffer(const uint16_t* buffer, int16_t x, int16_t y, int16_t w, int16_t h) = 0;
    virtual void setCursor(int16_t x, int16_t y) = 0;
    virtual void setTextColor(uint16_t color) = 0;
    virtual void setTextSize(uint8_t size) = 0;
    virtual void print(const char* text) = 0;
    virtual void print(int value) = 0;
    virtual void print(float value, int decimals = 2) = 0;
    virtual int16_t width() const = 0;
    virtual int16_t height() const = 0;
};

#endif
