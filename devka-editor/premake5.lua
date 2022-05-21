project "devka-editor"
    kind "ConsoleApp"
    language "c++"
    cppdialect "c++20"
    staticruntime "off"

    targetdir("%{wks.location}/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/" .. outputdir .. "/.int/%{prj.name}")

    includedirs {
        "src",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.common}",
        "%{IncludeDirs.physics}",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.Glad}",
        "%{IncludeDirs.imgui}",
        "%{IncludeDirs.graphic}",
        "%{IncludeDirs.core}",
    }

    files {
        "src/**.hpp",
        "src/**.cpp",
    }

    links {
        "common",
        "devka-core",
        "glfw",
        "Glad",
    }

    defines {
        "DK_DLL_IMPORT",
    }


    filter "system:linux"
        systemversion "latest"
        defines {
            "DK_PLATFORM_LINUX",
        }

        filter "configurations:Debug"
        defines "DK_DEBUG"
        runtime "Debug"
        symbols "on"
        -- buildoptions {
        --     "-MDd"
        -- }

    filter "configurations:Release"
        defines "DK_RELEASE"
        runtime "Release"
        optimize "on"
        -- buildoptions {
        --     "-MD"
        -- }


