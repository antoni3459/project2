// hotel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reservation.h"

int main()
{
    Reservation<std::string> _res = Reservation<std::string>();
    while (_res.Hotel())
    {
        _res.Affiche();

    }
}


