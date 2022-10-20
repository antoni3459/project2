#pragma once
#include <vector>

#pragma warning(disable: 4996)

class String
{
#pragma region f/p
private:
	const char* value = "";
	int length = 0;
#pragma endregion f/p

#pragma region constructor/destructor
public:
	String(const char* _value);
	String(const String& _copy);
	~String();
#pragma endregion constructor/destructor

#pragma region methods
public:
	String ToLower() const;
	String ToUpper() const;
	bool Contains(const String& _str) const;
	std::vector<String> Split(const char _c);
	String Replace(const char _old, const char _new);
	int LastIndexof(const char _c);
	int FirstIndexof(const char _c);
	String Join(const std::vector<String>& _value);
	String Trim();
	String SubString(const int _begin, const int _end);
	String SubString(const int _begin);
	int CountOf(const char _c);
	static bool IsNullOrEmpty(const String& _str);
#pragma endregion methods

#pragma region operator
public:
	String& operator+=(const char _c);
	String& operator+=(const String& _str);
	operator const char* ();
	String operator+(const String& _other);
#pragma endregion operator
};
typedef String string;
