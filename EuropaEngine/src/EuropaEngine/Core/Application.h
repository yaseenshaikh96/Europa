#pragma once

#include "EuropaEngine/Core/AppLayer.h"

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
	private:
		bool IsRunning = true;
		AppLayerStack m_AppLayerStack;
		std::string m_Name;
	};

	Application* CreateApplication();
}