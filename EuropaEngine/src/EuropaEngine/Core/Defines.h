#pragma once

#include <iostream>

#ifdef EUROPA_ENGINE_DEBUG
#define EUROPA_ENABLE_ASSERTS
#endif

#ifdef EUROPA_ENABLE_ASSERTS
#define EUROPA_ASSERT(x, ...) { if(!(x)) { std::cout << "Assertion Failed: " << __VA_ARGS__ << std::endl; __debugbreak(); } }
#else
#define EUROPA_ASSERT(X, ...)
#endif

#define EUROPA_LOG_INFO(...) std::cout << "Europa Log Info: " << __VA_ARGS__ << std::endl;



namespace EuropaEngine
{
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