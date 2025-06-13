#ifndef JOLTEON_H
#define JOLTEON_H

// Include C++ headers outside of extern "C" block
#ifdef __cplusplus
#include <Arduino.h>
#include "display_manager.h"
#include "core/framebuffer_manager.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern volatile bool sram_modified;
extern uint8_t btn_directions;
extern uint8_t btn_faces;

typedef uint16_t fbuffer_t;
extern uint16_t palette[];

void jolteon_update(void);
void jolteon_init(void);
void jolteon_faint(const char* msg);
fbuffer_t* jolteon_get_framebuffer(void);
void jolteon_clear_framebuffer(fbuffer_t col);
void jolteon_end_frame(void);
void jolteon_clear_screen(uint16_t col);
void jolteon_set_palette(const uint32_t* col);
void jolteon_render_border(const uint8_t* img, uint32_t size);
void jolteon_save_sram(uint8_t* ram, uint32_t size);
void jolteon_load_sram(uint8_t* ram, uint32_t size);
const uint8_t* jolteon_load_rom(const char* path);
const uint8_t* jolteon_load_bootrom(const char* path);
void jolteon_start_frame_timing(void);
void jolteon_end_frame_timing(void);
float jolteon_get_fps(void);
void jolteon_optimize_memory_early(void);
void jolteon_display_splash_screen(void);
void jolteon_display_test_pattern(void);

// Display manager access
DisplayManager* get_display_manager(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// C++ declarations (outside extern "C")
extern FramebufferManager framebuffer_manager;
namespace GameBoy {
    // Future: GameBoy-specific classes or types
}
namespace Platform {
    // Future: Platform-specific classes or types
}
#endif

#endif // JOLTEON_H
