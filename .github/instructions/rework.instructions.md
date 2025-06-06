---
applyTo: '!docs/**,!boards/**,**'
---
# Migration Steps: LVGL → ILI9341_t3_Menu for Jolteon on ESP32_2432S028Rv3

## Goal
- Replace all LVGL UI code with ILI9341_t3_Menu.
- Remove LVGL from the project.
- Ensure full functionality on ESP32_2432S028Rv3.

---

## Step-by-Step Instructions for AI

### 1. Remove LVGL UI

- Find all files with `#include "lvgl.h"` or `lv_` function calls.
- Delete or comment out LVGL UI code (`lv_menu_*`, `lv_obj_*`, `lv_label_*`, etc).
- Remove LVGL-specific configuration, initialization, and drivers.

---

### 2. Add ILI9341_t3_Menu

- Add the ILI9341_t3_Menu library to the project.
- Initialize `ILI9341_t3` display in `setup()` using ESP32_2432S028Rv3 pinout.
- Initialize touch (XPT2046) with correct pins.
- Replace old menu/pages with ILI9341_t3_Menu objects and logic.
- Recreate menu structure and event handlers using ILI9341_t3_Menu API.

---

### 3. Update PlatformIO Build

- Remove LVGL from `platformio.ini` dependencies.
- Remove all LVGL-related `extra_flags`.
- Add any required flags for ILI9341_t3_Menu or new touch/display libraries.
- Ensure all pin definitions match the ESP32_2432S028Rv3 board.

---

### 4. Port Hardware Code

- Review and update all pin numbers for: display, touch, SD card, RGB LEDs, speaker, etc.
- Replace any remaining LVGL-specific hardware code with Arduino/ESP32-compatible libraries.

---

### 5. Test and Optimize

- Build and flash the firmware on the target board.
- Verify display, touch, SD, LEDs, and speaker all work.
- Optimize UI for RAM usage and performance (ILI9341_t3_Menu is lighter than LVGL).

---

## Notes

- Use ILI9341_t3_Menu examples as a reference for menu structure.
- Focus on functionality first; UI refinements can follow.
- Document all changes in code comments and README.
