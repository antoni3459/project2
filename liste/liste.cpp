// liste.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion
int* tabInt = nullptr;
int b = 0;
void Add(int _a);
void clear();
void Read();
int ShowCase(int _b);


void Add(int _a)
{
    ShowCase(b);
    int* tabInt = new int [b];
    tabInt = &_a;
    *tabInt = _a;
}

int ShowCase(int _b)
{
    return _b++;
}
void Read()
{
    for (int i = 0; i < b;i++)
        cout << tabInt[i]<<endl;
}
void clear()
{
    delete[] tabInt;
}
   
int main()
{
    Add(5);
    Read();
    clear();
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
