#pragma once
#include "Menu.h"

class MenuMorpion: public Menu
{
#pragma region constructor
public:
	MenuMorpion();
#pragma endregion constructor
#pragma region override
public:
	void Open() override;
#pragma endregion override
};

