#pragma once


#include <common/data/primitives.hpp>

namespace dvk::graphic {

    enum GraphicAPI : u8 {
        None = 0,
        OpenGL
    };

    DK_API GraphicAPI get_graphic_api_type();
    DK_API void set_graphic_api_type(GraphicAPI graphic_api_type);

    
    DK_API u8 graphic_api_init();

    DK_API u8 graphic_api_terminate();

}
