#include "Windows.h"
#include "NewBooking.h"
#include "ViewAll.h"
#include <iostream>
#include <windows.h>
#include<windowsx.h>
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <commctrl.h>


#pragma region constructor

Windows::Windows()
{
    // toute cette partie permet d'initialiser la fenêtre 
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
    HWND textField = CreateWindowEx(0, L"Static", L"Hotel", WS_CHILD | WS_VISIBLE, 
        640, 1, 140, 30, windowInstance, NULL, _instance, NULL);

    createNewBooking = CreateWindowEx(0, L"Button", L"Create new Booking", WS_CHILD | WS_VISIBLE | WS_BORDER,
        200, 60, 150, 30, windowInstance, NULL, _instance, NULL);

    viewAllBookings = CreateWindowEx(0, L"Button", L"View all Bookings", WS_CHILD | WS_VISIBLE | WS_BORDER, 
        500, 60, 150, 30, windowInstance, NULL, _instance, NULL);

    SetWindowTextA(windowInstance, name.c_str());// ça permet d'afficher le nom de la fenêtre 
}

#pragma endregion constructor

#pragma region method

LRESULT __stdcall Windows::WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{

    switch (_msg)
    {

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    case WM_MOUSEACTIVATE:
    {
        int test = Button_GetState(viewAllBookings);
        int test1 = Button_GetState(createNewBooking);

        Button(test, test1, _msg);

    }
    }
    return DefWindowProc(_hWindow, _msg, _wp, _lp);
}

LRESULT __stdcall Windows::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
    if (_msg == WM_NCCREATE)
    {
        SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
        return true;
    }
    return reinterpret_cast<Windows*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
}

void Windows::Open()
{
    if (windowInstance == nullptr)return;
    isOpen = true;
    ShowWindow(windowInstance, SW_SHOWDEFAULT);
    UpdateWindow(windowInstance);
    Update();
}

void Windows::Update()
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

void Windows::Close()
{
    CloseWindow(windowInstance);
    isOpen = false;
}

void Windows::Button(int _test, int _test1, UINT _msg)
{
    if (count==0)
    {
        if (_test1 == 512 && _test == 0)
        {
            count = 1;
            Button_SetCheck(createNewBooking, BST_UNCHECKED);
            AddReserv();
        }
        if (_test1 == 0 && _test == 512)
        {
            count = 2;
            Button_SetCheck(viewAllBookings, BST_UNCHECKED);
            ViewAllM();
        }
    }
    if (count == 1)
    {
        book->WindowProc(_msg);
    }
}

void Windows::AddReserv()
{
    NewBooking newBooking = NewBooking();
    newBooking.OpenBook();
}

void Windows::ViewAllM()
{
    ViewAll viewAll = ViewAll();
    viewAll.Open();
}

#pragma endregion method
