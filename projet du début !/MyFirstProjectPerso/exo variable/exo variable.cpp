// exo variable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


unsigned short int uShort = 0; // prend les valeurs positif
short int shortInt = 100; // Le short prend moins de place que le int
unsigned int intsize; //prend que les positif 
int intSize = 2147483648;
unsigned long int 
long int longInt = 1000000000;// c'est plus long que le int

char c = 'a'; //-255/255
unsigned char uC = 100;
std::string s = "";

float f = 100.10f;
double d = 0.0;
long double lD = 0;

void Test(int _a, int _b)
{
    int _r =GetVar(); //_r est une vriable temporaire créé qu epour se bloc et il faut aussie mettre "_"
    _a = _r * 5;
    _b += _a * _r;
}
double GetVar()
{
    return GetVar(45661 * 45346) * 5;
}

int main()
{
    Test(5, 2);
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
