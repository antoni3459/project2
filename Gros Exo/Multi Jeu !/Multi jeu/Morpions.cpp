#include "Morpions.h"
#include "Utils.h"

Morpions::Morpions() : Menu("Morpions", {})
{	

}

Morpions::~Morpions()
{

}

void Morpions::Open()
{
	Play();
}

void Morpions::Play()
{
	while (EndGame() == false)
	{
		Display();
		Players();
		EndGame();
	}
}

void Morpions::Display()
{
	system("cls");
	if (players == true)
		std::cout << "joueur 1 joue : " << std::endl;
	else 
		std::cout << "joueur 2 joue : " << std::endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <3 ; j++)
			std::cout << plateaux[i][j] <<" || ";
		std::cout << std::endl;
	}
}

void Morpions::Players()
{
	if (players == true)
		Play1();
	else
		Play2();
}

void Morpions::Play1()
{
	char _input = ' ';
	std::cin >> _input;
	for (char i = 0; i < 3; i++)
	{
		for (char j = 0; j < 3; j++)
		{
			if (_input == jeux[i][j] && Verif(i, j) == false)
			{
				std::cout << "recommence" << std::endl;
				
			}
			if (_input == jeux[i][j] && Verif(i, j) == true)
			{
				plateaux[i][j] = "X";
			}
		}
	
	}
	players = false;
}

void Morpions::Play2()
{
	char _input = ' ';
	std::cin >> _input;
	for (char i = 0; i < 3; i++)
	{
		for (char j = 0; j < 3; j++)
		{
			if (_input == jeux[i][j] && Verif(i, j) == false)
			{
				std::cout << "recommence" << std::endl;
				return;
			}
			if (_input == jeux[i][j] && Verif(i, j) == true)
			{
				plateaux[i][j] = "O";
			}
		}
	}
	players = true;
}

bool Morpions::Verif(int _i, int _y)
{
	if (plateaux[_i][_y] == "X" || plateaux[_i][_y] == "O")
		return false;
	else
		return true;
}



bool Morpions::EndGame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			
		}
	}
	return false;
}
