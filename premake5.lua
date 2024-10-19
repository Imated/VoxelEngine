workspace "Voxel"
    language "C++"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    
    filter { "configurations:Debug" }
    symbols "On"
    
    filter { "configurations:Release" }
    optimize "On"
    
    filter {} -- Reset the filter
    
    targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")
    
    startproject "app"

project "Voxel"
    kind "ConsoleApp"
    targetname "Voxel"
    
    language "C++"
    cppdialect "C++20"
    staticruntime "off"
    
    files
    {
        "src/**.h",
        "src/**.cpp",
        "assets/",
        "lib/glad/src/glad.c"
    }
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
    }
    
    includedirs
    {
        "src",
        "lib/glad/include/",
        "lib/glm/glm/glm",
        "lib/glfw/include/",
        "lib/"
    }
    
    links
    {
        "opengl32.lib",
        "winmm.lib",
        "lib/glfw/lib/glfw3.lib",
        "lib/glfw/lib/glfw3dll.lib"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
