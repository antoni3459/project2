#pragma once
#include "../BaseMenu.h"

class LabelControl;
class Booking;

#define MAXCOLUMNNUMBER 3

class BookingViewMenu:public BaseMenu
{

	DECLARE_CLASS_INFO(BaseMenu)

public:
	static Booking* CurrentBooking;
private:
	LabelControl* textControl = nullptr;
public:
	BookingViewMenu() = default;
	BookingViewMenu(Windows* _owner);
	BookingViewMenu(const BookingViewMenu& _copy) = default;

private:
	void ReturnMainMenu();
	void LoadBookingData();

public:
	void SetCurrentBooking(Booking* _booking);
	void DisplayBooking(const std::vector<Booking*>& _bookings);

public:
	void Initialize()override;
	void Open()override;
	void Close()override;
};

