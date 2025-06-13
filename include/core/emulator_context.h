#ifndef CORE_EMULATOR_CONTEXT_H
#define CORE_EMULATOR_CONTEXT_H

#include "core/result.h"
#include "hal/display_interface.h"
#include "hal/touch_interface.h"
#include "hal/storage_interface.h"
#include "core/framebuffer_manager.h"
#include <memory>
#include <cstdint>

/**
 * EmulatorContext - Main application class that owns hardware dependencies
 * and manages the emulator state machine.
 * 
 * This class serves as the central coordinator for the Game Boy emulator,
 * managing all hardware abstractions through dependency injection and 
 * implementing a clean state machine pattern for application flow control.
 * 
 * Features:
 * - Dependency injection for all hardware interfaces
 * - State machine for emulator lifecycle management
 * - RAII-based resource management
 * - Result<void> return type for comprehensive error handling
 * - Separation of concerns between hardware and business logic
 */

/**
 * EmulatorState enum defines the possible states of the emulator
 */
enum class EmulatorState : uint8_t {
    UNINITIALIZED,  // Initial state, hardware not initialized
    SPLASH,         // Showing splash screen
    MENU,           // ROM selection menu
    RUNNING_ROM,    // Game Boy emulator running a ROM
    ERROR           // Error state requiring user intervention
};

class EmulatorContext {
private:
    // Hardware dependencies (injected via constructor)
    std::unique_ptr<IDisplay> display_;
    std::unique_ptr<ITouch> touch_;
    std::unique_ptr<IStorage> storage_;
    
    // Game Boy framebuffer for LCD output
    std::unique_ptr<FramebufferManager> framebuffer_manager_;
    
    // State machine
    EmulatorState current_state_;
    EmulatorError last_error_;
    
    // Internal state management
    bool initialized_;
    unsigned long state_start_time_;
    
    // State machine implementation methods
    Result<void> runSplash();
    Result<void> runMenu();
    Result<void> runEmulator();
    Result<void> handleError();
    
    // Helper methods
    void transitionToState(EmulatorState new_state);
    const char* stateToString(EmulatorState state) const;
    void logStateTransition(EmulatorState from, EmulatorState to);

public:
    /**
     * Constructor with dependency injection
     * @param display Display hardware abstraction (must not be null)
     * @param touch Touch input hardware abstraction (must not be null)
     * @param storage Storage hardware abstraction (must not be null)
     */
    EmulatorContext(
        std::unique_ptr<IDisplay> display,
        std::unique_ptr<ITouch> touch,
        std::unique_ptr<IStorage> storage
    );
    
    /**
     * Destructor - ensures proper cleanup
     */
    virtual ~EmulatorContext() = default;
    
    // Disable copy semantics (move-only class)
    EmulatorContext(const EmulatorContext&) = delete;
    EmulatorContext& operator=(const EmulatorContext&) = delete;
    
    // Enable move semantics
    EmulatorContext(EmulatorContext&&) = default;
    EmulatorContext& operator=(EmulatorContext&&) = default;
    
    /**
     * Initialize all hardware components
     * Calls init() on all hardware interfaces and validates they're working
     * @return Result<void> indicating success or specific error
     */
    Result<void> initialize();
    
    /**
     * Main execution loop - implements the state machine
     * This method should be called continuously from main loop
     * @return Result<void> indicating success or error requiring handling
     */
    Result<void> run();
    
    // State query methods
    EmulatorState getCurrentState() const { return current_state_; }
    bool isInitialized() const { return initialized_; }
    EmulatorError getLastError() const { return last_error_; }
    unsigned long getStateUptime() const;
    
    // Hardware access (for testing/debugging)
    IDisplay* getDisplay() const { return display_.get(); }
    ITouch* getTouch() const { return touch_.get(); }
    IStorage* getStorage() const { return storage_.get(); }
    
    // Manual state transitions (for testing)
    void forceState(EmulatorState state) { transitionToState(state); }
};

#endif // CORE_EMULATOR_CONTEXT_H
