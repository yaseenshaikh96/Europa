#include "EuropaSandboxApp.h"

#include <EuropaEngine/DataStructures/LinkedList.h>
#include <EuropaEngine/DataStructures/Stack.h>

#include "TestClasses/Test.h"


namespace EuropaSandBox
{
	EuropaSandBoxApp::EuropaSandBoxApp()
		:
		Application()
	{
		using namespace EuropaEngine;
		
		Stack<Test> stack;
		stack.Push(Test(10));
		stack.Push(Test(20));
		stack.Push(Test(30));


		std::cout << "\n\n" << "stack:" << stack << std::endl;
		Test value = stack.Pop();
		std::cout << "\n\n" << "value: " << value << std::endl;
		std::cout << "\n\n" << "stack:" << stack << std::endl;


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