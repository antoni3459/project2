// morpions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
#pragma endregion

//string morpions[3][3] = {
    /*{"-","-","-"},
    {"-","-","-"},
    {"-","-","-"}
},
player = "";
int i = 0,
j = 0;
const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);*/

string morpions[3][3] = {
    {"-","-","-"},
    {"-","-","-"},
    {"-","-","-"}
},
player = "";
int i = 0,
j = 0;
const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Game()
{
    for (int _i = 0;_i < 3;_i++)
    {
        for (int _j = 0;_j < 3;_j++)
        {
            cout << morpions[_i][_j] << " ";
        }
        cout << endl;
    }
}

void Deplacement()
{
    string _touche = "";
    for (i=i; i < 4;i)
    {
        for (j=j;j < 4;j)
        {
            cin >> _touche;
            if (_touche == "z")
            {
                i -= 1;
                morpions[i][j] = "a";
                Deplacement();
            }
            else if (_touche == "s")
            {
                i+=1;
                morpions[i][j] = "a";
                Deplacement();
            }
            else if (_touche == "d")
            {
                j+=1;
                morpions[i][j] = "a";
                Deplacement();
            }
            else if (_touche == "q")
            {
                j -= 1;
                morpions[i][j] = "a";
                Deplacement();
            }
          
        }
    }
}



int main()
{
    Game();
    Deplacement();
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
