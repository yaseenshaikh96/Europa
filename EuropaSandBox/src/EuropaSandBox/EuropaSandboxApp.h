#pragma once

#include <EuropaEngine.h>

namespace EuropaSandBox
{
	class EuropaSandBoxApp : public EuropaEngine::Application
	{
	public:
		EuropaSandBoxApp();
		virtual void Run() override;
		virtual void Close() override;
	};
}

