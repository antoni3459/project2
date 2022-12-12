#pragma once
#include "../BaseMenu.h"


class BookingMenu:public BaseMenu
{

	DECLARE_CLASS_INFO(BaseMenu)

public:
	BookingMenu() = default;
	BookingMenu(Windows* _owner);
	BookingMenu(BookingMenu& _copy) = default;

public:
	void Initialize()override;
};

