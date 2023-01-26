#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean;
	UCLASS()
	class String : public ValueType
	{
		DECLARE_CLASS_INFO_FLAGS(String, ValueType, ClassFlags::Type)
	private:
		const char* value = nullptr;
		int length = 0;

	public:
		String() = default;
		String(const char* _value);
		String(const String& _copy);

	public:
		Boolean StartWith(char _c) const;
		Boolean EndWith(char _c) const;
		Boolean StartWith(const String& _str) const;
		Boolean EndWith(const String& _str) const;
		Boolean EqualsIgnoreCase(const String& _str) const;
		Boolean Contains(const String& _str) const;
		static Boolean IsNullOrEmpty(const String& _str);


		String SubString(int _begin) const;
		String SubString(int _begin, int _end) const;
		String Replace(const String& _old, const String _new) const;
		String Replace(char & _old, char _new);
		String Trim();
		String ToLower() const;
		String ToUpper() const;
		int FindFirstOf(char _c);
		int FindLastOf(char _c);
		int Length() const;
		void Append(const char* _str);
		void Append(const String& _str);
		const char* ToCstr() const;
	public:
		String ToString() const override;
	public:
		String& operator=(const String& _other);
		operator const char* ();
		operator const char* () const;
		Boolean operator==(const String& _str);
		Boolean operator!=(const String& _str);
		virtual Object& operator=(const Object* _obj);
	};
}