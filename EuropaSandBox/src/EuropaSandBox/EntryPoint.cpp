#include "EuropaSandboxApp.h"

#include <EuropaEngine/Core/EntryPoint.h>

extern EuropaEngine::Application* EuropaEngine::CreateApplication()
{
	return new EuropaSandBox::EuropaSandBoxApp();
}