#pragma once

#include "EuropaEngine/Core/AppLayer.h"
#include "EuropaEngine/Core/Window.h"

namespace EuropaEngine
{
	class Application
	{
	public:
		Application(const std::string& name = "Europa Engine Application");

		void PushLayer(Ref<AppLayer> layer);
		void PopLayer(Ref<AppLayer> layer);

		void PushOverlay(Ref<AppLayer> overlay);
		void PopOverlay(Ref<AppLayer> overlay);

		void Run();
		void Close();

		void OnEvent(Event& e);
		bool OnWindowCloseEvent(WindowCloseEvent& e);
	private:
		bool m_IsRunning = true;
		Ref<Window> m_Window;
		AppLayerStack m_AppLayerStack;
		std::string m_Name;
	};

	Application* CreateApplication();
}