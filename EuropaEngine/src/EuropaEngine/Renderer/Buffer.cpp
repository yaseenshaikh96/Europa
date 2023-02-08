#include "EuropaEnginePCH.h"
#include "Buffer.h"
#include "Renderer.h"

#include "EuropaEngine/Platforms/Graphics/OpenGL/OpenGLBuffer.h"

namespace EuropaEngine
{
	void BufferLayout::CalculateOffsetAndStride()
	{
		int32_t offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elements)
		{
			element.Offset = offset;
			offset += element.Size;
		}
		m_Stride = offset;
	}
	
	/**************************************************************************************************************************************************/
	/* VertexBuffer */
	/**************************************************************************************************************************************************/
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE: 
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(size);
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	/**************************************************************************************************************************************************/
	/* IndexBuffer */
	/**************************************************************************************************************************************************/
	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLIndexBuffer>(indices, count);
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}