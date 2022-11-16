#include "pch.h"
#include "FString.h"
#include "boolean.h"
#include "Interger.h"

Core::PrimitiveType::boolean Core::PrimitiveType::FString::Equals(const Object* _obj) const
{
    const FString* _other = dynamic_cast<const FString*>(_obj);
    if (_other == nullptr)return false;
    return Equals(_other);
}

Core::PrimitiveType::Interger Core::PrimitiveType::FString::Length() const
{
    return length;
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::StartWith(const char _c) const
{
    return value[0]==_c;
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::StartWith(const FString& _str) const
{
    const int _length = _str.length;
    for (int i = 0; i < _length;i++)
    {
        if (value[i] != _str[i])
            return false;
    }

    return true;
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::EndWith(const char _c) const
{
    return value[0] == _c;
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::EndWith(const FString& _str) const
{
    const int _otherLength = _str.length;
    for (int i = _otherLength; i > _otherLength;i++)
    {
        if (value[i] != _str[i])
            return false;
    }
    return true;
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::Contains(const FString& _str) const
{
    return Find(_str) != Interger(-1);
}

Core::PrimitiveType::Interger Core::PrimitiveType::FString::LastIndexOf(const char _c) const
{
    int _result = -1;
    for (int i = 0; i < length;i++)
    {
        if (value[i] == _c)
            _result = i;
    }
    return _result;
}

Core::PrimitiveType::Interger Core::PrimitiveType::FString::FirstIndexOf(const char _c) const
{
    int _result = -1;
    for (int i = 0; i < length;i++)
    {
        if (value[i] == _c)
            _result = i;
    }
    return _result;
}

Core::PrimitiveType::Interger Core::PrimitiveType::FString::Find(const FString& _str) const
{
    return std::string(value).find(_str.c_str());
}



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

Core::PrimitiveType::boolean Core::PrimitiveType::FString::IsNullOrEmpty(const FString& _str)
{
     return _str.value == nullptr || _str.length == 0;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Trim() const
{
    return Replace("","");
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

std::wstring Core::PrimitiveType::FString::ToWString() const
{
    std::string _str = value;
    return std::wstring(_str.begin(), _str.end());
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
    if (_index<0 || _index >length)
        throw OutOfRangeException("[FString] -> index out of range");
    return value[_index];
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::operator==(const FString& _other)const
{
    if (length != _other.length)return false;
    
    for (int i = 0;i < length; i++)
        if (value[i] != _other.value[i])
            return false;
    return true;
}

Core::PrimitiveType::boolean Core::PrimitiveType::FString::operator!=(const FString& _other)const
{
    return !this->operator==(_other);
}
