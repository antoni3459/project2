// la roulette sheh Yoni.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string dict = "poiuytrewq123456789",
text = "I like to code",
key = "iw3";

string InToOut(string _entry)
{
    string _result = "";
    for (int i = 0; i < _entry.size();i++)
    {
        for (int x = 0; x < dict.size();x++)
        {
            if (_entry[i] == dict[x])
                _result += text[x];
        }
    }
}


int main()
{
    for (char c : key)
        cout << text[dict.find(c)];
}

