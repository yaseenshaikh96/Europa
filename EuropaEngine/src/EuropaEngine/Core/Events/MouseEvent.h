#pragma once

#include "Event.h"

namespace EuropaEngine
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{}
		inline float GetX() const
		{
			return m_MouseX;
		}
		inline float GetY() const
		{
			return m_MouseY;
		}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << GetX() << ", " << GetY();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float offsetX, float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY)
		{}
		inline float GetOffsetX() const
		{
			return m_OffsetX;
		}
		inline float GetOffsetY() const
		{
			return m_OffsetY;
		}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << GetOffsetX() << ", " << GetOffsetY();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_OffsetX, m_OffsetY;
	};

	class MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(int button)
			: m_Button(button)
		{}
	public:
		inline int GetButton() const
		{
			return m_Button;
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouseButton)
	protected:
		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << GetButton();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << GetButton();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}