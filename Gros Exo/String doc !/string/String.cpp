#include "String.h"
#include <string>
#include <iostream>

#pragma region constructor
String::String(const char* _value, const int _mLength, char* _mValue)
{
	value = _value;
	mLength = _mLength;
	mValue = _mValue;
}



String::String(const char* _value)
{
	if (_value == nullptr) _value = "";
	const int _otherLength = strlen(_value);
	const int& _length = mLength;
	const int _newLength = _length + _otherLength;
	char* _char = new char[_newLength + 1];
    //ReSharper disable CppDeprecatedEntity
	strcpy(_char, mValue);
	// ReSharper disable once CppDeprecatedEntity
	strcat(_char, _value);
	mValue = _char;
	mLength = _newLength;
}

String::String(const String& _copy)
{
	value = _copy.value;
	mValue = _copy.mValue;
	mLength = _copy.mLength;
}
#pragma endregion constructor

#pragma region method
void String::ToLower( char _value)
{
	char* val = &_value;
	mLength = size_t(_value);
	for (int i = 0; i < mLength; i++)
	{
		if (val[i] >= 65 && val[i] <= 90)
		{
			val[i] = char(val[i] + 32);
			mValue = val;
			std::cout << mValue;
		}
	}
}

void String::ToUpper(char _value)
{
	char* val = &_value;
	mLength = char(_value);
	for (int i = 0; i < mLength; i++)
	{
		if (val[i] >= 65 && val[i] <= 90)
			val[i] = char(val[i]- 32);
	}
	std::cout << val ;
}



char String::LastIndexOf(char _value)
{
	char* val = &_value;
	mLength = char(_value);
	for (int i = 0; i <= mLength; i++)
	{
		if (i == mLength)
			return val[i];
	}
}

char String::FirstIndexOf(char _value)
{
	char* val = &_value;
	mLength = char(_value);
	for (int i = 0; i <= mLength; i++)
	{
		if (i == 0)
			return val[i];
	}
}

bool String::IsNullOrEmpty(char _value)
{
	if (char(_value) == 0)
	{
		std::cout << "vide" << std::endl;
		return true;
	}
	return false;
}
#pragma endregion method
























































