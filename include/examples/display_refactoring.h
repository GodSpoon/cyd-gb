#ifndef EXAMPLES_DISPLAY_REFACTORING_H
#define EXAMPLES_DISPLAY_REFACTORING_H

#include "hal/display_interface.h"
#include "hardware/tft_display.h"
#include <memory>

/**
 * @brief Example showing the transformation from global TFT usage to dependency injection
 * 
 * This file demonstrates the refactoring pattern:
 * 
 * BEFORE (Global usage):
 * ```cpp
 * extern TFT_eSPI tft;
 * 
 * void someFunction() {
 *     tft.fillScreen(TFT_BLACK);
 *     tft.setTextColor(TFT_WHITE);
 *     tft.print("Hello World");
 * }
 * ```
 * 
 * AFTER (Dependency injection):
 * ```cpp
 * class GameComponent {
 *     IDisplay& display;
 * public:
 *     GameComponent(IDisplay& d) : display(d) {}
 *     void render() { 
 *         display.fillScreen(0x0000);  // Black
 *         display.setTextColor(0xFFFF); // White
 *         display.print("Hello World");
 *     }
 * };
 * ```
 */

// Example game component using dependency injection
class GameComponent {
private:
    IDisplay& display;

public:
    /**
     * @brief Constructor takes display interface dependency
     * @param d Reference to display implementation
     */
    explicit GameComponent(IDisplay& d) : display(d) {}

    /**
     * @brief Render game content using injected display
     */
    void render() {
        // Clear screen to black
        display.fillScreen(0x0000);
        
        // Set white text
        display.setTextColor(0xFFFF);
        display.setTextSize(2);
        
        // Draw some game UI
        display.setCursor(10, 10);
        display.print("Game Boy Emulator");
        
        display.setCursor(10, 40);
        display.print("FPS: ");
        display.print(60);
        
        // Draw a simple border
        for (int i = 0; i < display.width(); i++) {
            display.drawPixel(i, 0, 0xFFFF);
            display.drawPixel(i, display.height() - 1, 0xFFFF);
        }
        for (int i = 0; i < display.height(); i++) {
            display.drawPixel(0, i, 0xFFFF);
            display.drawPixel(display.width() - 1, i, 0xFFFF);
        }
    }

    /**
     * @brief Update game state and render
     */
    void update() {
        // Game logic here...
        render();
    }
};

// Example menu system using dependency injection
class MenuSystem {
private:
    IDisplay& display;
    int selected_item;
    const char* menu_items[4] = {
        "Load ROM",
        "Settings",
        "About",
        "Exit"
    };

public:
    explicit MenuSystem(IDisplay& d) : display(d), selected_item(0) {}

    void render() {
        display.fillScreen(0x0000);  // Black background
        
        display.setTextSize(2);
        display.setTextColor(0xFFFF);  // White title
        display.setCursor(10, 10);
        display.print("Main Menu");
        
        // Draw menu items
        for (int i = 0; i < 4; i++) {
            display.setCursor(20, 50 + i * 30);
            
            if (i == selected_item) {
                display.setTextColor(0xFFE0);  // Yellow for selected
                display.print("> ");
            } else {
                display.setTextColor(0xFFFF);  // White for normal
                display.print("  ");
            }
            
            display.print(menu_items[i]);
        }
    }

    void selectNext() {
        selected_item = (selected_item + 1) % 4;
        render();
    }

    void selectPrevious() {
        selected_item = (selected_item - 1 + 4) % 4;
        render();
    }
};

// Factory function to create display instance
std::unique_ptr<IDisplay> createDisplay() {
    auto display = std::make_unique<TFTDisplay>(21);  // Backlight pin 21
    if (!display->init()) {
        return nullptr;  // Failed to initialize
    }
    return display;
}

// Example usage in main application
class Application {
private:
    std::unique_ptr<IDisplay> display;
    std::unique_ptr<GameComponent> game;
    std::unique_ptr<MenuSystem> menu;
    bool in_game;

public:
    bool init() {
        // Create display instance
        display = createDisplay();
        if (!display) {
            return false;
        }

        // Create components with dependency injection
        game = std::make_unique<GameComponent>(*display);
        menu = std::make_unique<MenuSystem>(*display);
        
        in_game = false;
        return true;
    }

    void run() {
        while (true) {
            if (in_game) {
                game->update();
            } else {
                menu->render();
            }
            
            // Handle input, state changes, etc.
            delay(16);  // ~60 FPS
        }
    }

    void switchToGame() {
        in_game = true;
    }

    void switchToMenu() {
        in_game = false;
    }
};

#endif // EXAMPLES_DISPLAY_REFACTORING_H
