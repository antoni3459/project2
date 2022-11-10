// correction tableau croissant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

int* intArray = nullptr;
int sizeArray = 0;
void clear();
void InitArray(int& _size);
void InsertValue();
void ReadArray();
void swap();

void clear()
{
    delete[] intArray;
}
void InitArray(int& _size)
{
    cout << "set array size : " << endl;
    _size = 0;
    cin >> _size;
    _size = _size <= 0 ? 1 : _size;
    intArray = new int[_size];
    cout << "new int* array size : " << _size << endl;
}

void InsertValue()
{
    for (size_t i = 0;i < sizeArray;i ++ )
    {
        int _input;
        cin >> _input;
        cout << "new value " << _input << "at index : " << i << endl;
        intArray[i] = _input;
    }
}

void swap()
{
    for (size_t i = 0;i < sizeArray;i++)
    {
        if (intArray[i] < intArray[i - 1])
        {
            int _tmp = intArray[i];
            intArray[i] = intArray[i - 1];
            intArray[i - 1] = _tmp;
        }
        else
        {
            intArray[i] = intArray[i];
            intArray[i - 1] = intArray[i - 1];
        }
    }
}
void ReadArray()
{
    for (size_t i = 0;i < sizeArray;i++)
        cout << intArray[i] << endl;
}

int main()
{
    InitArray(sizeArray);
    InsertValue();
    swap();
    ReadArray ();
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
