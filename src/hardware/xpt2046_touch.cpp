#include "hardware/xpt2046_touch.h"
#include <XPT2046_Touchscreen.h>
#include <Arduino.h>
#include <memory>
#include "core/memory_utils.h"

// Default pin definitions
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
    uint8_t current_rotation = 3; // Default to landscape flipped (180° rotated)
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
        
        // First, map raw coordinates to base screen coordinates
        int mapped_x = map(raw_x, calibration.x_min, calibration.x_max, 0, screen.width);
        int mapped_y = map(raw_y, calibration.y_min, calibration.y_max, 0, screen.height);
        
        // Apply rotation transformation for landscape orientation
        switch (current_rotation) {
            case 0: // Portrait (0°)
                result.x = mapped_x;
                result.y = mapped_y;
                break;
                
            case 1: // Landscape (90° clockwise) - DEFAULT
                // For landscape, we need to rotate coordinates
                result.x = mapped_y;
                result.y = screen.height - mapped_x;
                break;
                
            case 2: // Portrait flipped (180°)
                result.x = screen.width - mapped_x;
                result.y = screen.height - mapped_y;
                break;
                
            case 3: // Landscape flipped (270° clockwise) with horizontal mirroring
                result.x = mapped_y;  // Adjusted for display horizontal mirroring (MX=1)
                result.y = mapped_x;
                break;
                
            default:
                // Default to landscape flipped rotation with horizontal mirroring
                result.x = mapped_y;  // Adjusted for display horizontal mirroring (MX=1)
                result.y = mapped_x;
                break;
        }
        
        // Constrain to screen bounds based on current rotation
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
        // Create touchscreen instance with specified pins
        touchscreen = make_unique<XPT2046_Touchscreen>(cs_pin, irq_pin);
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
        
        if (!touchscreen) {
            Serial.println("XPT2046Touch: Touchscreen object not created");
            return false;
        }
        
        // Initialize the touchscreen
        touchscreen->begin();
        
        // Set default rotation to landscape flipped (180° rotated)
        touchscreen->setRotation(current_rotation);
        
        initialized = true;
        Serial.println("XPT2046Touch: Initialization complete");
        return true;
    }
    
    /**
     * Check if screen is currently being touched
     */
    bool touched() {
        if (!initialized || !touchscreen) return false;
        
        // Apply debouncing if enabled
        if (!shouldProcessTouch()) {
            return false;
        }
        
        // Check if underlying library reports touch
        if (!touchscreen->touched()) {
            return false;
        }
        
        // Validate coordinates to filter out noise/invalid readings
        TS_Point raw = touchscreen->getPoint();
        return isValidTouch(raw.x, raw.y);
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
        
        // Check if screen is being touched
        if (!touchscreen->touched()) {
            return result;
        }
        
        // Get raw touch coordinates
        TS_Point raw = touchscreen->getPoint();
        
        // Validate touch coordinates
        if (!isValidTouch(raw.x, raw.y)) {
            // Coordinates are invalid (noise), return no-touch result silently
            return result;
        }
        
        // Update last touch time for debouncing
        last_touch_time = millis();
        
        // Transform coordinates with rotation
        result = transformCoordinates(raw.x, raw.y);
        
        // Debug logging for touch coordinates (uncomment if needed for debugging)
        // Serial.printf("XPT2046Touch: Raw(%d,%d) -> Screen(%d,%d) [rotation=%d]\n", 
        //              raw.x, raw.y, result.x, result.y, current_rotation);
        
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
