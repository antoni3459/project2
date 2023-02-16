#include "Rectangle.h"

Engine::UI::Rectangle::Rectangle(float _width, float _height)
{
	width=_width;
	height = _height;
	shape = new sf::RectangleShape(sf::Vector2f(_width, _height));
	shape->setFillColor(sf::Color::Black);
	shape->setOutlineColor(sf::Color::White);
	shape->setOutlineThickness(1.0f);

}

Engine::UI::Rectangle::Rectangle(const Rectangle& _copy)
{
	width = _copy.width;
	height = _copy.height;
}

void Engine::UI::Rectangle::SetPosition(const PrimaryType::Vector2& _position)
{
	super::SetPosition(_position);
}

void Engine::UI::Rectangle::Draw(sf::RenderWindow* _window)
{
	super::Draw(_window);
}
