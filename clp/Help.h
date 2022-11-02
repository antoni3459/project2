#pragma once
#include <iostream>
#include "ShowConsole.h"
#include "Utils.h"
#include "EccoLeDauphins.h"
#include "Utils.h"

class EccoLeDauphins;

template <typename T>
class Help: public ShowConsole
{
private :
	std::string name = "Help";
	Help* className = nullptr;
	int count = 0;

public:
	Help()=default;
	Help(const std::initializer_list<T> _className);
	Help(const Help* _copy);
	~Help();

public:
	void Open();
	void List();
	void Display();
};

template<typename T>
inline Help<T>::Help(const std::initializer_list<T> _className)
{
	className = _className;
}

template<typename T>
inline Help<T>::Help(const Help* _copy)
{
	className = _copy.className;
}

template<typename T>
inline Help<T>::~Help()
{
	Utils::ClearConsole();
}

template<typename T>
inline void Help<T>::Open()
{
	List();
}

template<typename T>
inline void Help<T>::List()
{
	className->GetName()
	count = 1;
	Display();
}

template<typename T>
inline void Help<T>::Display()
{
	for (int i = 0; i < count; i++)
		std::cout << className << std::endl;
}

