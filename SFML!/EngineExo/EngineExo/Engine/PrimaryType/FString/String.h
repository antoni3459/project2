#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean;
	UCLASS()
	class String : public ValueType
	{
		DECLARE_CLASS_INFO(String, ValueType)

#pragma region f/p
	private:
		const char* value = nullptr;
		size_t length = 0;
#pragma endregion f/p

#pragma region constructor
	public:
		String() = default;
		String(const char* _value);
		String(const String& _copy);
#pragma endregion constructor

#pragma region method
	public:
		Boolean StartWith(char _c) const;
		Boolean EndWith(char _c) const;
		Boolean StartWith(const String& _str) const;
		Boolean EndWith(const String& _str) const;
		Boolean EqualsIgnoreCase(const String& _str) const;
		Boolean Contains(const String& _str) const;
		static Boolean IsNullOrEmpty(const String& _str);

		String SubString(size_t _begin) const;
		String SubString(size_t _begin, size_t _end) const;
		String Replace(const String& _old, const String _new) const;
		String Replace(char& _old, char _new);
		String Trim();
		String ToLower() const;
		String ToUpper() const;
		size_t FindFirstOf(char _c)const;
		size_t FindLastOf(char _c)const;
		size_t Length() const;
		void Append(const char* _str);
		void Append(char _c);
		void Append(const String& _str);
		const char* ToCstr() const;
#pragma endregion method

#pragma region override
	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index)override;
		void DeSerializeField(std::istream& _os, const PrimaryType::String& _fieldName)override;
#pragma endregion override

#pragma region operator
	public:
		String& operator+=(const char* _str);
		String& operator+=(char _str);
		String& operator+=(const String& _str);

		String& operator=(const String& _other);
		operator const char* ();
		operator const char* () const;
		Boolean operator==(const String& _str) const;
		Boolean operator!=(const String& _str) const;
		Boolean operator==(const char* _str)const;
		Boolean operator!=(const char* _str)const;
		virtual Object& operator=(const Object* _obj);
#pragma endregion operator
	};
}