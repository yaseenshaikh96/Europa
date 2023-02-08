#include "EuropaEnginePCH.h"
#include "FrameBuffer.h"

#include "EuropaEngine/Renderer/RendererAPI.h"
#include "EuropaEngine/Platforms/Graphics/OpenGL/OpenGLFrameBuffer.h"

namespace EuropaEngine
{
	Ref<FrameBuffer> FrameBuffer::Create(const FrameBufferSpecification& specs)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLFrameBuffer>(specs);
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
}