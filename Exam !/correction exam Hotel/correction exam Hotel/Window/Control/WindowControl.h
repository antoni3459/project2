#pragma once
#include "../../Object/Object.h"
#include "../../Utils/Rect/Rect.h"
#include <Windows.h>

class WindowControl : public Object
{
	DECLARE_CLASS_INFO(Object)

protected:
	int controlID = 0;
	HWND owner = nullptr;
	HWND instance = nullptr;
	HINSTANCE ownerInstance;
	Rect rect = Rect();
	bool isInitialized = false;
	bool isShow = true;

public:
	WindowControl() = default;
	WindowControl(int _controlID, HWND _owner,const Rect& rect);
	WindowControl(const WindowControl& copy);

public:
	void Show(); 
	void Hide();
	virtual HWND Create();

};

