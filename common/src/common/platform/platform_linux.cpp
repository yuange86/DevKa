#include "common/pch/commonpch.hpp"


#ifdef DK_PLATFORM_LINUX

#include "platform.hpp"

// #include <xcb/xcb.h>
// #include <X11/keysym.h>

// #include <sys/time.h>

namespace dvk::platform {

    void* platform_alloc(usize size) {
        return malloc(size);
    }

    void platform_free(void* pointer) {
        free(pointer);
    }

    void* platform_zero_memory(void* block, u64 size) {
        return memset(block, 0, size);
    }
    void* platform_copy_memory(void* dest, const void* source, u64 size) {
        return memcpy(dest, source, size);
    }
    void* platform_set_memory(void* dest, i32 value, u64 size) {
        return memset(dest, value, size);
    }

}

#endif
