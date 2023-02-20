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
#include "../../UI/Label/Label.h"
#include "../../ATest/ATest.h"
#include "../../UI/Label/Label.h"
#include <string>
#include <format>


Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
}

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
    : super(_copy.name, _copy.width, _copy.height) { }

void Engine::Window::EngineWindow::Test()
{
    ATest atest = ATest();
    atest.OpenTest();
    isClick = true;
}

void Engine::Window::EngineWindow::Open()
{
    UI::Rectangle* rectangleHor = new UI::Rectangle(1700, 230);
    rectangleHor->SetPosition(PrimaryType::Vector2(10, 700));

    UI::Rectangle* rectangleVert = new UI::Rectangle(300, 688);
    rectangleVert->SetPosition(PrimaryType::Vector2(1410, 10));

    UI::Rectangle* rectangleAsset = new UI::Rectangle(140, 50);
    rectangleAsset->SetPosition(PrimaryType::Vector2(10, 649));

    UI::Label* labelAsset = new UI::Label("Asset", 25);
    labelAsset->SetPosition(PrimaryType::Vector2(47, 655));

    UI::Rectangle* rectangleInspector = new UI::Rectangle(300, 70);
    rectangleInspector->SetPosition(PrimaryType::Vector2(1410, 10));

    UI::Label* labelInspector = new UI::Label("Inspector", 25);
    labelInspector->SetPosition(PrimaryType::Vector2(1500, 25));

    UI::Button* Asset = new UI::Button("Asset", 100, 100,18);
    Asset->AddListener(this, &EngineWindow::Test);
    Asset->SetPosition(PrimaryType::Vector2(200, 760));

    super::Open();
}

void Engine::Window::EngineWindow::OnUpdate()
{
    if (isClick)
    {
        ATest* at = nullptr;
        at = at->slider;
        pourcentage = new UI::Label(std::to_string(at->slider->GetCurrentValue()).c_str());
        pourcentage->SetPosition(PrimaryType::Vector2(1510, 255));
    }
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
