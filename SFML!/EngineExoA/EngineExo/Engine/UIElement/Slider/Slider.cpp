#include "Slider.h"
#include "../UIElement.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

Engine::UI::Slider::Slider(float _circleInt, float _lineInt, float x, float y) :super()
{
    circleInt = _circleInt;
    lineInt = _lineInt;
    posCircle = sf::Vector2f(x, y);
    posLine = sf::Vector2f(x, y);

    circle = new sf::CircleShape(_circleInt);
    circle->setOrigin(13,13);
    circle->setPosition(posCircle);


    line = new sf::RectangleShape(sf::Vector2f(_lineInt,3));
    line->setPosition(sf::Vector2f(posLine));
}

Engine::UI::Slider::Slider(const Slider& _copy) :super(_copy)
{
    line = _copy.line;
    circle = _copy.circle;
    posLine = _copy.posLine;
    posCircle = _copy.posCircle;

}

Engine::UI::Slider::~Slider()
{
    delete line;
    line = nullptr;
    delete circle;
    circle=nullptr;

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

bool Engine::UI::Slider::InLine()
{
    
    return false;
}

void Engine::UI::Slider::OnUpdate()
{
    if (Active())
    {
        if (sf::Event::MouseMoved)
        {
            sf::Vector2i globalPosition = sf::Mouse::getPosition();
            if (globalPosition.x < posLine.x)
            {
                return;
            }
            if (posCircle.x < lineInt + posLine.x && globalPosition.x < posLine.x)
            {
                posCircle.x = globalPosition.x;
                circle->setPosition(sf::Vector2f(posCircle.x - 8.f, posCircle.y));
                std::cout << posCircle.x << std::endl;
                
            }
            else if (posCircle.x = lineInt + posLine.x)
            {
                if (globalPosition.x > lineInt + posLine.x)
                    return;
                else
                {
                    posCircle.x = globalPosition.x;
                    circle->setPosition(sf::Vector2f(posCircle.x - 8.f, posCircle.y));
                }
            }
        }
    }
}

void Engine::UI::Slider::OnDraw()
{
    Draw(line);
    Draw(circle);
}
