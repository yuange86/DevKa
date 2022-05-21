project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "off"
    
    targetdir("%{wks.location}/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/" .. outputdir .. "/.int/%{prj.name}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs
    {
        "include"
    }
    
    filter "system:linux"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"