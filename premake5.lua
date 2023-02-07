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


group "Dependencies"
	include "EuropaEngine/vendor/glad"
	include "EuropaEngine/vendor/GLFW"
	include "EuropaEngine/vendor/spdlog"
group ""


group "Core"
	include "EuropaEngine"
group ""

group "Misc"
	include "EuropaSandBox"
group ""
	
