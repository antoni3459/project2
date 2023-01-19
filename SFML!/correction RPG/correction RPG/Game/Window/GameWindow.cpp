#include "GameWindow.h"
#include "Menu/MainMenu.h"

Game::GameWindow::GameWindow():super(900,800,"Rpg Game")
{
	MainMenu* _mainMenu = new MainMenu(this);
	RegisterMenu("main", _mainMenu);
	OpenMenu("main");
}

void Game::GameWindow::StartGame()
{
	OpenMenu("game");//TODO add to menu database
}
