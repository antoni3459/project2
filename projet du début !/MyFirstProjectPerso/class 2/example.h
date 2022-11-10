#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example
{
#pragma region f/p
private:
	string name = "";
#pragma endregion f/p

#pragma region constructor/ destructor
public:
	Example()
	{
		name = "thomas";
	}
	Example(const Example& _copy)
	{
		name = _copy.name;
		next = _copy.next;
	}
	~Example() // destructor 
	{
	}
#pragma endregion constructor/ destructor
#pragma region methode 

	void Test();// dans la classe on ne met que les signature
#pragma endregion methode 
#pragma region overide 
#pragma endregion overide 

#pragma region operator 
	Example operator=(const Example & _other)
	{
		name = _other.name;
		next = _other.next;
		return *this;
	}
	bool operator==(const Example& _other)
	{
		return name == _other.name;
	}
	bool operator !=(const Example& _other)
	{
		return name != _other.name;
	}
	operator string ()
	{
		return name;
	}
	operator bool()
	{
		return name == "Toto";
	}
#pragma endregion operator 


};

void Example::Test()
{
	cout << Test
}