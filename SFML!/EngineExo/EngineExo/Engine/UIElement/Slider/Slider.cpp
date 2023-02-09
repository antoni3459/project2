#include "Slider.h"
#include "../UIElement.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include <SFML/Graphics.hpp>

Engine::UI::Slider::Slider()
{
    
}

Engine::UI::Slider::Slider(float _circleInt, float _lineInt)
{
    circleInt=_circleInt;
    lineInt = _lineInt;
}


Engine::UI::Slider::Slider(float _circleInt, float _lineInt, float x, float y)
{
    circleInt = _circleInt;
    lineInt = _lineInt;
    //posLins = &UIElement(x, y);
    posCircle = sf::Vector2f(x, y);
}

bool Engine::UI::Slider::Active()
{
    sf::FloatRect positionCirlce = circle->getGlobalBounds();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (positionCirlce.contains(GetMousePosition()))
        {
            return true;
        }
    }
    return false;
}

void Engine::UI::Slider::OnUpdate()
{

    if (Active())
    {
        if (sf::Event::MouseMoved)
        {
            sf::Vector2i globalPosition = sf::Mouse::getPosition();
            posCircle.x = globalPosition.x;
        }
    }
}

void Engine::UI::Slider::OnClear() const
{
}

void Engine::UI::Slider::OnReciveEvent(const sf::Event& _event) const
{
}
