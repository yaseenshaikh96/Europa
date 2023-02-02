#pragma once

#include "EuropaEnginePCH.h"

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
	public:
		t_Type& Data() { return &m_Data; }

		BTreeNode<t_Type>* GetLeftChild() const { return m_LeftChild; }
		void SetLeftChild(BTreeNode<t_Type>* leftChild) { m_LeftChild = leftChild; }
		
		BTreeNode<t_Type>* GetRightChild() const { return m_RightChild; }
		void SetRightChild(BTreeNode<t_Type>* rightChild) { m_RightChild = rightChild; }
		
		BTreeNode<t_Type>* GetParent() const { return m_Parent; }
		void SetParent(BTreeNode<t_Type>* parent) { m_Parent = parent; }


	private:
		BTreeNode<t_Type>* m_Parent;
		BTreeNode<t_Type>* m_LeftChild;
		BTreeNode<t_Type>* m_RightChild;
		t_Type m_Data;
	};

	/************************************************************************************************************************************************/
	/* BTree */
	/************************************************************************************************************************************************/
	template<typename t_Type>
	class BTree
	{
	public:
		BTree()
		{}

	public:
		void Add(const t_Type& data)
		{
			BTreeNode<t_Type>* newNode = new BTreeNode<t_Type>(data);

			if (!m_Root)
			{
				m_Root = newNode;
			}

		}

	private:
		BTreeNode<t_Type>* m_Root = nullptr;
		uint64_t m_Size = 0;
	};


}