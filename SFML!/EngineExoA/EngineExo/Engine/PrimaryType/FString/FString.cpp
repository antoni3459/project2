#include "FString.h"
#include "../Boolean/Boolean.h"
#include "../../Utils/Template/Template.h"
#include "../../Reflection/Utils/ReflectionUtils.h"


Engine::PrimaryType::FString::FString(const char* _value) : super()
{
	if (value == nullptr) value = "";
	const size_t _otherLength = strlen(_value);
	const size_t _newLength = length + _otherLength;
	char* _array = new char[_newLength + 1];
	strcpy(_array, value);
	strcat(_array, _value);
	value = _array; 
	length = _newLength; 
}

Engine::PrimaryType::FString::FString(const FString& _copy) : super(_copy)
{
	if (_copy.value == nullptr) return;
	length = _copy.length;
	char* _array = new char[length + 1];
	memcpy(_array, _copy.value, length + 1);
	value = _array;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::StartWith(char _c) const
{
	return value[0] == _c;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::EndWith(char _c) const
{
	return value[length - 1] == _c;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::StartWith(const FString& _str) const
{
	for (int i = 0; i < _str.length; ++i)
		if (value[i] != _str.value[i])
			return false;
	return true;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::EndWith(const FString& _str) const
{
	const size_t _otherLength = _str.length;
	for (size_t i = _otherLength; i > 0; i--)
	{
		if (value[length - i] != _str.value[_otherLength - i])
			return false;
	}
	return true;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::EqualsIgnoreCase(const FString& _str) const
{
	if (length != _str.length) return false;
	return ToLower() == _str.ToLower();
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::Contains(const FString& _str) const
{
	std::string _string = value;
	return _string.find(_str.value) != std::string::npos;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::IsNullOrEmpty(const FString& _str)
{
	return _str.value == nullptr || _str.length == 0;
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::SubString(size_t _begin) const
{
	return SubString(_begin, Length());
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::SubString(size_t _begin, size_t _end) const
{
	FString _result = "";
	for (size_t i = _begin; i < _end; ++i)
		_result += value[i];
	return _result;
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::Replace(const FString& _old, const FString _new) const
{
	if (IsNullOrEmpty(_old)) return *this;
	std::string _str = value;
	size_t _startPos = 0;
	const std::string& _from = _old.value;
	const std::string& _to = _new.value;
  	while ((_startPos = _str.find(_from, _startPos)) != std::string::npos)
	{
		_str.replace(_startPos, _from.length(), _to);
		_startPos += _to.length();
	}
	return _str.c_str();
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::Replace(char& _old, char _new)
{
	char* _array = new char[length];
	strcpy(_array, value);
	for (int i = 0; i < length; ++i)
	{
		if (value[i] == _old)
			_array[i] = _new;
	}
	return _array;
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::Trim()
{
	return Replace(" ", "");
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::ToLower() const
{
	char* _array = new char[length];
	for (size_t i = 0; i < length; ++i)
	{
		_array[i] = std::tolower(value[i]);
	}
	return _array;
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::ToUpper() const
{
	char* _array = new char[length];
	for (size_t i = 0; i < length; ++i)
	{
		_array[i] = std::toupper(value[i]);
	}
	return _array;
}

size_t Engine::PrimaryType::FString::FindFirstOf(char _c) const
{
	
	for (size_t i = 0; i < length; i++)
		if (value[i] == _c) return i;
	return -1;
}

size_t Engine::PrimaryType::FString::FindLastOf(char _c) const
{
	int _result = -1;
	for (int i = 0; i < length; i++)
		if (value[i] == _c) _result = i;
	return _result;
}

size_t Engine::PrimaryType::FString::Length() const
{
	return length;
}

void Engine::PrimaryType::FString::Append(char _c)
{
	const size_t _newLength = length + 2;
	char* _array = new char[_newLength];
	strcpy(_array, value);
	_array[length] = _c;
	_array[length + 1] = '\0';
	value = _array;
	length += 1;
}

void Engine::PrimaryType::FString::Append(const char* _str)
{
	Append(FString(_str));
}

void Engine::PrimaryType::FString::Append(const FString& _str)
{
	const size_t _newLength = length + _str.length;
	char* _array = new char[_newLength + 1];
	strcpy(_array, value);
	strcat(_array, _str.value);
	value = _array;
	length = _newLength;
}

const char* Engine::PrimaryType::FString::ToCstr() const
{
	return value;
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::ToString() const
{
	return value;
}

void Engine::PrimaryType::FString::SerializeField(std::ostream& _os, const PrimaryType::FString& _fieldName, int _index)
{
	Reflection::ReflectionUtils::SerializePrimaryType(_os, this, _fieldName);
}

void Engine::PrimaryType::FString::DeSerializeField(std::istream& _is, const PrimaryType::FString& _fieldName)
{             
	FString _str = Reflection::ReflectionUtils::GetLine(_is, _fieldName);
	_str = _str.Replace("\"", "").Replace("\t", "").Replace(",", "").Replace(_fieldName, "").Replace(":", "").Trim();
	*this = _str.ToCstr();
}

Engine::PrimaryType::FString Engine::PrimaryType::FString::operator+(const FString& _str)
{
	FString _this =  FString(*this);
	_this += _str;
	return _this;
}

Engine::PrimaryType::FString& Engine::PrimaryType::FString::operator+=(const char* _str)
{
	Append(_str);
	return *this;
}

Engine::PrimaryType::FString& Engine::PrimaryType::FString::operator+=(char _c)
{
	Append(_c);
	return *this;
}

Engine::PrimaryType::FString& Engine::PrimaryType::FString::operator+=(const FString& _str)
{
	Append(_str);
	return *this;
}

Engine::PrimaryType::FString& Engine::PrimaryType::FString::operator=(const FString& _other)
{
	value = _other.value;
	length = _other.length;
	return *this;
}

Engine::PrimaryType::FString::operator const char* ()
{
	return value;
}

Engine::PrimaryType::FString::operator const char* () const
{
	return value;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::operator==(const FString& _str) const
{
	if (length != _str.length) return false;
	for (int i = 0; i < length; ++i)
		if (value[i] != _str.value[i]) return false;
	return true;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::operator!=(const FString& _str) const
{
	return !this->operator==(_str);
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::operator==(const char* _str) const 
{
	//return this->operator==(FString(_str));

	if (length != strlen(_str)) return false;
	for (int i = 0; i < length; ++i)
		if (value[i] != _str[i]) return false;
	return true;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::FString::operator!=(const char* _str) const 
{
	return !this->operator==(_str);
}

Engine::Object& Engine::PrimaryType::FString::operator=(const Object* _obj)
{
	if (!IsSame<FString>(_obj)) return *this;
	super::operator=(_obj);
	const FString* _string = dynamic_cast<const FString*>(_obj);
	value = _string->value;
	length = _string->length;
	return *this;
}
