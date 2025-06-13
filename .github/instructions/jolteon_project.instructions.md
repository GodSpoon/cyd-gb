---
applyTo: 'docs/Espeon_reference.md'
---
This file is for reference documentation related to the Jolteon project development. It is the original Espeon gameboy emulator and should not be edited, only referenced.

---
applyTo: `**/src/*`
---
C++ Header Guidelines:
- When writing headers that declare C++ classes or use C++-specific features, always wrap all such code with `#ifdef __cplusplus ... #endif` to prevent C compilers from seeing C++ code.
- Only include C++-only headers from C++ source files.
- If a header must be included from both C and C++ code, use `extern "C"` guards for C linkage of C functions, and keep all C++-only code (such as class declarations, templates, or C++-specific includes) inside `#ifdef __cplusplus`.
- Never use `extern "C++"` in headers.
- Always ensure that C++ class declarations and C++-specific code are not visible to C compilers by using `#ifdef __cplusplus ... #endif` blocks.

---
applyTo: `**`
---
- PlatformIO Build and Upload Guidelines
Before performing any PlatformIO upload or monitoring operations, you MUST kill all active terminals and shells to prevent port conflicts and ensure clean device communication:

1. **Pre-Upload Terminal Cleanup**: 
   - Kill all running terminal sessions that might be accessing the ESP32 device
   - Use `pkill -f "platformio"` to kill any lingering PlatformIO processes
   - Use `pkill -f "pio"` to kill any PIO command processes
   - Use `pkill -f "monitor"` to kill any active serial monitor sessions
   - Use `lsof | grep ttyUSB` or `lsof | grep ttyACM` to check for processes using serial ports

2. **Device Port Management**:
   - Always disconnect any active serial monitors before uploading
   - Ensure no other applications (Arduino IDE, serial terminals, etc.) are connected to the device
   - Wait 2-3 seconds after killing processes before attempting upload/monitor operations

3. **Recommended Pre-Upload Command Sequence**:
   ```bash
   # Kill all relevant processes
   pkill -f "platformio" 2>/dev/null || true
   pkill -f "pio" 2>/dev/null || true  
   pkill -f "monitor" 2>/dev/null || true
   pkill -f "minicom" 2>/dev/null || true
   pkill -f "screen" 2>/dev/null || true
   
   # Wait for processes to terminate
   sleep 3
   
   # Now proceed with upload/monitor
   ```

4. **Error Prevention**:
   - If you encounter "Permission denied" or "Device busy" errors, always check for active terminal sessions first
   - Use `ps aux | grep -E "(pio|platformio|monitor)"` to identify active processes
   - Restart the development environment if persistent conflicts occur

---
applyTo: `**`
---
- Project Development Plan
When working on the cyd-gb emulator project, you must strictly follow the phased implementation plan. This document is the single source of truth for the project's development direction and technical specifications.

- Plan Location: The plan is located at the following absolute path: /home/sam/SPOON_GIT/cyd-gb/EMULATOR_IMPROVEMENT_PLAN.md

- Primary Objective: The plan outlines the required steps for performance optimization, feature implementation (such as SD card loading), and architectural improvements. Adhere to it closely to ensure project goals are met.