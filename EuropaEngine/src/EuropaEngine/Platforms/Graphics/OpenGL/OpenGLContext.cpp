#include "EuropaEnginePCH.h"
#include "OpenGLContext.h"


#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace EuropaEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		EUROPA_ASSERT(windowHandle, "Window Handle is null");
	}

	void OpenGLContext::Init()
	{
		

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EUROPA_ASSERT(status, "Failed to initialize Glad!");

		EUROPA_INFO("OpenGL Info: ");
		EUROPA_INFO("	vendor: {0}", (char*)(glGetString(GL_VENDOR)));
		EUROPA_INFO("	Renderer: {0}", (char*)(glGetString(GL_RENDERER)));
		EUROPA_INFO("	Version: {0}", (char*)(glGetString(GL_VERSION)));
		
		#ifdef CALLISTO_ENABLE_ASSERTS
		int minorVersion;
		int majorVersion;
		glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
		glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
			EUROPA_ASSERT(majorVersion >= 3 || (majorVersion == 3 && minorVersion >= 3), "OpenGL version 3.3 minimum required!");
		#endif // CALLISTO_ENABLE_ASSERTS


	}
	void OpenGLContext::SwapBuffers()
	{
		
		glfwSwapBuffers(m_WindowHandle);
	}
}