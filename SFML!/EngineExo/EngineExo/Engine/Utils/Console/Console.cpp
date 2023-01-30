#include "Console.h"
#include <iostream>
#include "../../PrimaryType/FString/String.h"

void Engine::Utils::Console::Log(const std::string& _msg)
{
	std::cout << "[Log] => " << _msg << std::endl;
}

void Engine::Utils::Console::Log(const Object& _msg)
{
	std::cout << "[Log] => " << _msg.ToString() << std::endl;
}

void Engine::Utils::Console::Log(const ILogger* _msg)
{
	std::cout << "[Log] => " << _msg->ToString() << std::endl;
}

void Engine::Utils::Console::LogWarning(const std::string& _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_yellow);
	std::cout << "[Warning] => " << _msg << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);

}

void Engine::Utils::Console::LogWarning(const Object& _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_yellow);
	std::cout << "[Warning] => " << _msg.ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}

void Engine::Utils::Console::LogWarning(const ILogger* _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_yellow);
	std::cout << "[Warning] => " << _msg->ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}

void Engine::Utils::Console::LogError(const std::string& _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_red);
	std::cout << "[Error] => " << _msg << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}

void Engine::Utils::Console::LogError(const Object& _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_red);
	std::cout << "[Error] => " << _msg.ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}

void Engine::Utils::Console::LogError(const ILogger* _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_red);
	std::cout << "[Error] => " << _msg->ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
