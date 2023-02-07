#pragma once

#include <EuropaEngine.h>

namespace EuropaSandBox
{
	class ExampleLayer : public EuropaEngine::AppLayer
	{
	public:
		ExampleLayer()
			:
			EuropaEngine::AppLayer("ExampleLayer")
		{}

		virtual void OnAttach() override
		{
			EUROPA_INFO("ExampleLayer OnAttach");
		}
		virtual void OnDetach() override
		{
			EUROPA_INFO("ExampleLayer OnDetach");
		}
		virtual void OnUpdate() override
		{
			EUROPA_INFO("ExampleLayer OnUpdate");
		}
	};

	class ExampleLayer2 : public EuropaEngine::AppLayer
	{
	public:
		ExampleLayer2()
			:
			EuropaEngine::AppLayer("ExampleLayer2")
		{}

		virtual void OnAttach() override
		{
			EUROPA_INFO("ExampleLayer2 OnAttach");
		}
		virtual void OnDetach() override
		{
			EUROPA_INFO("ExampleLayer2 OnDetach");
		}
		virtual void OnUpdate() override
		{
			EUROPA_INFO("ExampleLayer2 OnUpdate");
		}
	};

	class ExampleOverlay : public EuropaEngine::AppLayer
	{
	public:
		ExampleOverlay()
			:
			EuropaEngine::AppLayer("ExampleOverlay")
		{}

		virtual void OnAttach() override
		{
			EUROPA_INFO("ExampleOverlay OnAttach");
		}
		virtual void OnDetach() override
		{
			EUROPA_INFO("ExampleOverlay OnDetach");
		}
		virtual void OnUpdate() override
		{
			EUROPA_INFO("ExampleOverlay OnUpdate");
		}
	};

	class ExampleOverlay2 : public EuropaEngine::AppLayer
	{
	public:
		ExampleOverlay2()
			:
			EuropaEngine::AppLayer("ExampleOverlay2")
		{}

		virtual void OnAttach() override
		{
			EUROPA_INFO("ExampleOverlay2 OnAttach");
		}
		virtual void OnDetach() override
		{
			EUROPA_INFO("ExampleOverlay2 OnDetach");
		}
		virtual void OnUpdate() override
		{
			EUROPA_INFO("ExampleOverlay2 OnUpdate");
		}
	};
}