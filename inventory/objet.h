#pragma once
#include <iostream>
#include <string>
using namespace std;
template<typename T>

class Objet
{
public:
	T* objet = nullptr;
public:
	T* Object();
	void List();
};


template<typename T>
inline T* Objet<T>::Object()
{
	return objet;
}

template<typename T>
inline void Objet<T>::List()
{
	string _list[3] = { "potion soins","potions dammmage ","potion mana" };
	for (int i = 0; i < 3; i++)
	{
		_list[ i ] = objet;
		Objet();
	}
}

