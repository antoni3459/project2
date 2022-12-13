#include "TextField.h"

TextField::TextField(int _controlID, HWND _owner, Rect _rect, const wchar_t* _defaultText):super(_controlID, _owner, _rect)
{
    defaultText = _defaultText;
    currentText = _defaultText;

}

TextField::TextField(TextField& copy):super(copy)
{
    defaultText = copy.defaultText;
        currentText = copy.currentText;
}

std::wstring TextField::CurrentText() const
{
    return currentText;
}

std::string TextField::CurrentTextStr() const
{
    return std::string(currentText.begin(),currentText.end());
}

void TextField::OnValueChange()
{
    const int _length = GetWindowTextLength(instance) + 1;
    char* _array = new char[_length];
    GetWindowTextA(instance, &_array[0], _length);
    std::string _result = _array;
    currentText = std::wstring(_result.begin(), _result.end());
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
