#include "App.h"
#include <exception>

TCHAR App::szWindowClass[]= _T("DesktopApp");
TCHAR App::szTitle[] = _T("Windows Desktop Guided Tour Application");

LRESULT App::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }
    return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void WINAPI App::Wind(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    WNDCLASS wc = { };

    wc.lpfnWndProc = WndProc;
    wc.hInstance = _hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Learn to Program Windows",
        WS_OVERLAPPEDWINDOW,

        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,
        NULL,
        _hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        return ;
    }
    ShowWindow(hwnd, _nCmdShow);
    MSG msg = { };
    while (GetMessage(&msg,NULL , 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return ;
}

