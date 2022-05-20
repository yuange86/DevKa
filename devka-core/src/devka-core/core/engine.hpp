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


        void example_main_window(WindowProc proc);
        // void apply_main_window(Raw(IWindow) window);

    private:

        u32 logger_code;
        Raw(IWindow) main_window;

    };

}

