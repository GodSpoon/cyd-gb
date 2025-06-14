#ifndef HARDWARE_TFT_DISPLAY_H
#define HARDWARE_TFT_DISPLAY_H

#include "hal/display_interface.h"
#include <memory>
#include <cstdint>

/**
 * @brief TFT Display implementation using TFT_eSPI library
 * 
 * This class implements the IDisplay interface using the TFT_eSPI library
 * internally. It uses the pImpl (Pointer to Implementation) pattern to
 * hide the TFT_eSPI dependency from the header file, reducing compilation
 * dependencies and improving encapsulation.
 * 
 * Features:
 * - Hardware abstraction for TFT displays
 * - Automatic backlight management
 * - Rotation support
 * - Buffered drawing operations
 * - Text rendering with configurable size and color
 */
class TFTDisplay : public IDisplay {
private:
    // Forward declaration for pImpl pattern
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    /**
     * @brief Construct TFTDisplay with default configuration
     * 
     * Creates internal TFT_eSPI instance and sets up default parameters.
     * The actual hardware initialization happens in init().
     */
    TFTDisplay();

    /**
     * @brief Construct TFTDisplay with custom backlight pin
     * @param backlight_pin GPIO pin number for backlight control (default: 21)
     */
    explicit TFTDisplay(uint8_t backlight_pin);

    /**
     * @brief Destructor
     * 
     * Automatically cleans up internal TFT_eSPI instance and
     * turns off backlight if it was initialized.
     */
    ~TFTDisplay() override;

    // Move-only semantics (TFT_eSPI is not copyable)
    TFTDisplay(const TFTDisplay&) = delete;
    TFTDisplay& operator=(const TFTDisplay&) = delete;
    TFTDisplay(TFTDisplay&&) noexcept;
    TFTDisplay& operator=(TFTDisplay&&) noexcept;

    // IDisplay interface implementation
    
    /**
     * @brief Initialize the TFT display
     * @return true if initialization successful, false otherwise
     * 
     * Performs the following initialization steps:
     * 1. Initialize TFT_eSPI instance
     * 2. Set rotation to landscape flipped (3)
     * 3. Configure backlight PWM on specified pin
     * 4. Set backlight to full brightness
     * 5. Clear screen to black
     */
    bool init() override;

    /**
     * @brief Set display rotation
     * @param rotation Rotation value (0-3): 0=0°, 1=90°, 2=180°, 3=270°
     */
    void setRotation(uint8_t rotation) override;

    /**
     * @brief Fill entire screen with specified color
     * @param color 16-bit RGB565 color value
     */
    void fillScreen(uint16_t color) override;

    /**
     * @brief Draw a single pixel
     * @param x X coordinate
     * @param y Y coordinate
     * @param color 16-bit RGB565 color value
     */
    void drawPixel(int16_t x, int16_t y, uint16_t color) override;

    /**
     * @brief Draw a buffer of pixels to specified rectangle
     * @param buffer Pointer to 16-bit RGB565 color buffer
     * @param x X coordinate of top-left corner
     * @param y Y coordinate of top-left corner
     * @param w Width of the rectangle
     * @param h Height of the rectangle
     */
    void drawBuffer(const uint16_t* buffer, int16_t x, int16_t y, int16_t w, int16_t h) override;

    /**
     * @brief Set text cursor position
     * @param x X coordinate
     * @param y Y coordinate
     */
    void setCursor(int16_t x, int16_t y) override;

    /**
     * @brief Set text color
     * @param color 16-bit RGB565 color value
     */
    void setTextColor(uint16_t color) override;

    /**
     * @brief Set text size
     * @param size Text size multiplier (1-8)
     */
    void setTextSize(uint8_t size) override;

    /**
     * @brief Print text string
     * @param text Null-terminated string to print
     */
    void print(const char* text) override;

    /**
     * @brief Print integer value
     * @param value Integer value to print
     */
    void print(int value) override;

    /**
     * @brief Print floating-point value
     * @param value Float value to print
     * @param decimals Number of decimal places (default: 2)
     */
    void print(float value, int decimals = 2) override;

    /**
     * @brief Get display width in pixels
     * @return Width in pixels
     */
    int16_t width() const override;

    /**
     * @brief Get display height in pixels
     * @return Height in pixels
     */
    int16_t height() const override;

    // Additional TFT-specific methods (not in interface)
    
    /**
     * @brief Set backlight brightness
     * @param brightness Brightness level (0-255)
     */
    void setBacklight(uint8_t brightness);

    /**
     * @brief Get current backlight brightness
     * @return Current brightness level (0-255)
     */
    uint8_t getBacklight() const;

    /**
     * @brief Enable or disable display
     * @param enable true to enable, false to disable (turns off backlight)
     */
    void setEnabled(bool enable);

    /**
     * @brief Check if display is enabled
     * @return true if enabled, false if disabled
     */
    bool isEnabled() const;

    /**
     * @brief Clear screen to black
     * 
     * Convenience method equivalent to fillScreen(0x0000)
     */
    void clear();

    /**
     * @brief Get the underlying TFT_eSPI instance for advanced operations
     * @return Reference to internal TFT_eSPI instance
     * 
     * Note: This breaks encapsulation but may be needed for advanced
     * graphics operations not covered by the IDisplay interface.
     * Use sparingly and consider extending the interface instead.
     */
    void* getTFTInstance();
    
    /**
     * @brief Run comprehensive display test
     * @return true if test completed successfully, false otherwise
     * 
     * This method runs a series of tests to verify display functionality
     * including color fills, text rendering, and pixel drawing.
     */
    bool testDisplay();
};

#endif // HARDWARE_TFT_DISPLAY_H
