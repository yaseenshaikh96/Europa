#include "EuropaEnginePCH.h"
#include "Renderer.h"

#include "EuropaEngine/Renderer/Renderer2D.h"

#include "EuropaEngine/Platforms/Graphics/OpenGL/OpenGLShader.h"

namespace EuropaEngine
{
	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData{};

	void Renderer::Init()
	{
		
		RenderCommand::Init();
		Renderer2D::Init();
	}
	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewPort(0, 0, width, height);
	}


	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}
	void Renderer::EndScene()
	{
	}
	void Renderer::Submit(const Ref<Shader> shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		dynamic_cast<EuropaEngine::OpenGLShader*>(shader.get())->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);

		dynamic_cast<EuropaEngine::OpenGLShader*>(shader.get())->UploadUniformMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}