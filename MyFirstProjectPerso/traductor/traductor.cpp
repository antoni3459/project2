// traductor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int sizeTab = 2;
string tabFr[sizeTab] = { "avion", "arbre" },
tabEn[sizeTab] = { "plane", "tree" };
string lastInput;
bool isFrenchTranslation = false;

string GetModeWords(bool _frMode)
{
    string _word = "";
    if (_frMode)
    {
        for (int i = 0; i < sizeTab; i++)
        {
            string _endWord = (i == sizeTab-1) ? "." : ", ";
            _word += tabEn[i] + _endWord;
        }
        return " Word are : " + _word;
    }
    else
    {
        for (int i = 0; i < sizeTab; i++)
        {
            string _endWord = (i == sizeTab-1) ? "." : ", ";
            _word += tabFr[i] + _endWord;
        }
        return " Les mots sont : " + _word;
    }
}

void InitTranslator(bool _frMode)
{
    cout << GetModeWords(_frMode) << endl;
}

string IsValidWord(string _input)
{
    for (int i = 0; i < sizeTab; i++)
    {
        if (_input == tabFr[i])
            return  tabEn[i];
        if (_input == tabEn[i])
            return tabFr[i];
    }
}

string InputMode()
{
    string _input;
    cin >> _input;
    cout << "Word is : " << _input << endl;
    return _input;
}

int main()
{
    InitTranslator(isFrenchTranslation);
    lastInput = InputMode();
    cout << IsValidWord(lastInput) << endl;
    main();
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
