#include "EuropaSandboxApp.h"

#include <EuropaEngine/DataStructures/LinkedList.h>

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
		using namespace EuropaEngine;
		
		LinkedList<int> list(10);
		list.Add(20);
		list.Add(30);
		list.Add(40);
		list.Add(50);
		list.Add(60);
		list.Add(70);

		for (auto& value : list)
		{
			std::cout << value << std::endl;
		}
		
		list.Remove(3);

		std::cout << "***********" << std::endl;
		for (auto& value : list)
		{
			std::cout << value << std::endl;
		}

		std::cout << "end" << std::endl;
		std::cin.get();
	}
	void EuropaSandBoxApp::Run()
	{

	}
	void EuropaSandBoxApp::Close()
	{
		//std::cin.get();
	}
}