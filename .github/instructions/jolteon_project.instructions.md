---
applyTo: 'docs/Espeon_reference.md'
---
This file is for reference documentation related to the Jolteon project development. It is the original Espeon gameboy emulator and should not be edited, only referenced.

---
C++ Header Guidelines:
- When writing headers that declare C++ classes or use C++-specific features, always wrap all such code with `#ifdef __cplusplus ... #endif` to prevent C compilers from seeing C++ code.
- Only include C++-only headers from C++ source files.
- If a header must be included from both C and C++ code, use `extern "C"` guards for C linkage of C functions, and keep all C++-only code (such as class declarations, templates, or C++-specific includes) inside `#ifdef __cplusplus`.
- Never use `extern "C++"` in headers.
- Always ensure that C++ class declarations and C++-specific code are not visible to C compilers by using `#ifdef __cplusplus ... #endif` blocks.
---
