#include "Utils.h"
#include <string>
#include <iostream>

void Utils::Print(const std::string _msg)
{
	std::cout << _msg << std::endl;
}

bool Utils::Contain( std::string _msg,  char _obj)
{
	for (int i = 0; i < _msg.size();i++)
		if (_msg[i] == _obj)
			return true;
	return false;
}