#include "EuropaEditorApp.h"

#include <EuropaEngine/Core/EntryPoint.h>

extern EuropaEngine::Application* EuropaEngine::CreateApplication()
{
	return new EuropaEngine::EuropaEditorApp();
}