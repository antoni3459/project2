// CorrectionGuess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int guessMin = 1,
	guessMax = 100,
	guess = 0;

bool IsValidGuess(int _input, int _minGuess, int _maxGuess)
{
	if (_input < _minGuess || _input > _maxGuess)
		return false;
	return true; 
}

void SetGuessNumber(int _min, int _max)
{
	cout << "Set number to guess between : " << _min << " and " << _max << endl;
	cin >> guess;
	if (IsValidGuess(guess, _min, _max) == false)
		SetGuessNumber(_min, _max);
	else
		system("CLS");
}

bool Guess(int _guessInput, int _guessValid)
{
	if (_guessInput == _guessValid)
		return true;
	if (_guessInput > _guessValid)
	{
		cout << "Wrong ! It's less !" << endl;
		return false;
	}
	if (_guessInput < _guessValid)
	{
		cout << "Wrong ! It's more !" << endl;
		return false;
	}
}
void MainLoop()
{
	int _currentGuess = 0;
	cin >> _currentGuess;
	if (Guess(_currentGuess, guess) == true)
		cout << "WIN !";
	else
		MainLoop();
}

int main()
{
	SetGuessNumber(guessMin, guessMax);
	MainLoop();
}


