#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

string tabWord[],
getwords = "",
chooseletter = "choisie un combien il y a de lettre",
chooseWords = "choisie un combien il y a de mot",
setWord = "",
guessQuest = "choisie une lettre ou un mot ";




void GetWords(string _chooseWords, string _chosseLetter)
{
    int _i = 0;
    cout << _chosseLetter << endl;
    cin >> _i;
    cout << _chooseWords << endl;
    for (int i = 0;i <= _i;i++)
    {
        cin >> tabWord[i];
    }
    system("CLS");
}

void GuessWords(string _guessQuest, string _setword)
{
    for (int i = 0; i <= 10; i++)
    {
        cout << _guessQuest << "\n";
        cin >> _setword;
    }
}


int main()
{
    GetWords(chooseWords, chooseletter);
    cout << tabWord;
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
