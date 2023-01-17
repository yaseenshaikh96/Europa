#pragma once

#include <iostream>
#include <string>

namespace EuropaEngine
{
	template<typename t_Type>
	class BTreeNode
	{
	public:
		BTreeNode(const t_Type& data)
			:
			m_Data(data),
			Right(nullptr),
			Left(nullptr)
		{}

	public:
		void Connect(BTreeNode* left, BTreeNode* right)
		{
			Left = left;
			Right = right;
		}

		const t_Type& GetData() const { return m_Data; }
		void GetData(const t_Type& data) { m_Data = data; }

		void Print()
		{
			std::cout << "data: " << m_Data << std::endl;
			if (Left)
			{
				Left->Print();
			}
			if (Right)
			{
				Right->Print();
			}
		}

	public:
		BTreeNode* Left;
		BTreeNode* Right;
	private:
		t_Type m_Data;
	};

	template<typename t_Type>
	class BTree
	{
	public:
		BTree(const t_Type& headData)
			:
			m_HeadNode(headData)
		{
			BTreeNode<t_Type> node1(10);
			BTreeNode<t_Type> node2(20);
			BTreeNode<t_Type> node3(30);
			BTreeNode<t_Type> node4(40);
			BTreeNode<t_Type> node5(50);
		
			m_HeadNode.Connect(&node1, &node2);
			node1.Connect(&node3, &node4);
			node2.Connect(&node5, nullptr);

			Print();
		}

	public:
		void Print()
		{
			std::cout << "head: " << m_HeadNode.GetData() << std::endl;
			
			if (m_HeadNode.Left)
			{
				m_HeadNode.Left->Print();
			}
			if (m_HeadNode.Right)
			{
				m_HeadNode.Right->Print();
			}
		}

	private:
		BTreeNode<t_Type> m_HeadNode;
	};
}