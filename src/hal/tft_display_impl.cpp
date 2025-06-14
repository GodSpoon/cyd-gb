#include "hal/tft_display_impl.h"
#include <Arduino.h>

TFTDisplayImpl::TFTDisplayImpl(TFT_eSPI& display) : tft(display) {
}

bool TFTDisplayImpl::init() {
    if (initialized) return true;
    
    Serial.println("TFTDisplayImpl: Initializing TFT display...");
    
    // Basic TFT initialization
    tft.begin();
    tft.setRotation(3); // Default landscape flipped mode (180° rotated)
    tft.fillScreen(TFT_BLACK);
    
    // Test display functionality
    tft.drawPixel(width()/2, height()/2, TFT_WHITE);
    delay(100);
    tft.drawPixel(width()/2, height()/2, TFT_BLACK);
    
    initialized = true;
    Serial.println("TFTDisplayImpl: Initialization complete");
    return true;
}

void TFTDisplayImpl::setRotation(uint8_t rotation) {
    tft.setRotation(rotation);
}

void TFTDisplayImpl::fillScreen(uint16_t color) {
    tft.fillScreen(color);
}

void TFTDisplayImpl::drawPixel(int16_t x, int16_t y, uint16_t color) {
    tft.drawPixel(x, y, color);
}

void TFTDisplayImpl::drawBuffer(const uint16_t* buffer, int16_t x, int16_t y, int16_t w, int16_t h) {
    if (!buffer) return;
    tft.pushImage(x, y, w, h, (uint16_t*)buffer);
}

void TFTDisplayImpl::setCursor(int16_t x, int16_t y) {
    tft.setCursor(x, y);
}

void TFTDisplayImpl::setTextColor(uint16_t color) {
    tft.setTextColor(color);
}

void TFTDisplayImpl::setTextSize(uint8_t size) {
    tft.setTextSize(size);
}

void TFTDisplayImpl::print(const char* text) {
    if (text) {
        tft.print(text);
    }
}

void TFTDisplayImpl::print(int value) {
    tft.print(value);
}

void TFTDisplayImpl::print(float value, int decimals) {
    tft.print(value, decimals);
}

int16_t TFTDisplayImpl::width() const {
    return tft.width();
}

int16_t TFTDisplayImpl::height() const {
    return tft.height();
}
