#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <vector>

class Booking;

class BookingManager:public Singleton<BookingManager>
{
	DECLARE_CLASS_INFO(Singleton<BookingManager>)

private:
	std::vector<Booking*> bookings = std::vector<Booking*>();

public:
	void RegisterBooking(Booking* _booking);
	void DeleteBooking(Booking* _booking);

	std::vector<Booking*> GetBooking()const;

	void OnDestroy()override;

};

