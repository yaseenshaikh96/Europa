#pragma once

#include <EuropaEngine.h>
#include <EuropaEngine/Editor/EditorApplication.h>

#include <glm/glm.hpp>

namespace EuropaEngine
{
	class EuropaEditorApp : public EditorApplication
	{
	public:
		EuropaEditorApp(Ref<FrameBuffer> frameBuffer)
			:
			m_FrameBuffer(frameBuffer)
		{}

		virtual void Init() override;
		virtual void ShutDown() override;
		virtual void OnUIUpdate() override;

		void FrameBegin();
		void FrameEnd();

		void DockingBegin();
		void DockingEnd();

		void SetFrameBuffer(Ref<FrameBuffer> frameBuffer) { m_FrameBuffer = frameBuffer; }

	private:
		std::vector<EditorUIComponent> m_UIComponents;

		glm::vec2 m_ViewPortSize;
		bool m_ViewPortFocused;
		Ref<FrameBuffer> m_FrameBuffer;
	};

	extern EditorApplication* CreateEditorApplication()
	{
		return new EuropaEditorApp();
	}
}

