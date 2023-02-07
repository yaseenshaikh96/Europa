#include "EuropaEditorApp.h"

#include "EuropaEditor/Layers/EditorLayer.h"

namespace EuropaEngine
{
	EuropaEditorApp::EuropaEditorApp()
		:
		Application("EuropaEditor")
	{

		PushLayer(CreateRef<EditorLayer>());
	}
}