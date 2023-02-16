#include "EngineWindow.h"

#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../PrimaryType/Vector/Vector2.h"
#include "../../Time/Time.h"
#include "../../UI/Button/Button.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../UI/Slider/Slider.h"
#include "../../UI/TextField/TextField.h"

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
    UI::Button* asset= new UI::Button("Asset", 250, 40);
    asset->AddListener(this, &EngineWindow::Test);
    asset->SetPosition(PrimaryType::Vector2(100, 50));

    UI::Toggle* toggle = new UI::Toggle(false);
    toggle->SetPosition(PrimaryType::Vector2(100, 150));

    UI::Slider* slider = new UI::Slider(0.0f, 100.0f, 50.0f);
    slider->SetPosition(PrimaryType::Vector2(100, 250));

    UI::TextField* textField = new UI::TextField("", "text", PrimaryType::Vector2(100, 250));
    textField->SetPosition(PrimaryType::Vector2(100, 250));

    /*UI::Button* button = new UI::Button("Play", 250, 40);
    button->AddListener(this, &EngineWindow::Test);
    button->SetPosition(PrimaryType::Vector2(100, 50));

    UI::Toggle* toggle = new UI::Toggle(false);
    toggle->SetPosition(PrimaryType::Vector2(100, 150));

    UI::Slider* slider = new UI::Slider(0.0f, 100.0f, 50.0f);
    slider->SetPosition(PrimaryType::Vector2(100, 250));*/
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
