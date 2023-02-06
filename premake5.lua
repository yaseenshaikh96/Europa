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
	include "EuropaEngine/vendor/GLFW"
group ""


group "Core"
	include "EuropaEngine"
group ""

group "Misc"
	include "EuropaSandBox"
group ""
	
