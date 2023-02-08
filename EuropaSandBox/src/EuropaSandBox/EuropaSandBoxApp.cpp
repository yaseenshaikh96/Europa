#include "EuropaSandboxApp.h"

#include "EuropaSandBox/Layers/ExampleLayer.h"

namespace EuropaSandBox
{
	EuropaSandBoxApp::EuropaSandBoxApp()
		:
		EuropaEngine::Application("EuropaSandBox")
	{

		EuropaEngine::FrameBufferSpecification frameSpecs;
		frameSpecs.Width = 1280;
		frameSpecs.Height = 720;
		m_FrameBuffer = EuropaEngine::FrameBuffer::Create(frameSpecs);
		
		EditorApp = new EuropaEngine::EuropaEditorApp(m_FrameBuffer);
	}
}