project "devka-graphic"
    kind "StaticLib"
    language "c++"
    cppdialect "c++20"
    staticruntime "off"

    targetdir("%{wks.location}/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/" .. outputdir .. "/.int/%{prj.name}")

    includedirs {
        "src",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.common}",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.Glad}",
        "%{IncludeDirs.imgui}",
    }

    files {
        "src/**.hpp",
        "src/**.cpp",
    }

    links {
        "common",
        "GLFW",
        "Imgui",
        "Glad",
    }


    filter "system:linux"
        pic "On"
        
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


