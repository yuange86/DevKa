#include "common/pch/commonpch.hpp"


#include "common/memory/memory.hpp"

#include "common/platform/platform.hpp"

namespace dvk::memory {

    u32 StoredMemory::recoreded_bytes[StoredMemoryType_MAX];


    void StoredMemory::init() {
        record(StoredMemoryType_MAX * 4, StoredMemoryType_MANAGEMENT);
        dvk::platform::platform_zero_memory(recoreded_bytes, 4 * StoredMemoryType_MAX);
    }

    void StoredMemory::record(u32 bytes, StoredMemoryType type) {
        recoreded_bytes[type] += bytes;
    }

    void StoredMemory::remove(u32 bytes, StoredMemoryType type) {
        recoreded_bytes[type] -= bytes;
    }

    u32 StoredMemory::get_bytes(StoredMemoryType type) {
        return recoreded_bytes[type];
    }

    u32 StoredMemory::get_Kbytes(StoredMemoryType type) {
        return recoreded_bytes[type] / 1024;
    }

    u32 StoredMemory::get_Mbytes(StoredMemoryType type) {
        return recoreded_bytes[type] / 1024 / 1024;
    }

    u32 StoredMemory::get_Gbytes(StoredMemoryType type) {
        return recoreded_bytes[type] / 1024 / 1024 / 1024;
    }

}
