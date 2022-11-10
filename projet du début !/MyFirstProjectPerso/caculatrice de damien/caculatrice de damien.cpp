// caculatrice de damien.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

const int memSize = 5;
float stock[memSize];
int memIndex = 0;

void claerMemory()
{
    for (int i = 0; i < memSize;i++)
        stock[i] = 0;
}

void readMemory()
{
    cout << "Read current calc memory : \n";
    for (int i = 0; i < memSize; i++)
        cout << i+1<< " - " << stock[i] << endl;
}

void InitStock()
{
    for (int i = 0; i < memSize;i++)
        cout << stock[i] << endl;
}
void SetMemory(string _toSave)
{
    stock[memIndex] = _toSave;
    memIndex++;
    memIndex = (memIndex > memSize - 1) ? 0 : memIndex;
}

string addition(float _a, float _b)
{
    float _c = _a + _b;
    return to_string(_a) + " + " + to_string(_b) + " = " + to_string(_c);
}

float divide(float _a, float _b)
{
    float _c=_b == 0 ? 0 : _a / _b;
    return to_string(_a) + " / " + to_string(_b) + " = " + to_string(_c);
}

int main()
{
    claerMemory();
    readMemory();
    SetMemory(addition(5,2));
    SetMemory(addition(10, 2)); 
    SetMemory(addition(20, 2));
    readMemory();


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
