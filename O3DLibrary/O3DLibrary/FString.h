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

		class FString : public Object
		{
#pragma region f/p
			const char* value = "";
			int length = 0;
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
			O3DLIBRAIRY_API void Append(const FString& _str);
			O3DLIBRAIRY_API void Append(const char _value);
			O3DLIBRAIRY_API FString SubString(const int _begin, const int _end);
			O3DLIBRAIRY_API FString SubString(const int _begin);
			O3DLIBRAIRY_API Integer Length() const;
			O3DLIBRAIRY_API FString Replace(const char _old, const char _new) const;
			O3DLIBRAIRY_API FString Replace(const FString& _old, const FString& _new)const;
			O3DLIBRAIRY_API FString Trim() const;
			O3DLIBRAIRY_API FString ToLower() const;
			O3DLIBRAIRY_API FString ToUpper() const;
			O3DLIBRAIRY_API Boolean StartWidth(const char _c) const;
			O3DLIBRAIRY_API Boolean StartWidth(const FString& _str) const;
			O3DLIBRAIRY_API Boolean EndWidth(const char _c) const;
			O3DLIBRAIRY_API Boolean EndWidth(const FString& _str) const;
			O3DLIBRAIRY_API Integer LastIndexOf(const char _c) const;
			O3DLIBRAIRY_API Integer FirstIndexOf(const char _c) const;
			O3DLIBRAIRY_API Integer Find(const FString& _str) const;
			O3DLIBRAIRY_API Boolean Contains(const FString& _str) const;
			O3DLIBRAIRY_API std::wstring ToWString() const;
			O3DLIBRAIRY_API const char* ToCstr() const;
			O3DLIBRAIRY_API static Boolean IsNullOrEmpty(const FString& _str);
			O3DLIBRAIRY_API Boolean Equals(const FString& _other) const;
			template<typename ...Args>
			O3DLIBRAIRY_API static FString Format(const FString& _str, Args... _args);

#pragma endregion methods
#pragma region override
		public:
			O3DLIBRAIRY_API FString ToString() const override;
			O3DLIBRAIRY_API Boolean Equals(const Object* _obj) const override;
#pragma endregion override
			operator const char* ()
			{
				return value;
			}
			friend std::ostream& operator<<(std::ostream& _os, const FString& _str)
			{
				_os << _str.value;
				return _os;
			}
			O3DLIBRAIRY_API Boolean operator==(const FString& _other) const;
			O3DLIBRAIRY_API Boolean operator!=(const FString& _other) const;
			O3DLIBRAIRY_API FString operator+(const FString& _other) const;
			O3DLIBRAIRY_API FString& operator+=(const FString& _other);
			O3DLIBRAIRY_API char operator[](const int _index) const;
		};

#pragma region methods
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
					_result.Append(_package[i]->ToString());
					_index++, i++;
				}
				else
					_result.Append(_str[i]);
			}
			return _result;
		}
	}
#pragma endregion methods


}


