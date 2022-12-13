#pragma once
#include "../WindowControl.h"
#include "../../../Event/Delegate/Delegate.h"
#include "../../../Utils/Rect/Rect.h"
#include <map>

class ButtonControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

public:
	static inline std::map<int, ButtonControl*> buttons = std::map<int, ButtonControl*>();
private:
	const wchar_t* text = TEXT("Default");

public:
	Delegate<void> OnClick = nullptr;

public:
	ButtonControl() = default;
	ButtonControl(int _controlID, HWND _owner, const Rect& _rect,const wchar_t* _text);
	ButtonControl(ButtonControl& copy);

public:
	virtual void OnUse();
	HWND Create()override;
};

