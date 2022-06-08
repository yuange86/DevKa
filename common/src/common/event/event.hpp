#pragma once


#include "common/data/primitives.hpp"

namespace dvk
{
    
    typedef i8 EventCategory;

#define DKEventCategory_ENGINE          0x01
#define DKEventCategory_WINDOW          0x02

    enum EventType : i8 {
        None = 0,
        // EngineCreate, EngineInit, EnginePrepareMainWindow, EngineQuitMainWindow, EngineQuit, EngineDestroy,
        // WindowHandleCreate, WindowHandleHandleSwapBuffer, WindowHandleStartOneFrame, WindowHandleFinishOneFrame, WindowHandleDestroy,
        WindowClose, WindowStart, WindowFocus, WindowContentScale, 
        MouseClick, MouseHold, MouseRelease, MouseScroll,
            // MouseEnterWindow,
        KeyPress, KeyRepeate,
        CharMod
    };
    
    struct DK_API Event {
        const EventCategory category;
        const EventType type;
    };
    
}

