// Lib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FString.h"
#include "Object.h"
#include "Interger.h"
#include "Boolean.h"
#include "Process.h"
#include "Environment.h"
#include "CoreIO.h"
#include "Directory.h"
#include "TestWritter.h"
#include "TextReader.h"
#include "FileStream.h"
#include "Path.h"
#include "File.h"
#include "Console.h"
#include "EConsoleColor.h"
#include "Datetime.h"
#include "EDayOfWeek.h"
#include "BoxFile.h"
#include "ShObjIdl_core.h"
#include "windows.h"
#include "Window.h"
#include "WindowMenu.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "Shape.h"
#include "FieldInfo.h"

//using namespace Core::PrimitiveType;
//using namespace Core;
//
//template <typename Base, typename Derived>
//static bool Instanceof(Derived*)
//{
//	return std::is_same<Base, Derived>::value;
//}
//
//#define instanceof(a,b)Instanceof<a>(b)
using namespace Core::PrimitiveType;
using namespace Core;
using namespace Core::IO;

int main()
{
	/*Core::PrimitiveType::FString _str=Core::PrimitiveType::FString("hello");
	std::cout << _str;*/
	//MessageBox(nullptr, L"Comment ça va ?", L"Test", MB_OK | MB_ICONERROR);
	/*object o = new Object();
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
	return 0;*/
	class A : public Object
	{
	private:
		PrimitiveType::FString name = "";
	public:
		PrimitiveType::Integer age = 10;
	public:
		A()
		{
			RegisterField("name", &name, (int)BindingFlags::Private);
			RegisterField("age", &age, (int)BindingFlags::Public);

		}
	};


	A a;

	for (FieldInfo* info : a.GetFields())
	{
		LOG(info);
	}
	return 0;

}
