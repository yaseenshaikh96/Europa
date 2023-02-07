#pragma once

#include "EuropaEngine/Core/Defines.h"
#include "EuropaEngine/Core/Window.h"

namespace EuropaEngine
{
	class MSWindowsWindow : public Window
	{
	public:
		MSWindowsWindow(const WindowProps& windowProps);
		virtual ~MSWindowsWindow();


		virtual void Init() override;
		virtual void OnUpdate() override;
		virtual void ShutDown() override;

		virtual void* GetNativeWindow() override { return m_WindowProps.Window; }

		virtual uint32_t GetWidth() const override { return m_WindowProps.Width; }
		virtual uint32_t GetHeight() const override { return m_WindowProps.Height; }

		virtual bool GetVSync() const override { return m_WindowProps.VSync; }
		virtual void SetVSync(bool enable) override;

		void SetEventCallBackFunction(std::function<void(Event&)> function) override { m_WindowProps.EventCallBackFunction = function; }
	
	private:
		void SetCallBacks();

	private:
		WindowProps m_WindowProps;
	};
}