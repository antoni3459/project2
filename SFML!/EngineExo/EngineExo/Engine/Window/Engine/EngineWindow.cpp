#include "EngineWindow.h"

#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../PrimaryType/Vector/Vector2.h"
#include "../../Time/Time.h"
#include "../../UI/Button/Button.h"

Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
}

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
    : super(_copy.name, _copy.width, _copy.height) { }


void Engine::Window::EngineWindow::Test()
{
    LOG("Button Click !")
}

void Engine::Window::EngineWindow::Open()
{
    UI::Button* button = new UI::Button("Play", 200, 40);
    button->AddListener(this, &EngineWindow::Test);
    button->SetPosition(PrimaryType::Vector2(100, 50));
    super::Open();
}

void Engine::Window::EngineWindow::OnUpdate()
{
    Time::deltaTime = clock.restart().asSeconds();
    Manager::GameObjectManager::Instance()->Update();
    Manager::EventSystem::Instance()->Update(currentEvent, renderer);
    Clear();
    Manager::GameObjectManager::Instance()->Draw(this);
    Manager::EventSystem::Instance()->Draw(renderer);
    Display();
}
void Engine::Window::EngineWindow::OnClear() const
{
    super::OnClear();
}
void Engine::Window::EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
    super::OnReceiveEvent(_event);
}
