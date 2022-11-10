#include "Reservation.h"
#include "HomeMenu.h"
#include "MenuItem.h"
#include "ReservationMenu.h"

Reservation::Reservation() :Menu("Home", {
	new MenuItem("Reservation", "Reservation Gestion", new ReservationMenu())
		})
{

}
