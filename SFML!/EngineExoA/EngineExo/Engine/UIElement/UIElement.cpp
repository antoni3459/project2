#include "UIElement.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>
#include "../GameObject/GameObject.h"
#include "../PrimaryType/List/List.h"
#include "../PrimaryType/Vector2/Vector2.h"
#include "../Time/Time.h"
#include "Event/Event.h"

Engine::UI::UIElement::UIElement(const char* _label) :super()
{
	labelText.setString(_label);
	labelText.setChracterSize(12);

}

Engine::UI::UIElement::UIElement(const UIElement& _copy) :super(_copy)
{
	shape = _copy.shape;
		labelText = _copy.labelText;
		canInteract = _copy.canInteract;
		isActive = _copy.isActive;
}

Engine::UI::UIElement::~UIElement()
{
	delete shape;
	shape = nullptr;
}

void Engine::UI::UIElement::SetPosition(const PrimaryType::Vector2& _position)
{
	mouse = sf::Mouse::getPosition(*window);
	return sf::Vector2f(mouse);
}

void Engine::UI::UIElement::Update()
{
	sf::Event _event = sf::Event();
	sf::Clock _clock = sf::Clock();
	while (window->isOpen())
	{
		Time::deltaTime = _clock.restart().asSeconds();
		while (window->pollEvent(_event))
		{
			if (!window->hasFocus() && !eventIfNotFocus)continue;
			Event::currentEvent = &_event;
			OnReceiveEvent(_event);
			break;
		}
		OnUpdate();
		window->clear();
		OnDraw();
		window->display();
	}
}

void Engine::UI::UIElement::Open()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	Update();
}

void Engine::UI::UIElement::Close()
{
	if (!window->isOpen())return;
	window->close();
}

bool Engine::UI::UIElement::IsOpen() const
{
	return window->isOpen();
}

bool Engine::UI::UIElement::HasFocus() const
{
	return window->hasFocus();
}

void Engine::UI::UIElement::SetFrameLimit(const int _frame)
{
	window->setFramerateLimit(_frame);
}

void Engine::UI::UIElement::Draw(sf::Drawable* _drawable)
{
	window->draw(*_drawable);
}

void Engine::UI::UIElement::OnReceiveEvent(sf::Event& _event)
{
	Event::currentEvent = &_event;
	if (_event.type == sf::Event::Closed)
		Close();
}
