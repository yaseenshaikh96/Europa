#pragma once

#include "EuropaEngine/Core/Logger.h"

#ifdef EUROPA_ENGINE_DEBUG
#define EUROPA_ENABLE_ASSERTS
#endif

#ifdef EUROPA_ENABLE_ASSERTS
#define EUROPA_ASSERT(x, ...) { if(!(x)) { EUROPA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define EUROPA_ASSERT(X, ...)
#endif


namespace EuropaEngine
{
#define BIND_EVENT_FUNCTION(x, instance) std::bind(&x, instance, std::placeholders::_1)

	template<typename t_Type>
	using Scope = std::unique_ptr<t_Type>;
	
	template<typename t_Type, typename ... Args>
	constexpr Scope<t_Type> CreateScope(Args&& ... args)
	{
		return std::make_unique<t_Type>(std::forward<Args>(args)...);
	}

	template<typename t_Type>
	using Ref = std::shared_ptr<t_Type>;
	
	template<typename t_Type, typename ... Args>
	constexpr Ref<t_Type> CreateRef(Args&& ... args)
	{
		return std::make_shared<t_Type>(std::forward<Args>(args)...);
	}
}