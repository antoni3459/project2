#include "pch.h"
#include "FString.h"
#include "Interger.h"
#include "Boolean.h"
#include "Exception.h"

Core::PrimitiveType::FString const Core::PrimitiveType::FString::Empty = "";


void Core::PrimitiveType::FString::Append(const FString& _str)
{
    const int _newLength = length + _str.length;
    char* _array = new char[_newLength + 1];
    strcpy(_array, value);
    strcat(_array, _str.value);
    value = _array;
    length = _newLength;
}

void Core::PrimitiveType::FString::Append(const char _value)
{
    const int _newLength = length + 1;
    char* _array = new char[_newLength];
    strcpy(_array, value);
    _array[length] = _value;
    _array[length + 1] = '\0';
    value = _array;
    length += 1;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Convert(const std::wstring& _wstring)
{
    const std::string& _str = std::string(_wstring.begin(), _wstring.end());
    return _str.c_str();
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::SubString(const int _begin, const int _end)const
{
    FString _result = Empty;
    for (int i = _begin; i < _end; i++)
        _result.Append(value[i]);
    return _result;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::SubString(const int _begin)const
{
    return SubString(_begin, length);
}

Core::PrimitiveType::Integer Core::PrimitiveType::FString::Length() const
{
    return length;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Replace(const char _old, const char _new) const
{
    char* _array = new char[length];
    strcpy(_array, value);
    for (int i = 0; i < length; i++)
    {
        if (value[i] == _old)
            _array[i] = _new;
    }
    return _array;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::Replace(const FString& _old, const FString& _new) const
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

Core::PrimitiveType::FString Core::PrimitiveType::FString::Trim() const
{
    return Replace(" ", "");
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

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::StartWidth(const char _c) const
{
    return value[0] == _c;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::StartWidth(const FString& _str) const
{
    const int _length = _str.length;
    for (int i = 0; i < _length; i++)
    {
        if (value[i] != _str[i])
            return false;
    }
    return true;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::EndWidth(const char _c) const
{
    return value[length - 1] == _c;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::EndWidth(const FString& _str) const
{
    const int _otherLength = _str.length;
    for (int i = _otherLength; i > 0; i--)
    {
        if (value[length - 1] != _str[_otherLength - 1])
            return false;
    }
    return true;
}

Core::PrimitiveType::Integer Core::PrimitiveType::FString::LastIndexOf(const char _c) const
{
    int _result = -1;
    for (int i = 0; i < length; i++)
    {
        if (value[i] == _c);
        _result - 1;
    }
    return _result;
}
Core::PrimitiveType::Integer Core::PrimitiveType::FString::FirstIndexOf(const char _c) const
{
    for (int i = 0; i < length; i++)
    {
        if (value[i] == _c)
            return i;
    }
    return -1;
}

Core::PrimitiveType::Integer Core::PrimitiveType::FString::Find(const FString& _str) const
{
    return std::string(value).find(_str.ToCstr());
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::Contains(const FString& _str) const
{
    return Find(_str) != Integer(-1);
}

std::wstring Core::PrimitiveType::FString::ToWString() const
{
    std::string _str = value;
    return std::wstring(_str.begin(), _str.end());
}

const char* Core::PrimitiveType::FString::ToCstr() const
{
    return value;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::IsNullOrEmpty(const FString& _str)
{
    return _str.value == nullptr || _str.length == 0;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::Equals(const FString& _other) const
{
    return value == _other.value;
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::ToString() const
{
    return value;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::Equals(const Object* _obj) const
{
    const FString* _other = dynamic_cast<const FString*>(_obj);
    if (_other == nullptr) return false;
    return Equals(*_other);
}

Core::PrimitiveType::FString Core::PrimitiveType::FString::operator+(const FString& _other) const
{
    FString _result = *this;
    _result.Append(_other);
    return _result;
}

Core::PrimitiveType::FString& Core::PrimitiveType::FString::operator+=(const FString& _other)
{
    Append(_other);
    return *this;
}

char Core::PrimitiveType::FString::operator[](const int _index) const
{
    if (_index < 0 || _index > length)
        throw OutOfRangeException("[FString] => index out of range");
    return value[_index];
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::operator==(const FString& _other) const
{
    if (length != _other.length) return false;

    for (int i = 0; i < length; i++)
    {
        if (value[i] != _other.value[i])
            return false;
    }
    return true;
}

Core::PrimitiveType::Boolean Core::PrimitiveType::FString::operator!=(const FString& _other) const
{
    return !this->operator==(_other);
}
