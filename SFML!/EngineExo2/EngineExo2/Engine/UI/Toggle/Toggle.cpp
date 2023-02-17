#include "Toggle.h"
#include "../../Manager/Texture/TextureManager.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include <SFML/Graphics.hpp>

#pragma region constructor
Engine::UI::Toggle::Toggle() : super()
{
    shape = new sf::RectangleShape(sf::Vector2f(40, 40));
    toggleFalseTexture = new sf::Texture();
    toggleTrueTexture = new sf::Texture();
    if (!toggleFalseTexture->loadFromFile("../Texture/toggle_invalid.png")) return;
    if (!toggleTrueTexture->loadFromFile("../Texture/toggle_valid.png")) return;

    shape->setTexture(toggleFalseTexture);
    shape->setFillColor(sf::Color::White);
}
Engine::UI::Toggle::Toggle(bool _status) : self()
{
    SetStatus(_status);
}

Engine::UI::Toggle::Toggle(const Toggle& _copy) : super(_copy)
{
    status = _copy.status;
    toggleFalseTexture = _copy.toggleFalseTexture;
    toggleTrueTexture = _copy.toggleTrueTexture;
}
#pragma endregion

#pragma region methods
void Engine::UI::Toggle::SetStatus(bool _status)
{
    status = _status;
    shape->setTexture(status ? toggleTrueTexture : toggleFalseTexture);
}
#pragma endregion

#pragma region override
void Engine::UI::Toggle::OnPointerClick(const sf::Event& _event)
{
    if (status)
    {
        shape->setTexture(toggleFalseTexture);
        SetStatus(false);
    }
    else
    {
        shape->setTexture(toggleTrueTexture);
        SetStatus(true);
    }
}

bool Engine::UI::Toggle::GetStatus()
{
    return status;
}

#pragma endregion