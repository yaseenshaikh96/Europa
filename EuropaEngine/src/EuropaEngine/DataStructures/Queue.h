#pragma once

#include "LinkedList.h"

namespace EuropaEngine
{
	template<typename t_Type>
	class Queue
	{
	public:
		Queue() {}
		Queue(const Queue& other)
		{

			if (this == &other)
			{
				return;
			}
			DeepCopy(other);
		}
		void DeepCopy(const Queue& other)
		{
			std::cout << "Queue DeepCopy" << std::endl;
			DeepDelete();
			m_List.DeepCopy(other.m_List);
		}
		void ShallowCopy(const Queue& other)
		{
			DeepDelete();
			m_List.ShallowCopy(other.m_List);
		}
		Queue<t_Type>& operator=(const Queue<t_Type>& other)
		{
			if (this == &other)
			{
				return *this;
			}
			ShallowCopy();
			return *this;
		}
		Queue(Queue<t_Type>&& other) noexcept
		{
			std::cout << "Queue MoveCopy" << std::endl;

			if (this == &other)
			{
				return;
			}
			m_List.ShallowCopy(other.m_List);
			other.ShallowDelete();
		}

		void ShallowDelete()
		{
			m_List.ShallowDelete();
		}
		void DeepDelete()
		{
			m_List.DeepDelete();
			ShallowDelete();
		}
		~Queue()
		{
		}

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