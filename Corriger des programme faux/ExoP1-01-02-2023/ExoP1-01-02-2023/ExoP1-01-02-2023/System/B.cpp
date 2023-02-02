#include "B.h"

#include <iostream>
void B::Start()
{
    static int a = 0;
    while(a < 1)
    {
        std::cout << "AHHHHHHH" << std::endl;
        a++;
    }
}
