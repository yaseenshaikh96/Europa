include "premake5Dependencies.lua"

workspace "Europa"
	architecture "x64"
	startproject "EuropaEditor"

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
	include "EuropaEngine/vendor/imgui"
	include "EuropaEngine/vendor/glm"
group ""


group "Core"
	include "EuropaEngine"
	include "EuropaEditor"
group ""

group "Misc"
	include "EuropaSandBox"
group ""
	
