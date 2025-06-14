#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <TFT_eSPI.h>

namespace Platform {
    class Display;
}

class DisplayManager {
private:
    TFT_eSPI& tft;
    bool initialized = false;
    
    // Display constants
    static const int GAMEBOY_WIDTH = 160;
    static const int GAMEBOY_HEIGHT = 144;
    static const int CYD_WIDTH = 320;
    static const int CYD_HEIGHT = 240;
    
    // Center the Game Boy screen on the display
    static const int CENTER_X = (CYD_WIDTH - GAMEBOY_WIDTH) / 2;
    static const int CENTER_Y = (CYD_HEIGHT - GAMEBOY_HEIGHT) / 2;
    
    // Add pointer for back buffer (double buffering)
    uint16_t* back_buffer = nullptr;
    bool back_buffer_allocated = false;
    bool dma_enabled = false;
    volatile bool dma_busy = false;
    
public:
    DisplayManager(TFT_eSPI& display);
    
    bool init();
    
    // Double buffering methods
    bool allocate_back_buffer();
    void deallocate_back_buffer();
    uint16_t* get_back_buffer() { return back_buffer; }
    void swap_buffers(); // Atomic frame update
    
    // DMA management
    bool is_dma_busy() const { return dma_busy; }
    void wait_for_dma();
    bool try_swap_buffers(); // Non-blocking version
    
    // Single, reliable rendering method
    // Uses DMA for non-blocking display updates
    void render_gameboy_frame(const uint16_t* pixels);
    
    void clear_screen();
    void draw_gameboy_border();
    void display_debug_info(float fps, uint32_t free_heap);
    void display_error(const char* message);
    void display_test_pattern();
    
    // Getters for constants
    int get_gameboy_width() const { return GAMEBOY_WIDTH; }
    int get_gameboy_height() const { return GAMEBOY_HEIGHT; }
    int get_center_x() const { return CENTER_X; }
    int get_center_y() const { return CENTER_Y; }
    
    // Set the back buffer pointer
    void set_back_buffer(uint16_t* buffer) { back_buffer = buffer; }
    
    // Destructor to clean up
    ~DisplayManager();
};

#endif // DISPLAY_MANAGER_H
