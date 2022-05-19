project "common"
    kind "StaticLib"
    language "c++"
    cppdialect "c++20"
    staticruntime "off"

    targetdir("%{wks.location}/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/" .. outputdir .. "/.int/%{prj.name}")

    includedirs {
        "src",
        "%{IncludeDirs.spdlog}",
    }

    files {
        "src/**.hpp",
        "src/**.cpp",
    }


    filter "system:linux"
        systemversion "latest"
        defines{}

    filter "configurations:Debug"
        defines "DK_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "DK_RELEASE"
        runtime "Release"
        optimize "on"


