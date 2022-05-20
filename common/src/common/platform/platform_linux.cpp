#include "common/pch/commonpch.hpp"


#ifdef DK_PLATFORM_LINUX

#include "platform.hpp"

// #include <xcb/xcb.h>
// #include <X11/keysym.h>

// #include <sys/time.h>

namespace dvk::platform {

    Raw(void) platform_alloc(usize size) {
        return malloc(size);
    }

    void platform_free(Raw(void) pointer) {
        free(pointer);
    }

    Raw(void) platform_zero_memory(Raw(void) block, u64 size) {
        return memset(block, 0, size);
    }
    Raw(void) platform_copy_memory(Raw(void) dest, const Raw(void) source, u64 size) {
        return memcpy(dest, source, size);
    }
    Raw(void) platform_set_memory(Raw(void) dest, i32 value, u64 size) {
        return memset(dest, value, size);
    }

}

#endif
