#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace EuropaEngine
{
	class Logger
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define EUROPA_CORE_TRACE(...)    ::EuropaEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define EUROPA_CORE_INFO(...)     ::EuropaEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define EUROPA_CORE_WARN(...)     ::EuropaEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define EUROPA_CORE_ERROR(...)    ::EuropaEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define EUROPA_CORE_CRITICAL(...) ::EuropaEngine::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define EUROPA_TRACE(...)         ::EuropaEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define EUROPA_INFO(...)          ::EuropaEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define EUROPA_WARN(...)          ::EuropaEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define EUROPA_ERROR(...)         ::EuropaEngine::Logger::GetClientLogger()->error(__VA_ARGS__)
#define EUROPA_CRITICAL(...)      ::EuropaEngine::Logger::GetClientLogger()->critical(__VA_ARGS__)
