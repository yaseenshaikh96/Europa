include "premake5Dependencies.lua"

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


group "Core-Dependencies"
	include "EuropaEngine/vendor/glad"
	include "EuropaEngine/vendor/GLFW"
	include "EuropaEngine/vendor/spdlog"
	include "EuropaEngine/vendor/glm"
	include "EuropaEngine/vendor/stb"
	group ""
	
group "Editor-Dependencies"	
	include "EuropaEditor/vendor/imgui"
group ""



group "Core"
	include "EuropaEngine"
	include "EuropaEditor"
group ""

group "Misc"
	include "EuropaSandBox"
group ""
	
