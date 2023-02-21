#include "RectangleBox.h"

Engine::UI::RectangleBox::RectangleBox(float _width, float _height)
{
	width=_width;
	height = _height;
	shape = new sf::RectangleShape(sf::Vector2f(_width, _height));
	shape->setFillColor(sf::Color::Black);
	shape->setOutlineColor(sf::Color::White);
	shape->setOutlineThickness(1.0f);

}

Engine::UI::RectangleBox::RectangleBox(const RectangleBox& _copy)
{
	width = _copy.width;
	height = _copy.height;
}

void Engine::UI::RectangleBox::SetPosition(const PrimaryType::Vector2& _position)
{
	super::SetPosition(_position);
}

void Engine::UI::RectangleBox::Draw(sf::RenderWindow* _window)
{
	super::Draw(_window);
}
