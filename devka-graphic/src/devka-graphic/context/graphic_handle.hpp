#pragma once

#include <common/data/primitives.hpp>

#include <string>

#include "devka-graphic/preinit/graphic_init.hpp"

namespace dvk::graphic {

    struct DK_API WindowProc {
        std::string title;
        u32 width; u32 height;
        // u32 cursor_x; u32 cursor_y; 
        // bool external_logger;
        bool vsync;


        WindowProc()
            :   title("DevKa Editor Example Window"), width(1080), height(960), vsync(false)
        {}

        WindowProc(const std::string& title, u32 width, u32 height, bool vsync) 
            :   title(title), width(width), height(height), vsync(vsync)
        {}
    };

    struct GraphicContext {
        void* window_handle;
    };


    class DK_API GraphicContextSystem {
    public:
        static GraphicContext create(WindowProc proc);
        
        static void init(GraphicContext& context);
    };

}
