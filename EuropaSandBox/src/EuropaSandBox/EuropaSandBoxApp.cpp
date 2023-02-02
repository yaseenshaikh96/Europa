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
	Test(Test&& other) noexcept
		:
		m_Int(other.m_Int)
	{
		other.m_Int = 0;
		std::cout << "Variable MoveCopy Constructor" << std::endl;
	}
	Test(const Test& other)
		:
		m_Int(other.m_Int)
	{
		std::cout << "Variable HardCopy Constructor" << std::endl;
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
		
		LinkedList<Test> list1;

		list1.Add(Test(10));
		list1.Add(Test(20));
		list1.Add(Test(30));
		list1.Add(Test(40));
		list1.Add(Test(50));
		
		std::cout << "List1: before move" << std::endl;
		for (auto& value : list1)
		{
			std::cout << value << std::endl;
		}

		LinkedList<Test> list2(std::move(list1));

		std::cout << "List1: after move" << std::endl;
		for (auto& value : list1)
		{
			std::cout << value << std::endl;
		}

		std::cout << "List2: move" << std::endl;
		for (auto& value : list2)
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