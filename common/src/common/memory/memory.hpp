#pragma once


#include "common/base/macro.hpp"
#include "common/data/primitives.hpp"

#include "common/platform/platform.hpp"

namespace dvk::memory {

    enum StoredMemoryType {
        StoredMemoryType_UNKNOWN = 0,
        StoredMemoryType_RAW,
        StoredMemoryType_ENGINE,
        StoredMemoryType_DLL,
        StoredMemoryType_MANAGEMENT,

        StoredMemoryType_MAX
    };

    class DK_API StoredMemory {
    public:
    
        //! please call this once !
        static void init();
        static void record(u32 bytes, StoredMemoryType type = StoredMemoryType_UNKNOWN);
        static void remove(u32 bytes, StoredMemoryType type = StoredMemoryType_UNKNOWN);

        static u32 get_bytes(StoredMemoryType type = StoredMemoryType_UNKNOWN);
        static u32 get_Kbytes(StoredMemoryType type = StoredMemoryType_UNKNOWN);
        static u32 get_Mbytes(StoredMemoryType type = StoredMemoryType_UNKNOWN);
        static u32 get_Gbytes(StoredMemoryType type = StoredMemoryType_UNKNOWN);

    private:
        static u32 recoreded_bytes[StoredMemoryType_MAX];
    };


    template<typename __Type>
    __Type* alloc_type_with_init(__Type _default) {
        StoredMemory::record(sizeof(__Type), StoredMemoryType_RAW);
        __Type* pointer = (__Type*)dvk::platform::platform_alloc(sizeof(__Type));
        *pointer = _default;
        return pointer;
    }
    template<typename __Type>
    __Type* alloc_type() {
        StoredMemory::record(sizeof(__Type), StoredMemoryType_RAW);
        return (__Type*)dvk::platform::platform_alloc(sizeof(__Type));
    }

    template<typename __Type>
    void free_type(__Type* pointer) {
        StoredMemory::remove(sizeof(__Type), StoredMemoryType_RAW);
        dvk::platform::platform_free(pointer);
    }


}
