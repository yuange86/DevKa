
#include <devka-core/core.hpp>

int main()
{
    dvk::memory::StoredMemory::init();
    DK_LOG_INIT();
    
    DK_DEFAULT_INFO("Hello!");

    auto* pointer = dvk::memory::alloc_type<int>();
    *pointer = 0;
    DK_DEFAULT_TRACE("{0} -> {1}", (__ptr_t)pointer, *pointer);
    DK_DEFAULT_WARN("{}", dvk::memory::StoredMemory::get_bytes(dvk::memory::StoredMemoryType_MANAGEMENT));
    DK_DEFAULT_ERROR("{}", dvk::memory::StoredMemory::get_bytes(dvk::memory::StoredMemoryType_RAW));
    dvk::memory::free_type(pointer);
    DK_DEFAULT_FATAL("{}", dvk::memory::StoredMemory::get_bytes(dvk::memory::StoredMemoryType_RAW));
}
