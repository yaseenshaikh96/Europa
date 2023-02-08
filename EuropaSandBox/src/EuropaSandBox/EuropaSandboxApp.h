#pragma once

#include <EuropaEngine.h>
#include <EuropaEditor/EuropaEditorApp.h>

namespace EuropaSandBox
{
	class EuropaSandBoxApp : public EuropaEngine::Application
	{
	public:
		EuropaSandBoxApp();
	private:
		EuropaEngine::Ref<EuropaEngine::FrameBuffer> m_FrameBuffer;
		EuropaEngine::EuropaEditorApp* EditorApp;
	};
}

