#pragma once
#include <vector>
#include "Object.h"
class IGame;
class LauncherItem;

class Launcher : public Object
{

private :
	std::vector<LauncherItem*> items = std::vector<LauncherItem*>();
	bool isOpen = true;
	int currentGameIndex = -1;
	IGame* currentGame = nullptr;

public:
	Launcher() = default;
	Launcher(const std::initializer_list< LauncherItem*> _items);
	~Launcher()override;

private:
	void Update();
	void DisplayItems();
public :
	void Open();

};

