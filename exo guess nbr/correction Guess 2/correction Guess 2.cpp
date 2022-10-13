// correction Guess 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

int guessMin = 1,
guessMax = 100,
guess = 0;


bool IsvalidGuess(int _input, int _minguess, int _maxGuess)
{
    if (_input< _minguess || _input>_maxGuess)
        return false;
    return true;
}
    

void SetrGuessNumber(int _min, int _max)
{
    cout << "set number to guess : " << _min<<" and "<<_max<<endl;
    cin >> guess;
    if (IsvalidGuess(guess, guessMin, guessMax) == false)
        SetrGuessNumber(_min, _max);
    else
        system("CLS");
}

bool Guess(int _guessInput, int _guessValid)
{
    if (_guessInput == _guessValid)
        return true;
    if (_guessInput > _guessValid)
    {
        cout << "Wrong ! It's more !" << endl;
        return false;
    }
    if (_guessInput < _guessValid)
    {
        cout << "Wrong ! It's more!" << endl;
        return false;
    }
}

void MainLoop()
{
    int _currentPlayersGuess;
    cin >> _currentPlayersGuess;
    if (Guess(_currentPlayersGuess, guess) == true)
        cout << "Win";
    else
        MainLoop();
}

int main()
{
    SetrGuessNumber(guessMin, guessMax);
    void MainLoop();

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
