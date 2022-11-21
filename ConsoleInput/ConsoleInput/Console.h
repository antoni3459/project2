#pragma once
#include <windows.h>

class Console
{
private:
	static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	static inline COORD cursorPosition = { 0,0 };

public:
	static void SetCursorPosition(const int _x, const int _y);
};

