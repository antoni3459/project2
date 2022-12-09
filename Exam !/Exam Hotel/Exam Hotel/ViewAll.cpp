#include "ViewAll.h"

#pragma region constructor

ViewAll::ViewAll()
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

    HWND textField = CreateWindowEx(0, L"Static", L"Booking View", WS_CHILD | WS_VISIBLE | SS_CENTER, 
        640, 1, 140, 30, windowInstance, NULL, _instance, NULL);

    _return = CreateWindowEx(0, L"Button", L"Return", WS_CHILD | WS_VISIBLE | WS_BORDER, 
        1, 1, 100, 30, windowInstance, NULL, _instance, NULL);
}

#pragma endregion constructor

#pragma region method

void ViewAll::Open()
{
    if (windowInstance == nullptr)return;
    isOpen = true;
    ShowWindow(windowInstance, SW_SHOWDEFAULT);
    UpdateWindow(windowInstance);
    Update();
}

void ViewAll::Update()
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

void ViewAll::Close()
{
    CloseWindow(windowInstance);
    isOpen = false;
}

#pragma endregion method

//ListView_SetItem

//ListView