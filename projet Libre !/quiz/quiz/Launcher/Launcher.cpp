#include "Launcher.h"
#include "Item/Item.h"
#include "../Utils/Utils.h"
#include "../Menu/Menu.h"
#include <exception>
#include <string>

Launcher::Launcher(const std::initializer_list<Item*> _item)
{
	for (Item* _items : _item)
		item.push_back(_items);
}

Launcher::~Launcher()
{
	item.clear();
	delete current;
}

void Launcher::Update()
{
	while (open == true)
	{
		try
		{
			system("cls");
			DisplayItems();
			currentIndex = Utils::Choice<int>("Choose: ") - 1;
			if (currentIndex == item.size())
			{
				open = true;
				continue;
			}
			StartGame();
		}
		catch (std::exception e)
		{
			throw std::exception("e");
		}
	}
	system("cls");
}

void Launcher::StartGame()
{
	bool verif = false;
	while (verif == false)
	{
		if (currentIndex<0 && currentIndex>item.size()+1)
		{
			Utils::Choice<int>("refait");
		}
		else
			verif = true;
	}
	Item* _item = item[currentIndex];
	current = _item->Game();
	_item->Click();
}

void Launcher::DisplayItems()
{
	const size_t _size = item.size();
	for (int i = 0; i < _size;i++)
	{
		std::cout << std::to_string(i + 1) + " :";
		item[i]->Display();
	}
	Utils::Print(std::to_string(_size + 1) + ": quit");
}

void Launcher::Open()
{
	Update();
}
