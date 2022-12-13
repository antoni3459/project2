#pragma once
#include "../BaseMenu.h"

class MainMenu: public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)

public:
	MainMenu() = default;
	MainMenu(Windows* _owner);
	MainMenu(MainMenu& _copy)=default;

public:
	void Initialize()override;
	void OpenBookingMenu();
	void OpenBookingViewMenu();
};

