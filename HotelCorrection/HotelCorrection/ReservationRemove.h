#pragma once
#include "Men.h"
#include "Booking.h"

class ReservationRemoveMenu : public Menu
{
private:
	std::_Vector_iterator<Booking*> booking = std::_Vector_iterator<Booking*>();
public:
	ReservationRemoveMenu();

	void DisplayBookings();
	void ConfirmationDelete(char _choice);

	void Open() override;
};

