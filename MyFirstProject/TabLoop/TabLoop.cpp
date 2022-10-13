// TabLoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 
int a = 10; 
int tabA[] = {10,5,4,30,9};
float tabB[2]; 


//tableau de taille 5 
//array size 5 
//array length 5 (longueur) 
//0,1,2,3,4 
void GetResults()
{
    for (int index = 0; index <= 10; index++)
        std::cout << index * 10 << std::endl;
}
int main()
{
    //tabB[0] = 12.45f;
    //tabB[1] = 42.45f;
    //std::cout << tabB[0] << " " << tabB[1] << std::endl;
    ////[i] index = 0, n 
    //std::cout << tabA[0] << std::endl;//10
    //std::cout << tabA[1] << std::endl;//5
    //std::cout << tabA[2] << std::endl;//4
    //std::cout << tabA[3] << std::endl;//30
    //std::cout << tabA[4] << std::endl;//9
    //std::cout << tabA[5] << std::endl; //crash 
    //index out of range < 0 > size() 
    //int _example[10];
    //for (int i = 0; i < 10 ; i++  )
    //{
    //    _example[i] = 100 * i;
    //    std::cout << _example[i] << std::endl;
    //    //do something 
    //} 
    int b = 45;
    bool _canRun = true;
    for (float index = -100, j = b, k = 0; index <= 100 && _canRun; index++, j--, k+=.1f)
    {
        cout << "i : " << index << endl;
        cout << "j : " << j << endl;
        cout << "k : " << k << endl;
    }
    for (float i = 0; i < 100; i+=.1f)
    {
        cout << "f : " << i << endl;
    }
   /* for (char c = 0; c < 255; c++)
    {
        cout << c << endl; 
    }*/
}

