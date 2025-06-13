#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <Arduino.h>
#include <TFT_eSPI.h>

enum class EmulatorError {
    SUCCESS,
    MEMORY_EXHAUSTED,
    ROM_LOAD_FAILED,
    SD_CARD_ERROR,
    DISPLAY_ERROR
};

class ErrorHandler {
private:
    static TFT_eSPI* display;
    
public:
    static void init(TFT_eSPI* tft);
    static void handle_error(EmulatorError error, const char* context = nullptr);
    static void display_error_screen(const char* title, const char* message, const char* suggestion = nullptr);
};

#endif
