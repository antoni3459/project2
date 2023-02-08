#pragma once
#include "../Object/Object.h"
#include <vector>
#include <initializer_list>

class Item;
class Menu;

class Launcher: public Object
{
private:
	bool open = true;
	int currentIndex = -1;
	Menu* current = nullptr;
	std::vector<Item*> item = std::vector<Item*>();

public:
	Launcher() = default;
	Launcher(const std::initializer_list<Item*> _item);
	~Launcher()override;

private:
	void Update();
	void StartGame();
	void DisplayItems();

public:
	void Open();

};

