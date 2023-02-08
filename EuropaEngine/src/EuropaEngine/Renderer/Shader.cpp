#include "EuropaEnginePCH.h"
#include "Shader.h"

#include "EuropaEngine/Renderer/RendererAPI.h"
#include "EuropaEngine/Platforms/OpenGL/OpenGLShader.h"

namespace EuropaEngine
{
	/******************************************************************************************************************************/
	/* Shader */
	/******************************************************************************************************************************/
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::NONE:
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::NONE:
			EUROPA_ASSERT(false, "RenderAPI::NONE not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(path);
		}
		EUROPA_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
	/******************************************************************************************************************************/
	/* ShaderLibrary */
	/******************************************************************************************************************************/

	void ShaderLibrary::Add(Ref<Shader> shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}
	void ShaderLibrary::Add(const std::string& name, Ref<Shader> shader)
	{
		EUROPA_ASSERT(!Exist(name), "Shader already exist in library!");
		shader->SetName(name);
		m_Shaders[name] = shader;
	}


	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		EUROPA_ASSERT(Exist(name), "Shader doesnt exist in library!");
		return m_Shaders[name];
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& filePath)
	{
		Ref<Shader> shader = Shader::Create(filePath);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filePath)
	{
		Ref<Shader> shader = Shader::Create(filePath);
		Add(name, shader);
		return shader;
	}

	bool ShaderLibrary::Exist(const std::string& name)
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}