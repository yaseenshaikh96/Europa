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
			m_Next = nullptr;
			m_Prev = nullptr;
		}
	public:


	public:
		t_Type& Data() { return m_Data; }
		const t_Type& Data() const { return m_Data; }

		LinkedListNode* Get() { return this; }

		void SetNext(LinkedListNode<t_Type>* next) 
		{
			m_Next = next;
		}
		void SetPrev(LinkedListNode<t_Type>* prev)
		{
			m_Prev = prev;
		}
		LinkedListNode* GetNext() const { return m_Next; }
		LinkedListNode* GetPrev() const { return m_Prev; }

	private:
		t_Type m_Data;
		LinkedListNode<t_Type>* m_Next = nullptr;
		LinkedListNode<t_Type>* m_Prev = nullptr;
	};

	/************************************************************************************************/
	/* LinkedList Iterators */
	/************************************************************************************************/
	template<typename t_LinkedList>
	class BaseLinkedListIterator
	{
	public:
		using t_ValueType = typename t_LinkedList::t_ValueType;
		using t_ValuePointerType = typename t_ValueType*;
		using t_ValueReferenceType = typename t_ValueType&;

		using t_NodeType = typename t_LinkedList::t_NodeType;
		using t_NodePointerType = typename t_NodeType*;
		using t_NodeReferenceType = typename t_NodeType&;
	
	public:
		BaseLinkedListIterator(t_NodePointerType ptr)
			:
			m_Ptr(ptr)
		{}

		BaseLinkedListIterator& operator+=(uint64_t offSet)
		{
			while (offSet != 0)
			{
				offSet--;
				m_Ptr = m_Ptr->GetNext();
			}
			return *this;
		}
		BaseLinkedListIterator& operator++()
		{
			m_Ptr = m_Ptr->GetNext();
			return *this;
		}
		BaseLinkedListIterator operator++(int)
		{
			BaseLinkedListIterator iterator = *this;
			++(*this);
			return iterator;
		}
		BaseLinkedListIterator& operator-=(uint64_t offSet)
		{
			while (offSet != 0)
			{
				offSet--;
				m_Ptr = m_Ptr->GetPrev();
			}
			return *this;
		}
		BaseLinkedListIterator& operator--()
		{
			m_Ptr = m_Ptr->GetPrev();
			return *this;
		}
		BaseLinkedListIterator operator--(int)
		{
			BaseLinkedListIterator iterator = *this;
			--(*this);
			return iterator;
		}

		virtual bool operator==(const BaseLinkedListIterator& other)
		{
			if (other.m_Ptr == m_Ptr)
			{
				return true;
			}
			return false;
		}
		virtual bool operator!=(const BaseLinkedListIterator& other)
		{
			return !(*this == other);
		}

	protected:
		t_NodePointerType m_Ptr;
	};

	template<typename t_LinkedList>
	class LinkedListIterator : public BaseLinkedListIterator<t_LinkedList>
	{
	public:
		using t_ValueType = typename t_LinkedList::t_ValueType;
		using t_ValuePointerType = typename t_ValueType*;
		using t_ValueReferenceType = typename t_ValueType&;

		using t_NodeType = typename t_LinkedList::t_NodeType;
		using t_NodePointerType = typename t_NodeType*;
		using t_NodeReferenceType = typename t_NodeType&;

	public:
		LinkedListIterator(t_NodePointerType ptr)
			:
			BaseLinkedListIterator<t_LinkedList>(ptr)
		{}

		t_NodePointerType operator->()
		{
			return m_Ptr;
		}
		
		t_ValueType& operator*()
		{
			return m_Ptr->Data();
		}

	};

	template<typename t_LinkedList>
	class LinkedListConstIterator : public BaseLinkedListIterator<t_LinkedList>
	{
		using t_ValueTypeConst = typename t_LinkedList::t_ValueTypeConst;
		using t_ValuePointerTypeConst = typename t_ValueTypeConst*;
		using t_ValueReferenceTypeConst = typename t_ValueTypeConst&;

		using t_NodeTypeConst = typename t_LinkedList::t_NodeTypeConst;
		using t_NodePointerTypeConst = typename t_NodeTypeConst*;
		using t_NodeReferenceTypeConst = typename t_NodeTypeConst&;

	public:
		LinkedListConstIterator(t_NodePointerTypeConst ptr)
			:
			BaseLinkedListIterator<t_LinkedList>(ptr)
		{}
		
		t_NodePointerTypeConst operator->() const
		{
			return m_Ptr;
		}
		t_ValueReferenceTypeConst operator*() const
		{
			return m_Ptr->Data();
		}
	};

	/************************************************************************************************/
	/* LinkedList */
	/************************************************************************************************/
	template<typename t_Type>
	class LinkedList
	{
	public:
		using t_ValueType = t_Type;
		using t_ValueTypeConst = const t_Type;

		using t_NodeType = LinkedListNode<t_Type>;
		using t_NodeTypeConst = const LinkedListNode<t_Type>;
		
		using Iterator = LinkedListIterator<LinkedList<t_Type>>;
		using ConstIterator = LinkedListConstIterator<LinkedList<t_Type>>;
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
			next->SetPrev(m_Tail);
			m_Tail = next;
			m_Size++;
		}
		void Add(const t_Type& data, Iterator iter)
		{
			LinkedListNode<t_Type>* newNode = new LinkedListNode<t_Type>(data);
			if (iter == begin())
			{
				m_Head->SetPrev(newNode);
				newNode->SetNext(m_Head->GetNext());
				m_Head = newNode;
				return;
			}
			LinkedListNode<t_Type>* nodeAtIter = iter->Get();

			newNode->SetNext(nodeAtIter);
			newNode->SetPrev(nodeAtIter->GetPrev());

			nodeAtIter->GetPrev()->SetNext(newNode);
			nodeAtIter->SetPrev(newNode);
		}

		void Remove(Iterator iter)
		{
			LinkedListNode<t_Type>* nodeToDelete = iter->Get();
			LinkedListNode<t_Type>* previous = nodeToDelete->GetPrev();
			LinkedListNode<t_Type>* next = nodeToDelete->GetNext();
			
			previous->SetNext(next);
			next->SetPrev(previous);
			delete nodeToDelete;
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
		
		[[nodiscard]] Iterator begin()
		{
			return LinkedListIterator<LinkedList>(m_Head);
		}
		[[nodiscard]] Iterator end()
		{
			return LinkedListIterator<LinkedList>(nullptr);
		}
		[[nodiscard]] ConstIterator begin() const
		{
			return LinkedListConstIterator<LinkedList>(m_Head);
		}
		[[nodiscard]] ConstIterator end() const
		{
			return LinkedListConstIterator<LinkedList>(nullptr);
		}

	public:
		std::string ToString() const
		{
			std::stringstream ss;
			for (auto& value : (*this))
			{
				ss << value << ", ";
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
