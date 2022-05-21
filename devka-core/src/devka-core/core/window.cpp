#include <common/pch/commonpch.hpp>


#include "window.hpp"

#include <devka-graphic/preinit/graphic_init.hpp>

namespace dvk {

    void ExampleWindow::init(graphic::WindowProc proc) {
        this->graphic_window = graphic::GraphicContextSystem::create(proc);
    }

    void ExampleWindow::run() {
        
    }

    void ExampleWindow::destroy() {
        graphic::graphic_api_terminate();
    }

}
