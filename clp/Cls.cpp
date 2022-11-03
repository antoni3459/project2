#include "Cls.h"

void Cls::Open()
{
	Utils::ClearConsole();
}

std::string Cls::Name()
{
	return "cls";
}

std::string Cls::Description()
{
	return "Clears the screen. ";
}
