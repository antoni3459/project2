#include "Utils.h"
#include <string>
#include <iostream>

void Utils::Print(const std::string _msg)
{
	std::cout << _msg << std::endl;
}

void Utils::Print(const std::string _msg1,const std::string _msg2)
{
	std::cout << _msg1<< _msg2 << std::endl;
}

bool Utils::Contain( std::string _msg,  char _obj)
{
	for (int i = 0; i < _msg.size();i++)
		if (_msg[i] == _obj)
			return true;
	return false;
}

std::string Utils::DeleteEscape(std::string _msg)
{
	std::string a = "";
	int i = 0;
	for (char _letter : _msg)
		if (_letter != ' ')
			a[i] = _letter;
		else
			continue;
	return a;
}
