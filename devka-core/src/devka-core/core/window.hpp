#pragma once

#include <common/data/primitives.hpp>

#include <devka-graphic/context/graphic_handle.hpp>

#include <string>

namespace dvk {

    struct DK_API IWindow {
        virtual void init(graphic::WindowProc proc) = 0;
        virtual void run() = 0;
        virtual void destroy() = 0;
        // void on_event();

        virtual b1 is_running() = 0;
    };


    struct DK_API ExampleWindow : IWindow {
        virtual void init(graphic::WindowProc proc) override;
        virtual void run() override;
        virtual void destroy() override;

        virtual b1 is_running() override;

        ExampleWindow(graphic::WindowProc proc) {
            init(proc);
        }

        graphic::WindowProc proc;
        graphic::GraphicContext graphic_window;
        
    };

}
