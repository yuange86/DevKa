#include <common/pch/commonpch.hpp>


#include "window.hpp"

#include <devka-graphic/preinit/graphic_init.hpp>

namespace dvk {

    void ExampleWindow::init(graphic::WindowProc proc) {
        this->proc = proc;
        this->graphic_window = graphic::GraphicContextSystem::create(&this->proc);
    }

    void ExampleWindow::run() {
        graphic::GraphicContextSystem::clear();
        graphic::GraphicContextSystem::clear_color(0.2f, 0.4f, 0.7f, 1.0f);
        
        graphic::GraphicContextSystem::swap_buffer(this->graphic_window);
    }

    void ExampleWindow::destroy() {
        graphic::graphic_api_terminate();
    }

    b1 ExampleWindow::is_running() {
        return graphic::GraphicContextSystem::is_context_running(this->graphic_window);
    }

}
