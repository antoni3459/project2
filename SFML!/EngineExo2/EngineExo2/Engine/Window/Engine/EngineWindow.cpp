#include "EngineWindow.h"

#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../PrimaryType/Vector/Vector2.h"
#include "../../Time/Time.h"
#include "../../UI/Button/Button.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../UI/Slider/Slider.h"
#include "../../UI/TextField/TextField.h"
#include "../../UI/Rectangle/Rectangle.h"
#include "../../ATest/ATest.h"

Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
}

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
    : super(_copy.name, _copy.width, _copy.height) { }

void Engine::Window::EngineWindow::Test()
{
    ATest atest = ATest();
    atest.Open();
    isClick = true;
}

void Engine::Window::EngineWindow::Open()
{
    UI::Rectangle* rectangle = new UI::Rectangle(1700, 230);
    rectangle->SetPosition(PrimaryType::Vector2(10, 700));

    UI::Rectangle* rectangle1 = new UI::Rectangle(300, 688);
    rectangle1->SetPosition(PrimaryType::Vector2(1410, 10));

    UI::Button* Asset = new UI::Button("Asset", 100, 100,18);
    Asset->AddListener(this, &EngineWindow::Test);
    Asset->SetPosition(PrimaryType::Vector2(200, 760));

    super::Open();
}

void Engine::Window::EngineWindow::OnUpdate()
{
    Time::deltaTime = clock.restart().asSeconds();
    Manager::GameObjectManager::Instance()->Update();
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
    Manager::EventSystem::Instance()->Update(currentEvent, renderer);
}
