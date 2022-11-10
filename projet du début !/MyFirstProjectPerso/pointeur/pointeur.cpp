// pointeur.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int c = 65, a = 5, b = 6;

int* ptrC = nullptr;
int* ptrA = nullptr;
int* ptrB = nullptr;


void SwapAB(int* _a, int* _b)
{
    int _tmp = *_a;
    *_a = *_b;
    *_b = _tmp;
}
int main()
{
  
    //std::cout << ptrC << std::endl;
    //std::cout << *ptrC << std::endl; // defférencement du pointeur 
    //*ptrC = 10;
    //std ::cout << *ptrC << std::endl;
    /*SwapAB(&a, &b);
    cout << a << " " << b << endl;*/
    int* _integer = new int(5);
    cout << _integer << endl;
    delete _integer;
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
