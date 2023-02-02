#include "EuropaSandboxApp.h"

#include <EuropaEngine/DataStructures/LinkedList.h>

#include "TestClasses/LinkedListTest.h"

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
		/*
		list1.Add(Test(30));
		list1.Add(Test(40));
		list1.Add(Test(50));
		*/
		
		std::cout << "list1 before" << std::endl;
		std::cout << list1 << std::endl;

		list1.Remove(list1.begin());

		std::cout << "list1 after" << std::endl;
		std::cout << list1 << std::endl;

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