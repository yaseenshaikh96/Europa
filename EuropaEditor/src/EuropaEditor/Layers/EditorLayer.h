#pragma once

#include <EuropaEngine.h>

namespace EuropaEngine
{
	class EditorLayer : public AppLayer
	{
	public:
		EditorLayer();
		~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		
		virtual void OnEvent(Event& e) override;

		virtual void OnImguiRender() override;

	private:
		bool m_ViewPortFocused = false;
		float m_CubeRotation = 0.0f;
		glm::vec4 m_Color;
		Ref<FrameBuffer> m_FrameBuffer;
		glm::vec2 m_ViewPortSize;
		glm::mat4 m_CameraTransform;
		//Camera m_Camera;
		OrthographicCameraController m_OrthographicCameraController;
	};
}