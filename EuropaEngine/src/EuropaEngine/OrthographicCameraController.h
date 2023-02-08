#pragma once

#include "EuropaEngine/Renderer/Camera.h"
#include "EuropaEngine/Core/Events/MouseEvent.h"
#include "EuropaEngine/Core/Events/ApplicationEvent.h"

namespace EuropaEngine
{
	struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() const { return Right - Left; }
		float GetHeight() const { return Top - Bottom; }
	};

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }

		void OnUpdate();
		bool OnEvent(Event& e);


		void OnResize(float width, float height);
		const OrthographicCameraBounds& GetBounds() const { return m_Bounds; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; CalculateView(); }

	private:
		void CalculateView();

		bool OnMouseScrolled(const MouseScrollEvent& e);
		bool OnWindowResizeEvent(const WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel;
		bool m_Rotation;
		
		float m_CamRot = 0;
		glm::vec3 m_CamPos = glm::vec3(0.0f);

		float m_CamMoveSpeed = 3.0f;
		float m_CamRotSpeed = 90;

		OrthographicCameraBounds m_Bounds;

		OrthographicCamera m_Camera;
	};

}