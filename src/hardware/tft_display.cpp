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
        , current_rotation(0) {  // Try rotation 0 for portrait mode, then we'll use setRotation in init
    }

    bool init() {
        if (is_initialized) {
            Serial.println("TFTDisplay::Impl::init() - already initialized");
            return true;
        }

        Serial.println("TFTDisplay::Impl::init() - starting initialization...");
        
        // Initialize TFT with ST7789 specific sequence
        Serial.println("Calling tft.begin()...");
        tft.begin();
        Serial.println("tft.begin() completed");
        
        Serial.println("Calling tft.init()...");
        tft.init();
        Serial.println("tft.init() completed");

        // ST7789 specific initialization with explicit commands
        Serial.println("Applying ST7789 specific initialization...");
        delay(150);
        
        // Apply ST7789 specific initialization sequence
        tft.writecommand(0x01); // Software reset
        delay(150);
        tft.writecommand(0x11); // Sleep out
        delay(150);
        tft.writecommand(0x3A); // Set color mode
        tft.writedata(0x55);     // 16-bit RGB565
        delay(10);
        tft.writecommand(0x36); // Memory access control
        tft.writedata(0x08);    // MY=0, MX=1, MV=0 - mirror X-axis to fix orientation
        delay(10);
        tft.writecommand(0x20); // Display inversion OFF (try this instead of 0x21)
        delay(10);
        tft.writecommand(0x13); // Normal display mode
        delay(10);
        tft.writecommand(0x29); // Display on
        delay(150);
        
        Serial.println("ST7789 initialization completed");

        // Set rotation (landscape mode) - rotation 1 for landscape
        current_rotation = 1;
        tft.setRotation(current_rotation);
        Serial.printf("Display size after rotation: %dx%d\n", tft.width(), tft.height());
        
        // Configure backlight PWM
        if (backlight_pin != 255) {  // 255 = no backlight pin
            Serial.printf("Setting up backlight on pin %d...\n", backlight_pin);
            ledcSetup(BACKLIGHT_PWM_CHANNEL, BACKLIGHT_PWM_FREQ, BACKLIGHT_PWM_RESOLUTION);
            ledcAttachPin(backlight_pin, BACKLIGHT_PWM_CHANNEL);
            
            // Set full brightness immediately
            setBacklight(current_brightness);
            Serial.printf("Backlight set to brightness %d\n", current_brightness);
            
            // Test backlight control explicitly
            Serial.println("Testing backlight control...");
            for (int i = 0; i < 3; i++) {
                ledcWrite(BACKLIGHT_PWM_CHANNEL, 0);    // Off
                delay(200);
                ledcWrite(BACKLIGHT_PWM_CHANNEL, 255);  // Full brightness
                delay(200);
            }
            Serial.println("Backlight test completed - should have seen blinking");
        } else {
            Serial.println("No backlight pin configured");
        }

        // Quick test to verify display content and color format
        Serial.println("Testing display content visibility...");
        
        // Test basic colors
        Serial.println("Red test");
        tft.fillScreen(0xF800);  // Should be RED now with BGR fix
        delay(1000);
        
        Serial.println("Green test");
        tft.fillScreen(0x07E0);  // Should be GREEN
        delay(1000);
        
        Serial.println("Blue test");
        tft.fillScreen(0x001F);  // Should be BLUE now with BGR fix
        delay(1000);
        
        // Test text rendering capability  
        Serial.println("Testing basic text rendering...");
        tft.fillScreen(TFT_BLACK);
        tft.setTextColor(TFT_WHITE);
        tft.setTextSize(3);
        tft.setCursor(10, 10);
        tft.print("CYD Game Boy");
        tft.setCursor(10, 50);
        tft.print("Test Menu Text");
        tft.setCursor(10, 90);
        tft.print("Display OK!");
        Serial.println("TFT_Display: ST7789 initialization complete");
        
        delay(3000); // Let's see the test text for 3 seconds
        
        is_initialized = true;
        is_enabled = true;
        
        Serial.println("TFTDisplay::Impl::init() - initialization complete!");
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
        Serial.printf("TFT: Printing '%s'\n", text);
        pImpl->tft.print(text);
    } else {
        Serial.printf("TFT: Failed to print '%s' - init:%s enabled:%s\n", 
                     text ? text : "NULL",
                     (pImpl && pImpl->is_initialized) ? "Y" : "N",
                     (pImpl && pImpl->is_enabled) ? "Y" : "N");
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
