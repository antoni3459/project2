// liberty 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

string tabQuest[] = { "qu'elle est la date de la 2eme guerre mondiale ?","qu'elle est la date de la 1er guerre mondiale ? " },
tabRep[] = { "1939-1945","1914-1918" },
start="Est-tu pret a commencer oui ou non ? ";
string rep = "";

int point = 0;

void Play();
void Start(string _start);
bool Reponse();

void Start(string _start)
{
    string _rep = "";
    cout << _start << "\n";
    cin >> _rep;
    if (_rep == "oui")
    {
        cout << " c'est partit " << "\n";
    }
    else
    {
        Start(_start);
    }
}

void Play()
{
    for (int i = 0; i <= 1;i++)
    {
        cout << tabQuest[i] << "\n";
        Reponse();
        if (true)
        {
            cout << "c'est gagne" <<point++<<endl;
        }
        else
        {
            cout << "perdu recommence" <<i--<<point--<< endl;
        }
    }
}

bool Reponse()
{
    int _a = 0;
    cout << "1- 1494-1559" << endl;
    cout << "2- 1853-1856" << endl;
    cout << "3- 1904-1905" << endl;
    cout << "4- 1939 - 1945" << endl;
    cin >> _a;
    if (_a == 4)
        return true;
    else
        return false;
}

int main()
{
    Start(start);
    Play();
    cout << point;
}