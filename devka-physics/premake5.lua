project "devka-physics"
    kind "SharedLib"
    language "c++"
    cppdialect "c++20"
    staticruntime "off"

    targetdir("%{wks.location}/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/" .. outputdir .. "/.int/%{prj.name}")

    includedirs {
        "src",
        "%{IncludeDirs.common}",
    }

    files {
        "src/**.hpp",
        "src/**.cpp",
    }

    links {
        "common"
    }


    filter "system:linux"
        systemversion "latest"
        defines{}

    filter "configurations:Debug"
        defines "DK_DEBUG"
        buildoptions { "/MDd" }

    filter "configurations:Release"
        defines "DK_RELEASE"
        buildoptions { "/MD" }


