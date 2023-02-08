#pragma once
#include "../../Object/Object.h"

class Menu;

class Item:public Object
{
private:
	Menu* game = nullptr;

public:
	Item() = default;
	Item(Menu* _game);
	Item(Item& _copy);
	~Item();

public:
	void Click();
	void Display();
	Menu* Game();
};

