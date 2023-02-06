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

		virtual void OnUpdate() override;
		virtual void Init() override;
	};
}