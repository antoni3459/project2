#include "CalendarControl.h"
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>
#include <ctime>
#include <Windows.h>

CalendarControl::CalendarControl(int _controlID, HWND _owner, const Rect& _rect)
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
        Show();
    }
    return instance;
}
