#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Time/Time.h"

#pragma region constructor
Engine::Window::EngineWindow::EngineWindow() :super("Engine", 1920, 1080)
{
}
#pragma endregion constructor

#pragma region method
void Engine::Window::EngineWindow::Open()
{
	super::Open();
	SetFrameLimit(60);
}

void Engine::Window::EngineWindow::OnUpdate()
{
	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	Clear();
	Manager::GameObjectManager::Instance()->Draw(this);
	Display();
}

void Engine::Window::EngineWindow::OnClear() const
{
	super::OnClear();
}

void Engine::Window::EngineWindow::OnReciveEvent(const sf::Event& _event) const
{
	super::OnReciveEvent(_event);
}
#pragma endregion method