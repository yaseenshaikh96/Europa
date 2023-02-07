#include "EuropaEnginePCH.h"
#include "Logger.h"


namespace EuropaEngine {

	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("EUROPA_ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("EUROPA_APP");
		s_ClientLogger->set_level(spdlog::level::trace);
		
		
		EUROPA_CORE_INFO("Logger Initialized");
		EUROPA_INFO("Logger Initialized");
	}

}