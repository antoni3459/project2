#include "Morpions.h"
#include "Utils.h"

Morpions::Morpions() : Menu("Morpions", {})
{	

}

Morpions::~Morpions()
{
	if (end == true)
		delete plateaux;
	
}

void Morpions::Open()
{
	Play();
}

void Morpions::Play()
{
	while (EndGame())
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
		for (int j = 0; j < 5; j++)
			std::cout << plateaux[i][j] << " ";
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
		for (char j = 0; j < 5; j++)
		{
			if (_input == jeux[i][j])
				plateaux[i][j] = "X";
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
		for (char j = 0; j < 5; j++)
		{
			if (_input == jeux[i][j])
				plateaux[i][j] = "O";
		}
	}
	players = true;
}

bool Morpions::EndGame()
{
	return false;
}
