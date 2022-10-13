// TempVariable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//
unsigned short int uShort = 0;
short int shortInt = 32768;
unsigned int intSize = 2147483648;
int myVar = 0, testVar = 455500012;
unsigned long int uLong = 0;
long int longInt = 1000000;

char c = 'a'; //-255/255 
unsigned char uC = 100;
std::string s = "";

float f = 100.10f; 
double d = 0.0; 
long double lD = 0; 

int GetVar()
{
    return (455500012 * 455500012) * 5;
}

int Test(int _a, int _b)
{
    int _r = GetVar();
    _a = _r * 5;
    _b += _a * _r;
    return _r;
}
void Last()
{
    myVar = 15;
}
int main()
{
    std::cout << intSize << "\n";
}

