// correction calculette condition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int x, y;

char ChooseSign()
{
    char _tempResult;
    cin >> _tempResult;
    //DEBUG
    cout << _tempResult;
    return _tempResult;
}

void SetMemnber()
{
    cout << "set X member : " << endl;
    cin >> x;
    cout << "set Y member : " << endl;
    cin >> y;
}

int Add(int _a, int _b)
{
    return _a + _b;
}

int Sub(int _a, int _b)
{
    return _a - _b;
}
int Multiply(int _a, int _b)
{
    return _a * _b;
}
int Divide(int _a, int _b)
{
    if (_b == 0)
        return 0;
    return _a / _b;
}

void SetMember()
{
    cin >> x;
    cin >> y;
}

void SelectCalculator(char _mode, int _x, int _y)
{
    if (_mode == '+')
        cout << "result : " << Add(_x, _y);
    else if (_mode == '*' || _mode == 'x' || _mode == 'X')
        cout << "result : " << Multiply(_x, _y);
    else if (_mode == '/' || _mode == ':')
        cout << "result : " << Divide(_x, _y);
    else if (_mode == '-')
        cout << "result : " << Sub(_x, _y);
    else
        ChooseSign();
}

int main()
{
    SetMember();
    SelectCalculator(ChooseSign(), x, y );

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
