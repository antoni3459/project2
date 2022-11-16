#pragma once
#include "Object.h"
#include "O3DLibrary.h"
#include <string>
#include <iostream>
#include <vector>
#include "Exception.h"

#pragma warning(disable: 4996)

namespace Core
{
	namespace PrimitiveType
	{
		class boolean;
		class Interger;

		class FString sealed :public Object
		{

#pragma region f/p
		private:
			const char* value = "";
			int length = 0;
		public:
			static const FString Empty;
#pragma endregion f/p
#pragma region constructor 
		public:
			FString() = default;
			FString(const char* _value)
			{
				if (_value == nullptr)_value = "";
				const int _otherLength = strlen(_value);
				const int _newLength = length + _otherLength;
				char* _char = new char[_newLength + 1];
				strcpy(_char, value);
				strcat(_char, _value);
				value = _char;
				length = _newLength;
			}
			FString(const FString& _copy)
			{
				if (_copy.value == nullptr) return;
				const int _length = _copy.length;
				char* _array = new char[_length + 1];
				memcpy(_array, _copy.value, _length + 1);
				value = _array;
				length = _length;
			}
			////String(std::string::iterator _begin, std::string::iterator _end)
			//{
			//	for (; _begin != _end;++_begin)
			//		//		Append(*_begin);
			//}

		public:
			FString ToString()const override
			{
				return value;
			}
			O3DLIBRARY_API boolean Equals(const Object* _obj)const;

#pragma endregion constructor 
		public:
			void Append(const FString& _str)
			{
				const int _newLength = length + _str.length;
				char* _array = new char[_newLength + 1];
				strcpy(_array, value);
				strcat(_array, _str.value);
				value = _array;
				length = _newLength;
			}
			void Append(const char _value)
			{
				const int _newLength = length + 2;
				char* _array = new char[_newLength];
				strcpy(_array, value);
				_array[length] = _value;
				_array[length + 1] = '\0';
				value = _array;
				length += 1;
			}
			O3DLIBRARY_API Interger Length()const;
			O3DLIBRARY_API boolean StartWith(const char _c)const;
			O3DLIBRARY_API boolean StartWith(const FString& _str)const;
			O3DLIBRARY_API boolean EndWith(const char _c)const;
			O3DLIBRARY_API boolean EndWith(const FString& _str)const;
			O3DLIBRARY_API boolean Contains(const FString& _str) const;
			O3DLIBRARY_API Interger LastIndexOf(const char _c)const;
			O3DLIBRARY_API Interger FirstIndexOf(const char _c)const;
			O3DLIBRARY_API Interger Find(const FString& _str)const;
			template<typename... Args>
			O3DLIBRARY_API static FString Format(const FString& _str, Args..._args);

			const char* ToCstr()const
			{
				return value;
			}
			O3DLIBRARY_API FString SubString(const int _begin, const int _end);
			O3DLIBRARY_API FString SubString(const int _begin);
			O3DLIBRARY_API FString Replace(const char _old, const char _new)const;
			O3DLIBRARY_API FString Replace(const FString& _old, const FString& _new)const;
			O3DLIBRARY_API boolean IsNullOrEmpty(const FString& _str);
			O3DLIBRARY_API FString Trim()const;
			O3DLIBRARY_API FString ToLower()const;
			O3DLIBRARY_API FString ToUpper()const;
			O3DLIBRARY_API std::wstring ToWString()const;

		public:
			operator const char* () const
			{
				return value;
			}
			friend std::ostream& operator <<(std::ostream& _os, const FString& _str)
			{
				_os << _str.value;
				return _os;
			}
			O3DLIBRARY_API boolean operator==(const FString& _other)const;
			O3DLIBRARY_API boolean operator!=(const FString& _other)const;
			O3DLIBRARY_API FString operator+(const FString& _other)const;
			O3DLIBRARY_API FString operator+=(const FString& _other);
			O3DLIBRARY_API char operator[](const int _index);
		};
		template<typename ...Args>
		inline FString FString::Format(const FString& _str, Args ..._args)
		{
			FString _result = "";
			std::vector<Object> _package = std::vector<Object>();
			//size_t _count=sizeof...(_args);//=> nombre d'arguments dans _args

			(_package.push_back(&_args), ...);
			int _index = 0;
			for (int i = 0; i < _str.length; i++)
			{
				if (_str[i] == '{' && _str[i + 1] == '{')
				{
					_result.Append(_arguments[i]->ToString());
					_index++, i++;
				}
				else 
					_result.Append(_str[i]);
			}
			return _result;
		}
	}
}
