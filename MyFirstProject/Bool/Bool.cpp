// Bool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int a, b , c, d; 
bool light = false, switchButton = false;

void SwitchLight()
{
    switchButton = !switchButton;
    light = switchButton; 
}
bool IsValid()
{
    return a == c; 
}
int Test()
{
    return (a > 5) ? a : 5; 
}
int main()
{  
    a = 10; 
    b = 10; 
    if (a <= b)
        std::cout << "Yes"<< std::endl;
    else 
        std::cout << "No" << std::endl;

    if (a == b) // VRAI - FAUX 
        std::cout << "do" << std::endl;
    if( a != b) // VRAI - FAUX
        std::cout << "do" << std::endl;

    if( a > c && b < d ) // VRAI
        std::cout << "do" << std::endl;
    if (a > c || (b < d && c > 10)) // VRAI
        std::cout << "do" << std::endl;
    if (c < 10)
        return; 

    bool isValid = true; 

    if(isValid == true) 
        std::cout << "do" << std::endl;
    if (isValid == false)
        std::cout << "do" << std::endl;
    if(isValid)
        std::cout << "do" << std::endl;
    if (!isValid)
        return;
    isValid = false;
    isValid = true;

    bool isOn = true;
 /* if (isOn == true)
    {
        isOn = false;
    }
    else if (isOn == false)
    {
        isOn = true;
    }*/
    isOn = !isOn; 
    //f = v 
    //v = f 
    if (IsValid() == true)
        std::cout << "do" << std::endl;
    if (IsValid())
        std::cout << "do" << std::endl;
    if (!IsValid())
        std::cout << "do" << std::endl;

    if (a > 5)
        c = 10;
    else
        c = 5; 
    //ternaire
    c = (a > 5) ? 10 : 5; 
    a = (d == c) ? 100 : 5; 
    d = (a == 20) ? c : Test();

    //if elseif else 
    d = (a > 10) ? 10 :
        (d < 5) ? 10 : a;

    //
    bool _isAlien = false;
    bool _isValid = ((b > c) || c == 5 && c * 2 == 10);
    a = _isValid  ? 10 : 5;
    int _life = _isAlien ? 1000 : 100;
    bool _isDead = false;
    _isDead = _life <=0 ;

}
