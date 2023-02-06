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
		
		std::function<void(Event&)> EventCallBack;
	};

	class Window
	{
	protected:
		Window(const WindowProps& windowProps)
			:
			m_WindowProps(windowProps)
		{}

	public:
		static Ref<Window> Create(const WindowProps& windowProps);
		virtual ~Window() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void* GetNativeWindow() { return m_WindowProps.Window; }


		uint32_t GetWidth() const { return m_WindowProps.Width; }
		uint32_t GetHeight() const { return m_WindowProps.Height; }

		bool GetVSync() const { return m_WindowProps.VSync; }
		
		void SetEventCallBackFunction(std::function<void(Event&)> function) { m_WindowProps.EventCallBack = function; }

	protected:
		WindowProps m_WindowProps;
	};
}