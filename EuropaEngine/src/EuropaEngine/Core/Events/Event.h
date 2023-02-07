#pragma once

#include "EuropaEnginePCH.h"

namespace EuropaEngine
{

	enum class EventType
	{
		None = 0,
		MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled,
		KeyPressed, KeyReleased, KeyTyped,
		WindowResize, WindowMoved, WindowGainFocus, WindowLoseFocus, WindowClose
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= 1 << 0,
		EventCategoryInput			= 1 << 1,
		EventCategoryKeyboard		= 1 << 2,
		EventCategoryMouse			= 1 << 3,
		EventCategoryMouseButton	= 1 << 4
	};

	#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		
		inline bool IsInCategory(EventCategory category)
		{
			return (GetCategoryFlags() & category) > 0;
		}

	protected:
		bool m_Handled;
	};


	class EventDispatcher
	{
		// function that returns a bool and takes a t_EventType&
		template <typename t_EventType>
		using EventFn = std::function<bool(t_EventType&)>;

	public:
		EventDispatcher(Event& e)
			: m_Event(e)
		{}
		template <typename t_EventType>
		bool Dispatch(EventFn<t_EventType> func)
		{
			if (m_Event.GetEventType() == t_EventType::GetStaticType())
			{
				m_Event.m_Handled = func(*(t_EventType*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}