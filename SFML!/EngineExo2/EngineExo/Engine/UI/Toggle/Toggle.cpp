#include "Toggle.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Manager/Texture/TextureManager.h"
#include <SFML/Graphics/RectangleShape.hpp>

Engine::UI::Toggle::Toggle():super()
{
	shape = new sf::RectangleShape(sf::Vector2f(40, 40));
	toggleFalseTexture = Manager::TextureManager::Instance()->GetTexture(TOGGLE_INVALID_NAME);
	toggleTrueTexture = Manager::TextureManager::Instance()->GetTexture(TOGGLE_VALID_NAME);
	shape->setTexture(toggleFalseTexture);
	shape->setFillColor(sf::Color::White);
}

Engine::UI::Toggle::Toggle(bool _status):super()
{
	SetStatus(_status);
}

Engine::UI::Toggle::Toggle(const Toggle& _copy)
{
	status = _copy.status;
	toggleFalseTexture = _copy.toggleFalseTexture;
	toggleTrueTexture = _copy.toggleTrueTexture;
	SetStatus(status);
}

void Engine::UI::Toggle::SetStatus(bool _status)
{
	status = _status;
	shape->setTexture(status ? toggleTrueTexture : toggleFalseTexture);
}

void Engine::UI::Toggle::OnPointerClick(const sf::Event& _event)
{
	SetStatus(!status);
}
