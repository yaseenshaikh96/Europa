#include "EuropaEnginePCH.h"

#include "AppLayer.h"

namespace EuropaEngine
{
	/******************************************************************************************************************************/
	/* AppLayer */
	/******************************************************************************************************************************/



	/******************************************************************************************************************************/
	/* AppLayerStack */
	/******************************************************************************************************************************/

	void AppLayerStack::PushLayer(Ref<AppLayer> layer)
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); it++)
		{
			EUROPA_ASSERT((*it) != layer, "LayerStack cannot have dupicates!");
		}	
		m_Layers.push_back(layer);
		layer->OnAttach();
	}
	void AppLayerStack::PopLayer(Ref<AppLayer> layer)
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); it++)
		{
			if ((*it) == layer)
			{
				m_Layers.erase(it);
				layer->OnDetach();
				return;
			}
		}
		EUROPA_ASSERT(false, "Trying to delete layer but doesnt exist on the stack!");
	}

	void AppLayerStack::PushOverlay(Ref<AppLayer> overlay)
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); it++)
		{
			EUROPA_ASSERT((*it) != overlay, "LayerStack cannot have dupicates!");
		}
		m_Layers.insert(m_Layers.begin(), overlay);
		overlay->OnAttach();
	}
	void AppLayerStack::PopOverlay(Ref<AppLayer> overlay)
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); it++)
		{
			if ((*it) == overlay)
			{
				m_Layers.erase(it);
				overlay->OnDetach();
				return;
			}
		}
		EUROPA_ASSERT(false, "Trying to delete overlay but doesnt exist on the stack!");
	}
}