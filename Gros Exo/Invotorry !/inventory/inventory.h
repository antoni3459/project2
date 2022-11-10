#pragma once

#include <iostream>
#include <string>
#include "objet.h"

using namespace std;
template<typename T>

class Objet;

template<typename T>

class Inventory 
{
#pragma region f/p

private :
	int count = 0;
	T* stock = nullptr;
#pragma endregion f/p

#pragma region constructor
public:
	//List(initializer_list<T> _stock);
	//~List();

#pragma region method 
public:
	void Stock();



};



template<typename T>
inline void Inventory<T>::Stock() 
{
	string rep;
	cout << objet << "\n"<<"veut tu le prendre ? "<<endl;
	cin >> rep;
	if (rep == "oui")
		stock = objet;
	else
		delete objet;
}


