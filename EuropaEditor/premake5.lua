project "EuropaEditor"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"
	
	targetdir ( "%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ( "%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
        "%{wks.location}/EuropaEngine/src",
		"%{IncludeDir.glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.stb}"
	}

	links
	{
		"EuropaEngine",
		"imgui"
	}
	
	defines
	{
		"%{GlobalDefines.stb_image}"
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
		defines "EUROPA_DEBUG"
		runtime "Debug" 
		symbols "on"

	filter "configurations:Release"
		defines "EUROPA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EUROPA_DIST"
		runtime "Release"
		optimize "on"
        symbols "off"