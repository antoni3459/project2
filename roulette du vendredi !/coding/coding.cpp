// coding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	std::string _code = "794489686496476486";
	if (_code.size() % 3 != 0)
	{
		std::cout << "ERROR" << std::endl;
	}
	std::string _result = "";
	int _index = 0;
	for (int i = 3; i <= _code.size(); i += 3)
	{
		std::string _str = _code.substr(_index, 3);
		_index = i;
		int _value = std::atoi(_str.c_str());
		_result += (char)_value;
	}
	std::cout << _result << std::endl;
}

