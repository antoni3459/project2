#pragma once
#include <Windows.h>

#define INPUT_BUFFER_SIZE 128

class App
{
#pragma region f/p
private:
	HANDLE handle = HANDLE();
	DWORD oldMode, currentMode;
	bool isOpen = true;
	DWORD numRead, i;
	INPUT_RECORD inputRecord[INPUT_BUFFER_SIZE];
#pragma endregion f/p

#pragma region constructeur
public:
	App();
#pragma endregion constructeur
#pragma region method
private:
	void KeyEventProc(KEY_EVENT_RECORD _keyEvent);
	void MouseEventProc(MOUSE_EVENT_RECORD _mouseEvent);

public:
	void Open();

#pragma endregion method

};

