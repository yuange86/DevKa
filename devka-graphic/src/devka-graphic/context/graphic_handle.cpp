
#include "graphic_handle.hpp"

#include "devka-graphic/log/log_binding.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace dvk::graphic {

    GraphicContext GraphicContextSystem::create(WindowProc proc) {
        graphic_api_init();
        auto output = GraphicContext();
        {
            switch (get_graphic_api_type())
            {
            case GraphicAPI::None:
                DK_GRAPHIC_ERROR("Graphic API [None] is not available to create a graphic context handle!");
                break;
            case GraphicAPI::OpenGL:
                {
                #ifdef DK_DEBUG
                    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
                #endif
                    output.window_handle = glfwCreateWindow((i32)proc.width, (i32)proc.height, proc.title.c_str(), nullptr, nullptr);

                    //glad
                    glfwMakeContextCurrent((Raw(GLFWwindow))output.window_handle);
                    i32 hresult = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
                    // DK_GRAPHIC_FATAL("Failed to initialize Glad [code : {}]", hresult);        //todo : assert

                    DK_GRAPHIC_INFO("OpenGL Info :");
                    DK_GRAPHIC_INFO("   Vendor :    {0}", glGetString(GL_VENDOR));
                    DK_GRAPHIC_INFO("   Renderer :  {0}", glGetString(GL_RENDERER));
                    DK_GRAPHIC_INFO("   Version :   {0}", glGetString(GL_VERSION));
                }
                break;
            default:
                DK_GRAPHIC_ERROR("Unknown Graphic API [{}] is not available to create a graphic context handle!", (u8)get_graphic_api_type());
                break;
            }
        }
        return output;
    }

}
