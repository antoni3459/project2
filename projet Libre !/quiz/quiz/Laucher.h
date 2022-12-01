#pragma once
#include "Object.h"
#include <vector>
#include <initializer_list>

class Item;
class Menu;

class Laucher: public Object
{
private:
	bool open = true;
	int currentIndex = -1;
	Menu* current = nullptr;
	std::vector<Item*> item = std::vector<Item*>();

public:
	Laucher() = default;
	Laucher(const std::initializer_list<Item*> _item);
	~Laucher()override;

private:
	void Update();
	void StartGame();
	void DisplayItems();

public:
	void Open();

};

