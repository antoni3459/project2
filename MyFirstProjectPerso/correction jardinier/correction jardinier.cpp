// correction jardinier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion
int currentX,
currentY;

const int gardenSize = 3;
int garden[gardenSize][gardenSize];
void InitGarden();
void ReadGarden(int _garden[gardenSize][gardenSize]);

string GetCursor()
{
    return "current location is at : " + to_string(currentY) + ", x = " + to_string(currentX) + ")";
}
void SetCursor()
{
    char _input;
    bool _isValidInput = false;
    while (!_isValidInput)
    {
        cin >> _input;
        _isValidInput = _input == 'z' || _input == 's' || _input == 'q' || _input == 'd';
    }
    if (_input == 'z')
    {
        currentX--;
        currentX = currentX < 0 ? 0 : currentX;
    }
    else if (_input == 's')
    {
        currentX++;
        currentX = currentX > gardenSize ? gardenSize : currentX;
    }
    else if (_input == 'q')
    {
        currentX--;
        currentX = currentX < 0 ? 0 : currentX;
    }
    else if (_input == 'd')
    {
        currentX++;
        currentX = currentX > gardenSize ? gardenSize : currentX;
    }
}

void InitGarden()
{
    srand((unsigned int)time(NULL));
    for (size_t i = 0;i < gardenSize;i++)
    {
        for (size_t j = 0;j < gardenSize;j++)
        {
            garden[i][j] = rand() % 2;
        }
    }
}

void ReadGarden()
{
    string _tmp;
    for (int y = 0;y < gardenSize;y++)
    {
        for (int x = 0;x < gardenSize;x++)
        {
            _tmp += garden[x][y] == 1 ? "A" : "C";
        }
        _tmp += "\n";
    }
    cout << _tmp << endl;
}


void MovePlayer()
{
char _result = garden[currentX][currentY];
garden[currentX][currentY] = _result == 1 ? 0 : 1;
cout << garden[currentX][currentY] << endl;
}

int main()
{
    InitGarden();
    while (true)
    {
        ReadGarden( );
        SetCursor();
        MovePlayer();
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
