#pragma once


#ifdef DK_DLL
#   ifdef _MSC_VER
#       define      DK_API      __declspec(dllexport)
#       define      DK_EXT      export
#   elif defined(__GNUC__)
#       define      DK_API      __attribute__((dllexport))
#       define      DK_EXT      export
#   endif
#elif defined(DK_DLL_IMPORT)
#   ifdef _MSC_VER
#       define      DK_API      __declspec(dllimport)
#       define      DK_EXT      
#   elif defined(__GNUC__)
#       define      DK_API      // __attribute__((dllimport))
#       define      DK_EXT      
#   endif
#else
#   define      DK_API
#   define      DK_EXT
#endif

#define BIND_CLASS_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }


#define ASSIGN_DEBUG_ONLY(variable, value)      variable = value

