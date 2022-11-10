#include "Object.h"

bool Object::IsInterface() const
{
    return bitMask & Interfarce;
}

bool Object::IsClass() const
{
    return !(bitMask & Interfarce);
}

bool Object::IsAbstract() const
{
    return bitMask & Abstract;
}

int Object::SetBitMask(int _mask)
{
    return bitMask = _mask;;
}
