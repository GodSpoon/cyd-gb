#pragma once
#include <Arduino.h>

class PerformanceMonitor {
    uint32_t frame_count = 0;
    uint32_t last_fps_time = 0;
    uint32_t frame_start = 0;
    float current_fps = 0.0f;
    float frame_time = 0.0f;
    
public:
    void beginFrame() {
        frame_start = micros();
    }
    
    void endFrame() {
        frame_time = (micros() - frame_start) / 1000.0f;
        frame_count++;
        
        uint32_t now = millis();
        if (now - last_fps_time >= 1000) {
            current_fps = frame_count * 1000.0f / (now - last_fps_time);
            frame_count = 0;
            last_fps_time = now;
        }
    }
    
    float getFPS() const { return current_fps; }
    float getFrameTime() const { return frame_time; }
    
    void draw(TFT_eSPI& tft, int x, int y) {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setTextSize(1);
        tft.setCursor(x, y);
        tft.printf("FPS: %.1f (%.1fms)", current_fps, frame_time);
    }
};
