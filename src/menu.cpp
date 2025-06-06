#include <Arduino.h>
#include "menu.h"

static const char* rompath_c = nullptr;

void menu_init(void)
{
    Serial.println("Menu initialized (simplified for CYD)");
}

void menu_loop(void)
{
    // Simplified menu - just return immediately
    Serial.println("Menu loop (auto-selecting Pokemon Red)");
}

const char* menu_get_rompath(void)
{
    // Return NULL to use the compiled-in ROM
    return nullptr;
}
