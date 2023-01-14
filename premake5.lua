workspace "Europa"
	architecture "x64"
	startproject "EuropaSandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludedDirs = {}

project "EuropaEngine"
	location "EuropaEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}")
	objdir ( "bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "EuropaEnginePCH.h"
	pchsource "EuropaEngine/src/EuropaEnginePCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines
	{
	}

	includedirs
	{
		"%{prj.name}/src",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"_WINDLL",
			"_UNICODE",
			"UNICODE"
		}

	filter "configurations:Debug"
		defines "EUROPA_ENGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "EUROPA_ENGINE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EUROPA_ENGINE_DIST"
		runtime "Release"
		optimize "on"


	
project "EuropaSandBox"
	location "EuropaSandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"
	
	targetdir ( "bin/" .. outputdir .. "/%{prj.name}")
	objdir ( "bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"EuropaEngine/src",
		"EuropaEngine/vendor"
	}

	links
	{
		"EuropaEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"_WINDLL",
			"_UNICODE",
			"UNICODE"
		}

	filter "configurations:Debug"
		defines "EUROPA_ENGINE_DEBUG"
		runtime "Debug" 
		symbols "on"

	filter "configurations:Release"
		defines "EUROPA_ENGINE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EUROPA_ENGINE_DIST"
		runtime "Release"
		optimize "on"