#pragma once
#include "../WindowControl.h"
#include <Windows.h>
#include <CommCtrl.h>
#include <map>

class CalendarControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

public:
	static inline std::map<int, CalendarControl*> calendars = std::map<int, CalendarControl*>();

private:
	DateTime arrivedDate= DateTime();
	DateTime departdDate = DateTime();

public:
	CalendarControl() = default;
	CalendarControl(int _controlID, HWND _owner, const Rect& _rect);
	CalendarControl(const CalendarControl& _copy);

public:
	void SetMaxSelected(UINT _value);
	void SetValue(const DateTime& _a, const DateTime& _b);
	void OnChoice(LPNMSELCHANGE _value);
	DateTime ArrivedDate()const;
	DateTime DepartdDate()const;
public:
	HWND Create()override;
};
