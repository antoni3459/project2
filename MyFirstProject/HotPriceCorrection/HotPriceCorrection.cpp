// HotPriceCorrection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//kmh knots
//knots kmh 
//celcius fahr
//f -> c 
//litres en gallons us
//g -> l 
//feet metres 
//m f 


#include <iostream>
int n[10]; 
#pragma region Game settings
int guessNumber = 10,
	minGuess = 10,
	maxGuess = 25,
	gameAttempt = 0,
	gameAttemptMax = 2;
bool useLimitGame = false; 
#pragma endregion 
/// <summary>
/// Set guess number between min and max
/// </summary>
/// <param name="_min">min guess number clamp</param>
/// <param name="_max">max guess number clamp</param>
void SetGuessNumber(int _min, int _max)
{
	std::cout << "Set number between " << _min << " and " << _max << " : ";
	std::cin >> guessNumber; 
	if (guessNumber > _max)
		guessNumber = _max;
	else if (guessNumber < _min)
		guessNumber = _min;
	system("CLS");
}
/// <summary>
/// main loop
/// </summary>
void GuessGame()
{
	std::cout << "Guess a number between " << minGuess << " and " << maxGuess << std::endl;
 	int _guess = 0;
	std::cin >> _guess;
	std::cout << "Your input is : " << _guess << std::endl; 
	//gameAttempt = gameAttempt + 2; 
	//gameAttempt += 10; 
	//gameAttempt = gameAttempt - 2; 
	//gameAttempt -= 10; 
	//gameAttempt--; //-1
	if (useLimitGame)
	{
		gameAttempt++; //+1
		if (gameAttempt > gameAttemptMax)
		{
			std::cout << "YOU LOOSE ! No more try !" << std::endl;
			gameAttempt = 0;
			SetGuessNumber(minGuess, maxGuess);
			GuessGame();
		}
	}
	if (_guess == guessNumber)
	{
		std::cout << "YOU WIN ! Guess number was : " << _guess << std::endl;
		std::cout << gameAttempt << " attempt !" << std::endl;
		//game loop 
		SetGuessNumber(minGuess, maxGuess);
		GuessGame();
	}
	else if (_guess > guessNumber)
	{
		std::cout << "YOU LOOSE ! Your guess is too hight !" << std::endl;
		//game loop 
		GuessGame();
	}
	else 
	{
		std::cout << "YOU LOOSE ! Your guess is too low !" << std::endl;
		//game loop 
		GuessGame();
	}
}
int main()
{
	SetGuessNumber(minGuess, maxGuess);
	GuessGame(); 
}
