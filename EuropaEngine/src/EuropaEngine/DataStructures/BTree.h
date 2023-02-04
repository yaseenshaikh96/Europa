#pragma once

#include "EuropaEnginePCH.h"

#include "Stack.h"

namespace EuropaEngine
{
	template<typename t_Type>
	/************************************************************************************************************************************************/
	/* BTreeNode */
	/************************************************************************************************************************************************/
	class BTreeNode
	{
	public:
		BTreeNode(const t_Type& data)
			:
			m_Data(data)
		{}
		BTreeNode(t_Type&& data)
			:
			m_Data(std::move(data))
		{}
		void Delete()
		{
			delete m_LeftChild;
			delete m_RightChild;
			m_LeftChild = nullptr;
			m_RightChild = nullptr;
		}
		~BTreeNode()
		{
			Delete();
		}

	public:
		t_Type& Data() { return m_Data; }
		const t_Type& Data() const { return m_Data; }

		BTreeNode<t_Type>* GetLeftChild() const { return m_LeftChild; }
		void SetLeftChild(BTreeNode<t_Type>* leftChild) { m_LeftChild = leftChild; }
		
		BTreeNode<t_Type>* GetRightChild() const { return m_RightChild; }
		void SetRightChild(BTreeNode<t_Type>* rightChild) { m_RightChild = rightChild; }
		
		BTreeNode<t_Type>* GetParent() const { return m_Parent; }
		void SetParent(BTreeNode<t_Type>* parent) { m_Parent = parent; }


	private:
		BTreeNode<t_Type>* m_Parent = nullptr;
		BTreeNode<t_Type>* m_LeftChild = nullptr;
		BTreeNode<t_Type>* m_RightChild = nullptr;
		t_Type m_Data;
	};

	/************************************************************************************************************************************************/
	/* Iterators */
	/************************************************************************************************************************************************/
	template<typename t_BTree>
	class BTreeBaseIterator
	{
		// need stack
	};
	template<typename t_BTree>
	class BTreeIterator : public BTreeBaseIterator<t_BTree>
	{

	};
	template<typename t_BTree>
	class BTreeConstIterator : public BTreeBaseIterator<t_BTree>
	{

	};

	/************************************************************************************************************************************************/
	/* BTree */
	/************************************************************************************************************************************************/
	template<typename t_Type>
	class BTree
	{
		using t_ValueType = typename t_Type;
		using t_ValueTypeConst = typename const t_ValueType;

		using t_NodeType = BTreeNode<t_Type>;
		using t_NodeTypeConst = const BTreeNode<t_Type>;

		using Iterator = BTreeIterator<BTree<t_Type>>;
		using ConstIterator = BTreeConstIterator<BTree<t_Type>>;

	public:
		BTree()
		{
			BTreeNode<t_Type>* A = new BTreeNode<t_Type>(t_Type(10));
			BTreeNode<t_Type>* B = new BTreeNode<t_Type>(t_Type(20));
			BTreeNode<t_Type>* C = new BTreeNode<t_Type>(t_Type(30));
			BTreeNode<t_Type>* D = new BTreeNode<t_Type>(t_Type(40));
			BTreeNode<t_Type>* E = new BTreeNode<t_Type>(t_Type(40));
			BTreeNode<t_Type>* F = new BTreeNode<t_Type>(t_Type(40));
		
			m_Root = A;

			A->SetLeftChild(B);
			A->SetRightChild(C);

			B->SetLeftChild(D);
			B->SetRightChild(E);

			C->SetLeftChild(F);
		}
		BTree(const BTree& other)
		{
			if (this == &other)
			{
				return;
			}
			DeepCopy();
		}
		BTree& operator=(const BTree& other)
		{
			if (this == &other)
			{
				return &this;
			}
			DeepCopy();
		}
		void DeepCopy(const BTree& other)
		{
			// iterator!
		}
		void Delete()
		{
			delete m_Root;
		}
		~BTree()
		{
			Delete();
		}
	public:
		void Add(const t_Type& data)
		{
			BTreeNode<t_Type>* newNode = new BTreeNode<t_Type>(data);

			if (!m_Root)
			{
				m_Root = newNode;
			}
		}
		std::string ToString() const
		{
			std::stringstream ss;
			Stack<BTreeNode<t_Type>*> stack;
			if (!m_Root)
			{
				return "Empty Tree!";
			}
			BTreeNode<t_Type>* current;

			stack.Push(m_Root);

			while (stack.Size() != 0)
			{
				current = stack.Pop();
				ss << "Value: " << current->Data() << std::endl;
				if (current->GetLeftChild())
				{
					stack.Push(current->GetLeftChild());
				}
				if (current->GetRightChild())
				{
					stack.Push(current->GetRightChild());
				}
			}
			ss << "End!" << std::endl;
			return ss.str();
		}

	private:
		BTreeNode<t_Type>* m_Root = nullptr;
		uint64_t m_Size = 0;
	};

	template<typename t_Type>
	std::ostream& operator<<(std::ostream& os, const BTree<t_Type>& ref)
	{
		os << ref.ToString();
		return os;
	}
}