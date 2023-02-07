#pragma once

#include "EuropaEngine/Core/Events/Event.h"

namespace EuropaEngine
{
	struct WindowProps
	{
		void* Window = nullptr;
		
		bool IsInitialized = false;
		bool VSync = false;
		
		std::string Title;
		uint32_t Width = 0, Height = 0;
		
		std::function<void(Event&)> EventCallBackFunction;
	};

	class Window
	{
	public:
		static Ref<Window> Create(const WindowProps& windowProps);
		virtual ~Window() = default;

		virtual void Init() = 0;
		virtual void ShutDown() = 0;
		virtual void OnUpdate() = 0;

		virtual void* GetNativeWindow() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual bool GetVSync() const = 0;
		virtual void SetVSync(bool enable)  = 0;

		
		virtual void SetEventCallBackFunction(std::function<void(Event&)> function) = 0;
	};
}