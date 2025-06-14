#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <SD.h>
#include <vector>
#include <string>

class SimpleMenu {
    TFT_eSPI& tft;
    XPT2046_Touchscreen& touch;
    
    struct MenuItem {
        std::string text;
        int16_t x, y, w, h;
    };
    
    std::vector<MenuItem> items;
    int selected = -1;
    
public:
    SimpleMenu(TFT_eSPI& t, XPT2046_Touchscreen& ts) : tft(t), touch(ts) {}
    
    void scanROMs() {
        items.clear();
        File root = SD.open("/");
        int y = 60;
        
        while (File entry = root.openNextFile()) {
            if (!entry.isDirectory()) {
                String name = entry.name();
                if (name.endsWith(".gb") || name.endsWith(".gbc")) {
                    items.push_back({name.c_str(), 20, y, 280, 20});
                    y += 25;
                    if (y > 200) break;  // Limit items shown
                }
            }
            entry.close();
        }
        root.close();
    }
    
    void draw() {
        tft.fillScreen(TFT_BLACK);
        
        // Title
        tft.setTextColor(TFT_CYAN);
        tft.setTextSize(3);
        tft.drawCentreString("Game Boy", 160, 10, 1);
        
        // ROM list
        tft.setTextSize(2);
        for (size_t i = 0; i < items.size(); i++) {
            const auto& item = items[i];
            uint16_t color = (i == selected) ? TFT_YELLOW : TFT_WHITE;
            tft.setTextColor(color);
            tft.drawString(item.text.c_str(), item.x, item.y, 1);
        }
        
        // Instructions
        tft.setTextColor(TFT_GREEN);
        tft.setTextSize(1);
        tft.drawCentreString("Touch to select ROM", 160, 220, 1);
    }
    
    int handleTouch() {
        if (!touch.touched()) return -1;
        
        TS_Point p = touch.getPoint();
        // Map to screen coordinates (landscape)
        int x = map(p.x, 200, 3900, 0, 320);
        int y = map(p.y, 200, 3900, 0, 240);
        
        // Check which item was touched
        for (size_t i = 0; i < items.size(); i++) {
            const auto& item = items[i];
            if (x >= item.x && x < item.x + item.w &&
                y >= item.y && y < item.y + item.h) {
                selected = i;
                draw();  // Redraw with selection
                delay(200);  // Visual feedback
                return i;
            }
        }
        return -1;
    }
    
    const std::string& getROM(int index) {
        return items[index].text;
    }
};
