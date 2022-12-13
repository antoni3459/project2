#include "CalendarControl.h"
#include <ctime>
#include <Windows.h>

CalendarControl::CalendarControl(int _controlID, HWND _owner, const Rect& _rect) : super(_controlID, _owner, _rect)
{
}

CalendarControl::CalendarControl(const CalendarControl& _copy):super(_copy)
{
}

void CalendarControl::SetMaxSelected(UINT _value)
{
    if (!isInitialized)return;
    MonthCal_SetMaxSelCount(instance, _value);
}

void CalendarControl::SetValue(const DateTime& _a, const DateTime& _b)
{
    const SYSTEMTIME _start = _a.ToSystemTime();
    const SYSTEMTIME _end = _b.ToSystemTime();
    LPSYSTEMTIME _tab = new SYSTEMTIME[2] (_start,_end) ;
    MonthCal_SetSelRange(instance, _tab);
}

void CalendarControl::OnChoice(LPNMSELCHANGE _value)
{
    arrivedDate = DateTime(_value->stSelStart);
    departdDate = DateTime(_value->stSelStart);
}

DateTime CalendarControl::ArrivedDate()const 
{
    return arrivedDate;
}

DateTime CalendarControl::DepartdDate()const 
{
    return departdDate;
}

HWND CalendarControl::Create()
{
    instance = CreateWindowEx(0, MONTHCAL_CLASS, L"", WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_DAYSTATE|MCS_MULTISELECT,
        rect.X(), rect.Y(), rect.Width(), rect.Heigth(), owner, (HMENU)controlID, ownerInstance, nullptr);
    RECT _minRect = {};
    MonthCal_GetMinReqRect(instance, &_minRect);
    SetWindowPos(instance, NULL, rect.X(), rect.Y(), _minRect.right, _minRect.bottom, SWP_NOZORDER);

    SYSTEMTIME* _times =new SYSTEMTIME[2];
    GetSystemTime(&_times[0]);
    MonthCal_SetRange(instance, GDTR_MIN, &_times[0]);

    MonthCal_SetCurrentView(instance, MCMV_MONTH);
    if (instance != NULL)
    {
        isInitialized = true;
        calendars.insert(std::pair(controlID, this));
        Show();
    }
    return instance;
}
