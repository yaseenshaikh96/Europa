#pragma once

#include <EuropaEngine/Core/Defines.h>
#include <EuropaEngine/Core/Events/Event.h>
#include <EuropaEngine/Core/AppLayer.h>

namespace EuropaEngine
{
	class ImguiLayer : public AppLayer
	{
	public:
		ImguiLayer();
		virtual ~ImguiLayer();

		virtual void OnEvent(Event& e) override;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		
		void SetBlockImGuiEvent(bool block) { m_BlockImGuiEvent = block; }

		void Begin();
		void End();
	private:
		bool m_BlockImGuiEvent = true;
	};
}


