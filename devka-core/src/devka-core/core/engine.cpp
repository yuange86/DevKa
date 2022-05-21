#include <common/pch/commonpch.hpp>
#include "engine.hpp"

namespace dvk {

    DKEngine::DKEngine() {
        DK_CREATE_LOGGER("DevKa", 1);
        ASSIGN_DEBUG_ONLY(this->logger_code, 1);
        DK_INFO(this->logger_code, "Engine Created !");
    }

    DKEngine::DKEngine(const std::string& name) {
        DK_CREATE_LOGGER(name, 1);
        ASSIGN_DEBUG_ONLY(this->logger_code, 1);
        DK_INFO(this->logger_code, "Engine Created !");
    }

    Raw(DKEngine) DKEngine::create(const std::string& name) {
        return dvk::memory::alloc_type_default<DKEngine>(DKEngine(name));
    }

    void DKEngine::example_main_window(graphic::WindowProc proc) {
        this->main_window = new ExampleWindow(proc);
    }


}
