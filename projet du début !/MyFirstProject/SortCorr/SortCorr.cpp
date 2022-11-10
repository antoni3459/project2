// SortCorr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int* intArray = nullptr; 
int sizeArray = 0;

void InitArray(int& _size);
void ReadArray();
void Clear();
void Sort(); 

void InitArray(int& _size)
{
    std::cout << "Set array size : " << std::endl; 
    _size = 0;
    std::cin >> _size; 
    _size = _size <= 0 ? 1 : _size;
    intArray = new int[_size];
    std::cout << "New int* array size : " << _size <<  std::endl;
}
void InsertValues()
{
    for (size_t i = 0; i < sizeArray; i++)
    {
        int _input; 
        std::cin >> _input; 
        std::cout << "New value "<< _input << " at index : " << i << std::endl;
        intArray[i] = _input;
    }
}
void ReadArray()
{
    for (size_t i = 0; i < sizeArray; i++)
        std::cout << intArray[i] << std::endl;
    std::cout << "\0" << std::endl;
}
void Clear()
{
    delete[] intArray; 
}
void Sort()
{
    int _tmp = 0;
    for (size_t i = 0; i < sizeArray; i++)
    {
        for (size_t j = i; j < sizeArray; j++)
        {
            if (intArray[i] > intArray[j]) 
            {
                _tmp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = _tmp;
            }
        }
    }
}
int main()
{
    while (true)
    {
        InitArray(sizeArray);
        InsertValues();
        ReadArray();
        Sort();
        ReadArray();
        Clear();
    }

}


