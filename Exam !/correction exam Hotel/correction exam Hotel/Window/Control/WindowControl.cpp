#include "WindowControl.h"

WindowControl::WindowControl(int _controlID, HWND _owner, const Rect& _rect):super()
{
	controlID = _controlID;
	owner = _owner;
	ownerInstance = (HINSTANCE)GetWindowLongPtr(owner, GWLP_HINSTANCE);
	rect = _rect;
}

WindowControl::WindowControl(const WindowControl& copy): super(copy)
{
	controlID=copy.controlID;
	owner = copy.owner;
	ownerInstance = copy.ownerInstance;
}

void WindowControl::Show()
{
	if (!isInitialized)return;
	ShowWindow(instance, true);
	isShow = true;
}

void WindowControl::Hide()
{
	if (!isInitialized)return;
	ShowWindow(instance, false);
	isShow = false;
}

HWND WindowControl::Create()
{
	return (HWND)NULL;
}

