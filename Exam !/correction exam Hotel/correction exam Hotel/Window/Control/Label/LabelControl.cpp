#include "LabelControl.h"

LabelControl::LabelControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _text):super(_controlID, _owner, _rect)
{
	text = _text;
}

LabelControl::LabelControl(LabelControl& copy) :super(copy)
{
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
