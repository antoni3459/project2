// calcullette condition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

#pragma region infos
int a = 0,
b = 0,
result = 0;
string type = "";
#pragma endregion 

#pragma region questions
string chooseA = "choisis le a : ",
chooseB = "choisis le b : " , 
chooseClalc= "choisis ton calcule ?";
#pragma endregion 

void ChooseA(string _locLabel)// on récupèrela valeur a
{
    cout << _locLabel << "\n";
    cin >> a;
}

void ChooseB(string _locLabel)// on récupère celle de b
{
    cout << _locLabel << "\n";
    cin >> b;
}

int ChooseCalc(string _locLabel, int _a, int _b)
{
    cout << _locLabel << "\n";
    cin >> type; // on récupère l'opération 
    if (type == "+") // nous allons testé quel type de claclul est demander
    {
        return _a + _b;
    }
    else if (type == "-")
    {
        return _a - _b;
    }
    else if (type == "*")
    {
        return _a * _b;
    }
    else
    {
        return _a / _b;
    }
}


int main()
{
    ChooseA(chooseA);
    ChooseB(chooseB);
    result=ChooseCalc(chooseClalc, a, b);
    cout << result;
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
