#pragma once

#include "EuropaEngine/Renderer/Camera.h"
#include "EuropaEngine/Renderer/Texture.h"
#include "EuropaEngine/Renderer/SubTexture2D.h"

namespace EuropaEngine
{
	class Renderer2D
	{
	public:
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;

			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndicesCount() { return QuadCount * 6; }
		};

	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void BeginScene(const Camera& camera, glm::mat4 transform);
		static void EndScene();

		static void Flush();
		
		
		static void DrawAxisAlignedQuadFilled(const glm::vec2& position, const glm::vec2& size, glm::vec4 color = glm::vec4(0.0f));
		static void DrawAxisAlignedQuadFilled(const glm::vec3& position, const glm::vec2& size, glm::vec4 color = glm::vec4(0.0f));

		static void DrawAxisAlignedQuadFilled(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec2& texScale, const glm::vec4& tintColor);
		static void DrawAxisAlignedQuadFilled(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec2& texScale, const glm::vec4& tintColor);

		static void DrawAxisAlignedQuadFilled(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& subTexture, const glm::vec2& texScale, const glm::vec4& tintColor);
		static void DrawAxisAlignedQuadFilled(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& subTexture, const glm::vec2& texScale, const glm::vec4& tintColor);

		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color);
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, const glm::vec2& texScale, const glm::vec4& tintColor);
		static void DrawQuad(const glm::mat4& transform, const Ref<SubTexture2D>& subTexture, const glm::vec2& texScale, const glm::vec4& tintColor);

		static void DrawRotatedQuadFilled(const glm::vec2& position, const glm::vec2& size, float rotation, glm::vec4 color = glm::vec4(0.0f));
		static void DrawRotatedQuadFilled(const glm::vec3& position, const glm::vec2& size, float rotation, glm::vec4 color = glm::vec4(0.0f));

		static void DrawRotatedQuadFilled(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, const glm::vec2& texScale, const glm::vec4& tintColor);
		static void DrawRotatedQuadFilled(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, const glm::vec2& texScale, const glm::vec4& tintColor);

		static void DrawRotatedQuadFilled(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& subTexture, const glm::vec2& texScale, const glm::vec4& tintColor);
		static void DrawRotatedQuadFilled(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& subTexture, const glm::vec2& texScale, const glm::vec4& tintColor);

		static void ResetStatistics();
		static Statistics GetStatistics();
	private:
		static void FlushAndReset();
	public:
		struct QuadVertex
		{
			glm::vec3 Position;
			glm::vec4 Color;
			float TexIndex;
			glm::vec2 TexCoord;
			glm::vec2 TexScale;
			// normal, texture id, etc
		};

		static const uint32_t MAX_TEXTURE_SLOTS;
	private:
		static const uint32_t MAX_QUAD_COUNT_PER_DRAW;
		static const uint32_t MAX_VERTICES_COUNT_PER_DRAW;
		static const uint32_t MAX_INDICES_COUNT_PER_DRAW;
	};
}