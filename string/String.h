#pragma once
#pragma warning(disable: 4996)

#include <string>
class String
{
#pragma region f/p
private:
	const char* value;
	int mLength=0;
	char* mValue;
	int count = 0;

	//int mLength = mValue.size();
#pragma endregion f/p
public:
#pragma region constuctor
	String() = default;
	String(const char* _value, const int _mLength, char* _mValue);
	String(const char* _value);
	String(const String& _copy);
	~String() = default;
#pragma endregion constructor

#pragma region method
	void ToLower( char _value); //minuscule
	void ToUpper(char _value);
	void Contains();
	void Split(const String& _value);//remplace ce que l'on veut par des mise a la ligne  Trim() enlève les espace 
	void SubString(); // begin / begin -> end
	void Replace();
	char LastIndexOf(char _value);
	char FirstIndexOf(char _value);
	bool IsNullOrEmpty(char _value);
	void Join();
#pragma endregion method
};