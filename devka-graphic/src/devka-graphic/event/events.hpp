#pragma once

#include <common/event/event.hpp>

namespace dvk::graphic {

    class WindowCloseEvent : Event {
    public:
        WindowCloseEvent();
        virtual ~WindowCloseEvent() = default;
    private:
        const EventCategory category = DKEventCategory_WINDOW;
        const EventType type = EventType::WindowClose;
    }
    
}

