// correction roulette 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <format>

std::vector<std::string> Split(const std::string& _str, const std::string& _delimiter)
{
	std::string _string = _str;
	size_t _posStart = 0, _posEnd = 0, _delimLenght = _delimiter.length();
	std::vector<std::string> _result = std::vector<std::string>();

	while ((_posEnd = _string.find(_delimiter, _posStart)) != std::string::npos)
	{
		_result.push_back(_string.substr(_posStart, _posEnd - _posStart));
		_posStart = _posEnd + _delimLenght;
	}
	_result.push_back(_string.substr(_posStart));

	std::vector<std::string>::iterator _index = _result.begin();
	while ((_index = std::find(_result.begin(), _result.end(), "")) != _result.end())
	{
		_result.erase(_index);
	}
	return _result;
}
std::string Banner(const std::string& _a, const std::string& _b)
{
	std::string _result = "";
	for (int i = 0; i < _a.size(); i++)
		_result += std::format("{} {}\n", _a[i], _b[_b.size() - i - 1]);
	return _result;
}

int main()
{
   std::string _str="Hello World";
   std::vector<std::string> _splited = Split(_str, " ");
   if (_splited[0].size() != _splited[1].size()) return -3;
   std::string _result = Banner(_splited[1], _splited[0]);
   std::cout << _result << std::endl;
   return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
