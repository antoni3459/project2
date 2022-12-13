#include "BookingViewData.h"
#include "../../../Utils/Interfarce/MenuInterfarce.h"
#include "../BookingViewMenu/BookingViewMenu.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../Windows.h"
#include "../../../Booking/Client/Client.h"
#include "../../Control/Label/LabelControl.h"
#include "../../Control/Button/ButtonControl.h"
#include "../../Control/Calandar/CalendarControl.h"
#include "../../../Booking/Booking.h"

BookingViewData::BookingViewData(Windows* _owner): super(_owner,BOOKINGVIEWDATAMENU)
{

}

void BookingViewData::Delete()
{
	BookingManager::Instance()->DeleteBooking(BookingViewMenu::CurrentBooking);
	ReturnToBookingView();
}

void BookingViewData::ReturnToBookingView()
{
	owner->SetCurrentMenu(BOOKINGVIEWDATAMENU);
}

void BookingViewData::Initialize()
{
	super::Initialize();
	ButtonControl* _returnControl = CreateButton(Rect(10, 0, 100, 20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingViewData::ReturnToBookingView);

	firstName = CreateLabel(Rect(10, 60, 250, 20), L"");
	lastName = CreateLabel(Rect(10, 90, 250, 20), L"");
	numberOfPeople = CreateLabel(Rect(10, 120, 250, 20), L"");
	calendar = CreateCalendar(Rect(10, 160, 250, 20));
	calendar->SetMaxSelected(15);

	ButtonControl* _deleteControl = CreateButton(Rect(10, 360, 100, 20), L"Delete");
	_deleteControl->OnClick.SetDynamic(this, &BookingViewData::Delete);

	isInitialized = true;
	Close();
}

void BookingViewData::Open()
{
	const Booking* _current = BookingViewMenu::CurrentBooking;
	if (_current == nullptr)
	{
		ReturnToBookingView();
		return;
	}
	const Client _client = _current->GetClient();
	firstName->SetText("firstName : " + _client.FirstName());
	lastName->SetText("lastName : " + _client.LastName());
	numberOfPeople->SetText("numberPeople : " + std::to_string(_current->NumberOfPeople()));
	calendar->SetValue(_current->ArrivedDate(), _current->DepartureDate());
	titleControl->SetText("Booking of: " + _client.FirstName() + " " + _client.LastName());
	super::Open();
}
