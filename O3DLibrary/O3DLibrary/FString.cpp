#include "pch.h"
#include "FString.h"
#include "Booleain.h"

Core::PrimitiveType::FString const Core::PrimitiveType::FString::Empty = "";

Core::PrimitiveType::FString Core::PrimitiveType::FString::SubString(const int _begin, const int _end)
{
    FString _result = Empty;
    for (int i = _begin; i < _end; i++)
        _result.Append(value[i]);
    return _result;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::SubString(const int _begin)
{
    return SubString(_begin, length);
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Replace(const char _old, const char _new)const
{
    char* _array = new char[length];
    strcpy(_array, value);
    for (int i = 0; i < length;i++)
    {
        if (value[i] == _old)
            _array[i] = _new;
    }
    return _array;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Replace(const FString& _old, const FString& _new)const
{
    std::string _str = value;
    size_t _startPos = 0;
    const std::string _from = _old.ToCstr();
    const std::string _to = _new.ToCstr();
    while ((_startPos = _str.find(_from, _startPos)) != std::string::npos)
    {
        _str.replace(_startPos, _from.length(), _to);
        _startPos += _to.length();
    }
    return _str.c_str();
}

Core::PrimitiveType::Booleain Core::PrimitiveType::FString::IsNullOrEpty(const FString& _str)
{
    return _str.value == nullptr || _str.length == 0;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Trim() const
{
    return Replace("", "");
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::ToLower() const
{
    char* _array = new char[length];
    strcpy(_array, value);
    for (int i = 0; i < length; i++)
        _array[i] = std::tolower(_array[i]);
    return _array;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::ToUpper() const
{
    char* _array = new char[length];
    strcpy(_array, value);
    for (int i = 0; i < length; i++)
        _array[i] = std::toupper(_array[i]);
    return _array;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::operator+(const FString& _other) const
{
    FString _result = *this;
    _result.Append(_other);
    return _result;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::operator+=(const FString& _other)
{
    Append(_other);
    return *this;
}

char Core::PrimitiveType::FString::operator[](const int _index)
{
    //TODO get if out of range 
    return value[_index];
}

Core::PrimitiveType::Booleain Core::PrimitiveType::FString::operator==(const FString& _other)const
{
    if (length != _other.length)return false;

    for (int i = 0;i < length; i++)
        if (value[i] != _other.value[i])
            return false;
    return true;
}

Core::PrimitiveType::Booleain Core::PrimitiveType::FString::operator!=(const FString& _other)const
{
    return !this->operator==(_other);
}
