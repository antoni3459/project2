#include "BookingViewMenu.h"
#include "../../../Utils/Interfarce/MenuInterfarce.h"
#include "../../../Booking/Booking.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../../Utils/Rect/Rect.h"
#include "../../Control/Label/LabelControl.h"
#include "../../Control/Button/ButtonControl.h"
#include "../BaseMenu.h"
#include "../../Windows.h"
#include "../../../Window/Control/Button/ButtonBookingControl/ButtonBookingControl.h"

Booking* BookingViewMenu::CurrentBooking = nullptr;

BookingViewMenu::BookingViewMenu(Windows* _owner) : super(_owner, BOOKINGVIEWMENU)
{
}

void BookingViewMenu::ReturnMainMenu()
{
	owner->SetCurrentMenu(MAINMENU);
}

void BookingViewMenu::SetCurrentBooking(Booking* _booking)
{
	CurrentBooking = _booking;
}

void BookingViewMenu::DisplayBooking(const std::vector<Booking*>& _bookings)
{
	int _positionX = 10, _positionY = 30;
	int _index = 0;
	for (Booking* _booking : _bookings)
	{
		const Client _client = _booking->GetClient();
		const std::string _clientFullName = _client.FirstName() + " " + _client.LastName();
		const std::wstring _fullNameWstr = std::wstring(_clientFullName.begin(), _clientFullName.end());

		const int _width = _clientFullName.length() * 10;
		ButtonBookingControl* _button = CreateBookingButton(Rect(_positionX, _positionY, 250, 20), _fullNameWstr.c_str(), _booking);
		_button->OnClickBooking.SetDynamic(this, &BookingViewMenu::SetCurrentBooking);
		_button->OnClick.SetDynamic(this, &BookingViewMenu::LoadBookingData);

		_positionX += _width + 10;
		_index++;
		if (_index % MAXCOLUMNNUMBER == 0)
		{
			_positionX = 10;
			_positionY += 30;
		}
	}
}

void BookingViewMenu::Initialize()
{
	super::Initialize();
	textControl = CreateLabel(Rect(10, 30, 250, 20), L"");
	ButtonControl* _reuturnControl = CreateButton(Rect(10, 0, 100, 20), TEXT("Return"));
	_reuturnControl->OnClick.SetDynamic(this, &BookingViewMenu::ReturnMainMenu);
	isInitialized = true;
	Close();
}

void BookingViewMenu::Open()
{
	std::vector<Booking*> _bookings = BookingManager::Instance()->GetBooking();
	if (_bookings.empty())
	{
		textControl->SetText(L"No bookings...");
	}
	else
	{
		DisplayBooking(_bookings);
		textControl->SetText(L"");
	}
	super::Open();
}

void BookingViewMenu::Close()
{
	const size_t _size = controls.size();
	for (size_t i = 3;i < _size;i++)
	{
		controls[3]->Hide();
		delete controls[3];
		controls.erase(controls.begin() + 1);
	}
}

void BookingViewMenu::LoadBookingData()
{
	owner->SetCurrentMenu(BOOKINGVIEWDATAMENU);
}
