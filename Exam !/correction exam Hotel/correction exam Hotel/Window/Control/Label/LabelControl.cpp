#include "LabelControl.h"

LabelControl::LabelControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _text):super(_controlID, _owner, _rect)
{
	controlID = _controlID;
	owner = _owner;
	rect = _rect;
	text = _text;
}

LabelControl::LabelControl(LabelControl& copy) :super(copy)
{
	controlID=copy.controlID;
	owner = copy.owner;
	rect = copy.rect;
	text = copy.text;
}

std::string LabelControl::TextStr()
{
	const std::wstring _text = Text();
	return std::string(_text.begin(), _text.end());
}

void LabelControl::SetText(const wchar_t* _newText)
{
	text= _newText;
	SetWindowTextA(instance, TextStr().c_str());
}

void LabelControl::SetText(const std::string& _str)
{
	const std::string _wstr(_str.begin(), _str.end());
	SetText(_wstr.c_str());
}

std::wstring LabelControl::Text()
{
	return text;
}

HWND LabelControl::Create()
{
	instance = CreateWindowEx(0, TEXT("STATIC"), text, WS_CHILD | WS_VISIBLE, rect.X(), rect.Y(), rect.Width(), rect.Heigth(),
		owner, (HMENU)controlID, ownerInstance, nullptr);
	if (instance != NULL)
	{
		L"Test";
		isInitialized = true;
		Show();
	}
	return instance;
}
