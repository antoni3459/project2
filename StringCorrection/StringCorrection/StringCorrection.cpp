#include <iostream>
#include "String.h"


int main()
{
	String _str = "Hello World";
	std::cout << _str.SubString(0, _str.FirstIndexof(' '));
	std::string _s = "Hello World";
	std::cout << _s.substr(0, _s.find_last_of('d')) << std::endl;
}

