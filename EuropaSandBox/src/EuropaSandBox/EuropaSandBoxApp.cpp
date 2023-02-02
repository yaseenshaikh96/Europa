#include "EuropaSandboxApp.h"

#include <EuropaEngine/DataStructures/LinkedList.h>
#include <EuropaEngine/DataStructures/BTree.h>

#include "TestClasses/Test.h"

namespace EuropaSandBox
{
	EuropaSandBoxApp::EuropaSandBoxApp()
		:
		Application()
	{
		using namespace EuropaEngine;
		
		BTree<Test> btree;
		btree.Add(Test(20));

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