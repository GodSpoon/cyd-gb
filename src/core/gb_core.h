#pragma once
#include <cstdint>

namespace gb {

// Core types
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using s8 = int8_t;
using s16 = int16_t;

// Memory map
constexpr u16 ROM_BANK_0    = 0x0000;  // 16KB ROM Bank 0
constexpr u16 ROM_BANK_N    = 0x4000;  // 16KB ROM Bank N
constexpr u16 VRAM_START    = 0x8000;  // 8KB Video RAM
constexpr u16 CART_RAM      = 0xA000;  // 8KB Cart RAM
constexpr u16 WRAM_START    = 0xC000;  // 8KB Work RAM
constexpr u16 ECHO_START    = 0xE000;  // Echo RAM
constexpr u16 OAM_START     = 0xFE00;  // Sprite RAM
constexpr u16 IO_START      = 0xFF00;  // I/O Registers
constexpr u16 HRAM_START    = 0xFF80;  // High RAM

// Screen dimensions
constexpr int SCREEN_W = 160;
constexpr int SCREEN_H = 144;

// Core emulator state
struct State {
    // CPU registers
    union {
        struct { u8 f, a; };
        u16 af;
    };
    union {
        struct { u8 c, b; };
        u16 bc;
    };
    union {
        struct { u8 e, d; };
        u16 de;
    };
    union {
        struct { u8 l, h; };
        u16 hl;
    };
    u16 sp;
    u16 pc;
    
    // Memory
    u8 wram[8192];     // Work RAM
    u8 hram[127];      // High RAM
    u8 vram[8192];     // Video RAM
    u8 oam[160];       // Sprite data
    
    // I/O registers
    u8 io[128];
    
    // Interrupt flags
    bool ime;
    u8 ie;
    u8 if_;
    
    // Timing
    u32 cycles;
    u32 frame_cycles;
    
    // ROM data (external)
    const u8* rom = nullptr;
    u32 rom_size = 0;
    u8 rom_bank = 1;
    
    // Cart RAM (if needed)
    u8* cart_ram = nullptr;
    u32 cart_ram_size = 0;
};

// Core functions
void init(State& s);
void reset(State& s);
void load_rom(State& s, const u8* data, u32 size);
void run_frame(State& s, u16* framebuffer);
void step(State& s);

// Memory access
u8 read8(State& s, u16 addr);
u16 read16(State& s, u16 addr);
void write8(State& s, u16 addr, u8 val);
void write16(State& s, u16 addr, u16 val);

} // namespace gb
