# Jolteon ESP32_2432S028Rv3 Firmware

## Migration: LVGL → ILI9341_t3_Menu

This project has migrated from LVGL to [ILI9341_t3_Menu](https://github.com/duff2013/ILI9341_t3_Menu) for UI rendering on the ESP32_2432S028Rv3 board.

### Key Changes
- **LVGL removed**: All LVGL code, configuration, and dependencies have been removed.
- **ILI9341_t3_Menu added**: UI is now rendered using ILI9341_t3_Menu, with ILI9341_t3 for display and XPT2046_Touch for touch input.
- **PlatformIO config updated**: All build flags and dependencies now target ILI9341_t3_Menu and the correct hardware pinout for ESP32_2432S028Rv3.
- **Hardware pinout**: See `boards/esp32-2432S028Rv3.json` for display, touch, SD, RGB LED, and speaker pin assignments.

### Features Implemented
- **Splash Screen**: Enhanced display with correct RGB565 color format, buffered rendering, and loading progress indication
- **Image Processing**: Smart memory allocation (PSRAM → RAM → direct rendering fallback) for smooth display

### Next Steps
- Implement menu/pages using ILI9341_t3_Menu in `src/jolteon.cpp` and `src/main.cpp`.
- Use the [ILI9341_t3_Menu examples](https://github.com/duff2013/ILI9341_t3_Menu/tree/master/examples) as a reference for menu structure and event handling.
- Test all hardware features: display, touch, SD, LEDs, speaker.

### Development Notes
- **RGB565 Byte Order**: For TFT_eSPI displays, ensure RGB565 data uses little-endian byte order. See `boards/README.md` for technical details.
- **Image Conversion**: Use `convert_splash.py` for generating display-compatible image headers.

### References
- [ILI9341_t3_Menu](https://github.com/duff2013/ILI9341_t3_Menu)
- [ILI9341_t3](https://github.com/PaulStoffregen/ILI9341_t3)
- [XPT2046_Touch](https://github.com/greiman/XPT2046_Touch)
- [CYD Board Definitions](boards/README.md) - Technical specifications and display best practices

---

For migration details, see `.github/instructions/rework.instructions.md`.
