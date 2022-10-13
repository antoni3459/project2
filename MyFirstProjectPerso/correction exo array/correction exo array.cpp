// correction exo array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>

class Array 
{
private:
    int count = 0;
        T * tab = nullptr;

public:
    Array(int _count)
    {
        count = _count;
        tab = new T[count];
    }
    Array(T _item, int _count)
    {
        
    }

    Array(initializer_list<T> _tab)
    {
        count = _count;
        tab = new T[count];
        int _index = 0;
        for (int i = 0; i < count; i++)
        {
            tab[_index] = _item;
            _index++;
        }
              
    }
    T& At(int _index)
    {
        return tab[_index];
    }
    T& Back()
    {
        return tab[0];
    }
    T& Front (int _index)
    {
        return tab[_index];
    }
    void Resize(int _newCount)
    {
        T* _tmp = tab;
        int _oldcount = count;
        count = _newCount;
        tab = new T[count];
        for (int i = 0; i < _oldCount; i++)
            tab[i] = _tmp[i];
    }
    bool operator ==(const Array& _other)
    {
        if (count != _other.count) return false;
        for (int i = 0; i < count; i++)
        {
            if (tab[i] != _other.tab[i])return false;
        }
        return true;
    }
    bool operator  != (const Array& _other)
    {
        return !this -> operator ==(_other);
    }
    T& operator 
int main()
{
    Array<int>  _tab = Array <int>(10);
    for (int 

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
