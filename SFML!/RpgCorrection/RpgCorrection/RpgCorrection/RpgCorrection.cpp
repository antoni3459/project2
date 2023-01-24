#include <iostream>

#include "Core/Input/Input.h"
#include "Core/Manager/Font/FontManager.h"
#include "Core/Manager/GameObject/GameObjectManager.h"
#include "Core/Manager/Texture/TextureManager.h"
#include "Game/Window/GameWindow.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Core::Input::Init();
    Core::Manager::FontManager::Instance()->Init();
    Core::Manager::TextureManager::Instance()->Init();
    // Game Window
    Game::GameWindow _gameWindow = Game::GameWindow();
    _gameWindow.Open();
    // End
    Core::Manager::FontManager::Instance()->Destroy();
    Core::Manager::TextureManager::Instance()->Destroy();
    Core::Manager::GameObjectManager::Instance()->Destroy();
}
