// TrapGrid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

const int sizeZone = 6;
char cells[sizeZone][sizeZone]; 
bool trap[sizeZone][sizeZone]; 
int playerLife = 100;
bool isDead = false;

void InitGrid()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sizeZone; i++)
	{
		for (int j = 0; j < sizeZone; j++)
		{
			int _rand = rand() % 2;
			trap[i][j] = _rand == 1 ? true : false;
			cells[i][j] = trap[i][j] ? 't' : '-';
		}
	}
	int _randY = rand() % sizeZone;
	int _randX = rand() % sizeZone;
	cells[_randY][_randX] = 'e';
}
void ReadCells()
{
	std::string _grid; 
	for (int i = 0; i < sizeZone; i++)
	{
		for (int j = 0; j < sizeZone; j++)
		{
			_grid  += cells[i][j];
		}
		_grid += "\n";
	}
	std::cout << _grid << std::endl;
}
void Move()
{
}
void AffectPlayer()
{
	bool _isTrap = trap[0][0];
	playerLife += _isTrap ? -10 : 10;
	playerLife = playerLife < 0 ? 0 : playerLife > 100 ? 100 : playerLife;
	isDead = playerLife == 0;
}
void ReadPlayerStats()
{
	std::cout << playerLife << std::endl; 
}
int main()
{
	//while (true)
	{
		InitGrid();
		ReadCells();
		Move();
		AffectPlayer();
		ReadPlayerStats();
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
