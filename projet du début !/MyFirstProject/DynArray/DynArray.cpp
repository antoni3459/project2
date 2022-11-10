// DynArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int* dynArray = nullptr;
int currentSize = 0;

void Clear();
void Read(); 
void Add(int _value);
void RemoveAt(int _value);

void Clear()
{
    delete[] dynArray;
}

void Add(int _value)
{
    int* _copy = dynArray;
    currentSize++;
    dynArray = new int[currentSize];
    for (size_t i = 0; i < currentSize-1; i++)
        dynArray[i] = _copy[i];
    dynArray[currentSize - 1] = _value;
}
void RemoveAt(int _index)
{
    int _tmpSize = currentSize;
    int* _copy = dynArray;
    currentSize--;
    dynArray = new int[currentSize];
    for (size_t i = 0; i < _index; i++)
        dynArray[i] = _copy[i];
    for (size_t i = _index+1; i < _tmpSize; i++)
        dynArray[i-1] = _copy[i];
}
void Read()
{
    for (size_t i = 0; i < currentSize; i++)
        std::cout << dynArray[i] << std::endl;
}
int main()
{
    Read(); 
    Add(2); 
    Add(5);
    Add(20);
    Read();
    Clear();
}

