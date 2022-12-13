#include "Windows.h"
#include "Control/Button/ButtonControl.h"
#include "Menu/BaseMenu.h"
#include "Control/TextField/TextField.h"
#include "Control/Calandar/CalendarControl.h"
#include <exception>
#include <Windows.h>
#include <format>
#include <ranges>
#include <iostream>


Windows::Windows(const wchar_t* _title, int _width, int _height)
{
    title = _title;
    width = _width;
    height = _height;

    INITCOMMONCONTROLSEX _iccex;
    _iccex.dwSize = sizeof(_iccex);
    _iccex.dwICC = ICC_DATE_CLASSES;

    if (!InitCommonControlsEx(&_iccex))
        throw std::exception("[Window] => failed to initialize common controls !");
    hInstance = GetModuleHandle(NULL);
    LPCWSTR _className = TEXT("Sample Window Class");
    WNDCLASS _wndClass = { };
    _wndClass.style = CS_HREDRAW | CS_VREDRAW;
    _wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    _wndClass.lpszClassName = _className;
    _wndClass.hInstance = hInstance;
    _wndClass.lpfnWndProc = WindowsProcInternal;
    RegisterClass(&_wndClass);

    windowsInstance = CreateWindowEx(WS_EX_APPWINDOW, _className, title,
        WS_OVERLAPPEDWINDOW , CW_USEDEFAULT, CW_USEDEFAULT,
        width, height, nullptr, nullptr, hInstance, this);

    std::wstring _wstr = title;
    std::string _titleCstr(_wstr.begin(), _wstr.end());
    SetWindowTextA(windowsInstance, _titleCstr.c_str());
}

Windows::~Windows()
{
    for (BaseMenu* _menu : menu | std::ranges::views::values)
        delete _menu;
    menu.clear();
    if (isOpen)
        Close();
}

LRESULT __stdcall Windows::WindowsProcInternal(HWND _hwindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
    if (_msg == WM_NCCREATE)
    {
        SetWindowLongPtr(_hwindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
        return true;
    }
    return reinterpret_cast<Windows*>(GetWindowLongPtr(_hwindow, GWLP_USERDATA))->WindowsProc(_hwindow, _msg, _wp, _lp);
}

LRESULT __stdcall Windows::WindowsProc(HWND _hwindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
    if (_hwindow == nullptr) return false;
    switch (_msg)
    {
    case WM_COMMAND:
    {
        if (ButtonControl::buttons.contains(_wp))
        {
            ButtonControl::buttons[_wp]->OnClick.Invoke();
            break;
        }
        WORD _word = HIWORD(_wp);
        switch (_word)
        {
        case EN_CHANGE:
        {
            std::map<int, TextField*> textfields = TextField::textField;
            for (std::pair<int, TextField*> _pair : textfields)
            {
                if (_pair.first == LOWORD(_wp))
                {
                    _pair.second->OnValueChange();
                    break;
                }

            }
            break;

        }
        }
        break;
    }
    case WM_NOTIFY:
    {
        LPNMHDR _lpm = (LPNMHDR)_lp;
        switch (_lpm->code)
        {
        case MCN_SELECT:
        {
            std::map<int, CalendarControl*> _calendars = CalendarControl::calendars;
            for (std::pair<int, CalendarControl*> _pair : _calendars)
            {
                if (_pair.first == _wp)
                {
                    _pair.second->OnChoice((LPNMSELCHANGE)_lp);
                    break;
                }
            }
            break;
        }
        }
        break;
    }
    case WM_DESTROY:
    {
        isOpen = false;
        exit(0);
        break;
    }
    }
    
    return DefWindowProc(_hwindow, _msg, _wp, _lp);
}

void Windows::RegisterMenu(BaseMenu* _menu)
{
    if (menu.contains(_menu->Name()))return;
    if (!_menu->IsInitialized())
        _menu->Initialize();
    menu.insert(std::pair(_menu->Name(), _menu));
}

void Windows::SetCurrentMenu(const char* _menuName)
{
    if (!menu.contains(_menuName))
        throw std::exception(std::format("[Window] => ()doen't exist", _menuName).c_str());
    if (currentMenu != nullptr)
        currentMenu->Close();
    currentMenu = menu[_menuName];
    currentMenu->Open();
}

void Windows::Open()
{
    if (windowsInstance == nullptr)
        throw std::exception("[Window] => window instance is null !");
    ShowWindow(windowsInstance, SW_NORMAL);
    UpdateWindow(windowsInstance);
    isOpen = true;
    Update();
}

void Windows::Close()
{
    if(windowsInstance==nullptr||isOpen)
        throw std::exception("[Window] => window instance is null or not open, failed to close window !");
    isOpen = true;
}

void Windows::Update()
{
    MSG msg = { };
    while (isOpen)
    {
        try
        {
            while (PeekMessage(&msg, windowsInstance, 0, 0, PM_REMOVE))
            {
                if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
        }
        catch (const std::exception& _e)
        {
            std::cout << _e.what() << std::endl;
        }
    }
}

HWND Windows::WindowInstance()
{
    return windowsInstance;
}

int Windows::Width() const
{
    return width;
}
