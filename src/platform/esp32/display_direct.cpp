#include <TFT_eSPI.h>
#include <cstring>

class DisplayDirect {
    TFT_eSPI& tft;
    static constexpr int GB_W = 160;
    static constexpr int GB_H = 144;
    int x_offset, y_offset;
    
public:
    DisplayDirect(TFT_eSPI& t) : tft(t) {
        x_offset = (tft.width() - GB_W) / 2;
        y_offset = (tft.height() - GB_H) / 2;
    }
    
    void init() {
        tft.begin();
        tft.setRotation(1);
        tft.fillScreen(TFT_BLACK);
        
        // Draw border
        tft.drawRect(x_offset - 1, y_offset - 1, GB_W + 2, GB_H + 2, TFT_DARKGREY);
    }
    
    void drawFrame(const uint16_t* framebuffer) {
        // Direct push to display - no scaling
        tft.pushImage(x_offset, y_offset, GB_W, GB_H, framebuffer);
    }
    
    void clear() {
        tft.fillScreen(TFT_BLACK);
    }
};
