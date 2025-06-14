#include "hardware/xpt2046_touch.h"
#include <XPT2046_Touchscreen.h>
#include <SPI.h>
#include <Arduino.h>
#include <memory>
#include "core/memory_utils.h"
static constexpr uint8_t DEFAULT_TOUCH_CS = 33;
static constexpr uint8_t DEFAULT_TOUCH_IRQ = 36;

// Default calibration constants for CYD boards
static constexpr int DEFAULT_RAW_X_MIN = 200;
static constexpr int DEFAULT_RAW_X_MAX = 3900;
static constexpr int DEFAULT_RAW_Y_MIN = 200;
static constexpr int DEFAULT_RAW_Y_MAX = 3900;

// Default screen dimensions
static constexpr int DEFAULT_SCREEN_WIDTH = 320;
static constexpr int DEFAULT_SCREEN_HEIGHT = 240;

// Default debounce settings
static constexpr unsigned long DEFAULT_DEBOUNCE_MS = 250;

/**
 * pImpl implementation class
 * Contains all the private implementation details
 */
class XPT2046Touch::Impl {
private:
    std::unique_ptr<XPT2046_Touchscreen> touchscreen;
    uint8_t cs_pin;
    uint8_t irq_pin;
    bool initialized = false;
    uint8_t current_rotation = 1; // Default to inverted landscape (90° counter-clockwise rotation)
    unsigned long last_touch_time = 0;
    
    // Calibration settings
    struct Calibration {
        int x_min = DEFAULT_RAW_X_MIN;
        int x_max = DEFAULT_RAW_X_MAX;
        int y_min = DEFAULT_RAW_Y_MIN;
        int y_max = DEFAULT_RAW_Y_MAX;
    } calibration;
    
    // Screen settings
    struct Screen {
        int width = DEFAULT_SCREEN_WIDTH;
        int height = DEFAULT_SCREEN_HEIGHT;
    } screen;
    
    // Debounce settings
    struct Debounce {
        bool enabled = true;
        unsigned long delay_ms = DEFAULT_DEBOUNCE_MS;
    } debounce;
    
    /**
     * Transform raw touch coordinates to screen coordinates with rotation
     * @param raw_x Raw X coordinate from touchscreen
     * @param raw_y Raw Y coordinate from touchscreen
     * @return Transformed TouchPoint with screen coordinates
     */
    TouchPoint transformCoordinates(int raw_x, int raw_y) const {
        TouchPoint result = {0, 0, true};
        
        // Map raw coordinates to screen coordinates
        int mapped_x = map(raw_x, calibration.x_min, calibration.x_max, 0, screen.width - 1);
        int mapped_y = map(raw_y, calibration.y_min, calibration.y_max, 0, screen.height - 1);
        
        switch (current_rotation) {
            case 0: // Portrait
                result.x = mapped_x;
                result.y = mapped_y;
                break;
            case 1: // Landscape 90°
                result.x = screen.height - 1 - mapped_y;
                result.y = mapped_x;
                break;
            case 2: // Portrait 180°
                result.x = screen.width - 1 - mapped_x;
                result.y = screen.height - 1 - mapped_y;
                break;
            case 3: // Landscape 270°
                result.x = mapped_y;
                result.y = screen.width - 1 - mapped_x;
                break;
            default:
                result.x = mapped_x;
                result.y = mapped_y;
                break;
        }
        
        // Determine max coordinates based on rotation
        int max_x = (current_rotation == 1 || current_rotation == 3) ? screen.height : screen.width;
        int max_y = (current_rotation == 1 || current_rotation == 3) ? screen.width : screen.height;
        
        result.x = constrain(result.x, 0, max_x - 1);
        result.y = constrain(result.y, 0, max_y - 1);
        
        return result;
    }
    
    /**
     * Validate if raw touch coordinates are within expected range
     * @param raw_x Raw X coordinate
     * @param raw_y Raw Y coordinate
     * @return True if coordinates are valid
     */
    bool isValidTouch(int raw_x, int raw_y) const {
        return (raw_x >= calibration.x_min && raw_x <= calibration.x_max &&
                raw_y >= calibration.y_min && raw_y <= calibration.y_max);
    }
    
    /**
     * Check if enough time has passed since last touch (debouncing)
     * @return True if touch should be processed
     */
    bool shouldProcessTouch() const {
        if (!debounce.enabled) return true;
        
        unsigned long now = millis();
        return (now - last_touch_time >= debounce.delay_ms);
    }
    
public:
    /**
     * Constructor with pin configuration
     */
    Impl(uint8_t cs, uint8_t irq) : cs_pin(cs), irq_pin(irq) {
        // Don't create the touchscreen object here - defer to init()
        // This prevents hardware access during constructor
        Serial.printf("XPT2046Touch::Impl constructor with CS=%d, IRQ=%d\n", cs, irq);
    }
    
    /**
     * Initialize the touchscreen hardware
     */
    bool init() {
        if (initialized) {
            Serial.println("XPT2046Touch: Already initialized");
            return true;
        }
        
        Serial.printf("XPT2046Touch: Initializing with CS=%d, IRQ=%d\n", cs_pin, irq_pin);
        
        // Create touchscreen instance now (not in constructor)
        Serial.println("XPT2046Touch: Creating XPT2046_Touchscreen object...");
        touchscreen = make_unique<XPT2046_Touchscreen>(cs_pin, irq_pin);
        
        if (!touchscreen) {
            Serial.println("XPT2046Touch: Failed to create touchscreen object");
            return false;
        }
        
        // Initialize SPI for touch controller
        // NOTE: We do NOT call SPI.begin() here because:
        // 1. The SD card initialization configures SPI with its own pins first
        // 2. The XPT2046_Touchscreen library will use the default SPI instance 
        // 3. Both peripherals need to share the same SPI bus but with different CS pins
        // 4. The SD card pins (MOSI=23, MISO=19, SCLK=18) are compatible with touch
        Serial.println("XPT2046Touch: Using existing SPI configuration from SD card");
        
        // Initialize the touchscreen
        Serial.println("XPT2046Touch: Calling touchscreen->begin()...");
        try {
            touchscreen->begin();
            Serial.println("XPT2046Touch: touchscreen->begin() completed");
        } catch (...) {
            Serial.println("XPT2046Touch: Exception in touchscreen->begin()");
            return false;
        }
        
        // Set default rotation to inverted landscape (90° counter-clockwise)
        touchscreen->setRotation(current_rotation);
        
        initialized = true;
        Serial.println("XPT2046Touch: Initialization complete");
        
        // Test if touch controller is responding
        Serial.println("XPT2046Touch: Testing touch controller response...");
        bool test_touch = touchscreen->touched();
        Serial.printf("XPT2046Touch: Initial touch state: %s\n", test_touch ? "touched" : "not touched");
        
        return true;
    }
    
    /**
     * Check if screen is currently being touched
     */
    bool touched() {
        if (!initialized || !touchscreen) {
            Serial.println("XPT2046Touch: touched() called but not initialized or touchscreen is null");
            return false;
        }
        
        // Apply debouncing if enabled - TEMPORARILY DISABLED FOR DEBUGGING
        // if (!shouldProcessTouch()) {
        //     // Serial.println("XPT2046Touch: touched() - debouncing blocked");
        //     return false;
        // }
        
        // Temporarily reconfigure SPI for touch controller pins
        SPI.end();
        SPI.begin(25, 39, 32);  // Touch controller pins: SCLK, MISO, MOSI
        
        // Check if underlying library reports touch
        bool lib_touched = touchscreen->touched();
        
        // Restore SPI for SD card pins
        SPI.end();
        SPI.begin(18, 19, 23);  // SD card pins: SCLK, MISO, MOSI
        
        if (!lib_touched) {
            // Only log occasionally to reduce spam
            static unsigned long last_no_touch_log = 0;
            if (millis() - last_no_touch_log > 5000) {
                Serial.println("XPT2046Touch: No touch detected");
                last_no_touch_log = millis();
            }
            return false;
        }

        Serial.println("XPT2046Touch: Touch detected - validating coordinates");
        return true;
    }
    
    /**
     * Get current touch point with coordinate transformation
     */
    TouchPoint getPoint() {
        TouchPoint result = {0, 0, false};
        
        if (!initialized || !touchscreen) {
            return result;
        }
        
        // Check if we should process this touch (debouncing)
        if (!shouldProcessTouch()) {
            return result;
        }
        
        // Temporarily reconfigure SPI for touch controller pins
        SPI.end();
        SPI.begin(25, 39, 32);  // Touch controller pins: SCLK, MISO, MOSI
        
        // Check if screen is being touched
        bool is_touched = touchscreen->touched();
        if (!is_touched) {
            // Restore SPI for SD card pins before returning
            SPI.end();
            SPI.begin(18, 19, 23);  // SD card pins: SCLK, MISO, MOSI
            return result;
        }
        
        // Get raw touch coordinates
        TS_Point raw = touchscreen->getPoint();
        
        // Restore SPI for SD card pins
        SPI.end();
        SPI.begin(18, 19, 23);  // SD card pins: SCLK, MISO, MOSI
        
        // Validate touch coordinates
        if (!isValidTouch(raw.x, raw.y)) {
            Serial.printf("XPT2046Touch: Invalid coordinates (%d, %d) - rejecting\n", raw.x, raw.y);
            return result;
        }
        
        // Update last touch time for debouncing
        last_touch_time = millis();
        
        // Transform coordinates with rotation
        result = transformCoordinates(raw.x, raw.y);
        
        // Debug logging for touch coordinates (enabled for debugging)
        Serial.printf("XPT2046Touch: Raw(%d,%d) -> Screen(%d,%d) [rotation=%d]\n", 
                      raw.x, raw.y, result.x, result.y, current_rotation);
        
        return result;
    }
    
    /**
     * Set screen rotation
     */
    void setRotation(uint8_t rotation) {
        current_rotation = rotation % 4; // Ensure valid rotation (0-3)
        
        if (initialized && touchscreen) {
            touchscreen->setRotation(current_rotation);
        }
        
        Serial.printf("XPT2046Touch: Rotation set to %d\n", current_rotation);
    }
    
    /**
     * Check if touchscreen is initialized
     */
    bool isInitialized() const {
        return initialized;
    }
    
    /**
     * Get current rotation setting
     */
    uint8_t getCurrentRotation() const {
        return current_rotation;
    }
    
    /**
     * Set calibration values
     */
    void setCalibration(int x_min, int x_max, int y_min, int y_max) {
        calibration.x_min = x_min;
        calibration.x_max = x_max;
        calibration.y_min = y_min;
        calibration.y_max = y_max;
        
        Serial.printf("XPT2046Touch: Calibration set - X:[%d,%d] Y:[%d,%d]\n", 
                     x_min, x_max, y_min, y_max);
    }
    
    /**
     * Set screen dimensions
     */
    void setScreenSize(int width, int height) {
        screen.width = width;
        screen.height = height;
        
        Serial.printf("XPT2046Touch: Screen size set to %dx%d\n", width, height);
    }
    
    /**
     * Configure debouncing
     */
    void setDebouncing(bool enable, unsigned long debounce_ms) {
        debounce.enabled = enable;
        debounce.delay_ms = debounce_ms;
        
        Serial.printf("XPT2046Touch: Debouncing %s (delay=%lu ms)\n", 
                     enable ? "enabled" : "disabled", debounce_ms);
    }
};

// XPT2046Touch public interface implementation

XPT2046Touch::XPT2046Touch() 
    : pImpl(make_unique<Impl>(DEFAULT_TOUCH_CS, DEFAULT_TOUCH_IRQ)) {
}

XPT2046Touch::XPT2046Touch(uint8_t cs_pin, uint8_t irq_pin) 
    : pImpl(make_unique<Impl>(cs_pin, irq_pin)) {
}

XPT2046Touch::~XPT2046Touch() = default;

XPT2046Touch::XPT2046Touch(XPT2046Touch&& other) noexcept 
    : pImpl(std::move(other.pImpl)) {
}

XPT2046Touch& XPT2046Touch::operator=(XPT2046Touch&& other) noexcept {
    if (this != &other) {
        pImpl = std::move(other.pImpl);
    }
    return *this;
}

bool XPT2046Touch::init() {
    return pImpl ? pImpl->init() : false;
}

bool XPT2046Touch::touched() {
    return pImpl ? pImpl->touched() : false;
}

TouchPoint XPT2046Touch::getPoint() {
    return pImpl ? pImpl->getPoint() : TouchPoint{0, 0, false};
}

void XPT2046Touch::setRotation(uint8_t rotation) {
    if (pImpl) {
        pImpl->setRotation(rotation);
    }
}

bool XPT2046Touch::isInitialized() const {
    return pImpl ? pImpl->isInitialized() : false;
}

uint8_t XPT2046Touch::getCurrentRotation() const {
    return pImpl ? pImpl->getCurrentRotation() : 0;
}

void XPT2046Touch::setCalibration(int x_min, int x_max, int y_min, int y_max) {
    if (pImpl) {
        pImpl->setCalibration(x_min, x_max, y_min, y_max);
    }
}

void XPT2046Touch::setScreenSize(int width, int height) {
    if (pImpl) {
        pImpl->setScreenSize(width, height);
    }
}

void XPT2046Touch::setDebouncing(bool enable, unsigned long debounce_ms) {
    if (pImpl) {
        pImpl->setDebouncing(enable, debounce_ms);
    }
}
