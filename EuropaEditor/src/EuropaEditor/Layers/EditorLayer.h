#pragma once

#include <EuropaEngine.h>

namespace EuropaEngine
{
	class EditorLayer : public AppLayer
	{
	public:
		EditorLayer();
		~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		
		virtual void OnEvent(Event& e) override;

		virtual void OnImguiRender() override;
	};
}