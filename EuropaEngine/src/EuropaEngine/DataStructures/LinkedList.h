#pragma once

#include <iostream>
#include <string>
#include <sstream>

namespace EuropaEngine
{
	/************************************************************************************************/
	/* LinkedListNode */
	/************************************************************************************************/
	template<typename t_Type>
	class LinkedListNode
	{
	public:
		LinkedListNode(const t_Type& data)
			:
			m_Data(data)
		{}
		~LinkedListNode()
		{
		}
	public:


	public:
		t_Type& Data() { return m_Data; }
		const t_Type& Data() const { return m_Data; }

		void SetNext(LinkedListNode<t_Type>* next) { m_Next = next; }
		LinkedListNode* GetNext() const { return m_Next; }

	private:
		t_Type m_Data;
		LinkedListNode<t_Type>* m_Next = nullptr;
	};

	/************************************************************************************************/
	/* LinkedList Iterators */
	/************************************************************************************************/
	template<typename t_LinkedList>
	class LinkedListIterator
	{
		using t_NodeValueType = typename t_LinkedList::t_ValueType;
		using t_NodeValuePointerType = typename t_NodeValueType*;
		using t_NodeValueReferenceType = typename t_NodeValueType&;

		using t_NodeType = typename t_LinkedList::t_NodeType;
		using t_NodePointerType = typename t_NodeType*;
		using t_NodeReferenceType = typename t_NodeType&;

	public:
		LinkedListIterator(t_NodePointerType head, t_NodePointerType ptr)
			:
			m_Head(head),
			m_Ptr(ptr)
		{}

		LinkedListIterator& operator++()
		{
			m_Ptr = m_Ptr->GetNext();
			return *this;
		}
		LinkedListIterator operator++(int)
		{
			LinkedListIterator iterator = *this;
			++(*this);
			return iterator;
		}
		LinkedListIterator& operator--()
		{
			t_NodePointerType next = m_Head;
			while (next)
			{
				if (next->GetNext() == m_Ptr)
				{
					m_Ptr = next;
					return *this;
				}
				next = next->GetNext();
			}
			return *this;
		}
		LinkedListIterator operator--(int)
		{
			LinkedListIterator iterator = *this;
			--(*this);
			return iterator;
		}

		t_NodeValueReferenceType operator[](uint64_t index)
		{
			uint64_t i = 0;
			t_NodePointerType next = m_Head;

			while (i != index)
			{
				i++;
				next = next->GetNext();
			}
			return next->Data();
		}
		t_NodePointerType operator->()
		{
			return m_Ptr;
		}

		bool operator==(const LinkedListIterator& other)
		{
			if (other.m_Ptr == m_Ptr)
			{
				return true;
			}
			return false;
		}
		bool operator!=(const LinkedListIterator& other)
		{
			return !(*this == other);
		}

		t_NodeType& operator*()
		{
			return *m_Ptr;
		}


	private:
		t_NodePointerType m_Head;
		t_NodePointerType m_Ptr;
	};

	/************************************************************************************************/
	/* LinkedList */
	/************************************************************************************************/
	template<typename t_Type>
	class LinkedList
	{
	public:
		using t_ValueType = t_Type;
		using t_NodeType = LinkedListNode<t_Type>;
		using Iterator = LinkedListIterator<LinkedList<t_Type>>;
	public:
		LinkedList(const t_Type& headData)
			:
			m_Head(new LinkedListNode<t_Type>(headData)),
			m_Tail(m_Head),
			m_Size(1)
		{}
		~LinkedList()
		{
			Delete();
		}
		void Delete()
		{
			LinkedListNode<t_Type>* temp;
			LinkedListNode<t_Type>* next = m_Head->GetNext();
			delete m_Head;
			m_Head = nullptr;
			while (next)
			{
				temp = next;
				next = next->GetNext();
				delete temp;
			}
		}
	public:
		void Add(const t_Type& data)
		{
			LinkedListNode<t_Type>* next = new LinkedListNode<t_Type>(data);
			m_Tail->SetNext(next);
			m_Tail = next;
			m_Size++;
		}

	public:
		t_Type& At(uint64_t index)
		{
			if (index >= m_Size)
			{
				__debugbreak();
			}
			return (*this)[index];
		}
		t_Type& operator[](uint64_t index)
		{
			size_t i = 0;
			LinkedListNode<t_Type>* next = m_Head;

			while (i != index)
			{
				i++;
				next = next->GetNext();
			}
			return next->Data();
		}
		
		Iterator begin()
		{
			return LinkedListIterator<LinkedList>(m_Head, m_Head);
		}
		Iterator end()
		{
			return LinkedListIterator<LinkedList>(m_Head, nullptr);
		}

	public:
		std::string ToString() const
		{
			std::stringstream ss;
			ss << m_Head->Data();
			LinkedListNode<t_Type>* next = m_Head->GetNext();
			while (next)
			{
				ss << ", " << next->Data();
				next = next->GetNext();
			}
			return ss.str();
		}

	private:
		uint64_t m_Size;
		LinkedListNode<t_Type>* m_Head;
		LinkedListNode<t_Type>* m_Tail;
	};


	template<typename t_Type>
	std::ostream& operator<<(std::ostream& os, const LinkedList<t_Type>& ref)
	{
		os << ref.ToString();
		return os;
	}

	template<typename t_Type>
	std::ostream& operator<<(std::ostream& os, const LinkedListNode<t_Type>& ref)
	{
		os
			<< "Data: " << ref.Data() << "\n"
			<< "Next: " << (ref.GetNext() ? ref.GetNext() : 0)
			<< std::endl ;
		return os;
	}
}
