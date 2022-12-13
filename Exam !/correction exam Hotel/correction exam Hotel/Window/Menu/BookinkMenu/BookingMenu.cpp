#include "BookingMenu.h"
#include "../../../Utils/Interfarce/MenuInterfarce.h"
#include "../../../Utils/Rect/Rect.h"
#include "../../Control/Calandar/CalendarControl.h"
#include "../../Control/Button/ButtonControl.h"
#include "../../../Booking/Booking.h"
#include"../../../Booking/Client/Client.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../Control/TextField/TextField.h"
#include "../../Windows.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../Control/Label/LabelControl.h"

BookingMenu::BookingMenu(Windows* _owner):super(_owner,BOOKINGMENU)
{
}

void BookingMenu::ReturnMainMenu()
{
	owner->SetCurrentMenu(MAINMENU);

}

void BookingMenu::SaveBooking()
{
	try
	{
		const int _numberPeople = std::stoi(numberOfPeople->CurrentTextStr());
		const Client _client = Client(firstName->CurrentTextStr(), lastName->CurrentTextStr());
		Booking* _booking = new Booking(calendar->ArrivedDate(), calendar->DepartdDate(), _client, _numberPeople);
		BookingManager::Instance()->RegisterBooking(_booking);
		messageControl->SetText(TEXT("Succesful booking"));
	}
	catch (const std::exception& o)
	{
		messageControl->SetText(TEXT("error"));

	}
}

void BookingMenu::Initialize()
{
	super::Initialize();
	messageControl = CreateLabel(Rect(owner->Width() / 2, 50, 200, 20), TEXT(""));
	firstName=CreateTextField(Rect(10, 50, 255, 20), L"first name...");
	lastName=CreateTextField(Rect(10, 80, 255, 20), L"last name...");
	numberOfPeople=CreateTextField(Rect(10, 100, 255, 20), L"number of people...");

	ButtonControl* _saveControl=CreateButton(Rect(60, 360, 150,20), L"SaveBooking");
	_saveControl->OnClick.SetDynamic(this, &BookingMenu::SaveBooking);

	ButtonControl* _returnControl=CreateButton(Rect(10, 0, 100, 20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingMenu::SaveBooking);

	calendar = CreateCalendar(Rect(10, 140, 150, 150));
	calendar->SetMaxSelected(15);

	isInitialized = true;
	Close();
}
