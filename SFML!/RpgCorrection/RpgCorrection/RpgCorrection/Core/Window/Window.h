#pragma once
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../Object/Object.h"

namespace Core
{
    class Window : public Object
    {
        DECLARE_CLASS_INFO(Window, Object)
#pragma region f/p
    protected:
        int width = 900;
        int height = 800;
        const char* title = "Default Window Name";
        sf::RenderWindow* render = nullptr;
        sf::Event currentEvent = sf::Event();
        sf::Clock deltaClock = sf::Clock();
        std::map<const char*, class BaseMenu*> menus = std::map<const char*, BaseMenu*>();
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Window() = delete;
        Window(int _width, int _height, const char* _title);
        Window(const Window&) = delete;
        ~Window() override;
#pragma endregion constructor/destructor
#pragma region methods
    public:
        void Open();
        void Close();
        int Width() const;
        int Height() const;
        sf::RenderWindow* Render() const;
        void Draw(const sf::Drawable* _drawable) const;
        void OpenMenu(const char* _name);
    protected:
        void CloseAllMenus();
        void RegisterMenu(const char* _name, BaseMenu* _menu);
        void OnDraw();
        void OnUpdate();
        void OnReceiveEvent(const sf::Event& _event);
    private:
        void Update();
#pragma endregion methods
    };
}
