
#include "graphic_init.hpp"


#include <common/base/return.hpp>

#include "devka-graphic/log/log_binding.hpp"

#include <GLFW/glfw3.h>


static void GLFWErrorCallback(i32 error, const char* description) {
    DK_GRAPHIC_ERROR("GLFW Error [code : {0}] : {1}", error, description);
}


static b1 inited = false;
static dvk::graphic::GraphicAPI static_graphic_api_type = dvk::graphic::GraphicAPI::None;

dvk::graphic::GraphicAPI dvk::graphic::get_graphic_api_type() {
    return static_graphic_api_type;
}

void dvk::graphic::set_graphic_api_type(dvk::graphic::GraphicAPI graphic_api_type) {
    static_graphic_api_type = graphic_api_type;
}

u8 dvk::graphic::graphic_api_init() {
    using namespace dvk::graphic;

    if(inited) return U8_RETURN_ERROR_ONLY_ONE_CALL;

    switch (dvk::graphic::get_graphic_api_type())
    {
    case GraphicAPI::None:
        DK_GRAPHIC_ERROR("Graphic API [None] is not available to be initialized!");
        break;
    case GraphicAPI::OpenGL:
        {
            i32 hresult = glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
            DK_GRAPHIC_INFO("glfwInit result : {}", hresult);
            return U8_RETURN_UNDEFINED;
        }
        break;
    default:
        DK_GRAPHIC_ERROR("Unknown Graphic API [{}] is not available to be initialized!", (u8)dvk::graphic::get_graphic_api_type());
        break;
    }
    return U8_RETURN_ERROR_NO_MATCHED_CALLBACK;
}

u8 dvk::graphic::graphic_api_terminate() {
    switch (dvk::graphic::get_graphic_api_type())
    {
    case GraphicAPI::None:
        break;
    case GraphicAPI::OpenGL:
        {
            glfwTerminate();
        }
        break;
    default:
        break;
    }
    return U8_RETURN_UNDEFINED;
}

