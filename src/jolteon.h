#ifndef JOLTEON_H
#define JOLTEON_H

#include <Arduino.h>

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

// Performance monitoring functions
void jolteon_start_frame_timing(void);
void jolteon_end_frame_timing(void);
float jolteon_get_fps(void);

// Memory optimization functions
void jolteon_optimize_memory_early(void);

// Splash screen functions
void jolteon_display_splash_screen(void);

#endif
