// PtrTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int a = 5, b = 10;

int DoubleInt(int _i); 
int* AddressOf(int _i);
void RefExample(int& _value, int _add);
void SwapRef(int& _a, int& _b);
void Sort()
{
    int _sort[] = { 5,15,23,4,611 };
    int _temp = 9999999;
    for (int i = 0; i < 5; i++)
        std::cout << _sort[i] << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (_sort[i] > _sort[j])
            {
                _temp = _sort[i];
                _sort[i] = _sort[j];
                _sort[j] = _temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
        std::cout << _sort[i] << std::endl;
}


void RefExample(int& _value, int _add)
{
    //copy 
    _value *= 2 + _add;
}
int DoubleInt(int _i)
{
    int* _ptr = new int(_i);
    std::cout << _ptr << std::endl;
    int _tmp = *_ptr *= 2;
    delete _ptr; 
    return _tmp;
}
int* AddressOf(int _i)
{
    return &_i;
}
void SwapRef(int& _a, int& _b)
{
    int _tmp = _a; 
    _a = _b;
    _b = _tmp;
}
void SwapRef(int* _a, int* _b)
{
    int _tmp = *_a;
    *_a = *_b;
    *_b = _tmp;
}
int main()
{
    Sort();
    return 0;
    char* _chaine = new char[3];
    _chaine[0] = 'S';
    _chaine[1] = 'T';
    _chaine[2] = '\0';
    std::cout << _chaine << std::endl;
    delete[] _chaine;
    int* _tabInt = new int[a]; 
    for (size_t i = 0; i < a; i++)
    {
        _tabInt[i] = i; 
        std::cout << _tabInt[i] << std::endl; 
    }
    std::cout << _tabInt << std::endl; 
    std::cout << &_tabInt[0] << std::endl;
    std::cout << &_tabInt[1] << std::endl;
    std::cout << &_tabInt[2] << std::endl;
    std::cout << &_tabInt[3] << std::endl;
    std::cout << &_tabInt[4] << std::endl;
    int* _other = new int[a];
    std::cout << _other << std::endl;
    delete[] _tabInt, _other;
    return 0;
    std::cout << a << std::endl;
    RefExample(a,10);
    std::cout << a << std::endl;
    std::cout << a << " " << b << std::endl;
    SwapRef(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << a << " " << b << std::endl;
    SwapRef(&a, &b);
    std::cout << a << " " << b << std::endl;
    int* _aPtr = &a; 
    int* _bPtr = &b;
    _aPtr = _bPtr; 
    if (_aPtr == _bPtr)
        std::cout << "OK" << std::endl; 
    else 
        std::cout << "KO" << std::endl;
    if (!_aPtr) //ptr == nullptr
        return 0;
    if (_aPtr) //ptr != nullptr
    {

    }
    //std::cout << DoubleInt(10) << std::endl;
    //std::cout << AddressOf(100) << std::endl;
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
