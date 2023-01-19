#include "EuropaSandboxApp.h"

#include <EuropaEngine/Graph.h>

class Test
{
public:
	Test(int myInt)
		:
		m_Int(myInt)
	{
		std::cout << "Constructor!" << std::endl;
	}
public:
	int m_Int = 10;
};
std::ostream& operator<<(std::ostream& os, const Test& ref)
{
	os << ref.m_Int;
	return os;
}


namespace EuropaSandBox
{
	EuropaSandBoxApp::EuropaSandBoxApp()
		:
		Application()
	{

	}
	void EuropaSandBoxApp::Run()
	{
		using namespace EuropaEngine;
		BTree<int> bTree(1);

		bTree.Add(10);
		bTree.Add(20);
		bTree.Add(30);
		bTree.Add(40);
		bTree.Add(50);

		bTree.Print();

		std::cin.get();
	}
	void EuropaSandBoxApp::Close()
	{

	}
}