﻿#include "EventSystem.h"
#include "../../UI/Element/UIElement.h"
#include "../../UI/Interface/IPointerClickHandler.h"
#include "../../UI/Interface/IPointerEnterHandler.h"
#include "../../UI/Interface/IPointerExitHandler.h"

#pragma region constructor
Engine::Manager::EventSystem::EventSystem(const EventSystem& _copy) = default;
#pragma endregion constructor

#pragma region methods
void Engine::Manager::EventSystem::RemoveHoveredElement(const UI::UIElement* _element)
{
    std::vector<UI::UIElement*>::iterator _index = std::find(hoveredElements.begin(), hoveredElements.end(), _element);
    if (_index == hoveredElements.end()) return;
    hoveredElements.erase(_index);
}
void Engine::Manager::EventSystem::Register(UI::UIElement* _element)
{
    elements.push_back(_element);
}
void Engine::Manager::EventSystem::UnRegister(UI::UIElement* _element)
{
    std::vector<UI::UIElement*>::iterator _index = std::find(elements.begin(), elements.end(), _element);
    if (_index == elements.end()) return;
    elements.erase(_index);
}
void Engine::Manager::EventSystem::CheckPointerClickHandler(const sf::Event& _event, UI::UIElement* _element)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        IPointerClickHandler* _mouseClick = dynamic_cast<IPointerClickHandler*>(_element);
        if (_mouseClick != nullptr) _mouseClick->OnPointerClick(_event);
    }
}
void Engine::Manager::EventSystem::CheckEnterHandler(UI::UIElement* _element)
{
    if (std::find(hoveredElements.begin(), hoveredElements.end(), _element) == hoveredElements.end())
    {
        IPointerEnterHandler* _pointerEnter = dynamic_cast<IPointerEnterHandler*>(_element);
        if (_pointerEnter != nullptr)
        {
            _pointerEnter->OnPointerEnter();
            hoveredElements.push_back(_element);
        }
    }
}
void Engine::Manager::EventSystem::CheckExitHandler(UI::UIElement* _element)
{
    if (std::find(hoveredElements.begin(), hoveredElements.end(), _element) != hoveredElements.end())
    {
        IPointerExitHandler* _pointerExit = dynamic_cast<IPointerExitHandler*>(_element);
        if (_pointerExit != nullptr)
        {
            _pointerExit->OnPointerExit();
            RemoveHoveredElement(_element);
        }
    }
}
void Engine::Manager::EventSystem::Update(const sf::Event& _event, const sf::Window* _window)
{
    const sf::Vector2i _position = sf::Mouse::getPosition(*_window);
    const sf::Vector2f _mousePosition = sf::Vector2f(_position.x, _position.y);
    for (UI::UIElement* _element : elements)
    {
        if (!_element->IsActive() || !_element->CanInteract()) continue;
        if (_element->Shape()->getGlobalBounds().contains(_mousePosition))
        {
            CheckPointerClickHandler(_event, _element);
            CheckEnterHandler(_element);
        }
        else CheckExitHandler(_element);
    }
}
void Engine::Manager::EventSystem::Draw(sf::RenderWindow* _window) const
{
    for (UI::UIElement* _element : elements)
    {
        if (!_element->IsActive()) continue;
        _element->Draw(_window);
    }
}
#pragma endregion methods
#pragma region override
void Engine::Manager::EventSystem::OnDestroy()
{
    for (UI::UIElement*& _element : elements)
    {
        delete _element;
        _element = nullptr;
    }
    elements.clear();
    hoveredElements.clear();
}
#pragma endregion override
