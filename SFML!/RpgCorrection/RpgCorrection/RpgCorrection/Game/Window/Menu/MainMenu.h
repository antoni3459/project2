#pragma once
#include "../../../Core/Window/Menu/BaseMenu.h"

namespace Game
{
    
#define BACKGROUND_MAIN_MENU_PATH "background_main_menu"
#define TITLE_MAIN_MENU_PATH "title_main"
#define PLAY_BUTTON_MAIN_MENU_PATH "play_button"
#define QUIT_BUTTON_MAIN_MENU_PATH "quit_button"
    
    class MainMenu : public Core::BaseMenu
    {
        DECLARE_CLASS_INFO(MainMenu, BaseMenu)
#pragma region f/p
    private:
        Core::UI::Image* background = nullptr;
        Core::UI::Image* title = nullptr;
        Core::UI::Button* playButton = nullptr;
        Core::UI::Button* quitButton = nullptr;
#pragma endregion f/p
#pragma region constructor
    public:
        MainMenu(Core::Window* _owner);
        MainMenu(const MainMenu& _copy);
#pragma endregion constructor
#pragma region methods
    private:
        void InitBackground();
        void InitTitle();
        void InitPlayButton();
        void InitQuitButton();
    public:
        Core::UI::Button*& PlayButton();
        Core::UI::Button*& QuitButton();
#pragma endregion methods
#pragma region override
    public:
        void OnResize(const sf::Vector2f& _size) override;
#pragma endregion override
    };
}
