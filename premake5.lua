include "premakeIncludeDirs.lua"

workspace "devka"
    filename "DevKa Engine"
    configurations { "Debug", "Release", "Dist" }


outputdir = "bin/%{cfg.buildcfg}-%{cfg.system}"


group "3rdparty"
    include "devka-graphic/3rdparty/glfw"
    include "devka-graphic/3rdparty/imgui"
group ""

include "common"
include "devka-physics"
include "devka-graphic"
include "devka-core"
include "devka-editor"