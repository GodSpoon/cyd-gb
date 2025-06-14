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
        , current_rotation(1) {  // Start with inverted landscape mode, then we'll use setRotation in init
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
        
        // Set a basic MADCTL value for initial setup - will be reconfigured after rotation
        uint8_t madctl = 0x00;
        Serial.printf("ST7789: Initial Memory Access Control Register (0x36) = 0x%02X\n", madctl);
        tft.writedata(madctl);
        delay(10);
        tft.writecommand(0x20); // Display inversion OFF - inverts the current color scheme
        delay(10);
        tft.writecommand(0x13); // Normal display mode
        delay(10);
        tft.writecommand(0x29); // Display on
        delay(150);
        
        Serial.println("ST7789 initialization completed");

        // Set rotation (landscape mode) - rotation 1 for inverted landscape (90° counter-clockwise)
        current_rotation = 1;
        tft.setRotation(current_rotation);
        Serial.printf("Display size after rotation: %dx%d\n", tft.width(), tft.height());
        
        // IMPORTANT: Apply mirroring settings AFTER rotation to prevent TFT_eSPI from overriding them
        Serial.println("Applying mirroring settings after rotation...");
        tft.writecommand(0x36); // Memory access control
        
        // Reconfigure memory access control after rotation
        uint8_t madctl_final = 0x00;
        
        // Start with the rotation 1 base value and modify it
        // Rotation 1 typically sets MADCTL to 0x60 (MV=1, MX=1, MY=0)
        // We need to adjust based on our mirroring requirements
#ifdef DISPLAY_MIRROR_X
        if (DISPLAY_MIRROR_X) {
            // For rotation 1, we want to DISABLE MX to correct the mirroring
            madctl_final = 0x20; // MV=1, MX=0, MY=0 - keeps rotation but fixes X mirroring
            Serial.println("ST7789: X-axis mirroring correction applied (MX=0 for rotation 1)");
        } else {
            madctl_final = 0x60; // MV=1, MX=1, MY=0 - standard rotation 1
            Serial.println("ST7789: Standard rotation 1 (MX=1)");
        }
#else
        madctl_final = 0x60; // Default rotation 1 value
        Serial.println("ST7789: DISPLAY_MIRROR_X not defined, using standard rotation 1");
#endif

#ifdef DISPLAY_MIRROR_Y
        if (DISPLAY_MIRROR_Y) {
            madctl_final ^= 0x80; // Toggle MY bit for vertical mirroring
            Serial.println("ST7789: Y-axis mirroring applied");
        }
#endif
        
        Serial.printf("ST7789: Final Memory Access Control Register (0x36) = 0x%02X\n", madctl_final);
        tft.writedata(madctl_final);
        delay(10);
        
        // Load and setup fonts for text rendering
        Serial.println("Setting up fonts for text rendering...");
        tft.setTextWrap(false); // Disable text wrapping
        
        // Try different font options to ensure compatibility
        Serial.println("Testing font compatibility...");
        tft.setTextFont(0);     // Use Adafruit GFX built-in font first
        tft.setTextSize(1);     // Start with size 1
        tft.setTextColor(TFT_WHITE, TFT_BLACK); // White text on black background
        tft.setTextDatum(TL_DATUM); // Top-left text alignment
        
        // Test if font 0 works
        tft.setCursor(10, 200);
        tft.print("Font 0 test");
        delay(200);
        
        // Try font 1 if available
        tft.setTextFont(1);
        tft.setCursor(10, 210);
        tft.print("Font 1 test");
        delay(200);
        
        Serial.println("Font setup completed");
        
        // Test font rendering immediately after font setup
        Serial.println("Testing font rendering with basic characters...");
        tft.setCursor(10, 100);
        tft.setTextSize(1);
        tft.setTextFont(1); // Use font 1 by default
        tft.print("Font Test: ABCDEFGHIJK");
        tft.setCursor(10, 120);
        tft.setTextSize(2);
        tft.print("Size 2 Text Test");
        delay(500); // Pause to see the font test
        
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
        tft.setTextSize(2);  // Reduced size for better visibility
        tft.setCursor(10, 10);
        tft.print("CYD Game Boy");
        tft.setCursor(10, 40);
        tft.print("Display Init OK");
        tft.setCursor(10, 70);
        tft.setTextColor(TFT_GREEN);
        tft.print("Text Rendering OK");
        Serial.println("TFT_Display: ST7789 initialization complete");
        
        delay(1000); // Reduced delay to 1 second
        
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
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.fillScreen(color);
    }
}

void TFTDisplay::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.drawPixel(x, y, color);
    }
}

void TFTDisplay::drawBuffer(const uint16_t* buffer, int16_t x, int16_t y, int16_t w, int16_t h) {
    if (pImpl && pImpl->is_initialized && buffer) {
        // TFT_eSPI uses pushImage for buffer drawing
        pImpl->tft.pushImage(x, y, w, h, buffer);
    }
}

void TFTDisplay::setCursor(int16_t x, int16_t y) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.setCursor(x, y);
        Serial.printf("TFT: Set cursor to (%d, %d)\n", x, y);
    }
}

void TFTDisplay::setTextColor(uint16_t color) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.setTextColor(color);
        Serial.printf("TFT: Set text color to 0x%04X\n", color);
    }
}

void TFTDisplay::setTextSize(uint8_t size) {
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.setTextSize(size);
        Serial.printf("TFT: Set text size to %d\n", size);
    }
}

void TFTDisplay::print(const char* text) {
    if (pImpl && pImpl->is_initialized && text) {
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
    if (pImpl && pImpl->is_initialized) {
        pImpl->tft.print(value);
    }
}

void TFTDisplay::print(float value, int decimals) {
    if (pImpl && pImpl->is_initialized) {
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

bool TFTDisplay::testDisplay() {
    if (!pImpl || !pImpl->is_initialized) {
        Serial.println("TFTDisplay::testDisplay - Display not initialized");
        return false;
    }
    
    Serial.println("TFTDisplay::testDisplay - Running comprehensive display test");
    
    // Test 1: Fill screen with colors
    pImpl->tft.fillScreen(TFT_RED);
    delay(200);
    pImpl->tft.fillScreen(TFT_GREEN);
    delay(200);
    pImpl->tft.fillScreen(TFT_BLUE);
    delay(200);
    pImpl->tft.fillScreen(TFT_BLACK);
    delay(200);
    
    // Test 2: Text rendering at different sizes
    pImpl->tft.setTextColor(TFT_WHITE);
    for (int size = 1; size <= 3; size++) {
        pImpl->tft.setTextSize(size);
        pImpl->tft.setCursor(10, 10 + (size-1) * 30);
        pImpl->tft.printf("Size %d Text Test", size);
    }
    
    delay(1000);
    
    // Test 3: Pixel drawing
    for (int i = 0; i < 100; i++) {
        pImpl->tft.drawPixel(random(pImpl->tft.width()), random(pImpl->tft.height()), TFT_WHITE);
    }
    
    delay(1000);
    pImpl->tft.fillScreen(TFT_BLACK);
    
    Serial.println("TFTDisplay::testDisplay - Test completed");
    return true;
}
