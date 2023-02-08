#include "EuropaEnginePCH.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace EuropaEngine
{
	static GLenum ShaderDataTypeToOpenGlType(ShaderDataType type)
	{
		switch (type)
		{
		case EuropaEngine::ShaderDataType::None:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Float:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Float2:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Float3:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Float4:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Mat3:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Mat4:	return GL_FLOAT;
		case EuropaEngine::ShaderDataType::Int:		return GL_INT;
		case EuropaEngine::ShaderDataType::Int2:	return GL_INT;
		case EuropaEngine::ShaderDataType::Int3:	return GL_INT;
		case EuropaEngine::ShaderDataType::Int4:	return GL_INT;
		case EuropaEngine::ShaderDataType::Bool:	return GL_BOOL;
		}
		EUROPA_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		
		glGenVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		
		glDeleteVertexArrays(1, &m_RendererID);
	}
	
	void OpenGLVertexArray::Bind() const
	{
		
		glBindVertexArray(m_RendererID);
	}
	void OpenGLVertexArray::UnBind() const
	{
		
		glBindVertexArray(0);
	}
	
	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		

		EUROPA_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "VertexBuffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();


		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGlType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}
	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		

		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}
}