// Liberty 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

int x = 0, y = 0;

bool tab[5][5] = {
    {true ,false, true, true, true},
    {true ,false, true, false, true},
    {true ,true, true, false, true},
    {false ,false, false, false, true},
    {false ,false, false, false, false}
};

string temple[5][5] = {
    {"E","-","-","-","-"},
    {"-","-","-","-","-"},
    {"-","-","-","-","-"},
    {"-","-","-","-","S"},
    {"-","-","-","-","-"}
};


const int tabSize = 5;

int playerLife = 100,
dammage = 20,
heal = 10;

void Game();
void Deplacement();
void Trap();


void Game()
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            cout << temple[y][x]<< " ";
        }
        cout << endl;
    }
    Deplacement();
    Trap();
}

void Deplacement()
{
    string _touche;
    cin >> _touche;
    if (_touche == "z")
    {
        y--;
        temple[y][x] = "X";
    }
    else if (_touche == "s")
    {
        y++;
        temple[y][x] = "X";
    }
    else if (_touche == "d")
    {
        x++;
        temple[y][x] = "X";
    }
    else if (_touche == "q")
    {
        x--;
        temple[y][x] = "X";
    }
}

void Trap()
{
    if (tab[y][x] == false)
        playerLife = playerLife - dammage;
    else
        playerLife = playerLife + heal;
}

void Win()
{

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
