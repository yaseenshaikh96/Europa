#pragma once


extern EuropaEngine::Application* EuropaEngine::CreateApplication();

int main()
{
	EuropaEngine::Application* app = EuropaEngine::CreateApplication();
	app->Run();
}