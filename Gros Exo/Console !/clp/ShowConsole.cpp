#include "ShowConsole.h"
#include "EccoLeDauphins.h"
#include "Help.h"
#include "Time.h"
#include "Cls.h"
#include "ExitProg.h"

#include <iostream>
#include <stdlib.h>


void ShowConsole::Open()
{
	std::string _input = "";
	std::cin >> _input;
	if (_input == "echo" || _input == "ecco")
	{
		Echo intance = Echo();
		intance.Open();
	}
	if (_input == "help")
	{
		Help help = Help();
		help.Open();
	}
	if (_input == "time")
	{
		Time time = Time();
		time.Open();
	}
	if (_input == "cls")
	{
		Cls cls = Cls();
		cls.Open();
	}
	if (_input == "exit")
	{
		ExitProg exit = ExitProg();
		exit.Open();
	}
}
