#pragma once
#include "../../../Core/Window/Menu/BaseMenu.h"

#include <SFML/Graphics.hpp>

namespace Game
{
#define BACKGROUND_MAIN_MENU_PATH "background_main_menu"
#define TITLE_MAIN_MENU_PATH "title_main"

    class MainMenu :
        public Core::BaseMenu
    {
        DECLARE_CLASS_INFO(MainMenu, BaseMenu)

    private:
        Core::UI::Image* background = nullptr;
        Core::UI::Image* title = nullptr;

    public:
        MainMenu(Core::Window* _owner);
        MainMenu(const MainMenu& _copy);

    public:
        void OnResize(const sf::Vector2f& _size)override;
    };
}

