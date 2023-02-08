#include "EuropaEnginePCH.h"
#include "RenderCommand.h"

#include "EuropaEngine/Platforms/OpenGL/OpenGLRendererAPI.h"

namespace EuropaEngine
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}