# Game Boy Emulator ESP32 Enhancement Plan

This file details the phased implementation plan for improving the ESP32 Game Boy emulator project. Reference this plan before starting any related work. Each phase includes a mandatory audit and testing step to verify the implementation.

---

## Part 1: Rendering Performance and Visuals

### 1.1 Implement Double Buffering
- **Back Buffer:** In `display_manager.h`, declare a second framebuffer (the "back buffer") sized 160x144 (Game Boy screen). Allocate in PSRAM if available to conserve internal memory.
- **Render to Back Buffer:** Modify `lcd.cpp` and `cpu.cpp` to render each frame to this back buffer instead of directly to the display.
- **Atomic Frame Updates:** After a frame is fully rendered in the back buffer, use TFT_eSPI's `pushImage` function to push the entire buffer to the display in a single, high-speed operation.

#### 1.1.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions (like Guru Meditation Errors), or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

### 1.2 Use DMA for Display Updates
- **Enable DMA:** Ensure DMA is enabled in the TFT_eSPI library configuration. This can be set in `User_Setup.h` or defined in `platformio.ini` (e.g., `-D TFT_eSPI_DMA`).
- **Non-Blocking Transfers:** Utilize non-blocking DMA transfer capabilities when pushing the back buffer. This frees the CPU to continue with emulation tasks while the display data is being transferred.

#### 1.2.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

### 1.3 Optimize Core Affinity
- **Emulation Core:** Dedicate one CPU core (e.g., Core 1) exclusively to the emulation tasks (CPU and sound processing) using FreeRTOS's `xTaskCreatePinnedToCore`.
- **Rendering/System Core:** Assign the other core (e.g., Core 0) to handle rendering, Wi-Fi, Bluetooth, and other system-level tasks.

#### 1.3.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

---

## Part 2: Dynamic ROM Loading from Micro SD Card

### 2.1 Integrate SD Card Support
- **Add SD Library:** Ensure the `SD.h` library is included in the project and listed under `lib_deps` in `platformio.ini`.
- **Initialize SD Card:** Add logic to initialize the SD card at startup. This can be placed in `main.cpp` or a new, dedicated `sd_manager.cpp`.
- **Define SD Pins:** Confirm that the correct SPI pins for the SD card are defined in the appropriate board configuration file (e.g., `esp32-2432S028Rv3.json`).

#### 2.1.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

### 2.2 Implement ROM Loading Logic
- **Remove Hardcoded ROM:** Delete the `pokemon_red_rom.h` file and remove all references to it from the codebase (e.g., in `jolteon.cpp`).
- **ROM Loading Function:** Create a new function, `load_rom_from_sd(const char* filename)`, in `rom.cpp`.
- **File Scanning:** After SD card initialization, scan the root directory for files with a `.gb` extension using `SD.open("/")` and `openNextFile()`.
- **Load First ROM:** As an initial implementation, load the first `.gb` file found on the card.
- **Memory Allocation:** In `mem.cpp`, dynamically allocate a buffer in PSRAM to store the ROM data read from the SD card, replacing the static array.

#### 2.2.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

---

## Part 3: Core Emulation and Architectural Improvements

### 3.1 Refactor the Main Emulation Loop
- **Decouple Emulation/Rendering:** Separate the emulation loop (`cpu_emulate`) from the rendering loop. Use FreeRTOS queues to safely pass completed frame data between them.
- **Accurate Timing:** Synchronize the emulation speed to the Game Boy's original CPU clock (4.194304 MHz). This requires a precise, timer-based approach in `cpu.cpp`. Update `timer.cpp` to provide a stable timing source. The goal is to execute approximately 70,224 CPU cycles per frame to achieve a 59.7 fps target.

#### 3.1.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

### 3.2 Improve Code Organization
- **HAL Directory:** Create a `hal/` directory to abstract all hardware-specific code (display, SD card, touch input, etc.), improving portability.
- **Core vs. Platform:** Clearly separate the core emulation logic (`cpu`, `mem`, `lcd`, etc.) from the ESP32 platform-specific code.

#### 3.2.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

### 3.3 Add a Simple User Interface
- **ROM Selection Menu:** Once SD card loading is functional, implement a basic menu to list and select ROMs from the SD card. Use TFT_eSPI for drawing and the touch screen for input. The existing `menu.cpp` can be extended for this purpose.

#### 3.3.1 Audit and Test
- **Code Review:** Review the implemented code to confirm it integrates without causing compilation errors, breaking existing functionality, or introducing logical flaws.
- **Deploy and Monitor:** In VSCode, kill any active terminals. Build, upload, and monitor the application by running the following command in the shell:
  ```sh
  pio run -t upload && pio device monitor --baud 115200 --echo
  ```
- **Error Resolution:** If the monitor output displays any compilation errors, runtime exceptions, or other unexpected behavior, diagnose the root cause and apply a fix immediately. Repeat the Deploy and Monitor step until the feature is stable and error-free.

---
