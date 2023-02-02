#pragma once

#include "LinkedList.h"

namespace EuropaEngine
{

	template<typename t_Type>
	class Stack
	{
	public:
		void Push(const t_Type& data)
		{
			m_List.Add(data, m_List.begin());
		}
		void Push(t_Type&& data)
		{
			m_List.Add(std::move(data), m_List.begin());
		}
		t_Type&& Pop()
		{
			return std::move(m_List.Remove(m_List.begin()));
		}

	public:
		std::string ToString() const
		{
			std::stringstream ss;
			ss << "[ " << m_List.ToString() << " ]";
			return ss.str();
		}
	private:
		LinkedList<t_Type> m_List;
	};

	template<typename t_Type>
	std::ostream& operator<<(std::ostream& os, const Stack<t_Type>& ref)
	{
		os << ref.ToString();
		return os;
	}
}