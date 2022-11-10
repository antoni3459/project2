#pragma once
#include "Menu.h"
#include "Object.h"
#include <iostream>

class Menu;

class MenuItem : public Object
{
#pragma region f/p
private:
	std::string name = "";
	Menu* nextMenu = nullptr;
	#pragma endregion f/p
	
#pragma region construcror
public:
	MenuItem() = default;
	MenuItem(const std::string& _name, Menu* _owner);
	MenuItem(const MenuItem& _copy);
	~MenuItem() override = default;
#pragma endregion construcror

#pragma region method
public:
	void OnClick(Menu* _currentMenu);
	std::string Name()const;
	Menu* NextMenu()const;
#pragma endregion method

#pragma region override
public:
	std::string ToString() const override;
#pragma endregion override


};

