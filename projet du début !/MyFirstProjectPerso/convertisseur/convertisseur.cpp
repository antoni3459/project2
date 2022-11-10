// convertisseur.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

float a = 0,
b = 0,
result = 0;
string conv = "",
getValue = "donne ta valeur a convertir ",
getConv = "choisis la mesure a convertir";


void ChooseConv(string _localbel)
{
    cout << _localbel << "\n";
    cin >> conv;
}

float ChooseValue(string _localbel)
{
    cout << _localbel << "\n";
    cin >> a;
    return a;
}

float Conversion(string _conv, int _a)
{
    if (_conv == "km/h")
        return result = _a * 0.54;
    else if (_conv == "knot")
        return result = _a / 0.54;
    else if (_conv == "celcius")
        return result = (_a * (9 / 5)) + 32;
    else if (_conv == "far")
        return  result= (_a * (9 / 5)) - 32;
    else if (_conv == "litre")
        return result = _a / 3.7;
    else if (_conv == "gallon")
        return result = _a * 3.7;
    else if (_conv == "metre")
        return result = _a * 3.28;
    else if (_conv == "feet")
        return result = _a / 3.28;
}

int main()
{
    ChooseConv(getConv);
    ChooseValue(getValue);
    Conversion(conv, a);
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
