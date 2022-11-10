// tableau croissant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

int x = 0;

void SizeTab()
{
    int _a = 0;
    int _value;
    cout << "combien collone vous voulez dans votre tableau" << "\n";
    cin >> _a;
    int* _tabInt = new int[_a];
    for (x ;x < _a; x++)
    {
        cin >> _value;
        _tabInt[x] = _value;
    }
    for (x;x < _a;x++)
    {
        if (_tabInt[x + 1] < _tabInt[x])
        {
            int _tmp = _tabInt[x];
            _tabInt[x] = _tabInt[x + 1];
            _tabInt[x + 1] = _tmp;
        }
        else
        {
            _tabInt[x];
            _tabInt[x + 1];
        }
    }
 
    for (x=0 ;x < _a; x++) 
    {
        cout << _tabInt[x] << endl;
    }
    delete[] _tabInt;
}

int main()
{
    SizeTab();
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
