#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MENU_RESULT_CONTINUE,
    MENU_RESULT_START_GAME,
    MENU_RESULT_EXIT
} menu_result_t;

void menu_init();
menu_result_t menu_loop();
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
