#pragma once

#include <vector>
#include <string>

namespace EuropaEngine
{

	/******************************************************************************************************************************/
	/* AppLayer */
	/******************************************************************************************************************************/
	class AppLayer
	{
	public:
		AppLayer(const std::string& name);
		virtual ~AppLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
	private:

		std::string m_Name;
	};

	/******************************************************************************************************************************/
	/* AppLayerStack */
	/******************************************************************************************************************************/
	class AppLayerStack
	{
	public:
		AppLayerStack();

		void PushLayer();
		void PopLayer();

		/*
		std::vector<AppLayer>::iterator begin();
		std::vector<AppLayer>::iterator end();
		*/

	private:
		std::vector<AppLayer> m_Layers;
	};
}