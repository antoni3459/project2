// TranslateCorr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

const int sizeTab = 5;

string frenchWords[sizeTab] = { "avion", "arbre","pomme", "chevre", "eau"};
string englishWords[sizeTab] = { "plane", "tree","apple", "goat", "water"};

bool isFrenchTranslation = false;

string GetModeWords(bool _frMode)
{
    string _word = "";
    if (_frMode)
    {
        for (int i = 0; i < sizeTab; i++)
        {
            string _endWord = (i == sizeTab-1) ? "." : ", ";
            _word += englishWords[i] + _endWord;
        }
        return "Words are : " + _word;
    }
    else
    {
        for (int i = 0; i < sizeTab; i++)
        {
            string _endWord = (i == sizeTab-1) ? "." : ", ";
            _word += frenchWords[i] + _endWord;
        } 
        return "Les mots sont : " + _word;
    }
}
void InitTranslator(bool _frMode)
{
    cout << GetModeWords(_frMode) << endl;
    //example github
}
string IsValidWord(string _input)
{
    //loop? 
    for (int i = 0; i < sizeTab; i++)
    {
        if (_input == frenchWords[i])
            return englishWords[i];
        if (_input == englishWords[i])
            return frenchWords[i];
    }
}
string InputWord()
{
    string _input;
    cin >> _input; 
    cout << "Word is : " << _input << endl;
    return _input; 
}
int main()
{
    InitTranslator(isFrenchTranslation);
    cout << IsValidWord(InputWord()) << endl;
    main();
}


