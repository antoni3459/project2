// exo 5 calculette.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#pragma endregion 

#pragma region questions
string chooseA = "choisis le a : ",
chooseB = "choisis le b : ";
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

// on va calculer a et b grâce au paramètre _a et _b 

int Add(int _a, int _b)
{ ;
    return _a + _b;
}

int Substract(int _a, int _b)
{
    return _a - _b;
}

int Divide(int _a, int _b)
{
    return _a / _b;
}

int Multiply(int _a, int _b)
{
    return _a * _b;
}

int main()
{
    ChooseA(chooseA);
    ChooseB(chooseB);

    result = Add(a, b);// on remplace les paramètre _a et _b par a et b 
    cout << result << "\n"; // affiche le résulta 
    result = Substract(a, b);
    cout << result << "\n";
    result = Multiply(a, b);
    cout << result << "\n";
    result = Divide(a, b);
    cout << result << "\n";
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
