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
- Project Development Plan
When working on the cyd-gb emulator project, you must strictly follow the phased implementation plan. This document is the single source of truth for the project's development direction and technical specifications.

- Plan Location: The plan is located at the following absolute path: /home/sam/SPOON_GIT/cyd-gb/EMULATOR_IMPROVEMENT_PLAN.md

- Primary Objective: The plan outlines the required steps for performance optimization, feature implementation (such as SD card loading), and architectural improvements. Adhere to it closely to ensure project goals are met.