#pragma once
#include "Windows.h"

class NewBooking;

class ViewAll:public Windows
{
#pragma region f/p

private:
	HWND windowInstance = nullptr;
	const std::string name = "Hotel Application";
	const int width = 1920;
	const int height = 1080;
	bool isOpen = true;

	HWND _return = nullptr;
	NewBooking* booking = nullptr;

#pragma endregion f/p

#pragma region constructor/destructor

public:
	ViewAll();
	~ViewAll() = default;

#pragma endregion constructor/destructor

#pragma region method

public:
	void Open();
	void Update();
	void Close();

#pragma endregion method

};
