#include "EuropaEnginePCH.h"

#include "MSWindowsWindow.h"

#include <GLFW/glfw3.h>

namespace EuropaEngine
{
	Ref<Window> Window::Create(const WindowProps& windowProps)
	{
		return CreateRef<MSWindowsWindow>(windowProps);
	}

	MSWindowsWindow::MSWindowsWindow(const WindowProps& windowProps)
		:
		Window(windowProps)
	{}
	MSWindowsWindow::~MSWindowsWindow()
	{
		glfwDestroyWindow((GLFWwindow*)m_WindowProps.Window);
		glfwTerminate();
	}

	void MSWindowsWindow::Init()
	{
		if (!m_WindowProps.IsInitialized)
		{
			int success = glfwInit();
			EUROPA_ASSERT(success, "Could not initialze GLFW!");
			m_WindowProps.IsInitialized = true;
		}
		m_WindowProps.Window = (void*)glfwCreateWindow((int)m_WindowProps.Width, (int)m_WindowProps.Height, m_WindowProps.Title.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer((GLFWwindow*)m_WindowProps.Window, &m_WindowProps);
	
		if (m_WindowProps.VSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

	}

	void MSWindowsWindow::OnUpdate()
	{
		glfwPollEvents();
	}
}