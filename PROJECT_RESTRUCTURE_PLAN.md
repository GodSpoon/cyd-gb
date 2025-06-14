# CYD Game Boy Emulator - Project Restructuring Plan

## Current Issues
1. Mixed C/C++ code without clear separation
2. Complex dependency injection that could be simplified
3. Memory management issues with limited ESP32 RAM
4. Overly complex display/touch abstractions
5. Poor separation between emulator core and platform code
6. Menu system needs complete rewrite

## New Architecture

### Directory Structure
cyd-gb/
├── src/
│   ├── main.cpp              # Entry point
│   ├── core/                 # Core emulator engine
│   │   ├── gb_cpu.cpp       # Game Boy CPU emulation
│   │   ├── gb_ppu.cpp       # PPU (LCD controller)
│   │   ├── gb_apu.cpp       # APU (sound - stub for now)
│   │   ├── gb_mmu.cpp       # Memory management unit
│   │   ├── gb_timer.cpp     # Timer/divider
│   │   └── gb_cart.cpp      # Cartridge/MBC handling
│   ├── ui/
│   │   ├── menu.cpp         # Simple menu system
│   │   ├── overlay.cpp      # On-screen controls
│   │   └── status.cpp       # FPS/debug display
│   ├── platform/esp32/
│   │   ├── display.cpp      # Direct TFT_eSPI usage
│   │   ├── input.cpp        # Touch & button handling
│   │   ├── storage.cpp      # SD card operations
│   │   └── system.cpp       # ESP32-specific setup
│   └── utils/
│       ├── config.cpp       # Settings management
│       └── perf.cpp         # Performance monitoring
├── include/
│   ├── core/
│   │   ├── gb_types.h      # Common types/constants
│   │   ├── gb_state.h      # Emulator state structure
│   │   └── gb_opcodes.h    # CPU instruction set
│   ├── ui/
│   │   └── ui_common.h     # UI constants/types
│   ├── platform/
│   │   └── hardware.h      # Hardware constants
│   └── utils/
│       └── common.h        # Common utilities
├── platformio.ini
└── data/                    # SPIFFS/LittleFS data
└── config.json         # Default configuration

### Simplified Architecture Principles

1. **Direct Hardware Access**: Remove abstraction layers, use TFT_eSPI and XPT2046 directly
2. **Static Allocation**: Use static buffers where possible to avoid heap fragmentation
3. **Single Responsibility**: Each module has one clear purpose
4. **Minimal Dependencies**: Reduce cross-module dependencies
5. **C++ Best Practices**: Use modern C++ (C++17) features appropriately

## Implementation Plan

### Phase 1: Core Cleanup (Week 1)
- [ ] Create new directory structure
- [ ] Rewrite CPU core with cleaner C++ design
- [ ] Implement efficient PPU with direct framebuffer access
- [ ] Simplify memory management (static buffers)

### Phase 2: Platform Layer (Week 2)
- [ ] Direct TFT_eSPI implementation without abstractions
- [ ] Simple touch input handling
- [ ] Efficient SD card ROM loading
- [ ] Remove complex dependency injection

### Phase 3: UI/Menu System (Week 3)
- [ ] Simple, fast menu using direct drawing
- [ ] Touch-based ROM selection
- [ ] On-screen controls for gameplay
- [ ] Performance overlay

### Phase 4: Optimization (Week 4)
- [ ] Profile and optimize hot paths
- [ ] Implement frame skipping
- [ ] Add audio stub (prepare for future)
- [ ] Fine-tune for 60 FPS

## Key Simplifications

1. **Remove HAL abstractions** - Use hardware libraries directly
2. **Static memory allocation** - Avoid heap fragmentation
3. **Single framebuffer** - No complex double buffering
4. **Direct file access** - Simple SD card reading
5. **Inline critical functions** - Better performance
6. **Remove FreeRTOS tasks** - Use main loop only

## Memory Budget (320KB total)
- Framebuffer: 46KB (160x144x2)
- ROM Cache: 64KB (4 banks)
- Work RAM: 32KB (includes VRAM)
- Stack/Heap: 178KB (remaining)

## Performance Targets
- 60 FPS gameplay
- < 16ms frame time
- Instant menu response
- 2-second ROM load time
