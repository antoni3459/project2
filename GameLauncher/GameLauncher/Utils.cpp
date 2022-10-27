#include "Utils.h"
#include "Object.h"
#include <windows.h>
#include <conio.h>
#include <random>

void Utils::Sleep(const int _milliseconds)
{
    ::Sleep(_milliseconds);
}

void Utils::Log(const std::string& _msg)
{
    std::cout << _msg << std::endl;
}

void Utils::Log(const Object& _obj)
{
    std::cout << _obj.ToString() << std::endl;
}

void Utils::Log(const Object* _obj)
{
    std::cout << _obj->ToString() << std::endl;
}

void Utils::LogError(const std::string& _msg)
{
    const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_handle, color_red);
    std::cout << "[Error] => " << _msg << std::endl;
    SetConsoleTextAttribute(_handle, color_white);
}

void Utils::LogError(const Object& _obj)
{
    const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_handle, color_red);
    std::cout << "[Error] => " << _obj.ToString() << std::endl;
    SetConsoleTextAttribute(_handle, color_white);
}

void Utils::LogError(const Object* _obj)
{
    const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_handle, color_red);
    std::cout << "[Error] => " << _obj->ToString() << std::endl;
    SetConsoleTextAttribute(_handle, color_white);
}

void Utils::LogTitle(const std::string& _title)
{
    const std::string& _msg = "\t\t" + _title;
    Log(_msg);
    Log(Underline(_msg));
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
            if (i < _pos) std::cout << "=";
            else if (i == _pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(_progress * 100.0f) << " % " << _msg << "\r";
        std::cout.flush();
        _progress += 0.001f;
    }
}

int Utils::Random(const int _min, const int _max)
{
    std::random_device _device = std::random_device();
    std::mt19937 _gen(_device());
    const std::uniform_int_distribution<> _distr = std::uniform_int_distribution<>(_min, _max);
    return _distr(_gen);
}

void Utils::LogWhithEffect(const std::string& _msg, const int _time)
{
    for (char _c : _msg)
    {
        std::cout << _c;
        ::Sleep(_time);
    }
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
    return std::string(_count, _c);
}

void Utils::SetCursorPosition(const int _x, const int _y)
{
    cursorPosition.X = _x;
    cursorPosition.Y = _y;
    SetConsoleCursorPosition(console, cursorPosition);
}

int Utils::CinNOBlock()
{
    if (kbhit()) //=> conio.h
    {
        return getch(); //=> conio.h
    }
    return -1;
}

void Utils::SetCursor(const bool _visible, const int _size)
{
    int _currentSize = _size;
    if (_currentSize == 0) _currentSize = 20;
    CONSOLE_CURSOR_INFO _cursorInfo = {};
    _cursorInfo.bVisible = _visible;
    _cursorInfo.dwSize = _currentSize;
    SetConsoleCursorInfo(console, &_cursorInfo);
}

