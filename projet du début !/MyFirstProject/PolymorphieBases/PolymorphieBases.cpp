// PolymorphieBases.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int playerLife = 100;

void Toto(); 
void First();
void Example(float, int);

float Last();
float Last(int _a); 
float Last(int _a, int _b);

int GetPlayerLife();
int GetPlayerLife(int _dmg); 
int GetPlayerLife(int _dmg, int _hour);
int GetPlayerLife(std::string _dmg, int _hour);

int DefaultSpec(int _dmg = 1);
//int DefaultSpec(int _dmg = 1, float _other);
int DefaultSpec(int _dmg = 1, float _other = 2);
//int DefaultSpec(int _dmg, float _other = 2);
/////
/////
/////

int DefaultSpec(int _dmg)
{
	return _dmg * 2;
}

int GetPlayerLife()
{
	return playerLife;
}
int GetPlayerLife(int _dmg)
{
	return playerLife * _dmg;
}
int GetPlayerLife(int _dmg, int _hour)
{
	return (playerLife * _dmg) / _hour;
}

void First()
{
	Toto(); 
	Example(5,0);
	DefaultSpec(6);
	DefaultSpec();
}

void Toto()
{

}
void Example(float _f,int _i)
{

}
float Last()
{
	return 0;
}
float Last(int _a)
{
	return 0;
}
float Last(int _a, int _b)
{
	return 0;
}

int main()
{
	GetPlayerLife();
	GetPlayerLife(5);
	GetPlayerLife(5, 2);
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
