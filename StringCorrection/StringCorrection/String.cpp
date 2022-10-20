#include "String.h"
#include <iostream>

#pragma region constructor/destructor
String::String(const char* _value)
{
    if (_value == nullptr) _value = "";
    const int _otherLength = strlen(_value);
    const int _newLength = length + _otherLength;
    char* _char = new char[_newLength + 1];
    strcpy(_char, value);
    strcat(_char, _value);
    value = _char;
    length = _newLength;
}

String::String(const String& _copy)
{
    if (_copy.value == nullptr) return;
    const int _length = _copy.length;
    char* _char = new char[_length + 1];
    memcpy(_char, _copy.value, _length + 1);
    value = _char;
    length = _length;
}

String::~String()
{
    delete value;
}
#pragma endregion constructor/destructor

#pragma region methods
String String::ToLower() const
{
    char* _result = new char[length];
    for (int i = 0; i < length; i++)
        _result[i] = std::tolower(value[i]);
    _result[length] = '\0';
    return _result;
}

String String::ToUpper() const
{
    char* _result = new char[length];
    for (int i = 0; i < length; i++)
        _result[i] = std::toupper(value[i]);
    _result[length] = '\0';
    return _result;
}

bool String::Contains(const String& _str) const
{
    for (int i = 0; i < length; i++)
    {
        if (value[i] == _str.value[0])
        {
            bool _isValid = true;
            for (int x = i; x < i + _str.length && _isValid; x++)
            {
                if (value[x] != _str.value[x - i])
                    _isValid = false;
            }
            if (_isValid) return true;
        }
    }
    return false;
}

std::vector<String> String::Split(const char _c)
{
    std::vector<String> _result = std::vector<String>();
    int _start = 0;
    for (int i = 0; i < length; i++)
    {
        if (value[i] == _c)
        {
            String _toAdd = "";
            for (int x = _start; x < i; x++)
                _toAdd += value[x];
            _result.push_back(_toAdd);
            _start = i + 1;
        }
    }

    String _toAdd = "";
    for (int x = _start; x < length; x++)
        _toAdd += value[x];
    _result.push_back(_toAdd);
    return _result;
}

String String::Replace(const char _old, const char _new)
{
    char* _char = new char[length];
    for (int i =0 ; i <length; i++)
        _char[i] = value[i] == _old ? _new : value[i];
    _char[length] = '\0';
    return value;
}

int String::LastIndexof(const char _c)
{
    int _result = -1;
    for (int i = 0; i < length; i++)
        if (value[i]==_c)
            _result = i;
    return -1;
}

int String::FirstIndexof(const char _c)
{
    for (int i=0; i<length; i++)
        if (value[i] == _c)
            return i;
    return -1;
}

String String::Join(const std::vector<String>& _value)
{
    String _result = *this;
    const size_t _size = _value.size();
    for (int i = 0; i < _size; i++)
    {
        _result += _value[i];
    }
    return "";
}
String String::Trim()
{
    const int _newLength = length - CountOf(' ');
    char* _tab = new char[_newLength];
    int _index = 0;
    for (int i = 0; i < length; i++)
    {
        if (value[i] == ' ')continue;
        _tab[_index++] = value[i];
    }
    _tab[_newLength] = '\0';
    return _tab;
}

String String::SubString(const int _begin, const int _end)
{
    String _result = "";
    for (int i = _begin; i < _end; i++)
        _result += value[i];
    return _result;
}

String String::SubString(const int _begin)
{
    return SubString(_begin, length);
}

int String::CountOf(const char _c)
{
    int _result =0;
    for (int i = 0; i < length; i++)
        if (value[i] == _c)
            _result++;
    return _result;
}

bool String::IsNullOrEmpty(const String& _str)
{
    return _str.value == nullptr || _str.length == 0;
}

#pragma endregion methods

#pragma region operator
String& String::operator+=(const char _c)
{
    const int _newLength = length + 2;
    char* _char = new char[_newLength];
    strcpy(_char, value);
    _char[length] = _c;
    _char[length + 1] = '\0';
    value = _char;
    length += 1;
    return *this;
}
String& String::operator+=(const String& _str)
{
    const int _newLength = length + _str.length;
    char* _char = new char[_newLength + 1];
    strcpy(_char, value);
    strcat(_char, _str.value);
    value = _char;
    length = _newLength;
    return *this;
}
String::operator const char* ()
{
    return value;
}
String String::operator+(const String& _other)
{
    const int _newLength = length + _other.length;
    char* _char = new char[_newLength + 1];

    strcpy(_char, value);
    strcat(_char, _other.value);

    return _char;
}
#pragma endregion oeprator
