#pragma once
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus

class FramebufferManager {
public:
    static constexpr int FB_WIDTH = 160;
    static constexpr int FB_HEIGHT = 144;
    static constexpr size_t FB_SIZE = FB_WIDTH * FB_HEIGHT * sizeof(uint16_t);

    FramebufferManager();
    bool init();
    uint16_t* get_back_buffer();
    const uint16_t* get_front_buffer() const;
    void swap_buffers();
    bool is_ready() const;
    void mark_displayed();
    void create_test_pattern(); // For testing the display pipeline

private:
    uint16_t* front_buffer;
    uint16_t* back_buffer;
    bool buffer_ready;
};

#endif
