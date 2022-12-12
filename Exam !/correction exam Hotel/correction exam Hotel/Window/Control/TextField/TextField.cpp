#include "TextField.h"

TextField::TextField(int _controlID, HWND _owner, Rect _rect, const wchar_t* _defaultText):super(_controlID, _owner, _rect)
{
    defaultText = _defaultText;
    currentText = _defaultText;

}

TextField::TextField(TextField& copy)
{

}

std::wstring TextField::CurrentText() const
{
    return currentText;
}

void TextField::OnTextChange(const wchar_t* _text) 
{
    defaultText = _text;
}

HWND TextField::Create()
{
    instance = CreateWindowEx(0, TEXT("EDIT"), defaultText, WS_CHILD | WS_VISIBLE, rect.X(), rect.Y(), rect.Width(),
        rect.Heigth(), owner, (HMENU)controlID, ownerInstance, nullptr);
    if(instance != NULL)
    {
        isInitialized = true;
        textField.insert(std::pair(controlID, this));
        Show();
    }
    return instance;
}
