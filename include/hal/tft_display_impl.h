#ifndef TFT_DISPLAY_IMPL_H
#define TFT_DISPLAY_IMPL_H

#include "hal/display_interface.h"
#include <TFT_eSPI.h>

/**
 * Concrete implementation of IDisplay interface using TFT_eSPI library
 * This class wraps the TFT_eSPI functionality to conform to the HAL interface
 */
class TFTDisplayImpl : public IDisplay {
private:
    TFT_eSPI& tft;
    bool initialized = false;

public:
    explicit TFTDisplayImpl(TFT_eSPI& display);
    virtual ~TFTDisplayImpl() = default;

    // IDisplay interface implementation
    bool init() override;
    void setRotation(uint8_t rotation) override;
    void fillScreen(uint16_t color) override;
    void drawPixel(int16_t x, int16_t y, uint16_t color) override;
    void drawBuffer(const uint16_t* buffer, int16_t x, int16_t y, int16_t w, int16_t h) override;
    void setCursor(int16_t x, int16_t y) override;
    void setTextColor(uint16_t color) override;
    void setTextSize(uint8_t size) override;
    void print(const char* text) override;
    void print(int value) override;
    void print(float value, int decimals = 2) override;
    int16_t width() const override;
    int16_t height() const override;

    // Additional methods for advanced features
    TFT_eSPI& getDisplay() { return tft; }
    bool isInitialized() const { return initialized; }
};

#endif // TFT_DISPLAY_IMPL_H
