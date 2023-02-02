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