#pragma once
#include "../BaseMenu.h"

class CalendarControl;
class TextField;
class LabelControl;

class BookingMenu:public BaseMenu
{

	DECLARE_CLASS_INFO(BaseMenu)
private:
	CalendarControl* calendar = nullptr;
	TextField* firstName = nullptr;
	TextField* lastName = nullptr;
	TextField* numberOfPeople = nullptr;
	LabelControl* messageControl = nullptr;

public:
	BookingMenu() = default;
	BookingMenu(Windows* _owner);
	BookingMenu(BookingMenu& _copy) = default;

private:
	void ReturnMainMenu();
	void SaveBooking();

public:
	void Initialize()override;
};

