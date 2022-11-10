#pragma once

#include <string>
#include <vector>
#include "MenuItem.h"
#include "Object.h"

class MenuItem;

class Menu : public Object
{
#pragma region f/p
public:
std::string title = "";
	Menu* oldMenu = nullptr;
	bool isOpen = false;
	std::vector<MenuItem*> items = std::vector<MenuItem*>();

#pragma region f/p

#pragma region constructor
public:
	Menu() = default;
	Menu(const std::string& _title, std::initializer_list<MenuItem*> _items);
	Menu(const Menu& _copy);
	~Menu() override;

#pragma endregion constructor

#pragma region method
public:
	virtual void Open();
	virtual void Update();
	virtual void Close();
	void OpenOldMenu();
	void DisplayItems();
	std::vector<MenuItem*> Items() const;
	void Choose(const int _index);
	Menu* OldMenu() const;
	void SetOldMenu(Menu* _old);
	bool Equals(const Menu* _other);
#pragma endregion method


};

