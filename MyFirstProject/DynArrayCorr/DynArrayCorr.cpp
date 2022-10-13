// DynArrayCorr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int* tab = nullptr; 
int sizeTab = 0;

void Add(int _value);
void Clear();
void Read(); 

void Add(int _value)
{
	int* _tmp = tab;
	std::cout << _tmp << " == " << tab << std::endl; 
	sizeTab++;
	tab = new int[sizeTab]; 
	for (size_t i = 0; i < sizeTab-1; i++)
		tab[i] = _tmp[i];
	tab[sizeTab - 1] = _value; 
	std::cout << tab << " tableau is ptr " << &tab[0] << std::endl;
}
void Read()
{
	for (size_t i = 0; i < sizeTab; i++)
		std::cout << tab[i] << std::endl; 
}
void Clear()
{
	sizeTab = 0;
	tab = nullptr;
	delete[] tab;
}

int main()
{
	Add(10);
	Add(100);
	Add(20);
	Add(150);
	Read();
	Clear(); 
}

