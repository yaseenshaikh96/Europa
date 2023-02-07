project "EuropaEditor"
	kind "ConsoleApp"
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
		"%{wks.location}/EuropaEngine/vendor",
		"%{IncludeDir.spdlog}"
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