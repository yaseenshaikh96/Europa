#include "EuropaSandboxApp.h"

#include <EuropaEngine/DataStructures/LinkedList.h>
#include <EuropaEngine/DataStructures/Stack.h>
#include <EuropaEngine/DataStructures/Queue.h>
#include <EuropaEngine/DataStructures/BTree.h>

#include "TestClasses/Test.h"

#include "EuropaSandBox/Layers/ExampleLayer.h"

namespace EuropaSandBox
{
	EuropaSandBoxApp::EuropaSandBoxApp()
		:
		EuropaEngine::Application("EuropaSandBox")
	{
		PushOverlay(EuropaEngine::CreateRef<ExampleOverlay>());
		PushLayer(EuropaEngine::CreateRef<ExampleLayer>());
		PushOverlay(EuropaEngine::CreateRef<ExampleOverlay2>());
		PushLayer(EuropaEngine::CreateRef<ExampleLayer2>());


		using namespace EuropaEngine;

		Stack<Test> stack;
		BTree<Test> bTree;
		LinkedList<Test> list;
		Queue<Test> queue;


	}
}