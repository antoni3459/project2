#pragma once
#include "Client/Client.h"
#include "../Utils/DateTime/DateTime.h"

class Booking:public Object
{
	DECLARE_CLASS_INFO(Object)

private:
	DateTime arrivedDate = DateTime();
	DateTime departureDate = DateTime();
	Client client = Client();
	int numberOfPeople = 1;

public:
	Booking() = default;
	Booking(const DateTime& arrivedDate, const DateTime& departureDate, const Client& client, const int numberOfPeople);
	Booking(const Booking& _copy);

public:
	DateTime ArrivedDate()const ;
	DateTime DepartureDate()const;
	Client GetClient()const;
	int NumberOfPeople()const ;
};

