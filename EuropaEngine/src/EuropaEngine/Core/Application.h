#pragma once

#include "EuropaEngine/Core/AppLayer.h"
#include "EuropaEngine/Core/Window.h"

#include "EuropaEngine/Editor/imgui/ImguiLayer.h"

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
	
		inline static Application& Get() { return *s_Instance; }
		inline Ref<ImguiLayer> GetImguiLayer() { return m_ImguiLayer; }
		inline Ref<Window> GetWindow() { return m_Window; }

	private:
		bool m_IsRunning = true;
		Ref<Window> m_Window;
		AppLayerStack m_AppLayerStack;
		std::string m_Name;

		Ref<ImguiLayer> m_ImguiLayer;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}