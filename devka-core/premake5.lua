project "devka-core"
    kind "SharedLib"
    language "c++"
    cppdialect "c++20"
    staticruntime "off"

    targetdir("%{wks.location}/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/" .. outputdir .. "/.int/%{prj.name}")

    pchheader "%{IncludeDirs.common}/common/pch/commonpch.hpp"
    pchsource "%{IncludeDirs.common}/common/pch/commonpch.cpp"

    includedirs {
        "src",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.common}",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.imgui}",
        "%{IncludeDirs.graphic}",
        "%{IncludeDirs.physics}",
    }

    files {
        "src/**.hpp",
        "src/**.cpp",
    }

    links {
        "devka-physics",
        "devka-graphic",
    }

    defines {
        "DK_DLL",
    }

    -- postbuildcommands {
    --     ("%{COPY} %{cfg.buildtarget.relpath} %{wks.location}/lib/" .. outputdir .. "/%{prj.name}"),
    -- }


    filter "system:linux"
        systemversion "latest"
        defines {
            "DK_PLATFORM_LINUX",
        }

        filter "configurations:Debug"
        defines "DK_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "DK_RELEASE"
        runtime "Release"
        optimize "on"


