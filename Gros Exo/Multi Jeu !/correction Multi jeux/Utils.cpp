#include "Utils.h"
#include "Object.h"
#include <windows.h>
#include <conio.h>

#pragma region Log
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
	std::cout << _obj->ToString() << std::endl;
}

void Utils::DebugLog(const std::string& _str)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _str << std::endl;
#endif
}

void Utils::DebugLog(const Object& _obj)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _obj.ToString() << std::endl;
#endif
}

void Utils::DebugLog(const Object* _obj)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _obj->ToString() << std::endl;
#endif
}

void Utils::LogWarning(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogWarning(const Object& _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogWarning(const Object* _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogError(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}
void Utils::LogError(const Object& _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}
void Utils::LogError(const Object* _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}
void Utils::LoadingBar(const std::string& _msg)
{
	float _progress = 0.0f;
	const int _barWidth = 70;
	while (_progress < 1.0f)
	{
		std::cout << "[";
		int _pos = _barWidth * _progress;
		for (int i = 0; i < _barWidth; i++)
		{
			if (i == _pos) std::cout << "=";
			else if (i == _pos) std::cout << ">";
			else std::cout << "";
		}
		std::cout << "]" << int(_progress * 100.0f) << " % " << _msg << "\r";
		std::cout.flush();
		_progress += 0.001f;
	}
}
std::string Utils::UnderLine(const std::string& _str)
{
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
	return std::string(_tabCount, '\t') + std::string(_count, '-');

}
std::string Utils::UserStringChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	std::string _result = "";
	std::getline(std::cin, _result);
	std::cin.ignore(1000, '\n');
	return _result;
}
void Utils::LogSeparator(const int _count)
{
	Log(std::string(_count, '='));
}

std::string Utils::Underline(const std::string& _str)
{
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
	return std::string(_tabCount, '\t') + std::string(_count, '-');
}
void Utils::UnderlineAndDisplay(const std::string& _str)
{
	Log(_str);
	Log(Underline(_str));
}
void Utils::LogTitle(const std::string& _title)
{
	UnderlineAndDisplay("\t\t" + _title);
}
void Utils::ClearConsole()
{
	system("cls");
}
void Utils::Pause()
{
	system("pause");
}
std::string Utils::Separator(const int _count, const char _c)
{
	return std::string(_count,_c);
}

void Utils::SetCursorPosition(const int _x, const int _y)
{
	cursorPosition.X = _x;
	cursorPosition.Y = _y;
	SetConsolePosition(console, cursorPosition);
}




int Utils::CinNOBlock()
{
	if (kbhit()) //=> conio.h
		return getch(); //=> conio.h
	return -1;
}
#pragma endregion Log  