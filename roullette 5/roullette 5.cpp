
// roullette 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#pragma warning (disable: 4996)
char* ToCharArray(const std::string& _str)
{
    char* _result = new char[_str.size() + 1];
    strcpy(_result, _str.c_str());
    return _result;
}

int main()
{
    int n = 321;
    char* _array = ToCharArray(std::to_string(n));
    std::reverse(_array, _array + strlen(_array));
    std::cout << n - std::stoi(_array);
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
