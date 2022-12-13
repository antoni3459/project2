#include "BookingManager.h"
#include "../Booking.h"

void BookingManager::RegisterBooking(Booking* _booking)
{

}

void BookingManager::DeleteBooking(Booking* _booking)
{
	const size_t _size = bookings.size();
	for (size_t i = 0; i < _size;i++)
	{
		if (bookings[i] == _booking)
		{
			bookings.erase(bookings.begin() + i);
			delete _booking;
			break;
		}
	}

}

std::vector<Booking*> BookingManager::GetBooking() const
{
	return bookings;
}

void BookingManager::OnDestroy()
{
	const size_t _size = bookings.size();
	for (size_t i = 0; i < _size;i++)
	{
		delete bookings[i];
	}
}
