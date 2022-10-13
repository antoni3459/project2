// tableau dynaùique class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 


class Node
{
public:
    int data;

    Node* next = nullptr;
    Node(int _data, Node* _next = nullptr)
    {
        data = _data;
        next = _next;
    }
};

template<typename T>

class List
{
private:
    int* tree = nullptr;
    int count = 0,
        index = 0;
    T* tab = new T[0];
public:
    void Array(initializer_list<T> _tab)
    {
        tab = new T[_tab.size()];
        count = _tab.size();
         index = 0;
        for (T _item : _tab)
        {
            tab[index++] = _item;
        }
    }
    T At(int _index)
    {
        return tab[index];

    }
    void Display()
    {
        while (tree != nullptr)
        {
            cout << tab << " ";
            tab = tab;
        }
    }
};

int main()
{
    
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
