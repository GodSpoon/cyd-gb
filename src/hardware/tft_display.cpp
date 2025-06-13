#include "hardware/tft_display.h"
#include <TFT_eSPI.h>
#include <Arduino.h>
#include <memory>
#include "core/memory_utils.h"

// PWM configuration for backlight
#define BACKLIGHT_PWM_CHANNEL 0
#define BACKLIGHT_PWM_FREQ 5000
#define BACKLIGHT_PWM_RESOLUTION 8

/**
 * @brief Implementation class for TFTDisplay (pImpl pattern)
 * 
 * This class contains the actual TFT_eSPI instance and all implementation
 * details, keeping them hidden from the header file to reduce dependencies.
 */
class TFTDisplay::Impl {
public:
    TFT_eSPI tft;
    uint8_t backlight_pin;
    uint8_t current_brightness;
    bool is_initialized;
    bool is_enabled;
    uint8_t current_rotation;

    explicit Impl(uint8_t bl_pin) 
        : backlight_pin(bl_pin)
        , current_brightness(255)
        , is_initialized(false)
        , is_enabled(false)
        , current_rotation(1) {
    }

    bool init() {
        if (is_initialized) {
            return true;
        }

        // Initialize TFT
        tft.init();

        // Set default rotation to landscape
        tft.setRotation(current_rotation);

        // Configure backlight PWM
        if (backlight_pin != 255) {  // 255 = no backlight pin
            ledcSetup(BACKLIGHT_PWM_CHANNEL, BACKLIGHT_PWM_FREQ, BACKLIGHT_PWM_RESOLUTION);
            ledcAttachPin(backlight_pin, BACKLIGHT_PWM_CHANNEL);
            
            // Set full brightness
            setBacklight(current_brightness);
        }

        // Clear screen to black
        tft.fillScreen(TFT_BLACK);

        is_initialized = true;
        is_enabled = true;

        return true;
    }

    void setBacklight(uint8_t brightness) {
        current_brightness = brightness;
        if (is_initialized && backlight_pin != 255) {
            ledcWrite(BACKLIGHT_PWM_CHANNEL, brightness);
        }
    }

    void setEnabled(bool enable) {
        is_enabled = enable;
        if (is_initialized) {
            if (enable) {
                setBacklight(current_brightness);
            } else {
                setBacklight(0);  // Turn off backlight
            }
        }
    }
};

// TFTDisplay implementation

TFTDisplay::TFTDisplay() : TFTDisplay(21) {
    // Default backlight pin is 21 (common for ESP32 CYD boards)
}

TFTDisplay::TFTDisplay(uint8_t backlight_pin) 
    : pImpl(make_unique<Impl>(backlight_pin)) {
}

TFTDisplay::~TFTDisplay() {
    if (pImpl && pImpl->is_initialized) {
        // Turn off backlight before destruction
        pImpl->setEnabled(false);
    }
}

// Move semantics
TFTDisplay::TFTDisplay(TFTDisplay&&) noexcept = default;
TFTDisplay& TFTDisplay::operator=(TFTDisplay&&) noexcept = default;

bool TFTDisplay::init() {
    if (!pImpl) {
        return false;
    }
    return pImpl->init();
}

void TFTDisplay::setRotation(uint8_t rotation) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->current_rotation = rotation;
        pImpl->tft.setRotation(rotation);
    }
}

void TFTDisplay::fillScreen(uint16_t color) {
    if (pImpl && pImpl->is_initialized && pImpl->is_enabled) {
        pImpl->tft.fillScreen(color);
    }
}

void TFTDisplay::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if (pImpl && pImpl->is_initialized && pImpl->is_enabled) {
        pImpl->tft.drawPixel(x, y, color);
    }
}

void TFTDisplay::drawBuffer(const uint16_t* buffer, int16_t x, int16_t y, int16_t w, int16_t h) {
    if (pImpl && pImpl->is_initialized && pImpl->is_enabled && buffer) {
        // TFT_eSPI uses pushImage for buffer drawing
        pImpl->tft.pushImage(x, y, w, h, buffer);
    }
}

void TFTDisplay::setCursor(int16_t x, int16_t y) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.setCursor(x, y);
    }
}

void TFTDisplay::setTextColor(uint16_t color) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.setTextColor(color);
    }
}

void TFTDisplay::setTextSize(uint8_t size) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.setTextSize(size);
    }
}

void TFTDisplay::print(const char* text) {
    if (pImpl && pImpl->is_initialized && pImpl->is_enabled && text) {
        pImpl->tft.print(text);
    }
}

void TFTDisplay::print(int value) {
    if (pImpl && pImpl->is_initialized && pImpl->is_enabled) {
        pImpl->tft.print(value);
    }
}

void TFTDisplay::print(float value, int decimals) {
    if (pImpl && pImpl->is_initialized && pImpl->is_enabled) {
        pImpl->tft.print(value, decimals);
    }
}

int16_t TFTDisplay::width() const {
    if (pImpl && pImpl->is_initialized) {
        return pImpl->tft.width();
    }
    return 0;
}

int16_t TFTDisplay::height() const {
    if (pImpl && pImpl->is_initialized) {
        return pImpl->tft.height();
    }
    return 0;
}

// Additional TFT-specific methods

void TFTDisplay::setBacklight(uint8_t brightness) {
    if (pImpl) {
        pImpl->setBacklight(brightness);
    }
}

uint8_t TFTDisplay::getBacklight() const {
    if (pImpl) {
        return pImpl->current_brightness;
    }
    return 0;
}

void TFTDisplay::setEnabled(bool enable) {
    if (pImpl) {
        pImpl->setEnabled(enable);
    }
}

bool TFTDisplay::isEnabled() const {
    if (pImpl) {
        return pImpl->is_enabled;
    }
    return false;
}

void TFTDisplay::clear() {
    fillScreen(0x0000);  // Black in RGB565
}

void* TFTDisplay::getTFTInstance() {
    if (pImpl && pImpl->is_initialized) {
        return &(pImpl->tft);
    }
    return nullptr;
}
