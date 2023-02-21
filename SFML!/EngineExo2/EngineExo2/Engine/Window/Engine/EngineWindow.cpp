#include "EngineWindow.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../PrimaryType/Vector/Vector2.h"
#include "../../Time/Time.h"
#include "../../UI/Button/Button.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../UI/Slider/Slider.h"
#include "../../UI/TextField/TextField.h"
#include "../../UI/Rectangle/RectangleBox.h"
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
    UI::Toggle* toggle = new UI::Toggle(false);
	toggle->SetPosition(PrimaryType::Vector2(1540, 150));

	UI::TextField* textField = new UI::TextField("", "text", PrimaryType::Vector2(90, 90));
	textField->SetPosition(PrimaryType::Vector2(1530, 350));

	slider = new UI::Slider(0.0f, 100.0f, 40.0f);
	slider->SetPosition(PrimaryType::Vector2(1510, 250));

    isClick = true;
}

void Engine::Window::EngineWindow::Open()
{
    UI::RectangleBox* rectangleHor = new UI::RectangleBox(1700, 230);
    rectangleHor->SetPosition(PrimaryType::Vector2(10, 700));

    UI::RectangleBox* rectangleVert = new UI::RectangleBox(300, 688);
    rectangleVert->SetPosition(PrimaryType::Vector2(1410, 10));

    UI::RectangleBox* rectangleAsset = new UI::RectangleBox(140, 50);
    rectangleAsset->SetPosition(PrimaryType::Vector2(10, 649));

    UI::Label* labelAsset = new UI::Label("Asset", 25);
    labelAsset->SetPosition(PrimaryType::Vector2(47, 655));

    UI::RectangleBox* rectangleInspector = new UI::RectangleBox(300, 70);
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
        pourcentage = new UI::Label(std::to_string(slider->GetCurrentValue()).c_str());
        pourcentage->SetPosition(PrimaryType::Vector2(1510, 255));
    }
    Time::deltaTime = clock.restart().asSeconds();
    Manager::GameObjectManager::Instance()->Update();
    Clear();
    Manager::GameObjectManager::Instance()->Draw(this);
    Manager::EventSystem::Instance()->Draw(renderer);
    
    Display();
    pourcentage->Clear();

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
