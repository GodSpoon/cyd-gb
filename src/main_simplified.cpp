#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <SD.h>
#include <SPI.h>

// Hardware pins (from board definition)
#define TOUCH_CS  33
#define TOUCH_IRQ 36
#define SD_CS     5

// Display constants
#define GB_WIDTH  160
#define GB_HEIGHT 144
#define SCALE     1  // No scaling to save memory

// Global hardware instances
TFT_eSPI tft;
XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

// Global emulator state
struct EmulatorState {
    uint16_t framebuffer[GB_WIDTH * GB_HEIGHT];  // 46KB
    uint8_t* rom_data = nullptr;
    size_t rom_size = 0;
    bool running = false;
    uint32_t frame_count = 0;
    float fps = 0.0f;
} emu;

// Function prototypes
bool initHardware();
bool loadROM(const char* path);
void runEmulator();
void showMenu();

void setup() {
    Serial.begin(115200);
    Serial.println("CYD Game Boy - Simplified Version");
    
    if (!initHardware()) {
        Serial.println("Hardware init failed!");
        while(1) delay(1000);
    }
    
    showMenu();
}

void loop() {
    if (emu.running) {
        runEmulator();
    } else {
        // Handle menu
        if (touch.touched()) {
            TS_Point p = touch.getPoint();
            // Simple touch handling for menu
            // ... menu logic ...
        }
    }
}

bool initHardware() {
    // Initialize display
    tft.begin();
    tft.setRotation(1);  // Landscape
    tft.fillScreen(TFT_BLACK);
    
    // Initialize touch
    touch.begin();
    touch.setRotation(1);
    
    // Initialize SD card
    if (!SD.begin(SD_CS)) {
        Serial.println("SD init failed!");
        return false;
    }
    
    Serial.println("Hardware initialized");
    return true;
}

bool loadROM(const char* path) {
    File file = SD.open(path);
    if (!file) return false;
    
    emu.rom_size = file.size();
    emu.rom_data = (uint8_t*)malloc(emu.rom_size);
    
    if (!emu.rom_data) {
        file.close();
        return false;
    }
    
    file.read(emu.rom_data, emu.rom_size);
    file.close();
    
    return true;
}

void runEmulator() {
    static uint32_t last_frame = 0;
    uint32_t now = millis();
    
    // Run one frame of emulation
    // gb_run_frame(emu.framebuffer);
    
    // Draw to display (centered)
    int x_offset = (tft.width() - GB_WIDTH) / 2;
    int y_offset = (tft.height() - GB_HEIGHT) / 2;
    tft.pushImage(x_offset, y_offset, GB_WIDTH, GB_HEIGHT, emu.framebuffer);
    
    // Calculate FPS
    emu.frame_count++;
    if (now - last_frame >= 1000) {
        emu.fps = emu.frame_count * 1000.0f / (now - last_frame);
        emu.frame_count = 0;
        last_frame = now;
        Serial.printf("FPS: %.1f\n", emu.fps);
    }
}

void showMenu() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    
    tft.setCursor(60, 20);
    tft.println("CYD Game Boy");
    
    tft.setTextSize(1);
    tft.setCursor(20, 60);
    
    // List ROM files
    File root = SD.open("/");
    int y = 80;
    while (File entry = root.openNextFile()) {
        if (!entry.isDirectory()) {
            String name = entry.name();
            if (name.endsWith(".gb")) {
                tft.setCursor(20, y);
                tft.println(name);
                y += 15;
            }
        }
        entry.close();
    }
    root.close();
}
