#ifndef ROM_H
#define ROM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct s_rominfo {
    uint16_t rom_banks;
    uint8_t ram_banks;
    uint8_t rom_mapper;
    uint8_t has_battery;
    uint8_t has_rtc;
};

bool rom_init(const uint8_t *);
const uint8_t *rom_getbytes(void);
const s_rominfo *rom_get_info(void);
uint32_t rom_get_ram_size();
const char* rom_get_title();

enum {
    NROM,
    MBC1,
    MBC2,
    MMM01,
    MBC3,
    MBC5,
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace GameBoy {
    // ROM-related declarations could go here if needed
}
#endif

#endif // ROM_H
