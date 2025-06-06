# ESP32-2432S028Rv3 "Cheap Yellow Display" Project

This project template is set up for the ESP32-2432S028Rv3 "Cheap Yellow Display" (CYD) board using PlatformIO and the esp32-smartdisplay library.

## Hardware

- **Board**: ESP32-2432S028Rv3 (Sunton)
- **Display**: 2.8" IPS LCD 240x320 pixels
- **Touch**: Resistive touch interface
- **Additional**: RGB LED, CdS light sensor

## Features

- ✅ LVGL 9.x GUI library integration
- ✅ Hardware-optimized display drivers
- ✅ Touch input support
- ✅ Adaptive brightness using CdS sensor
- ✅ RGB LED control
- ✅ Rotation support (0°, 90°, 180°, 270°)
- ✅ Performance monitoring (FPS, memory usage)

## Quick Start

1. **Clone this repository:**
   ```bash
   git clone --recurse-submodules https://github.com/GodSpoon/cyd-platformio
   cd cyd-platformio
   ```

2. **Open in PlatformIO:**
   - Launch VS Code with PlatformIO extension
   - Open this project folder
   - PlatformIO will automatically install dependencies

3. **Fix VS Code IntelliSense (Optional):**
   If you see false errors for `#include <Arduino.h>` or library includes:
   
   Add to `.vscode/settings.json`:
   ```json
   {
       "C_Cpp.intelliSenseEngine": "default",
       "C_Cpp.default.configurationProvider": "ms-vscode.vscode-platformio-ide",
       "platformio-ide.useBuiltinPIOCore": true
   }
   ```
   
   Then run in terminal:
   ```bash
   pio run --target compiledb
   ```
   
   Finally, use VS Code Command Palette (Ctrl+Shift+P):
   - `PlatformIO: Rebuild IntelliSense Index`
   - `C/C++: Reset IntelliSense Database`

4. **Build and Upload:**
   ```bash
   pio run -t upload
   ```

5. **Monitor Serial Output:**
   ```bash
   pio device monitor
   ```

## Project Structure

```
├── src/
│   └── main.cpp              # Main application code
├── include/
│   └── lv_conf.h             # LVGL configuration
├── boards/                   # Board definitions (git submodule)
├── platformio.ini            # PlatformIO configuration
└── README.md                 # This file
```

## Display Configuration

The display is configured for:
- **Resolution**: 240x320 pixels
- **Color Depth**: 16-bit (RGB565)
- **Orientation**: Portrait (default), rotatable
- **Backlight**: PWM controlled brightness

## Touch Configuration

- **Type**: Resistive touch
- **Calibration**: Automatic calibration supported
- **Rotation**: Follows display rotation

## LVGL Features Enabled

- Performance monitoring (FPS counter, memory usage)
- Default theme with light/dark mode support
- All standard widgets (buttons, labels, sliders, etc.)
- Flexible layout system (Flexbox, Grid)
- Logging for debugging

## Usage Examples

### Setting Display Brightness
```cpp
// Set brightness (0.0 = off, 1.0 = full)
smartdisplay_lcd_set_backlight(0.8);

// Enable adaptive brightness using CdS sensor
smartdisplay_lcd_set_brightness_cb(smartdisplay_lcd_adaptive_brightness_cds, 100);
```

### Display Rotation
```cpp
auto display = lv_display_get_default();
lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
```

### RGB LED Control
```cpp
smartdisplay_led_set_rgb(true, false, false);  // Red
smartdisplay_led_set_rgb(false, true, false);  // Green
smartdisplay_led_set_rgb(false, false, true);  // Blue
smartdisplay_led_set_rgb(true, true, true);    // White
```

### Creating LVGL Widgets
```cpp
// Create a button
lv_obj_t *btn = lv_btn_create(lv_screen_active());
lv_obj_set_size(btn, 120, 50);
lv_obj_center(btn);

// Add label to button
lv_obj_t *label = lv_label_create(btn);
lv_label_set_text(label, "Click me!");
lv_obj_center(label);
```

## Development Tools

### SquareLine Studio
For visual GUI design, you can use [SquareLine Studio](https://squareline.io/):
- Free for personal use
- Drag-and-drop UI designer
- Generates LVGL C code
- Supports animations and themes

### Debugging
Enable detailed logging by changing in `platformio.ini`:
```ini
build_flags =
    '-D CORE_DEBUG_LEVEL=ARDUHAL_LOG_LEVEL_DEBUG'
```

## Board Specifications

| Feature | Specification |
|---------|---------------|
| MCU | ESP32-WROOM-32 |
| Flash | 4MB |
| RAM | 520KB |
| Display | 2.8" IPS LCD 240x320 |
| Touch | Resistive |
| Interface | SPI |
| Power | 5V via USB or external |
| GPIO | Available pins broken out |

## Pin Mapping

| Function | GPIO Pin |
|----------|----------|
| LCD_CS | 15 |
| LCD_DC | 2 |
| LCD_RST | 4 |
| LCD_BL | 21 |
| TOUCH_CS | 33 |
| TOUCH_IRQ | 36 |
| LED_R | 4 |
| LED_G | 16 |
| LED_B | 17 |
| CDS | 34 |

## Troubleshooting

### Build Issues
1. Ensure board definitions are properly included as git submodule
2. Check that `lv_conf.h` path is correctly set in `platformio.ini`
3. Clean build if LVGL configuration changes: `pio run -t clean`

### Display Issues
1. Check power supply (5V recommended)
2. Verify board variant (Rv3 vs Rv2)
3. Try different rotation settings

### Touch Issues
1. Calibrate touch if needed
2. Check for proper touch driver initialization
3. Verify touch works with simple examples first

## References

- [esp32-smartdisplay Library](https://github.com/rzeldent/esp32-smartdisplay)
- [LVGL Documentation](https://docs.lvgl.io/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Sunton Boards Information](https://github.com/rzeldent/platformio-espressif32-sunton)

## License

This template project is provided as-is for educational and development purposes.
