#pragma once

#include <common/data/primitives.hpp>

#include <string>

#include "devka-core/core/window.hpp"

namespace dvk {

    class DKEngine {
        DKEngine();
        DKEngine(const std::string& name);
        virtual ~DKEngine() = default;

    public:

        static Raw(DKEngine) create(const std::string& name);


        void example_main_window(graphic::WindowProc proc);
        // void apply_main_window(Raw(IWindow) window);


        void run(/* f32 or timestep : deltatime */);

        b1 is_main_window_running();

    private:

        u32 logger_code;
        Raw(IWindow) main_window;

    };

}

