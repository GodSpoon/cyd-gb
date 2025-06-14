#ifndef LCD_H
#define LCD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Forward declaration for C++ classes
#ifdef __cplusplus
class FramebufferManager;
#endif

bool lcd_init(void);
void lcd_cycle(uint32_t);
void lcd_reset(void);
uint8_t lcd_get_line(void);
uint8_t lcd_get_stat();
void lcd_write_control(uint8_t);
void lcd_write_stat(uint8_t);
void lcd_write_scroll_x(uint8_t);
void lcd_write_scroll_y(uint8_t);
void lcd_write_bg_palette(uint8_t);
void lcd_write_spr_palette1(uint8_t);
void lcd_write_spr_palette2(uint8_t);
void lcd_set_window_y(uint8_t);
void lcd_set_window_x(uint8_t);
void lcd_set_ly_compare(uint8_t);

// Dependency injection for framebuffer manager
#ifdef __cplusplus
void lcd_set_framebuffer_manager(FramebufferManager* fbmgr);
#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace GameBoy {
    class LCD;
}
#endif

#endif // LCD_H
