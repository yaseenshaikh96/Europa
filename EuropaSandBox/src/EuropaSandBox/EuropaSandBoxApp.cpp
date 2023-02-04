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
		
		BTree<Test> btree;
		std::cout << btree << std::endl;


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