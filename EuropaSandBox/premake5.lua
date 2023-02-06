project "EuropaSandBox"
	location "EuropaSandBox"
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
		"%{wks.location}/EuropaEngine/vendor"
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