#include "Utils.h"

void Utils::Log(const std::string& _str)
{
	std::cout << _str << std::endl;
}

void Utils::Log(const Object& _obj)
{
	std::cout << _obj.ToString() << std::endl;
}

void Utils::Log(const Object* _obj)
{
}

void Utils::DebugLog(const Object& _obj)
{
}

void Utils::DebugLog(const Object* _obj)
{
}

void Utils::LogWarning(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, Color_yellow);
	std::cout << "[WARNING] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, Color_white);
#endif
}

void Utils::LogWarning(const Object& _obj)
{
}

void Utils::LogWarning(const Object* _obj)
{
}

void Utils::DebugLog(const std::string& _str)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _str << std::endl;
#endif
}

void Utils::LogError(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE handler = GetStHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _str << std::endl;
#endif
}

void Utils::LogError(const Object& _obj)
{
}

void Utils::LogError(const Object* _obj)
{
}

std::string Utils::UserStringChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);

	return _result;
}

void Utils::LogSeparator(const int _count)
{
	Log(std::string(_count, '='));
}

void Utils::Underline(const std::string& _str)
{
	std::string _result = "";
	int _tabCount = 0, _count = 0;
	for (char _c : _str)
	{
		if (_c == '\t')
		{
			_tabCount++;
			continue;
		}
		_count++;
	}
	return std::string(_tabCount, '\t') + std::string;
}

void Utils::UnderlineDisplay(const std::string& _str)
{
	Log(_str);
	Log(Underline(_str));
}

void Utils::LogTile(const std::string& _title)
{
	UnderlineDisplay("\t\t" + _title);
}

void Utils::ClearConsole()
{
	system("cls")
}

void Utils::Pause()
{
	system("pause");
}
