#pragma once
#include "../../../Core/Window/Menu/BaseMenu.h"

#include <SFML/Graphics.hpp>

namespace Game
{
#define BACKGROUND_MAIN_MENU_PATH "background_main_menu"
#define TITLE_MAIN_MENU_PATH "title_main"
#define PLAY_BUTTON_MAIN_MENU_PATH "play_button"
#define QUIT_BUTTON_MAIN_MENU_PATH "quit_button"

    class MainMenu :
        public Core::BaseMenu
    {
        DECLARE_CLASS_INFO(MainMenu, BaseMenu)

    private:
        Core::UI::Image* background = nullptr;
        Core::UI::Image* title = nullptr;
        Core::UI::Button* playButton = nullptr;
        Core::UI::Button* quitButton = nullptr;
        
    public:

        MainMenu(Core::Window* _owner);
        MainMenu(const MainMenu& _copy);

    private:
        void InitBackround();
        void InitTitle();
        void InitPlayButton();
        void InitQuitButton();

    public:
        Core::UI::Button*& PlayButton();
        Core::UI::Button*& QuitButton();

    public:
        void OnResize(const sf::Vector2f& _size)override;

    };
}

