#include "Item.h"
#include "Menu.h"
#include "Utils.h"

Item::Item(Menu* _game)
{
    game = _game;
}

Item::Item(Item& _copy)
{
    game = _copy.game;
}

Item::~Item()
{
    delete game;
}

void Item::Click()
{
    if (game == nullptr) throw std::exception("error");
    game->Open();
    game->Update();
    game->Close();
}

void Item::Display()
{
    Utils::Print(game->GameName());
}

Menu* Item::Game()
{
    return game;
}
