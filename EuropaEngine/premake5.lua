project "EuropaEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ( "%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ( "%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "EuropaEnginePCH.h"
	pchsource "src/EuropaEnginePCH.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	defines
	{
	}

	includedirs
	{
		"src",
		"%{IncludeDir.glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.stb}"
	}

	links
	{
		"glad",
		"GLFW",
		"opengl32.lib",
		"imgui"
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
		symbols "off"