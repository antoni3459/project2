#include "UI_Elements.h"

Engine::UI::UI_Elements::UI_Elements(Window::EngineWindow* _owner)
{
    owner = _owner;
    //TODO Register dans UI_ElementsManager
}

Engine::UI::UI_Elements::UI_Elements(const UI_Elements& _copy) : super(_copy)
{
    owner = _copy.owner;
    //TODO Register
}

Engine::UI::UI_Elements::~UI_Elements()
{
    delete owner;
    owner = nullptr;
    //TODO UnRegister
}



void Engine::UI::UI_Elements::SetPosition(sf::Vector2f _position) {}


sf::Vector2f Engine::UI::UI_Elements::Position() const
{
    return sf::Vector2f();
}


void Engine::UI::UI_Elements::SetScale(sf::Vector2f _scale) {}


sf::Vector2f Engine::UI::UI_Elements::Scale() const
{
    return sf::Vector2f();
}


void Engine::UI::UI_Elements::SetOrigin(sf::Vector2f _origin) {}


sf::Vector2f Engine::UI::UI_Elements::Origin() const
{
    return sf::Vector2f();
}


sf::FloatRect Engine::UI::UI_Elements::GlobalBounds() const 
{
    return sf::FloatRect();
}



void Engine::UI::UI_Elements::Draw()
{

}

void Engine::UI::UI_Elements::OnUpdate()
{
}

void Engine::UI::UI_Elements::SetActive(bool _statue)
{
    isActive = _statue;
}

bool Engine::UI::UI_Elements::IsActive() const
{
    return isActive;
}

