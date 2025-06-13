#ifndef JOLTEON_H
#define JOLTEON_H

// Include C++ headers outside of extern "C" block
#ifdef __cplusplus
#include <Arduino.h>
#include "core/framebuffer_manager.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/display_interface.h"
#include "hal/touch_interface.h"
#include "core/framebuffer_manager.h"

extern volatile bool sram_modified;
extern uint8_t btn_directions;
extern uint8_t btn_faces;

typedef uint16_t fbuffer_t;
extern uint16_t palette[];

void jolteon_update(ITouch& touch);
void jolteon_init(IDisplay& display, FramebufferManager& fbmgr);
void jolteon_set_display(IDisplay* display);
IDisplay* jolteon_get_display(void);
void jolteon_faint(IDisplay& display, const char* msg);
void jolteon_faint_global(const char* msg);  // Uses global display reference
fbuffer_t* jolteon_get_framebuffer(void);
void jolteon_clear_framebuffer(fbuffer_t col);
void jolteon_end_frame_with_display(IDisplay& display);
void jolteon_end_frame(void);  // Uses global display reference
void jolteon_clear_screen(IDisplay& display, uint16_t col);
void jolteon_set_palette(const uint32_t* col);
void jolteon_render_border(IDisplay& display, const uint8_t* img, uint32_t size);
void jolteon_save_sram(uint8_t* ram, uint32_t size);
void jolteon_load_sram(uint8_t* ram, uint32_t size);
const uint8_t* jolteon_load_rom(const char* path);
const uint8_t* jolteon_load_bootrom(const char* path);
void jolteon_start_frame_timing(void);
void jolteon_end_frame_timing(void);
float jolteon_get_fps(void);
void jolteon_optimize_memory_early(void);
void jolteon_display_splash_screen(IDisplay& display);
void jolteon_display_test_pattern(IDisplay& display);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// C++ declarations (outside extern "C")
namespace GameBoy {
    // Future: GameBoy-specific classes or types
}
namespace Platform {
    // Future: Platform-specific classes or types
}
#endif

#endif // JOLTEON_H
