#pragma once
#include <iostream>
#include "Action.h"
template <typename T>
class A
{
public :
    T Add(const T _a, const T _b)
    {
        return _a + _b;
    }

    void Test()
    {
        std::cout << "test" << std::endl;
    }
};
