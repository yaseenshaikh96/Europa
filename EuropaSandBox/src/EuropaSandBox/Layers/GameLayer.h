#pragma once

#include <EuropaEngine.h>

namespace EuropaSandBox
{
	class GameLayer : public EuropaEngine::AppLayer
	{
	public:
		GameLayer(EuropaEngine::Ref<EuropaEngine::FrameBuffer> frameBuffer)
			:
			EuropaEngine::AppLayer("GameLayer"),
			m_FrameBuffer(frameBuffer)
		{}

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(EuropaEngine::Event& e) override;

	private:
		myUIComponent m_UICompoenet;

		EuropaEngine::Ref<EuropaEngine::FrameBuffer> m_FrameBuffer;
	};

	class myUIComponent : EuropaEngine::EditorUIComponent
	{
	public:
		virtual void OnUIRender() override;
	};
}