#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#pragma warning(disable: 4996)

class Object;


class Utils
{
public:
	static void Print(const std::string _msg);
	template<typename T>
	static T Choice(const std::string& _msg="");
};


template<typename T>
inline T Utils::Choice(const std::string& _msg)
{
	if (_msg != "") Print(_msg);
	T _result = T();
	std::cin >> _result;
	return _result;
}



