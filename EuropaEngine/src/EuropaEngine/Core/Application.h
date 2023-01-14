#pragma once

namespace EuropaEngine
{
	class Application
	{
	public:

		virtual void Run() = 0;
		virtual void Close() = 0;
	};

	Application* CreateApplication();
}