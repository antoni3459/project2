#pragma once
#include "../../../../Core/Window/Menu/BaseMenu.h"
#include "../../../Entity/Mob/Mob.h"
#include "../../../Ground/Ground.h"
#include "../../../Player/Player.h"

namespace Game
{
#define BACKGROUND_GAME_PATH "background_game"

    class GameMenu : public Core::BaseMenu
    {
        DECLARE_CLASS_INFO(GameMenu, BaseMenu)

    private:
        Core::UI::Image* background = nullptr;
        Entity::Mob* mob = nullptr;
        Ground* ground = nullptr;
        Player* player = nullptr;
    public:
        GameMenu(Core::Window* _owner);
        GameMenu(const GameMenu&) = delete;

    private:
        void Init();

    public:
        void Open()override;
        void OnResize(const sf::Vector2f& _size)override;
    };
}

