// CPU interface for dependency injection
#include "cpu.h"
#include "core/framebuffer_manager.h"

// Static reference to framebuffer manager for CPU module
static FramebufferManager* g_cpu_framebuffer_manager = nullptr;

// C++ function for dependency injection
void cpu_set_framebuffer_manager(FramebufferManager* fbmgr) {
    g_cpu_framebuffer_manager = fbmgr;
}

// Getter function that can be called from C code
extern "C" {
    FramebufferManager* cpu_get_framebuffer_manager(void) {
        return g_cpu_framebuffer_manager;
    }
}
