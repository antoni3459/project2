#include "BookingMenu.h"
#include "../../../Utils/Interfarce/MenuInterfarce.h"
#include "../../../Utils/Rect/Rect.h"
#include "../../Control/Calandar/CalendarControl.h"

BookingMenu::BookingMenu(Windows* _owner):super(_owner,BOOKINGMENU)
{
}

void BookingMenu::Initialize()
{
	super::Initialize();
	CreateTextField(Rect(10, 50, 255, 20), L"first name...");
	CreateTextField(Rect(10, 80, 255, 20), L"last name...");
	CreateTextField(Rect(10, 100, 255, 20), L"number of people...");
	CreateButton(Rect(60, 360, 150,20), L"SaveBooking");
	CalendarControl* _callendar = CreateCalendar(Rect(10, 140, 150, 150));
	_callendar->SetMaxSelected(15);
	isInitialized = true;
	Close();
}
