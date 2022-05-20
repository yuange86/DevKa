#pragma once


#include "common/base/macro.hpp"
#include "common/data/primitives.hpp"

namespace dvk {
    namespace platform {

        DK_API void* platform_alloc(usize size);
        DK_API void platform_free(void* pointer);

        DK_API void* platform_zero_memory(void* block, u64 size);
        DK_API void* platform_copy_memory(void* dest, const void* source, u64 size);
        DK_API void* platform_set_memory(void* dest, i32 value, u64 size);

    }
}
