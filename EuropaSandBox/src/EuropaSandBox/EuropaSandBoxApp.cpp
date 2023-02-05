#include "EuropaSandboxApp.h"

#include <EuropaEngine/DataStructures/LinkedList.h>
#include <EuropaEngine/DataStructures/Stack.h>
#include <EuropaEngine/DataStructures/Queue.h>
#include <EuropaEngine/DataStructures/BTree.h>

#include "TestClasses/Test.h"


namespace EuropaSandBox
{
	EuropaSandBoxApp::EuropaSandBoxApp()
		:
		Application()
	{
		using namespace EuropaEngine;
		
		Stack<Test> stack1;
		stack1.Push(Test(10));
		stack1.Push(Test(20));
		stack1.Push(Test(30));
		stack1.Push(Test(40));


		std::cout << "Stack1: " << stack1 << std::endl;
		
		Stack<Test> stack2(std::move(stack1));
		
		std::cout << "Stack1: " << stack1 << std::endl;
		std::cout << "Stack2: " << stack2 << std::endl;


		std::cout << "end" << std::endl;
		std::cin.get();
	}
	void EuropaSandBoxApp::Run()
	{
		std::cout << "end" << std::endl;
		std::cout << "end" << std::endl;

	}
	void EuropaSandBoxApp::Close()
	{
		//std::cin.get();
	}
}