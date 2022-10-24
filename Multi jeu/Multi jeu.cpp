// Multi jeu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HomeMenu.h"
#include "Morpions.h"

int main()
{
	HomeMenu home = HomeMenu();
	home.Open();
	home.Update();
	return 0;
}

