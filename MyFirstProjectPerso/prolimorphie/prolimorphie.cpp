// prolimorphie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void toto();
void First();

float last();
float last(int _a );
float last(int _a, int _b);// c'est une surcharge de Last car les paramètre change 

int DefaultSpec(int _dmg = 1); // valeur par defaut sa permet de pas avoir 30 surcharge 
/////
/////

void First()
{

}

void toto()
{
    DefaultSpec(2);
    DefaultSpec();// comme ça si il y a pas de paramètre c'est 1 par défault 

}

float last()
{

}

float last(int _a)
{

}

float last(int _a, int _b)
{

}
int main()
{
    std::cout << "Hello World!\n";
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
