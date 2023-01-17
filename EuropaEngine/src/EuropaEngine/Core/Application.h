#pragma once

#include "EuropaEngine/Core/AppLayer.h"

namespace EuropaEngine
{
	class Application
	{
	public:
		Application(const std::string& name = "Europa Engine Application");

		void PushLayer();
		void PopLayer();

		virtual void Run() = 0;
		virtual void Close() = 0;
	private:
		AppLayerStack m_LayerStack;
		std::string m_Name;
	};

	Application* CreateApplication();
}