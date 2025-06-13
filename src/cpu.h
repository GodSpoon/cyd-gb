#ifndef CPU_H
#define CPU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern bool halted;

void cpu_init(void);
uint32_t cpu_cycle(void);
uint32_t cpu_get_cycles(void);
void cpu_interrupt(uint16_t);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// Dependency injection for C++ components
class FramebufferManager;
void cpu_set_framebuffer_manager(FramebufferManager* fbmgr);

namespace GameBoy {
    class CPU;
}
#endif

#endif // CPU_H
