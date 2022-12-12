#pragma once
#include "../WindowControl.h"
class CalendarControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

private:

public:
	CalendarControl() = default;
	CalendarControl(int _controlID, HWND _owner, const Rect& _rect);
	CalendarControl(const CalendarControl& _copy);

public:
	void SetMaxSelected(UINT _value);


public:
	HWND Create();
};

