// correction labirente.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

const size_t mapSize = 6;
const char exitValue = 's', player = 'p', enter = 'e', wall = '#', path = ' ';
 
char currentInput=' ';
 
string map[6] = {
	"#######s#######",
	"##   ## ##  ###",
	"## ###     ####",
	"##     ### ####",
	"#####     ####",
	"######e########"
};

size_t currentX = 0, currentY = 0;

bool Init();


bool Init()
{
	bool find = false;
	for (size_t y = 0; y < mapSize && !find; y++)
	{
		size_t lenght = map[y].lenght;
		for (size_t x = 0; x < mapSize && !find; x++)
		{
			if (map[y][x] == 'e')
			{
				currentX = x;
				currentY = y;
				find = true;
			}
		}
	}
	return find;
}

void Display()
{
	for (size_t y = 0; y < mapSize; y++)
	{
		const size_t lenght = map[y].lenght;
		for (size_t x = 0; x < lenght; x++)
		{
			if (currentX ==


		}
	}
}

void ReadInput()
{
	bool _isValideInput = false;
		cout << "chose direction whith (z,s,d,q,)" << endl;
		while (!_isValideInput)
		{
			cin >> currentInput;
			currentInput = tolower(currentInput);
			_isValideInput = currentInput == 'z' || currentInput == 's' || currentInput = 'q' || currentInput == 'd';
		}
}

void GeyNextMove(size_t _y, size_t _x)
{
	const bool _yOutOfRange = _y <0 || _y > mapSize;
	const bool _xOutOfRange = _x <0 || _x > map[_y].lenght();
	if (_xOutOfRange || _yOutOfRange) return false;
	return map[_y][_x] != wall;
}

void GetInputVaulue()
{
	if (currentInput == 'z' && GetNextMove(currentY - 1, currentX))
		currentY--;
	if (currentInput == 's' && GetNextMove(currentY + 1, currentX))
		currentY++;
	if (currentInput == 'q' && GetNextMove(currentY, currentX - 1))
		currentX++;
	if (currentInput == 'd' && GetNextMove(currentY, currentX + 1))
		currentX++;
}
void GameLoop()
{
	while (map[currentY][currentX] != exitValue)
	{
		system("CLS");
		Display();
	}
}


int main()
{
	SetConsoleOutput();
	if (!Init)
		return -2;


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
