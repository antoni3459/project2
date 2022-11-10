// Tabloop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

int a = 10;
int tabA[5] = { 10,5,4,30,9 }; // si on rajoute une valeur il y a errors 
float tabB[2];
// tableau de taille 5
// array size 5
//aray length 5 (longueur)
//0,1,2,3,4



int main()
{
    /* tabB[0] = 12.45f;
     tabB[1] = 42.45f;
     cout << tabB[0] << "" << tabB[1] << endl;
     return 0;*/

     //cout << tabA[0] << endl; //soit 10
     //cout << tabA[1] << endl;
     //cout << tabA[2] << endl;
     //cout << tabA[3] << endl;
     //cout << tabA[4] << endl;
     //cout << tabA[5] << endl; //crash
     ////index out of range <0> size
    int _example[10];
    int b = 45;
    bool _canRun = true;

    for (int i = 100, j=b, k=0; i < 100 && _canRun;i++, j--,k+=.1f)
    {
        cout << "i : " << i << endl;
        cout << "j : " << j << endl;
        cout << "k : " << k << endl;
    }
    for (int i = -10, j=10; i < 10;i++, j++)
    { 
        cout <<"i : "<< i << endl;
        cout << "j : " << j << endl;
    }
}
