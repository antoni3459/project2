// exo guess nbr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

#pragma region infos
int a = 0,
b = 0;
string getNbr = "donne un nombre";
#pragma endregion 

void GetNbr(string _locbel) // on récupère le nombre a deviner
{
    cout << _locbel << "\n";
    cin >> a;
    system("CLS"); // on nettoie la console
    cout << "choisis un nombre \n";
}

void GuessNbr(int _a) // fonction qui permet le chaud froid 
{
    int _b = a;
    cin >> b;
    if (_a == b) // permet que si c'est le bon nombre fait arreter le jeux 
        cout << " c'est win";
    else if (_a > b) // permet de de recommencer si c'est trop bas 
    {
        cout << "trop petit recomence " << "\n";
        GuessNbr(_b);
    }
    else
        cout << "trop grand recomence " << "\n"; // permet de de recommencer si c'est trop haut 
    GuessNbr(_b);
}

int main()
{
    GetNbr(getNbr);
    GuessNbr(a);
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
