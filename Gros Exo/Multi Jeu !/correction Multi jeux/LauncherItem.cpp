#include "LauncherItem.h"
#include "Utils.h"
#include "IGame.h"

LauncherItem::LauncherItem(IGame* _game)
{
	game = _game;
}

LauncherItem::LauncherItem(const LauncherItem& _copy)
{
	game = _copy.game;
}

LauncherItem::~LauncherItem()
{
	delete game;
}

void LauncherItem::OnClick()
{
	if (game == nullptr) throw std::exception("[Launcher Item] => current game is null !");
	Utils::ClearConsole();
	Utils::LoadingBar("Loading" + game->GameName());
	game->OnStart();
	game->DisplayMenu();
	game->OnUpdate();
	game->OnEnd();

}

void LauncherItem::Display()
{
	Utils::Log(game->GameName());
}

IGame* LauncherItem::Game() const
{
	return game;
}
