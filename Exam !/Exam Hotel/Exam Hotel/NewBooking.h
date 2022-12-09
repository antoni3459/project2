#pragma once
#include "Windows.h"

class NewBooking: public Windows
{
#pragma region f/p

private:
	HWND windowInstance = nullptr;
	const std::string name = "Hotel Application";
	const int width = 1920;
	const int height = 1080;
	bool isOpen = true;
	HWND _return = nullptr;
	HWND editFirstname = nullptr;
	HWND editLastName = nullptr;
	HWND editPeople = nullptr;
	HWND saveBook = nullptr;

#pragma endregion f/p

#pragma region constructor/destructor

public:
	NewBooking();
	~NewBooking() = default;

#pragma endregion constructor/destructor

#pragma region method

public:
	LRESULT __stdcall WindowProc(UINT _msg);
	void OpenBook();
	void Update();
	void Close();

#pragma endregion method

};
