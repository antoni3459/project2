// Tic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

const int gridSize = 3; 
int y = 0, x = 0;
char cells[gridSize][gridSize] = 
                                {
                                    {'-','-','-'},
                                    {'-','-','-'},
                                    {'-','-','-'}
                                };
bool isFirstPlayer = true; 

void ReadCells(char _cells[gridSize][gridSize])
{
    for (int y = 0; y < gridSize; y++)
    {
        string _tmpLine = "";
        for (int x = 0; x < gridSize; x++)
        {
            _tmpLine += _cells[y][x];
        }
        cout << _tmpLine <<endl;
    }
}
void ColorConsole()
{
    int _color = isFirstPlayer ? 3 : 2; // ou 9 
    const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_hConsole, _color);
}
string GetLocation()
{
    return "Current location is (x:" + to_string(x) + ", y:" + to_string(y) + ")";
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
    if(_left)
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
    cout << GetLocation() << endl;
    cout << "Want to move again ? (y/n) " << endl;
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
    cout << (isFirstPlayer ? "Player 1 turn !" : "Player 2 turn !") << endl;
    cout << GetLocation() << endl;
    cout << "Want to move ? (y/n) " << endl; 
    bool _isValid = false;
    if (!CanMove())
        return;
    SetLocation();
}
void SetValueAtCell(int _x, int _y)
{
    bool _canWrite = cells[_y][_x] == '-';
    if (!_canWrite)
        return; 
    cells[_y][_x] = isFirstPlayer ? 'x' : 'o';
}
void SetNextPlayer()
{
    isFirstPlayer = !isFirstPlayer;
}
int main()
{
    while (true)
    {
        ReadCells(cells);
        SelectCell();
        SetValueAtCell(x, y);
        SetNextPlayer();
    }

}

