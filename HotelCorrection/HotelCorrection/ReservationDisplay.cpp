#include "ReservationDisplay.h"
#include "Utils.h"
#include "Booking.h"
#include "BookingManager.h"

ReservationDisplay::ReservationDisplay() : Menu("All Bookings", {})
{

}

void ReservationDisplay::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(tile);
	std::vector<Booking*> _bookings = BookingManager::Instance()->Booking();
	if (_bookings.size() == 0)
	{
		Utils::Log("No Booking !");
	}
	else
	{
		for (Booking* _booking : _bookings)
		{
			Utils::LogSeparator(30);
			Utils::Log(_booking);
			Utils::LogSeparator(30);
		}
	}
	Utils::Pause();
	OpenOlMenu();
}
