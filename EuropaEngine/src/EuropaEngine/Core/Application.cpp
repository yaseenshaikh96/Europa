#include "EuropaEnginePCH.h"
#include "Application.h"

#include <glad/glad.h>

namespace EuropaEngine
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name)
		: m_Name(name)
	{
		s_Instance = this;

		Logger::Init();

		WindowProps windowProps;
		windowProps.Width = 1280;
		windowProps.Height = 720;
		windowProps.Title = m_Name;
		windowProps.VSync = true;
		windowProps.EventCallBackFunction = BIND_EVENT_FUNCTION(Application::OnEvent, this);
		m_Window = Window::Create(windowProps);
		m_Window->Init();
		
		m_ImguiLayer = CreateRef<ImguiLayer>();
		PushOverlay(m_ImguiLayer);
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
		while (m_IsRunning)
		{
			glClearColor(0.4, 0.01, 0.5, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto it = m_AppLayerStack.rbegin(); it != m_AppLayerStack.rend(); it++)
			{
				(*it)->OnUpdate();
			}

			m_ImguiLayer->Begin();
			for (auto it = m_AppLayerStack.rbegin(); it != m_AppLayerStack.rend(); it++)
			{
				(*it)->OnImguiRender();
			}
			m_ImguiLayer->End();
			
			m_Window->OnUpdate();
		}
	}

	void Application::Close()
	{
		m_Window->ShutDown();
	}

	/************************************************************************************************************************/
	/* Events */
	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispacther(e);

		eventDispacther.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowCloseEvent, this));
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		m_IsRunning = false;
		return true;
	}
}
