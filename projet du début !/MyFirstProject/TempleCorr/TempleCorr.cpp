// TempleCorr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std; 

const int row = 4, column = 4; 
char grid[row][column];

int content[row][column] =
{
	{1, 0, 0, 1}, 
	{0, 0, 1, 0},
	{1, 0, 1, 1},
	{0, 0, 0, 1}
};
//string[0] nom 
//int[0] damage 
//inventaire Nom / damage
//Fight() 

//inventory[index] = {"",""}
string inventory[5][2] =
{
	{"Arme 1", "10"},
	{"Arme 2", "20"},
	{"Arme 3", "30"},
	{"Arme 4", "40"},
	{"Arme 5", "50"}
};

int exitRow = 1,
	exitColumn = 0,
	currentLocationX = 0, 
	currentLocationY = 0;

int playerLife = 100, 
	maxDamage = 20,
	maxBonusLife = 10;

void InitPlayer(); 
void InitPlayer(int _life);
void InitPlayer(int _life, int _startWeapon);

void Init()
{
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < column; x++)
		{
			grid[y][x] = '_';
		}
	}
	grid[exitRow][exitColumn] = 'E';
	grid[currentLocationY][currentLocationX] = 'X';
}
void ReadTemple()
{
	std::string _tmp; 
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < column; x++)
		{
			_tmp += grid[y][x];
		}
		_tmp += "\n";
	}
	std::cout << _tmp << std::endl; 
}
void SetCursor()
{
	std::cout << "Move with z,s,q,d : " << std::endl; 
	char _input;
	bool _isValid = false;
	while (!_isValid)
	{
		std::cin >> _input;
		_isValid = _input == 's' 
			     || _input == 'z' 
			     || _input == 'q' 
			     || _input == 'd';
	}
	bool _left = _input == 'q',
		 _right = _input == 'd',
		 _up = _input == 'z',
		 _down = _input == 's';
	if (_left)
	{
		currentLocationX--;
		currentLocationX = currentLocationX < 0 ? 0 : currentLocationX;
	}
	else if (_right)
	{
		currentLocationX++;
		currentLocationX = currentLocationX > column-1 ? column - 1 : currentLocationX;
	}
	else if (_up)
	{
		currentLocationY--;
		currentLocationY = currentLocationY < 0 ? 0 : currentLocationY;
	}
	else if (_down)
	{
		currentLocationY++;
		currentLocationY = currentLocationY > row-1 ? row - 1 : currentLocationY;
	}
	if(grid[currentLocationY][currentLocationX] != 'E')
		grid[currentLocationY][currentLocationX] = 'X';
	std::cout << "Cursor location is at : " << currentLocationX << "," << currentLocationY << std::endl;
}
void SetPlayerDamage(int _dmg)
{
	playerLife -= _dmg; 
	playerLife = playerLife < 0 ? 0 : playerLife;
}
void SetPlayerEffect()
{
	bool _damage = content[currentLocationY][currentLocationX]; 
	playerLife += _damage ? -maxDamage : maxBonusLife;

	playerLife = playerLife < 0 ? 0 : 
				 playerLife > 100 ? 100 :
				 playerLife;	

	std::cout << "Player life is : " << playerLife << " PV " << std::endl;
}
bool LooseGame()
{
	return playerLife == 0;
}
bool WinGame()
{
	return playerLife > 0 && (currentLocationX == exitColumn && currentLocationY == exitRow);
}
void CheckEndGame()
{
	if (LooseGame())
		std::cout << "You loose" << std::endl;
	else if (WinGame())
		std::cout << "You win" << std::endl;
}
int PickWeapon()
{
	int _select = 0;
	string _fullID = "";
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			_fullID += " " + inventory[i][j];
		}
		cout << i + 1 << " - " << _fullID << endl;
		_fullID = "";
	}
	while(_select <= 0 || _select > 5)
		cin >> _select; 
	return stoi(inventory[_select-1][1]);
}
void Fight()
{
	srand((unsigned int)time(NULL));
	int _eDamage = (rand() % (20 - 11) + 10), _eLife = 100;
	while (_eLife > 0 && playerLife > 0)
	{
		_eLife -= PickWeapon(); 
		_eLife = _eLife < 0 ? 0 : _eLife;
		SetPlayerDamage(_eDamage);
		CheckEndGame();
		cout << "e : " << _eLife << " e damage : " << _eDamage << " p : " << playerLife << endl;
	}
}
int main()
{
	int i = 50; 
	float f; 
	f = i; //implicite
	cout << f << endl;
	f = 50.12f; 
	cout << f << endl;
	i = (int)f; //explicite
	cout << i << endl;
	string _s = "10.5";
	cout << stoi(_s) << endl;
	cout << stof(_s) << endl; 
	to_string(i); 
	return 0 ; 
	Fight();
	//srand((unsigned int)time(NULL));
	//std::cout << rand() % 11 << std::endl;
	Init();
	while (true)
	{
		ReadTemple();
		SetPlayerEffect();
		CheckEndGame();
		SetCursor();
	}
}

