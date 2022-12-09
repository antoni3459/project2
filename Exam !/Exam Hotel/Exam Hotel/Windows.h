#pragma once
#include "Object.h"
#include <vector>
#include <windows.h>
#include <string>
#include <initializer_list>
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <commctrl.h>

class NewBooking;

class Windows : public Object
{
#pragma region f/p

private:
	HWND windowInstance = nullptr;
	const std::string name = "Hotel Application";
	const int width = 1920;
	const int height = 1080;
	bool isOpen = true;

	HWND createNewBooking = HWND();
	HWND viewAllBookings = HWND();

	static inline int count = 0;

	NewBooking* book = nullptr;

#pragma endregion f/p

#pragma region constructor/destructor

public:
	Windows();
	~Windows() = default;

#pragma endregion constructor/destructor

#pragma region method

private:
	LRESULT __stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);

public:
	static LRESULT __stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);

	void Open();
	void Update();
	void Close();
	void Button(int _test, int _test1, UINT _msg);
	void AddReserv();
	void ViewAllM();

#pragma endregion method

};
