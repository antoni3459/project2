#pragma once
#include <iostream>
#include "Action.h"
template <typename Args>
class A
{
public :
    Args Add(const Args _a, const Args _b)
    {
        return _a + _b;
    }

    void Test()
    {
        std::cout << "test" << std::endl;
    }
};
