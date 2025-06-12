#ifndef MENU_H
#define MENU_H

typedef enum {
    MENU_RESULT_CONTINUE,
    MENU_RESULT_START_GAME,
    MENU_RESULT_EXIT
} menu_result_t;

void menu_init();
menu_result_t menu_loop();
// menu_get_rompath returns the selected ROM file path from SD card
const char* menu_get_rompath();

#endif
