// correction guess nbr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

#pragma region Game settings
int guessNumber = 10,
minGuess = 1,
maxGuess = 100,
gameAttempt = 0,
gameAttemptMax = 2;
bool useLimitGame = false;
#pragma endregion 

/// <summary>
/// Set guess between min and max
/// </summary>
/// <param name="_min">min guess number clamp</param>
/// <param name="_max">max guess number clamp</param>
void SetGuessNumber(int _min, int _max)
{
    cout << "Set number between " << _min << "and " << _max << " : ";
    cin >> guessNumber;
    if (guessNumber > _max)
        guessNumber = _max;
    else if (guessNumber < _min)
        guessNumber = _min;
    system("CLS");
}

void GuessGame()
{
    cout << "Guess a number between " << minGuess << " and " << maxGuess << endl;
    int _guess = 0;
    cin >> _guess;
    cout << _guess;
    cout << "Your imput is : " << _guess << endl;
    // gameAttempt = gameAttempt + 1    gameAttempt = gameAttempt - 1   
    // gameAttempt += gameAttempt    gameAttempt -= gameAttempt 
    if (useLimitGame)
    {
        gameAttempt++; //+1
        if (gameAttempt >= gameAttemptMax)
        {
            cout << "you loose ! No more try !";
            gameAttempt = 0;
            SetGuessNumber(minGuess, maxGuess);
            GuessGame();
        }
    }
    if (_guess == guessNumber)
    {
        cout << "YOU WIN! Guess was : " << _guess << endl;
        // game loop
        SetGuessNumber(minGuess, maxGuess);
        GuessGame();
    }
    else if (_guess > guessNumber)
    {
        cout << "You Lose ! Your guessis too hight !";
        GuessGame();
    }
    else
    {
        cout << "You lose ! Your guess is too low !";
        // game loop
        GuessGame();
    }
}


int main()
{
    SetGuessNumber(minGuess, maxGuess);
    GuessGame();
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
