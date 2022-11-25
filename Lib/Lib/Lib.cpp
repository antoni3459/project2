// Lib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "FString.h"
#include "DateTime.h"

using namespace Core::PrimitiveType;
using namespace Core;

template <typename Base, typename Derived>
static bool Instanceof(Derived*)
{
	return std::is_same<Base, Derived>::value;
}

#define instanceof(a,b)Instanceof<a>(b)

int main()
{
	/*Core::PrimitiveType::FString _str=Core::PrimitiveType::FString("hello");
	std::cout << _str;*/
	//MessageBox(nullptr, L"Comment ça va ?", L"Test", MB_OK | MB_ICONERROR);
	object o = new Object();
	DateTime* time = new DateTime(0, 0, 0, 0);
	if (instanceof(Object, o))
	{
		std::cout << "o is Object" << std::endl;
	}
	if (instanceof(Object, time))
	{
		std::cout << "time is object" << std::endl;
	}
	if (instanceof(DateTime, time))
	{
		std::cout << "time is DateTime" << std::endl;
	}
	return 0;

}
