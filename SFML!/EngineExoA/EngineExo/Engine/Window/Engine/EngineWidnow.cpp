#include "EngineWidnow.h"
#include "../../Time/Time.h"
#include "../../Manager/GameObject/GameObjectManager.h"

Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
	textField->SetPosition(sf::Vector2f(200, 500));
	// [TOGGLE]
	toggle->SetPosition(sf::Vector2f(250, 300));
	// [SLIDER]
	slider->SetScale(sf::Vector2f(3.0f, 3.0f));
	slider->SetPosition(sf::Vector2f(250, 200));
	// [LABEL]
	text->SetString("hello");
	text->SetColor(sf::Color::Red);
	text->SetCharacterSize(50);
	text->SetScale(sf::Vector2f(4, 4));

}

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
	: super(_copy.name, _copy.width, _copy.height) { }



void Engine::Window::EngineWindow::Open()
{
	super::Open();
}

void Engine::Window::EngineWindow::OnUpdate()
{
	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	toggle->OnUpdate();
	textField->OnUpdate();
	slider->OnUpdate();
	Clear();
	Manager::GameObjectManager::Instance()->Draw(this);
	textField->Draw();
	toggle->Draw();
	slider->Draw();
	Display();
}

void Engine::Window::EngineWindow::OnClear() const
{
	super::OnClear();
}

void Engine::Window::EngineWindow::OnRecieveEvent(const sf::Event& _event) const
{
	super::OnRecieveEvent(_event);
}
