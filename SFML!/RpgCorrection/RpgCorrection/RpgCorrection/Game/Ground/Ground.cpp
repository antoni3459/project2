#include "Ground.h"
#include "../../Core/Window/Window.h"
#include "../../Core/Utils/Debug/Debug.h"

Game::Ground::Ground::Ground(const sf::Vector2f& _size, const sf::Color& _color) :super()
{
	rectShape = new sf::RectangleShape(_size);
	rectShape->setFillColor(_color);
}

void Game::Ground::Ground::Draw(Core::Window* _window)
{
	_window->Draw(rectShape);
}

void Game::Ground::Ground::SetPosition(const sf::Vector2f& _position)
{
	checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")

	rectShape->setPosition(_position);
}

void Game::Ground::Ground::SetOrigin(const sf::Vector2f& _origin)
{
	checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")
		rectShape->setOrigin(_origin);

}

void Game::Ground::Ground::SetScale(const sf::Vector2f& _scale)
{
	checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")
		rectShape->setScale(_scale);
}

sf::Vector2f Game::Ground::Position() const
{
	check((rectShape != nullptr), "[Ground] => rectShape is nullptr", sf::Vector2f(0, 0))
		return rectShape->getPosition();
}

sf::FloatRect Game::Ground::GlobalBounds() const
{
	check((rectShape != nullptr), "[Ground] => rectShape is nullptr", sf::FloatRect(0, 0, 0, 0))
		return rectShape->getGlobalBounds();
}
