#pragma once

#include "LinkedList.h"

namespace EuropaEngine
{
	template<typename t_Type>
	class Queue
	{
	public:
		void Enqueue(const t_Type& data)
		{
			m_List.Add(data, m_List.end());
		}
		void Enqueue(t_Type&& data)
		{
			m_List.Add(std::move(data), m_List.end());
		}
		t_Type&& Dequeue()
		{
			return std::move(m_List.Remove(m_List.begin()));
		}
		t_Type& Peek()
		{
			return m_List[m_List.begin()];
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
	std::ostream& operator<<(std::ostream& os, const Queue<t_Type>& ref)
	{
		os << ref.ToString();
		return os;
	}
}