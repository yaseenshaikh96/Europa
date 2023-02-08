#include "EuropaEnginePCH.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "EuropaEngine/Platforms/OpenGL/OpenGLVertexArray.h"

namespace EuropaEngine
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}