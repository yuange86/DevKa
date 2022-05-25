
#define DK_GRAPHIC_GLFW_GL

#include <devka-core/core.hpp>

int main()
{
    dvk::memory::StoredMemory::init();
    DK_LOG_INIT();
    DK_GRAPHIC_LOG_INIT();
    
    // default logger debugging
    DK_DEFAULT_INFO("Hello!");
    DK_INFO(1000, "?");

    dvk::graphic::set_graphic_api_type(dvk::graphic::GraphicAPI::OpenGL);

    auto* engine = dvk::DKEngine::create("DevKa");

    engine->example_main_window(dvk::graphic::WindowProc());

    while(engine->is_main_window_running()) {
        engine->run();
    }

}
