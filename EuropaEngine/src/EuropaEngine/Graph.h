#pragma once

#include <iostream>

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
		~BTreeNode()
		{
		}
		void Delete()
		{
			if (Left)
			{
				Left->Delete();
				Left = nullptr;
			}

			if (Right)
			{
				Right->Delete();
				Right = nullptr;
			}

			delete this;
		}
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
		BTreeNode* Left = nullptr;
		BTreeNode* Right = nullptr;
	private:
		t_Type m_Data;
	};

	template<typename t_Type>
	class BTree
	{
	public:
		BTree(const t_Type& headData)
			:
			m_HeadNode(new BTreeNode<t_Type>(headData))
		{
		}
		~BTree()
		{
			Delete();
		}
		void Delete()
		{
			if(m_HeadNode)
			{
				delete m_HeadNode;
				m_HeadNode = nullptr;
			}
		}
	public:

		const BTreeNode<t_Type>* GetHead() const { return m_HeadNode; }

		void Test() { Print(); }
		void Print()
		{
			std::cout << "head: " << m_HeadNode->GetData() << std::endl;
			
			if (m_HeadNode->Left)
			{
				m_HeadNode->Left->Print();
			}
			if (m_HeadNode->Right)
			{
				m_HeadNode->Right->Print();
			}
		}

		void Add(const t_Type& data)
		{
			BTreeNode<t_Type>* newNode(new BTreeNode<t_Type>(data));
			BTreeNode<t_Type>* currentNode = m_HeadNode;
			
			while(true)
			{
				if (data < currentNode->GetData())
				{
					if (currentNode->Left)
					{

						if (data > currentNode->Left->GetData())
						{
							newNode->Left = currentNode->Left;
							currentNode->Left = newNode;
							break;
						}
						currentNode = currentNode->Left;
						continue;
					}
					else
					{
						currentNode->Left = newNode;
						break;
					}
				}
				else if (data > currentNode->GetData())
				{
					if (currentNode->Right)
					{
						if (data < currentNode->Right->GetData())
						{
							newNode->Right = currentNode->Right;
							currentNode->Right = newNode;
							break;
						}
						currentNode = currentNode->Right;
						continue;
					}
					else
					{
						currentNode->Right = newNode;
						break;
					}
				}
				else
				{
					delete newNode; 
					newNode = nullptr;
				}
			}
		}

	private:
		BTreeNode<t_Type>* m_HeadNode;
	};
}