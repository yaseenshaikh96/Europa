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
		BTree<int> bTree(0);

		bTree.Add(-10);
		bTree.Add(-20);

		bTree.Add(10);
		bTree.Add(20);
		
		bTree.Add(-30);
		bTree.Add(-40);
		bTree.Add(-50);

		bTree.Add(30);
		bTree.Add(40);
		bTree.Add(50);


		bTree.Add(-15);
		bTree.Add(-25);

		bTree.Add(15);
		bTree.Add(25);

		bTree.Add(-35);
		bTree.Add(-45);
		bTree.Add(-55);

		bTree.Add(1235);
		bTree.Add(12);
		bTree.Add(156);

		bTree.Add(-143);
		bTree.Add(-213);

		bTree.Add(1123);
		bTree.Add(22);

		bTree.Add(-63);
		bTree.Add(-43);
		bTree.Add(-13);

		bTree.Add(23);
		bTree.Add(43);
		bTree.Add(13);

		bTree.Print();


		auto head = bTree.GetHead();

		std::cin.get();
	}
	void EuropaSandBoxApp::Close()
	{

	}
}