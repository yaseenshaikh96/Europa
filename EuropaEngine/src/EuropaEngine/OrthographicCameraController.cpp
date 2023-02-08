#include "EuropaEnginePCH.h"
#include "OrthographicCameraController.h"

#include "EuropaEngine/Core/Input.h"
#include "EuropaEngine/Core/KeyCodes.h"

namespace EuropaEngine
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		:
		m_AspectRatio(aspectRatio),
		m_ZoomLevel(1),
		m_Rotation(rotation),
		m_Camera(-aspectRatio * m_ZoomLevel, aspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel),
		m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel })
	{
	}

	void OrthographicCameraController::OnUpdate()
	{
		if (Input::IsKeyPressed((int)Key::W))
			m_CamPos.y += m_CamMoveSpeed * 0.03f;
		else if (Input::IsKeyPressed((int)Key::S))
			m_CamPos.y -= m_CamMoveSpeed * 0.03f;
		if (Input::IsKeyPressed((int)Key::A))
			m_CamPos.x -= m_CamMoveSpeed * 0.03f;
		else if (Input::IsKeyPressed((int)Key::D))
			m_CamPos.x += m_CamMoveSpeed * 0.03f;
		
		m_Camera.SetPosition(m_CamPos);

		if(m_Rotation)
		{
			if (Input::IsKeyPressed((int)Key::Q))
				m_CamRot += m_CamRotSpeed * 0.03f;
			else if (Input::IsKeyPressed((int)Key::E))
				m_CamRot -= m_CamRotSpeed * 0.03f;
			m_Camera.SetRotation(m_CamRot);
		}
	
	}
	bool OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrollEvent>(BIND_EVENT_FUNCTION(OrthographicCameraController::OnMouseScrolled, this));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNCTION(OrthographicCameraController::OnWindowResizeEvent, this));
		return false;
	}
	bool OrthographicCameraController::OnMouseScrolled(const MouseScrollEvent& e)
	{
		m_ZoomLevel -= e.GetOffsetY() * 0.25f;
		m_ZoomLevel = std::max(0.25f, m_ZoomLevel);

		m_CamMoveSpeed = m_ZoomLevel * 1.5f;

		CalculateView();
		return false;
	}
	bool OrthographicCameraController::OnWindowResizeEvent(const WindowResizeEvent& e)
	{
		OnResize((float)e.GetWidth(), (float)e.GetHeight());
		return false;
	}
	void OrthographicCameraController::CalculateView()
	{
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
	}

	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		CalculateView();
		//m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		//m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
	}
}
