#pragma once
#pragma once
#include "../WindowControl.h"
#include "../../../Event/Delegate/Delegate.h"
#include "../../../Utils/Rect/Rect.h"
#include <map>

class LabelControl :public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

private:
	const wchar_t* text = TEXT("");

public:
	LabelControl() = default;
	LabelControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _text);
	LabelControl(LabelControl& copy);

public:
	std::string TextStr();
	void SetText(const wchar_t* _newText);
	void SetText(const std::string& _str);
	std::wstring Text();
	HWND Create()override;

};

