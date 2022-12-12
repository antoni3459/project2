#pragma once
#include "../WindowControl.h"
#include "../../../Event/Delegate/Delegate.h"
#include "../../../Utils/Rect/Rect.h"
#include <map>

class TextField:public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

public:
	static inline std::map<int, TextField*> textField = std::map<int, TextField*>();
private:
	const wchar_t* defaultText = TEXT("");
	std::wstring currentText = TEXT("");


public:
	TextField() = default;
	TextField(int _controlID, HWND _owner, Rect _rect, const wchar_t* _defaultText);
	TextField(TextField& copy);

public:
	std::wstring CurrentText()const;
	void OnTextChange(const wchar_t* _text);
	HWND Create()override;

};

