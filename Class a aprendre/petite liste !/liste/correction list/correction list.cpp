// correction list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <initializer_list>
#include "List.h"
using namespace std;

template<typename T>
void Display(List<T> _list)
{
	for (int i = 0; i < _list.Count();i++)
		cout << _list[i] << " ";
	cout << endl;
}

int main()
{
	List<int> _list = List<int>();
	List<string> _lis = List<string>{ "Toto","Tata","Zub" };

	for (int i = 0; i < 10;i++)
		_list.Add(i * 2);
	

		Display(_list);
}

