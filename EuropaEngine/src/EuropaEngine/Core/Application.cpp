#include "EuropaEnginePCH.h"
#include "Application.h"

namespace EuropaEngine
{
	Application::Application(const std::string& name)
		: m_Name(name)
	{
		WindowProps windowProps;
		windowProps.Width = 1280;
		windowProps.Height = 720;
		windowProps.Title = m_Name;
		windowProps.VSync = true;

		m_Window = Window::Create(windowProps);
		m_Window->Init();
	}

	void Application::PushLayer(Ref<AppLayer> layer)
	{
		m_AppLayerStack.PushLayer(layer);
	}
	void Application::PopLayer(Ref<AppLayer> layer)
	{
		m_AppLayerStack.PopLayer(layer);
	}
	void Application::PushOverlay(Ref<AppLayer> overlay)
	{
		m_AppLayerStack.PushOverlay(overlay);
	}
	void Application::PopOverlay(Ref<AppLayer> overlay)
	{
		m_AppLayerStack.PopOverlay(overlay);
	}
	
	void Application::Run()
	{
		while (IsRunning)
		{
			IsRunning = false;

			for (auto it = m_AppLayerStack.rbegin(); it != m_AppLayerStack.rend(); it++)
			{
				(*it)->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	void Application::Close()
	{
		EUROPA_LOG_INFO("Application::Close");
		std::cin.get();
	}

}
