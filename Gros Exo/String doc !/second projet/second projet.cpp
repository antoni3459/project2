// second projet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

int a = 10;
int b = 5;

int* ptrA = nullptr;
int* ptrB = nullptr;

void Double(int _a)
{
    ptrA = &_a;
    *ptrA = *ptrA * 2;
    cout << ptrA << "\n";
    cout << *ptrA << endl;
}

void Pointeur(int _b)
{
    ptrB = &_b;
    cout << ptrB << endl;
}

int main()
{
    Double(a);
    Pointeur(b);
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