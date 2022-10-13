// GardenerCorr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
using namespace std; 

const int gardenSize = 3; 
int garden[gardenSize][gardenSize];
int currentX = 0, currentY = 0;

#pragma region Methods Header
void InitGarden();
void ReadGarden(int _garden[gardenSize][gardenSize]);
void MovePlayer(); 
void SetCursor();
string GetCursorLocation();
#pragma endregion

string GetCursorLocation()
{
	return "Current location is at : (y = " + to_string(currentY) + ", x = " + to_string(currentX)+")";
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
		currentX = currentX > gardenSize-1 ? gardenSize - 1 : currentX;
	}
	else if (_input == 'q')
	{
		currentY--;
		currentY = currentY < 0 ? 0 : currentY;
	}
	else if (_input == 'd')
	{
		currentY++;
		currentY = currentY > gardenSize - 1 ? gardenSize - 1 : currentY;
	}
	cout << GetCursorLocation() << endl; 
}
void MovePlayer()
{
	char _result = garden[currentX][currentY];
	garden[currentX][currentY] = _result == 1 ? 0 : 1;
	cout << garden[currentX][currentY] << endl;
}
void InitGarden()
{
	srand((unsigned int)time(NULL));
	for (size_t i = 0; i < gardenSize; i++)
	{
		for (size_t j = 0; j < gardenSize; j++)
		{
			garden[j][i] = rand()%2;
		}
	}
}
void ReadGarden(int _garden[gardenSize][gardenSize])
{
	std::string _tmp;
	for (int y = 0; y < gardenSize; y++)
	{
		for (int x = 0; x < gardenSize; x++)
		{
			_tmp += _garden[y][x] == 1 ? "A" : "C";
		}
		_tmp += "\n";
	}
	std::cout << _tmp << std::endl;
}
int main()
{
	InitGarden();
	while (true) 
	{
		ReadGarden(garden);
		SetCursor();
		MovePlayer();
	}

}

