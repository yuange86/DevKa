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
        b1 vsync;
        b1 exit;


        WindowProc()
            :   title("DevKa Editor Example Window"), width(1080), height(960), vsync(false), exit(false)
        {}

        WindowProc(const std::string& title, u32 width, u32 height, b1 vsync, b1 exit = false) 
            :   title(title), width(width), height(height), vsync(vsync), exit(exit)
        {}
    };

    struct GraphicContext {
        void* window_handle;
        Raw(WindowProc) proc;
    };


    class DK_API GraphicContextSystem {
    public:
        static GraphicContext create(WindowProc* proc);
        
        static void init(GraphicContext& context);
        static void swap_buffer(GraphicContext& context);

        static void poll_event();

        static b1 is_context_running(GraphicContext& context);

        // glad implements?
        static void clear(/* i32 flags */);
        static void clear_color(f32 red, f32 green, f32 blue, f32 alpha);
    };

}
