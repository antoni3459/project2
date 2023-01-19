#include <iostream>
#include "Core/Input/Input.h"
#include "Core/Utils/Debug/Debug.h"
#include "Core/Manager/Font/FontManager.h"
#include "Core/Manager/Texture/TextureManager.h"
#include "Core/Manager/GameObject/GameObjectManager.h"
#include "Game/Window/GameWindow.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Core::Input::Init();
	Core::Manager::FontManager::Instance()->Init();
	Core::Manager::TextureManger::Instance()->Init();

	Game::GameWindow _gameWindow = Game::GameWindow();
	_gameWindow.Open();

	Core::Manager::FontManager::Instance()->Destroy();
	Core::Manager::TextureManger::Instance()->Destroy();
	Core::Manager::GameObjectManager::Instance()->Destroy();

}
