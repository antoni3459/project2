// bool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int a, b;


int main()
{
	a = 10;
	b = 5;
	if (a <= b)
		std::cout << "yes" << std:: endl;
	else
		std::cout << "no" << std::endl;

	if (a == b)//Vrai - Faux
		std::cout << "do" << std::endl;
	if (a != b)// Vrai - Faux
		std::cout << "do";


	if (a > 5)
		c = 10;
	else
		c = 5;
	//trenaire

	c = (a > 5) ? 10 : 5;
	a = (d == c) ? 100 : 50;
	d = (a == 20) ? c : Test();


	a = (b > c) ? 10 : 5;

	int _life = 100;
	bool _isdead = false;
	_isdead= _life <=0 //permet de tester automatique sans mettre de if ni de else 

} 

