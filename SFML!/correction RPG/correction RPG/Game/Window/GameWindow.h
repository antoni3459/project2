#pragma once

#include "../../Core/Window/Window.h"

namespace Game
{
    class GameWindow :
        public Core::Window
    {
        DECLARE_CLASS_INFO(GameWindow, Window)

    public:
        GameWindow();

    private:
        void StartGame();
    };
}

