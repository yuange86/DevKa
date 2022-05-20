#pragma once


#include "common/base/macro.hpp"
#include "common/data/primitives.hpp"

namespace dvk {
    namespace platform {

        Raw(void) platform_alloc(usize size);
        void platform_free(Raw(void) pointer);

        Raw(void) platform_zero_memory(Raw(void) block, u64 size);
        Raw(void) platform_copy_memory(Raw(void) dest, const Raw(void) source, u64 size);
        Raw(void) platform_set_memory(Raw(void) dest, i32 value, u64 size);

    }
}
