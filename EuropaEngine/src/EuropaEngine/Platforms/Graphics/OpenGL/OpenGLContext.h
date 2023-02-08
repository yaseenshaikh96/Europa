#pragma once

#include <EuropaEngine/Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace EuropaEngine
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
	public:
		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}