#pragma once

#include <common/data/primitives.hpp>

#include <string>

namespace dvk {

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

    struct DK_API IWindow {
        virtual void init(WindowProc proc) = 0;
        virtual void run() = 0;
        virtual void destroy() = 0;
        // void on_event();
    };


    struct DK_API ExampleWindow : IWindow {
        virtual void init(WindowProc proc) override;
        virtual void run() override;
        virtual void destroy() override;

        ExampleWindow(WindowProc proc) {
            init(proc);
        }

        // fields
        WindowProc proc;
    };

}
