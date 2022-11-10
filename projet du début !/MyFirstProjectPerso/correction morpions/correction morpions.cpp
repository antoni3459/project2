// correction morpions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
#pragma endregion

const int gridSize = 3;
int y = 0, x = 0;
char cells[gridSize][gridSize] =
{
    {'-','-','-'},
{'-','-','-'},
{'-','-','-'}
};

bool isFistPlayer = true;
void ReadCells(char _cells[gridSize][gridSize])
{
    for (int y = 0; y < gridSize; y++)
    {
        string _tmpLine = "";
        for (int x = 0; x < gridSize;x++)
        {
            _tmpLine += _cells[y][x];
        }
        cout << _tmpLine << endl;
    }
}

void ColorConsole()
{
    int _color = isFistPlayer ? 3 : 2;
    const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_hConsole, _color);
}

string GetLocation()
{
    return "current location is (x:" + x + ", y:" + y + ")";
}

bool CanMove()
{
    char _select = 0;
    bool _isValid = false;
    while (!_isValid)
    {
        cin >> _select;
        _isValid = (_select == 'y' || _select == 'n');
    }
    return _select == 'y';
}

void SetLocation()
{
    cout << "Move keys (z,s,q,d) : " << endl;
    char _input = 0;
    cin >> _input;
    bool _left = _input == 'q',
        _right = _input == 'd',
        _up = _input == 'z',
        _down = _input == 's';
    if (_left)
    {
        x--;
        x = x < 0 ? 0 : x;
    }
    else if (_right)
    {
        x++;
        x = x > gridSize - 1 ? gridSize - 1 : x;
    }
    else if (_up)
    {
        y--;
        y = y < 0 ? 0 : y;
    }
    else if (_down)
    {
        y++;
        y = y > gridSize - 1 ? gridSize - 1 : y;
    }
        cout << GetLocation();
        cout "Want to move again ? (y/n)" << endl;
        if (!CanMove())
        {
            system("CLS");
            return;
        }
        SetLocation();
}

void SelectCell()
{
    ColorConsole();
    cout << (isFistPlayer ? "Player 1 turn !" : "Player 2 turn !") << endl;
    cout << GetLocation() << endl;
    cout << "Want to move ? (y/n) " << endl;
    if (!CanMove)
        return;
    SetLocation();
}

void SetValueAtCell(int _x, int _y)
{
    bool _canWrite = cells[_x][_y] == '-';
    if (!_canWrite)
        return;
    cells[_y][_x] = isFistPlayer ? 'x' : 'o';
}

void SetNextPlayer()
{
    isFistPlayer = !isFistPlayer;
}

int main()
{
    while (true)
    {
        ReadCells(cells);
        SelectCell();
        SetValueAtCell(x, y);
    }
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
