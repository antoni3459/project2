// jardinier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

bool flid[3][3] = {
    {true, true , false},
    {true, false , false},
    {false, true , false}
};

string garden[3][3] = {
    {"-","-","-"},
    {"-","-","-"},
    {"-","-","-"}
};

int i = 0,
j = 0;

string question1 = "tu veux couper l'arbre ?",
 question2 = "tu veux planter l'arbre ?";


void Cut(string _teeth);
void Plant(string _teeth);
void Fild();
void Garden();
/////
/////

void Garden()
{
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            cout << garden[i][j] <<" ";
        }
        cout << endl;
    }
}

void Fild()
{
    bool _teeth = true;
    for ( i = 0;i < 3;i++)
    {
        for ( j = 0;j < 3;j++)
        {
            if (_teeth == flid[i][j])
            {
                Cut(question1);
                
            }
            else 
            {
                Plant(question2);
            }
        }
    }
}

void Cut(string _teeth)
{
    string _input;
    cout << _teeth << endl;
    cin >> _input;
    if (_input == "oui")
        flid[i][j] != flid[i][j];
    else
    {
        flid[i][j] == flid[i][j];
        garden[i][j] = "arbre";
    }
}

void Plant(string _teeth)
{
    string _input;
    cout << _teeth << endl;
    cin >> _input;
    if (_input == "oui")
    {
        flid[i][j] != flid[i][j];
        garden[i][j] = "arbre";
    }
    else
        flid[i][j] == flid[i][j];
}

int main()
{
    Fild();
    Garden();
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
