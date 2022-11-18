#pragma once
#include <iostream>
#include <string>
class Utils
{
#pragma region methods
public:
	template<typename T>
	static T Clamp(const T& _value, const T& _min, const T& _max);
	static void Log(const std::string& _msg);
	template<typename T>
	static T UserChoice(const std::string& _msg);
#pragma endregion methods
};

template<typename T>
T Utils::Clamp(const T& _value, const T& _min, const T& _max)
{
	if (_value < _min) return _min;
	if (_value > _max) return _max;
	return _value;
}

template<typename T>
T Utils::UserChoice(const std::string& _msg)
{
	T _rep = T();
	std::cout << _msg << std::endl;
	std::cin >> _rep;
	return _rep;
}