#include "UIElement.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../GameObject/GameObject.h"
#include "../PrimaryType/List/List.h"

Engine::UI::UIElement::UIElement() : super("UIELement", 1920, 1080)
{
}

Engine::UI::UIElement::UIElement(float _x, float _y):super("UIELement", 1920, 1080)
{
	x = _x;
	y = _y;
}

void Engine::UI::UIElement::Open()
{
	super::Open();
	SetFrameLimit(60);
}

sf::Vector2f Engine::UI::UIElement::GetPosition()const
{
	return sf::Vector2f(x, y);
}

int Engine::UI::UIElement::GetPositionX()const
{
	return x;
}

int Engine::UI::UIElement::GetPositionY()const
{
	return y;
}

void Engine::UI::UIElement::SetPosition(int _x, int _y)
{
	x=_x;
	y = _y;
}

sf::Vector2f Engine::UI::UIElement::GetMousePosition()
{
	mouse = sf::Mouse::getPosition(*render);
	return sf::Vector2f(mouse);
}

void Engine::UI::UIElement::OnUpdate()
{

}

void Engine::UI::UIElement::OnClear() const
{
	super::OnClear();
}

void Engine::UI::UIElement::OnReciveEvent(const sf::Event& _event) const
{
	super::OnReciveEvent(_event);
}
