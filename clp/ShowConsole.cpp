#include "ShowConsole.h"
#include "EccoLeDauphins.h"
#include "Help.h"
#include "Time.h"
#include <iostream>


void ShowConsole::Open()
{
	std::string _input = "";
	std::cin >> _input;
	if (_input == "echo" || _input == "ecco")
	{
		EccoLeDauphins intance = EccoLeDauphins();
		intance.Open();
	}
	else if (_input == "help")
	{
		Help help = Help<std::string>();
		help.Open();
	}
	else if (_input == "time")
	{
		Time time = Time();
		time.Open();
	}
}
