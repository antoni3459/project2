#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

#include <vector>

namespace Core
{
    namespace Event
    {
        template<typename T, typename... Params>
        class Delegate;
    }
    namespace UI
    {
        class UIElement;
        class Image;
        class Button;
        class Label;

    }
    class BaseMenu : public Object
    {
        DECLARE_CLASS_INFO (BaseMenu, Object)
    protected:
        std::vector<UI::UIElement*> elements = std::vector<UI::UIElement*>();
        class Window* owner = nullptr;
    public:
        bool isOpen = false;

    public:
        BaseMenu() = delete;
        BaseMenu(Window* _owner);
        BaseMenu(const BaseMenu& _copy);
        ~BaseMenu()override;

    public:
        virtual void SetActive(bool _status);
        virtual void Open();
        virtual void Close();
        virtual void Draw();
        virtual void OnUpdate();
        bool IsOpen() const;
        virtual void OnResize(const sf::Vector2f& _size);

    protected:
        Core::UI::Image* CreateImage(const sf::Vector2f& _position, const char* _texture);
        Core::UI::Button* CreateButton(const sf::Vector2f& _position, const char* _texture,const Event::Delegate<void>& _onClick);
        Core::UI::Label* CreateLabel(const sf::Vector2f& _position, const char* _text);

    };
}

