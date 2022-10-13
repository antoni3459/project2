// exo 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int a = 0,
    b = 0;

int result = 0,
resultSou = 0;

string chooseA = "choisis le a : ",
chooseB = "choisis le b : ";

void ChooseA(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> a;
}

void ChooseB(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> b;
}

int Addition()
{
    return result = a + b;
}

void ShowAdd()
{
    cout << Addition();
}

int Soutraction()
{
    return resultSou = a - b;
}

void ShowSou()
{
    cout << Soutraction();
}


int main()
{
    ChooseA(chooseA);
    ChooseB(chooseB);
    ShowAdd();
    ShowSou();
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
