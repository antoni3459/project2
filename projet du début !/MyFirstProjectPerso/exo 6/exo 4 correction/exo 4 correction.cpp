// exo 4 correction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int x, y , result;

int Add(int _a, int _b)
{
    return _a + _b;

}
int Substract(int _a, int _b)
{
    return _a - _b;
}

int Divide(int _a, int _b)
{
    return _a / _b;
}

int Multiply(int _a, int _b)
{
    return _a * _b;
}

void SetFirstMember()
{
    cin >> x;
}

void SetLastMember()
{
    cin >> y;
}

int main()
{
    SetFirstMember();
    SetLastMember();

    result = Add(x, y);
    cout << result << "\n";

    result = Substract(x, y);
    cout << result << "\n";

    result = Multiply(x, y);
    cout << result << "\n";

    result = Divide(x, y);
    cout << result << "\n";
    return 0;
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
