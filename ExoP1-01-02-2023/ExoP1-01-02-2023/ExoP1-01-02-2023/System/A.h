#pragma once
#include "B.h"
#include <string>

class A
{
private:
    B* bahDommage = nullptr;
    static inline std::string str = "";
    int* tab = new int[400];
    float sabug = 0.0f;

public:
    A() = default;
    ~A();

public:
    void Test();
    void Hello();
};
