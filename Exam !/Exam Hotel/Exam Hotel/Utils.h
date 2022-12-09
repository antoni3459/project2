#pragma once
#include <string>
#include <iostream> 

class Utils
{
public:
	static void Print(std::string _msg);
	template <typename T>
	static T UserChoice(std::string _msg);
};

template<typename T>
inline T Utils::UserChoice(std::string _msg)
{
	T _rep = T();
	std::cout << _msg << std::endl;
	std::cin >> _rep;
	return _rep;
}
