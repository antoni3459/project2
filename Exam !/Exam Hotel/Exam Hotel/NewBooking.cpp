#include "NewBooking.h"
#include "Windows.h"
#include <iostream>
#include <windows.h>
#include<windowsx.h>
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <commctrl.h>


#pragma region constructor

NewBooking::NewBooking()
{
    const LPCWSTR _className = L"Default Window";
    HINSTANCE _instance = HINSTANCE();
    WNDCLASS _wnclass = {};
    _wnclass.lpszClassName = _className;
    _wnclass.hInstance = _instance;
    _wnclass.cbClsExtra = 0;
    _wnclass.style = CS_HREDRAW | CS_VREDRAW;
    _wnclass.lpfnWndProc = WindowProc_Internal;
    _wnclass.hbrBackground = CreateSolidBrush(RGB(240, 240, 240)); 
    _wnclass.hCursor = LoadCursor(_instance, IDC_HAND);
    RegisterClass(&_wnclass);

    //cette partie la permet de faire apparaitre la fenêtre 
    std::wstring _wName = std::wstring(name.begin(), name.end());
    windowInstance = CreateWindowEx(0, _className, _wName.c_str(),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZE, CW_USEDEFAULT, CW_USEDEFAULT,
        width, height, nullptr, nullptr, _instance, this);

    //cette partie de rajouter plusieur chose dans la fenêtre 

    _return = CreateWindowEx(0, L"Button", L"Return", WS_CHILD | WS_VISIBLE | WS_BORDER, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        1, 1, 100, 30, windowInstance, NULL, _instance, NULL);

    HWND textField = CreateWindowEx(0, L"Static", L"Réservation", WS_CHILD | WS_VISIBLE | SS_CENTER, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        640, 1, 140, 30, windowInstance, NULL, _instance, NULL);

    HWND _statFirstname = CreateWindowEx(0, L"Static", L"enter firstname :", WS_CHILD | WS_VISIBLE, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        2, 90, 150, 30, windowInstance, NULL, _instance, NULL);

    editFirstname = CreateWindowEx(0, L"Edit", L"enter firstname", WS_CHILD | WS_VISIBLE | WS_BORDER, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        160, 90, 190, 30, windowInstance, NULL, _instance, NULL);

    HWND _statLastName = CreateWindowEx(0, L"Static", L"enter LastName :", WS_CHILD | WS_VISIBLE, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        2, 150, 150, 30, windowInstance, NULL, _instance, NULL);

    editLastName = CreateWindowEx(0, L"Edit", L"enter LastName", WS_CHILD | WS_VISIBLE | WS_BORDER, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        160, 150, 190, 30, windowInstance, NULL, _instance, NULL);

    HWND _statPeople = CreateWindowEx(0, L"Static", L"For how many people :", WS_CHILD | WS_VISIBLE, //tatic tu écrit pas dans le bouton Edit si || WS_VSCROLL avec les autres WS il y a une barre de scroll
        2, 210, 150, 30, windowInstance, NULL, _instance, NULL);

    editPeople = CreateWindowEx(0, L"Edit", L" ", WS_CHILD | WS_VISIBLE | WS_BORDER,
        160, 210, 190, 30, windowInstance, NULL, _instance, NULL);

    //partie Callendar

    HWND _callandar = CreateWindowEx(0, MONTHCAL_CLASS, L"Callandar", WS_CHILD | WS_VISIBLE | WS_BORDER | MCS_MULTISELECT, 
        2, 260, 230, 165, windowInstance, NULL, _instance, NULL);
    MonthCal_SetMaxSelCount(_callandar, 624);

    SYSTEMTIME _time[1] = { };
    MonthCal_GetToday(_callandar, _time);
    MonthCal_SetRange(_callandar, GDTR_MIN, _time);
    LPARAM _lp = LPARAM();

    saveBook = CreateWindowEx(0, L"Button", L"Save Booking", WS_CHILD | WS_VISIBLE | WS_BORDER, 
        10, 490, 200, 40, windowInstance, NULL, _instance, NULL);


    SetWindowTextA(windowInstance, name.c_str());// ça permet d'afficher le nom de la fenêtre 
}

#pragma endregion constructor

#pragma region method

LRESULT __stdcall NewBooking::WindowProc(UINT _msg)
{

    switch (_msg)
    {
    case WM_DESTROY:
    {
        break;
    }
    case WM_MOUSEACTIVATE:
    {
        // je n'arrive pas a faire comme dans l'autre partie du code car il refuse les macro 
        break;
    }
    }
    return _msg;
}

void NewBooking::OpenBook()
{
    if (windowInstance == nullptr)return;
    isOpen = true;
    ShowWindow(windowInstance, SW_SHOWDEFAULT);
    UpdateWindow(windowInstance);
    Update();
}

void NewBooking::Update()
{
    MSG _msg = {};
    while (isOpen)
    {
        while (PeekMessage(&_msg, windowInstance, 0, 0, PM_REMOVE))
        {
            if (!TranslateAccelerator(_msg.hwnd, nullptr, &_msg))
            {
                TranslateMessage(&_msg);
                DispatchMessage(&_msg);
            }
        }
    }
}

void NewBooking::Close()
{
    CloseWindow(windowInstance);
    isOpen = false;
}

#pragma endregion method



//MonthCal_GetCurSel pour chopper la date du callendrier