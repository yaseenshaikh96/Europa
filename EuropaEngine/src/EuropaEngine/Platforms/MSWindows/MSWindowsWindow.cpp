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
		m_WindowProps(windowProps)
	{}
	MSWindowsWindow::~MSWindowsWindow()
	{
		ShutDown();
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
	
		SetVSync(true);

		SetCallBacks();
	}

	void MSWindowsWindow::OnUpdate()
	{
		glfwPollEvents();
	}

	void MSWindowsWindow::ShutDown()
	{
		glfwDestroyWindow((GLFWwindow*)m_WindowProps.Window);
		glfwTerminate();
	}

	/************************************************************************************************************************************************/

	void MSWindowsWindow::SetVSync(bool enable)
	{
		m_WindowProps.VSync = enable;
		if (m_WindowProps.VSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}


	void MSWindowsWindow::SetCallBacks()
	{
		glfwSetWindowSizeCallback((GLFWwindow*)m_WindowProps.Window,
			[](GLFWwindow* window, int width, int height)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
				data.Width = width;
				data.Height = height;
				
				WindowResizeEvent e(width, height);
				data.EventCallBackFunction(e);
			});

		glfwSetWindowCloseCallback((GLFWwindow*)m_WindowProps.Window,
			[](GLFWwindow* window)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
				WindowCloseEvent e;
				data.EventCallBackFunction(e);
			});
		
		glfwSetKeyCallback((GLFWwindow*)m_WindowProps.Window,
			[](GLFWwindow* window, int key, int scancode, int action, int mode)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key, 0);
					data.EventCallBackFunction(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key); 
					data.EventCallBackFunction(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key, 1);
					data.EventCallBackFunction(e);
					break; 
				}
				}
			});
		glfwSetCharCallback((GLFWwindow*)m_WindowProps.Window, 
			[](GLFWwindow* window, unsigned int charCode)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
				KeyTypedEvent e = (int)charCode;
				data.EventCallBackFunction(e);
			});

		glfwSetMouseButtonCallback((GLFWwindow*)m_WindowProps.Window,
			[](GLFWwindow* window, int button, int action, int mode)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					data.EventCallBackFunction(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.EventCallBackFunction(e);
					break;
				}
				}
			});

		glfwSetScrollCallback((GLFWwindow*)m_WindowProps.Window,
			[](GLFWwindow* window, double offsetX, double offsetY)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));

				MouseScrollEvent e(static_cast<float>(offsetX), static_cast<float>(offsetY));
				data.EventCallBackFunction(e);
			});

		glfwSetCursorPosCallback((GLFWwindow*)m_WindowProps.Window,
			[](GLFWwindow* window, double posX, double posY)
			{
				WindowProps& data = *static_cast<WindowProps*>(glfwGetWindowUserPointer(window));

				MouseMovedEvent e(static_cast<float>(posX), static_cast<float>(posY));
				data.EventCallBackFunction(e);
			});
	}
}