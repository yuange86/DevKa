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
    };


    struct DK_API ExampleWindow : IWindow {
        virtual void init(graphic::WindowProc proc) override;
        virtual void run() override;
        virtual void destroy() override;

        ExampleWindow(graphic::WindowProc proc) {
            init(proc);
        }

        graphic::GraphicContext graphic_window;
        
    };

}
