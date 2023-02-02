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
		LinkedListNode(t_Type&& data)
			:
			m_Data(std::move(data))
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
	class LinkedListIterator
	{
		using t_ValueType = typename t_LinkedList::t_ValueType;
		using t_ValuePointerType = typename t_ValueType*;
		using t_ValueReferenceType = typename t_ValueType&;

		using t_NodeType = typename t_LinkedList::t_NodeType;
		using t_NodePointerType = typename t_NodeType*;
		using t_NodeReferenceType = typename t_NodeType&;

	public:
		LinkedListIterator(t_NodePointerType ptr)
			:
			m_Ptr(ptr)
		{}
		LinkedListIterator& operator+=(uint64_t offSet)
		{
			while (offSet != 0)
			{
				offSet--;
				m_Ptr = m_Ptr->GetNext();
			}
			return *this;
		}
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
		LinkedListIterator& operator-=(uint64_t offSet)
		{
			while (offSet != 0)
			{
				offSet--;
				m_Ptr = m_Ptr->GetPrev();
			}
			return *this;
		}
		LinkedListIterator& operator--()
		{
			m_Ptr = m_Ptr->GetPrev();
			return *this;
		}
		LinkedListIterator operator--(int)
		{
			LinkedListIterator iterator = *this;
			--(*this);
			return iterator;
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

		t_ValueType& operator*()
		{
			return m_Ptr->Data();
		}

		t_NodePointerType Get()
		{
			return m_Ptr;
		}

	private:
		t_NodePointerType m_Ptr;
	};

	template<typename t_LinkedList>
	class LinkedListConstIterator
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
			m_Ptr(ptr)
		{}

		LinkedListConstIterator& operator++()
		{
			m_Ptr = m_Ptr->GetNext();
			return *this;
		}
		LinkedListConstIterator operator++(int)
		{
			LinkedListConstIterator iterator = *this;
			++(*this);
			return iterator;
		}
		LinkedListConstIterator& operator--()
		{
			m_Ptr = m_Ptr->GetPrev();
			return *this;
		}
		LinkedListConstIterator operator--(int)
		{
			LinkedListConstIterator iterator = *this;
			--(*this);
			return iterator;
		}
		t_NodePointerTypeConst operator->() const
		{
			return m_Ptr;
		}

		bool operator==(const LinkedListConstIterator& other) const
		{
			if (other.m_Ptr == m_Ptr)
			{
				return true;
			}
			return false;
		}
		bool operator!=(const LinkedListConstIterator& other) const
		{
			return !(*this == other);
		}

		t_ValueReferenceTypeConst operator*() const
		{
			return m_Ptr->Data();
		}

	private:
		t_NodePointerTypeConst m_Ptr;
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
		LinkedList()
			:
			m_Head(nullptr),
			m_Tail(m_Head),
			m_Size(0)
		{}
		LinkedList(const LinkedList<t_Type>& other)
			:
			LinkedList()
		{
			DeepCopy(other);
		}
		void DeepCopy(const LinkedList<t_Type>& other)
		{
			Delete();

			const LinkedListNode<t_Type>* next = other.m_Head;
			while (next)
			{
				Add(next->Data());
				next = next->GetNext();
			}
		}
		LinkedList<t_Type> operator=(const LinkedList<t_Type>& other)
		{
			return LinkedList<t_Type>(other);
		}
		LinkedList(LinkedList<t_Type>&& other) noexcept
			:
			LinkedList()
		{
			std::cout << "Moved!" << std::endl;

			m_Head = other.m_Head;
			m_Tail = other.m_Tail;
			m_Size = other.m_Size;

			other.m_Head = nullptr;
			other.m_Tail = nullptr;
			other.m_Size = 0;
		}

		void Delete()
		{
			if (!m_Head)
			{
				return;
			}
			LinkedListNode<t_Type>* temp;
			LinkedListNode<t_Type>* next = m_Head;
			while (next)
			{
				temp = next;
				next = next->GetNext();
				delete temp;
			}
			m_Head = nullptr;
		}
		~LinkedList()
		{
			Delete();
		}

	
	public:
		void Add(t_Type&& data)
		{
			InternalAdd(new LinkedListNode<t_Type>(data));
		}
		void Add(const t_Type& data)
		{
			InternalAdd(new LinkedListNode<t_Type>(data));
		}
		void Add(const t_Type& data, Iterator iter)
		{
			InternalIterAdd(new LinkedListNode<t_Type>(data), iter);
		}
		void Add(t_Type&& data, Iterator iter)
		{
			InternalIterAdd(new LinkedListNode<t_Type>(data), iter);
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
	private:
		void InternalAdd(LinkedListNode<t_Type>* newNode)
		{
			if (!m_Head)
			{
				m_Head = newNode;
				m_Tail = m_Head;
			}
			else
			{
				m_Tail->SetNext(newNode);
				newNode->SetPrev(m_Tail);
				m_Tail = newNode;
			}
			m_Size++;
		}
		void InternalIterAdd(LinkedListNode<t_Type>* newNode, Iterator iter)
		{
			if (iter == begin())
			{
				if (!m_Head)
				{
					m_Head = newNode;
					m_Head->SetNext(m_Tail);
					return;
				}


				m_Head->SetPrev(newNode);
				newNode->SetNext(m_Head);
				m_Head = newNode;
				return;
			}

			LinkedListNode<t_Type>* nodeAtIter = iter->Get();

			newNode->SetNext(nodeAtIter);
			newNode->SetPrev(nodeAtIter->GetPrev());

			nodeAtIter->GetPrev()->SetNext(newNode);
			nodeAtIter->SetPrev(newNode);
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
		LinkedList<t_Type> Reverse()
		{
			LinkedList<t_Type> reverseList;
			LinkedListNode<t_Type>* prev = m_Tail;
			while (prev)
			{
				reverseList.Add(prev->Data());
				prev = prev->GetPrev();
			}
			return reverseList;
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
		LinkedListNode<t_Type>* m_Head;
		LinkedListNode<t_Type>* m_Tail;
		uint64_t m_Size;
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
			<< std::endl;
		return os;
	}
}
