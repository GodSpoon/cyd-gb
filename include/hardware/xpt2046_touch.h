#ifndef XPT2046_TOUCH_H
#define XPT2046_TOUCH_H

#include "hal/touch_interface.h"
#include <cstdint>
#include <memory>

// Forward declaration for pImpl pattern
class XPT2046_Touchscreen;

/**
 * XPT2046Touch class implementing ITouch interface using pImpl pattern
 * 
 * This class provides a hardware-specific implementation of touch operations
 * using the XPT2046_Touchscreen library with the pImpl (Pointer to Implementation)
 * design pattern for better encapsulation and compilation efficiency.
 * 
 * Features:
 * - pImpl pattern for better encapsulation
 * - Automatic touchscreen initialization with specified pins
 * - Coordinate transformation for landscape rotation using map() function
 * - Rotation state management
 * - Debouncing and touch validation
 * - Configurable calibration constants
 * 
 * Hardware Configuration:
 * - TOUCH_CS = 33 (Chip Select)
 * - TOUCH_IRQ = 36 (Interrupt)
 */
class XPT2046Touch : public ITouch {
private:
    // pImpl pattern - forward declaration of implementation
    class Impl;
    std::unique_ptr<Impl> pImpl;
    
public:
    /**
     * Constructor with default pin configuration
     * Uses TOUCH_CS=33, TOUCH_IRQ=36 as specified
     */
    XPT2046Touch();
    
    /**
     * Constructor with custom pin configuration
     * @param cs_pin Chip Select pin
     * @param irq_pin Interrupt pin
     */
    XPT2046Touch(uint8_t cs_pin, uint8_t irq_pin);
    
    /**
     * Destructor - required for pImpl pattern
     */
    virtual ~XPT2046Touch();
    
    // Disable copy operations for pImpl safety
    XPT2046Touch(const XPT2046Touch&) = delete;
    XPT2046Touch& operator=(const XPT2046Touch&) = delete;
    
    // Enable move operations
    XPT2046Touch(XPT2046Touch&& other) noexcept;
    XPT2046Touch& operator=(XPT2046Touch&& other) noexcept;
    
    // ITouch interface implementation
    bool init() override;
    bool touched() override;
    TouchPoint getPoint() override;
    void setRotation(uint8_t rotation) override;
    
    // Additional utility methods
    bool isInitialized() const;
    uint8_t getCurrentRotation() const;
    
    /**
     * Set custom calibration values for coordinate mapping
     * @param x_min Minimum raw X value
     * @param x_max Maximum raw X value
     * @param y_min Minimum raw Y value
     * @param y_max Maximum raw Y value
     */
    void setCalibration(int x_min, int x_max, int y_min, int y_max);
    
    /**
     * Set screen dimensions for coordinate transformation
     * @param width Screen width in pixels
     * @param height Screen height in pixels
     */
    void setScreenSize(int width, int height);
    
    /**
     * Enable or disable touch debouncing
     * @param enable True to enable debouncing
     * @param debounce_ms Debounce time in milliseconds
     */
    void setDebouncing(bool enable, unsigned long debounce_ms = 250);
};

#endif // XPT2046_TOUCH_H
