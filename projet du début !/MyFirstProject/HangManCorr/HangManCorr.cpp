#include <iostream>
#include <string>
using namespace std; 

string guessWord = "helicoptere",
	   current = "";

void InitWord()
{
	current = "";
	cout << "Enter word to guess : " << endl; 
	cin >> guessWord;
	system("CLS");
	for (int i = 0; i < guessWord.length(); i++)
	{
		current += "-";
	}
	cout << current << endl;
}

bool CheckEndGame(char _input)
{
	for (int i = 0; i < guessWord.length(); i++)
	{
		if (tolower(guessWord[i]) == tolower(_input))
			current[i] = tolower(_input);
	}
	return current == guessWord; 
}

char GetInput()
{
	char _input; 
	cin >> _input; 
	return _input; 
}
void ShowGuess()
{
	cout << current << endl;
}
void GameLoop()
{
	if (CheckEndGame(GetInput()))
	{
		InitWord();
		GameLoop();
	}
	else
	{
		ShowGuess();
		GameLoop();
	}
}
int main()
{
	InitWord();
	GameLoop();
}

