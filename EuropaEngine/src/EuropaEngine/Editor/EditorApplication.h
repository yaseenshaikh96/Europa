#pragma once

namespace EuropaEngine
{
	class EditorUIComponent
	{
	public:
		virtual void OnUIRender() = 0;
	};

	class EditorApplication
	{
	public:
		EditorApplication() = default;
		virtual ~EditorApplication() = default;

		virtual void Init() = 0;
		virtual void ShutDown() = 0;

		virtual void OnUIUpdate() = 0;
	};
}