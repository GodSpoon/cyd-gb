#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hal/display_interface.h"
#include "hal/touch_interface.h"

typedef enum {
    MENU_RESULT_CONTINUE,
    MENU_RESULT_START_GAME,
    MENU_RESULT_EXIT
} menu_result_t;

void menu_init(IDisplay& display, ITouch& touch);
menu_result_t menu_update(IDisplay& display, ITouch& touch);
const char* menu_get_rompath();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace Platform {
    class Menu;
}
#endif

#endif // MENU_H
