#include "ReservationRemove.h"
#include "Utils.h"
#include "Booking.h"
#include "BookingManager.h"

ReservationRemoveMenu::ReservationRemoveMenu() : Menu("Booking Remove", {})
{

}

void ReservationRemoveMenu::DisplayBookings()
{
	if (booking.size() == 0)
	{
		Utils::Log("No Bookings !");
		Utils::Pause();
		OpenOlMenu();
		return;
	}
	const size_t _size = booking.size();
	for (size_t i = 0; i < _size; i++)
	{
		Utils::LogSeparator(30);
		Utils::Log(std::to_string(i + 1) + ": " + booking[i]->ToString());
		Utils::LogSeparator(30);
	}
}

void ReservationRemoveMenu::ConfirmationDelete(char _choice)
{
	int _index = _choice - '0' - 1;
	Utils::ClearConsole();
	Utils::LogSeparator();
	Utils::Log(booking[_index]);
	Utils::LogSeparator(30);

	_choice = Utils::UserChoice<char>("Are you sure to delete ? (y/n)");
	if (std::tolower(_choice) == 'n')
	{
		OpenOlMenu();
		return;
	}
	if (std::tolower(_choice)!=
}

void ReservationRemoveMenu::Open()
{
	Menu::Open();
	booking = BookingManager::Instance()->Booking();
	DisplayBookings();

	char _choice = Utils::UserChoice<char>("which reservation do you wantto delete ? (n for cancel)";
	if (dtd

}
