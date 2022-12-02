#include "Console.h"
#include "FString.h"
#include "TestWritter.h"
#include "Path.h"
#include "Environment.h"
#include "Directory.h"
#include <iostream>

Core::IO::TestWritter* Core::Console::Out = Out_Internal();

Core::IO::TestWritter* Core::Console::Out_Internal()
{
	const Core::PrimitiveType::FString& _directoryPath = Core::IO::Path::Combine({ Core::IO::Path::GetParent(Core::Environment::CurrentDirectory), "App_Bug" });
	IO::Directory::MakeDirectory(_directoryPath);
	const  Core::PrimitiveType::FString& _fullPath = Core::IO::Path::Combine({ _directoryPath, "Debug.Log" });
	Core::IO::TestWritter* _writter = new Core::IO::TestWritter(_fullPath.ToCstr());
	_writter->Clear();
	return new Core::IO::TestWritter(_fullPath.ToCstr());
}

void Core::Console::WritLine(const PrimitiveType::FString& _label, const object _obj, const EConsoleColor& _color)
{
	SetConsoleTextAttribute(console, (int)_color);
	const PrimitiveType::FString _now = DateTime::Now().ToStringFormat("h:m:s");
	std::cout << _now << ":" << _label << "=>" << _obj->ToString() << std::endl;
	*Out << PrimitiveType::FString("[LOG] ") + _now + "=>" + _obj->ToString();
	SetConsoleTextAttribute(console, (int)EConsoleColor::Reset);
}

void Core::Console::WritLine(const PrimitiveType::FString& _label, const object& _obj, const EConsoleColor& _color)
{
	SetConsoleTextAttribute(console, (int)_color);
	const PrimitiveType::FString _now = DateTime::Now().ToStringFormat("h:m:s");
	std::cout << _now << ":" << _label << " => " << _obj->ToString() << std::endl;
	*Out << PrimitiveType::FString("[LOG] ") + _now + "=>" + _obj->ToString();
	SetConsoleTextAttribute(console, (int)EConsoleColor::Reset);
}
