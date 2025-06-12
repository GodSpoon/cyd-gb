---
applyTo: 'docs/Espeon_reference.md'
---
This file is for reference documentation related to the Jolteon project development. It is the original Espeon gameboy emulator and should not be edited, only referenced.

---
C++ Header Guidelines:
- When writing headers that declare C++ classes, always wrap class declarations and C++-specific includes with `#ifdef __cplusplus ... #endif` to prevent C compilers from seeing C++ code.
- Only include C++-only headers from C++ source files.
- If a header must be included from both C and C++ code, use `extern "C"` guards for C linkage, and keep C++-only code inside `#ifdef __cplusplus`.
---
