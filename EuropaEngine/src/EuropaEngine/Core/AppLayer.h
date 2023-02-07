#pragma once

#include <vector>
#include <string>

#include "EuropaEngine/Core/Events/Event.h"
#include "EuropaEngine/Core/Defines.h"

namespace EuropaEngine
{

	/******************************************************************************************************************************/
	/* AppLayer */
	/******************************************************************************************************************************/
	class AppLayer
	{
	public:
		AppLayer(const std::string& name)
			:
			m_Name(name)
		{}
		virtual ~AppLayer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}

		virtual void OnImguiRender() {}

		virtual void OnEvent(Event& e) = 0;
	private:
		std::string m_Name;
	};

	/******************************************************************************************************************************/
	/* AppLayerStack */
	/******************************************************************************************************************************/
	class AppLayerStack
	{
	public:
		AppLayerStack() = default;
		~AppLayerStack() = default;

		void PushLayer(Ref<AppLayer> layer);
		void PopLayer(Ref<AppLayer> layer);

		void PushOverlay(Ref<AppLayer> overlay);
		void PopOverlay(Ref<AppLayer> overlay);

		std::vector<Ref<AppLayer>>::iterator begin() { return m_Layers.begin(); }
		std::vector<Ref<AppLayer>>::iterator end() { return m_Layers.end(); }

		std::vector<Ref<AppLayer>>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Ref<AppLayer>>::reverse_iterator rend() { return m_Layers.rend(); }
	private:
		std::vector<Ref<AppLayer>> m_Layers;
	};
}