// Labirinthe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

const int sizeLaby = 6;

bool win = false;

string map[6] = {
	"#######s#######",
	"##   ## ##  ###",
	"## ###     ####",
	"##     ### ####",
	"#####     ####",
	"######e########"
};
int x = 5, y = 6;
int player[2] = { x,y },
out[2] = { 0,7 };


void MovePlayer();
void Init();
void SetCursor();
void Win();

void Init()
{
	for (int i = 0; i < 6; i++)
	{
		cout << map[i] << endl;
	}
}

void MovePlayer()
{
    char _consol;
    cin >> _consol;
    if (_consol == 'z')
    {
        x++;
        if (map[player[0] - 1][player[1]] != '#')
            player[0] = x == 0 ? 0 : player[0] - 1;
    }
    else if (_consol == 's')
    {
        x--;
        if (map[player[0] + 1][player[1]] != '#')
        {
            player[0] = x == 15 ? 15 : player[0] + 1;
            x = x < 4 ? 4 : x;
        }
    }
    else if (_consol == 'd')
    {
        y++;
        if (map[player[0]][player[1] + 1] != '#')
            player[1] = y == 15 ? 15 : player[1] + 1;
    }
    if (_consol == 'q')
    {
        y--;
        if (map[player[0]][player[1] - 1] != '#')
            player[1] = y == 0 ? 0 : player[1] - 1;
    }
    SetCursor();
    Win();
}

void SetCursor()
{
    string _laby = "";
    for (int i = 0; i < sizeLaby; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (player[0] == i && player[1] == j)
                _laby += "P";
            else if (out[0] && out[1])
                _laby += "S";
            else
               _laby += map[i][j];
        }
        _laby += "\n";
    }
    cout << _laby << endl;
}

void Win()
{
    if (player[0] == out[0] && player[1] == out[1])
        cout << "c'est gagner" << endl;
    else
        MovePlayer();
}

int main()
{
	
	Init();
	
		MovePlayer();
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
