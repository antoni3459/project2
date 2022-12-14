#pragma once
#include <iostream>
#include <string>
#include "Object.h"
#include <vector>
#include <ostream>


namespace Core
{

#pragma warning(disable: 4996)
#pragma warning(disable: 4267)
	namespace PrimitiveType
	{
		class Boolean;
		class Integer;

		class O3DLIBRAIRY_API FString : public Object
		{
#pragma region f/p
		private:
			const char* value = "";
			int length = 0;
		public:
			static const Core::PrimitiveType::FString Empty;
#pragma endregion f/p

#pragma region constructor
		public:
			FString() = default;
			FString(const char* _value)
			{
				if (_value == nullptr) _value = "";
				const int _otherLength = strlen(_value);
				const int _newLength = length + _otherLength;
				char* _array = new char[_newLength + 1];
				strcpy(_array, value);
				strcat(_array, _value);
				value = _array;
				length = _newLength;
			}
			FString(const FString& _copy)
			{
				if (_copy.value == nullptr) return;
				const int _length = _copy.length;
				char* _array = new char[_length + 1];
				memcpy(_array, _copy.value, length + 1);
				value = _array;
				length = _length;
			}
			FString(std::string::iterator _begin, std::string::iterator _end)
			{
				for (; _begin != _end; ++_begin)
					Append(*_begin);
			}
#pragma endregion constructor

#pragma region methods
		public:
			void Append(const FString& _str);
			void Append(const char _value);
			static FString Convert(const std::wstring& _wstring);
			FString SubString(const int _begin, const int _end)const;
			FString SubString(const int _begin)const;
			Integer Length() const;
			FString Replace(const char _old, const char _new) const;
			FString Replace(const FString& _old, const FString& _new)const;
			FString Trim() const;
			FString ToLower() const;
			FString ToUpper() const;
			Boolean StartWidth(const char _c) const;
			Boolean StartWidth(const FString& _str) const;
			Boolean EndWidth(const char _c) const;
			Boolean EndWidth(const FString& _str) const;
			Integer LastIndexOf(const char _c) const;
			Integer FirstIndexOf(const char _c) const;
			Integer Find(const FString& _str) const;
			Boolean Contains(const FString& _str) const;
			std::wstring ToWString() const;
			const char* ToCstr() const;
			static Boolean IsNullOrEmpty(const FString& _str);
			Boolean Equals(const FString& _other) const;
			template<typename ...Args>
			static FString Format(const FString& _str, Args... _args);

#pragma endregion methods

#pragma region override
		public:
			FString ToString() const override;
			Boolean Equals(const Object* _obj) const override;
#pragma endregion override

#pragma region oprators

			operator const char* ()
			{
				return value;
			}
			friend std::ostream& operator<<(std::ostream& _os, const FString& _str)
			{
				_os << _str.value;
				return _os;
			}
			Boolean operator==(const FString& _other) const;
			Boolean operator!=(const FString& _other) const;
			FString operator+(const FString& _other) const;
			FString& operator+=(const FString& _other);
			char operator[](const int _index) const;
#pragma endregion oprators

		};


#pragma region methods

		template<typename... Args>
		FString FString::Format(const FString& _str, Args ..._args)
		{
			FString _res = "";
			std::vector<object> _package = std::vector<object>();
			//size_t _count = sizeof...(_args); => nb args
			(_package.push_back(&_args), ...);
			int _size = _package.size();
			int _index = 0;
			for (int i = 0; i < _str.length; i++)
			{
				if (_str[i] == '{' && _str[i + 1] == '}')
				{
					_res.Append(_package[_index]->ToString());
					_index++, i++;
				}
				else
					_res.Append(_str[i]);
			}
			return _res;
		}
#pragma endregion methods
	}

}


