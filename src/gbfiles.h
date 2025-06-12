#ifndef INTERNAL_H
#define INTERNAL_H

#include <stdint.h>
#ifndef __cplusplus
#define nullptr ((void*)0)
#endif

/* Uncomment if including a bios on compile */
//#define USE_INTERNAL_BIOS

// Disable internal border for now
//#define USE_INTERNAL_BORDER

// ROM is now loaded from SD card; fallback ROM is not used

#ifdef USE_INTERNAL_BIOS
	#include "gbbios.h"
#else
	const uint8_t* gb_bios = nullptr;
	const uint32_t gb_bios_size = 0;
#endif

#ifdef USE_INTERNAL_BORDER
	#include "gbborder.h"
#else
	const uint8_t* gb_border = nullptr;
	const uint32_t gb_border_size = 0;
#endif

#endif
