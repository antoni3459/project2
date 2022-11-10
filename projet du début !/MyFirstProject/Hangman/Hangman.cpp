// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
std::string hangWord = "test", current = "";

void InitWord()
{
	std::cout << "Enter word to guess  : " << std::endl;
	std::cin >> hangWord;
	system("CLS");
	std::string _tmp; 
	for (int i = 0; i < hangWord.length(); i++)
	{
		_tmp += "-";
	}
	current = _tmp;
	std::cout << _tmp << std::endl;
}
void ShowGuess()
{
	std::cout << current << std::endl;
}
char Guess()
{
	char _input; 
	std::cin >> _input;
	return _input;
}

bool CheckEndGame(char _input)
{
	for (int i = 0; i < hangWord.length(); i++)
	{
		if (hangWord[i] == _input)
			current[i] = _input; 
	}
	return current == hangWord;
}
void Game()
{
	if (CheckEndGame(Guess()))
	{
		InitWord();
		Game();
	}
	else
	{
		ShowGuess();
		Game();
	}
}
int main()
{
	InitWord();
	Game();
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
