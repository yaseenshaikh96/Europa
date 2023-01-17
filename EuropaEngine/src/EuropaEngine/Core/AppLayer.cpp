#include "EuropaEnginePCH.h"

#include "AppLayer.h"

namespace EuropaEngine
{
	/******************************************************************************************************************************/
	/* AppLayer */
	/******************************************************************************************************************************/
	AppLayer::AppLayer(const std::string& name)
		: m_Name(name)
	{}
	AppLayer::~AppLayer()
	{}

	void AppLayer::OnAttach()
	{}
	void AppLayer::OnDetach()
	{}
	void AppLayer::OnUpdate()
	{}


	/******************************************************************************************************************************/
	/* AppLayerStack */
	/******************************************************************************************************************************/
	AppLayerStack::AppLayerStack()
	{}

	void AppLayerStack::PushLayer()
	{
	}
	void AppLayerStack::PopLayer()
	{}

	/*
	std::vector<AppLayer>::iterator AppLayerStack::begin()
	{}
	std::vector<AppLayer>::iterator AppLayerStack::end()
	{}
	*/
}