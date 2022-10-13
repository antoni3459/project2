// pendule correction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

string guessWord = "toto",
current="";

void InitWord()
{
    current = "";
    cout << "enter word to guess : " << endl;
    cin >> guessWord;
    system("CLS");
    for (int i = 0; i < guessWord.length();i++)
        current += "-";
    cout << current << endl;
}

bool CheckEndGame(char _input)
{
    for (int i = 0; i < guessWord.length();i++)
    {
        if (tolower(guessWord[i]) == tolower(_input))
            current[i] = _input;
    }
    return current == guessWord;
}

char GetInput()
{
    char _intput;
    cin >> _intput;
    return _intput;
}

void GameLoop()
{
    if (CheckEndGame(GetInput()))
    {
        InitWord();
        GameLoop;
    }
    else
    {
        ShowGuess();
        GameLoop();
    }
}

void ShowGuess()
{
    cout << current << endl;
}

int main()
{
    InitWord();
    GameLoop();
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
