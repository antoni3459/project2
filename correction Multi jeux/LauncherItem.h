#pragma once
#include "Object.h"
class IGame;

class LauncherItem: public Object
{
private:
	IGame* game = nullptr;

public:
	LauncherItem() = default;
	LauncherItem(IGame* _game);
	LauncherItem(const LauncherItem& _copy);
	~LauncherItem();

	void OnClick();
	void Display();
	IGame* Game()const;
};

