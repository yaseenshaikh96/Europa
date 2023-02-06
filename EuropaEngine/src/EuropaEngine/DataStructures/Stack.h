#pragma once

#include "LinkedList.h"

namespace EuropaEngine
{
	template<typename t_Type>
	class Stack
	{
	public:
		Stack() {}
		Stack(const Stack& other)
		{
			if (this == &other)
			{
				return;
			}
			DeepCopy(other);
		}
		void DeepCopy(const Stack& other)
		{
			std::cout << "Stack DeepCopy" << std::endl;
			DeepDelete();
			m_List.DeepCopy(other.m_List);
		}
		void ShallowCopy(const Stack& other)
		{
			DeepDelete();
			m_List.ShallowCopy(other.m_List);
		}
		Stack<t_Type>& operator=(const Stack<t_Type>& other)
		{
			if (this == &other)
			{
				return *this;
			}
			ShallowCopy();
			return *this;
		}
		Stack(Stack<t_Type>&& other) noexcept
		{
			std::cout << "Stack MoveCopy" << std::endl;

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
		~Stack()
		{
		}
	public:
		uint64_t Size() const { return m_List.Size(); }

		bool IsEmpty()
		{

		}
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
	std::ostream& operator<<(std::ostream& os, const Stack<t_Type>& ref)
	{
		os << ref.ToString();
		return os;
	}
}