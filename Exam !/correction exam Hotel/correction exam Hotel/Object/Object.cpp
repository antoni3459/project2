#include "Object.h"
#include <string>
#include <typeinfo>
#include <math.h>

std::string Object::ToString() const
{
    std::string _name = typeid(*this).name();
    return _name.substr(_name.find_last_of(' ') + 1);
}
