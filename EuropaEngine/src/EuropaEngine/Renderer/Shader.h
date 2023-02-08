#pragma once

#include <string>
#include <glm/glm.hpp>

namespace EuropaEngine
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual const std::string& GetName() const = 0;
		virtual void SetName(const std::string& name) = 0;
	public:
		static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		static Ref<Shader> Create(const std::string& path);
		
		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;

		virtual void SetFloat2(const std::string& name, const glm::vec2& Float2) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& Float3) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& Float4) = 0;

		virtual void SetMat3(const std::string& name, const glm::mat3& matrix) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) = 0;

	protected:
		static constexpr size_t MAX_SHADER_COUNT = 4;
	};

	class ShaderLibrary
	{
	public:
		void Add(Ref<Shader> shader);
		void Add(const std::string& name, Ref<Shader> shader);
		Ref<Shader> Get(const std::string& name);
		Ref<Shader> Load(const std::string& filePath);
		Ref<Shader> Load(const std::string& name, const std::string& filePath);
		bool Exist(const std::string& name);
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}