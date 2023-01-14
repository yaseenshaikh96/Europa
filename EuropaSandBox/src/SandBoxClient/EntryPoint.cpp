#include <EuropaEngine.h>
#include <EuropaEngine/Core/EntryPoint.h>

class MyApplication : public EuropaEngine::Application
{
public:
	MyApplication()
	{
		std::cout << "Hello, World!" << std::endl;
	}
	virtual void Run() override
	{
		std::cout << "Hello, World! X 2" << std::endl;
		std::cin.get();
	}
	virtual void Close() override
	{

	}
};


extern EuropaEngine::Application* EuropaEngine::CreateApplication()
{
	return new MyApplication();
}