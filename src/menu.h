#ifndef MENU_H
#define MENU_H

typedef enum {
    MENU_RESULT_CONTINUE,
    MENU_RESULT_START_GAME,
    MENU_RESULT_EXIT
} menu_result_t;

void menu_init();
void draw_menu(); // Added for manual menu drawing
void touch_calibration_test(); // Added for touch debugging
menu_result_t menu_loop();
const char* menu_get_rompath();

#endif
