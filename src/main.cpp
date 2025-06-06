#include <Arduino.h>
#include <esp32_smartdisplay.h>

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32-2432S028R CYD Starting...");
    
    Serial.println("Initializing smart display...");
    // Initialize the smart display
    smartdisplay_init();
    Serial.println("Smart display initialized.");
    
    // Set display brightness (0.0 to 1.0)
    smartdisplay_lcd_set_backlight(0.8);
    Serial.println("Backlight set to 80%");
    
    // Optional: Set display rotation
    auto display = lv_display_get_default();
    // lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
    // lv_display_set_rotation(display, LV_DISPLAY_ROTATION_180);
    // lv_display_set_rotation(display, LV_DISPLAY_ROTATION_270);
    
    // Optional: Enable adaptive brightness using CdS sensor
    // smartdisplay_lcd_set_brightness_cb(smartdisplay_lcd_adaptive_brightness_cds, 100);
    
    // Set a dark background to ensure text contrast
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_make(0x00, 0x00, 0x40), 0); // Dark blue background
    Serial.println("Background color set.");
    
    // Create multiple labels with different fonts to test text rendering
    Serial.println("Creating labels...");
    
    // Title label with larger font
    lv_obj_t *title_label = lv_label_create(lv_screen_active());
    lv_label_set_text(title_label, "CYD Display Test");
    // Try to set font, fallback to default if font is null
    const lv_font_t* title_font = &lv_font_montserrat_18;
    if (title_font != NULL) {
        lv_obj_set_style_text_font(title_label, title_font, 0);
        Serial.println("Title label created with Montserrat 18");
    } else {
        Serial.println("Montserrat 18 font not available, using default");
    }
    lv_obj_set_style_text_color(title_label, lv_color_white(), 0);
    lv_obj_set_pos(title_label, 10, 10);
    
    // Main content label
    lv_obj_t *main_label = lv_label_create(lv_screen_active());
    lv_label_set_text(main_label, "Hello CYD!\nESP32-2432S028Rv3\nText Rendering Test");
    const lv_font_t* main_font = &lv_font_montserrat_16;
    if (main_font != NULL) {
        lv_obj_set_style_text_font(main_label, main_font, 0);
        Serial.println("Main label created with Montserrat 16");
    } else {
        Serial.println("Montserrat 16 font not available, using default");
    }
    lv_obj_set_style_text_color(main_label, lv_color_white(), 0);
    lv_obj_set_pos(main_label, 10, 60);
    
    // Status label with smaller font
    lv_obj_t *status_label = lv_label_create(lv_screen_active());
    lv_label_set_text(status_label, "Status: Running");
    lv_obj_set_style_text_font(status_label, &lv_font_montserrat_12, 0);
    lv_obj_set_style_text_color(status_label, lv_color_make(0x00, 0xFF, 0x00), 0); // Green color
    lv_obj_set_pos(status_label, 10, 150);
    
    // Test special characters
    lv_obj_t *special_label = lv_label_create(lv_screen_active());
    lv_label_set_text(special_label, "Special: !@#$%^&*()_+{}|:<>?");
    lv_obj_set_style_text_font(special_label, &lv_font_montserrat_10, 0);
    lv_obj_set_style_text_color(special_label, lv_color_make(0xFF, 0xFF, 0x00), 0); // Yellow color
    lv_obj_set_pos(special_label, 10, 180);
    
    // Test with default font to see if issue is font-specific
    lv_obj_t *default_label = lv_label_create(lv_screen_active());
    lv_label_set_text(default_label, "Default Font Test");
    // Using default font (no font set)
    lv_obj_set_style_text_color(default_label, lv_color_make(0xFF, 0x00, 0xFF), 0); // Magenta color
    lv_obj_set_pos(default_label, 10, 210);
    Serial.println("All labels created successfully!");
    
    Serial.println("Setup complete!");
}

void loop() {
    // Update LVGL tick and handle UI updates
    static auto lv_last_tick = millis();
    static unsigned long last_debug = 0;
    
    auto const now = millis();
    lv_tick_inc(now - lv_last_tick);
    lv_last_tick = now;
    
    // Update the UI
    lv_timer_handler();
    
    // Print debug info every 5 seconds
    if (now - last_debug > 5000) {
        Serial.print("Free heap: ");
        Serial.print(ESP.getFreeHeap());
        Serial.println(" bytes");
        last_debug = now;
    }
    
    // Small delay to prevent watchdog issues
    delay(5);
}
