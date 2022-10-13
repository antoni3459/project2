#include <iostream>
using namespace std;

int x, y, result; 

//signed - +
//unsigned + 

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
    
    result = Add(x,y);
    cout << result << "\n";
    
    result = Substract(x,y);
    cout << result << "\n";
    
    result = Multiply(x,y);
    cout << result << "\n";
    
    result = Divide(x,y);
    cout << result << "\n";
    return 0;
}
