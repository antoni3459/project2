// Ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void Swap(int* _a, int* _b)
{
    int _tmp;
    _tmp = *_a;
    *_a = *_b;
    *_b = _tmp;
}

int main()
{
    int _b = 50;
    int* _f = new int(5);
    int *_a = &_b;
    std::cout << _f << std::endl;
    std::cout << *_f << std::endl;
    std::cout << _a << std::endl;
    _a ++;
    std::cout << _a << std::endl;
    std::cout << *_a+6 << std::endl;
    int* _i =  new int(5);
    int* _j = new int(6);
    std::cout << _i << std::endl;
    std::cout << _j << std::endl;
    _j = _i;
    if (_j == _i)
        std::cout << "OK" << std::endl;
    std::cout << _j << std::endl;
    std::cout << *_j << std::endl;
    delete _f,_i,_j; 
    std::cout << "Hello World!\n";
    int a = 5, b = 10; 
    std::cout << a << " " << b << std::endl;
    Swap(&a, &b); 
    std::cout << a <<" "<< b<<std::endl;
    char* _c;
    _c = new char[4];
    _c[0] = 'a';
    _c[1] = 'b';
    _c[2] = 'c';
    _c[3] = '\0';
    std::cout << static_cast<void*>(_c) << std::endl;
    std::cout << _c << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << _c[i] << std::endl; 
    }
    delete[] _c;
    _c = new char[5];
    for (size_t i = 0; i < 5; i++)
    {
        _c[i] = i+225;
        std::cout << _c[i] << std::endl;
    }
    std::cout << _c << std::endl;
    delete[] _c;
    int* _int = new int[5] {0,1,2,3,4};
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << &_int[i] << std::endl;
    }
    std::cout << _int << std::endl;
    delete[] _int;
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
