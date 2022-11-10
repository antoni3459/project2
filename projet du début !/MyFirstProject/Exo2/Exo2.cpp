#include <iostream>
using namespace std;

//#include <string> 

int value = 10;

int ReturnExample()
{
    cout << "I'm return method !\n";
    return value * 2;
}
void SetValue()
{
    value = 20;
}
void NoReturnExample()
{
    cout << "I'm void method !\n";
}
int main()
{
    cout << value << "\n"; 
    SetValue();
    cout << value << "\n";
    value = ReturnExample();
    cout << value << "\n";
    value = (ReturnExample() * 2) + 100 ;
    cout << value << "\n"; 
}
