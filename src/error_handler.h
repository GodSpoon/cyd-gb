#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <Arduino.h>
#include "hal/display_interface.h"
#include "core/result.h"  // For EmulatorError enum

class ErrorHandler {
private:
    static IDisplay* display;
    
public:
    static void init(IDisplay* display_interface);
    static void handle_error(EmulatorError error, const char* context = nullptr);
    static void display_error_screen(const char* title, const char* message, const char* suggestion = nullptr);
};

#endif
