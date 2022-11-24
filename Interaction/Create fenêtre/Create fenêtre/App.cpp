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
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_BACKGROUND + 1));
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
    HWND button=CreateWindowEx(
        WS_EX_CLIENTEDGE,
        L"BUTTON",
        L"click here",
        WS_VISIBLE | WS_CHILD,
        100,
        95,
        80,
        50,
        hwnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
         NULL
    );

    HWND edit = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD,
        50,
        50,
        80,
        30,
        hwnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
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

#define IDM_ELLIPSE    1
#define IDM_RECTANGLE  6
#define IDM_ROUNDRECT  20


BOOL CALLBACK App::WndProci(HWND hwnd, UINT uMsg, WPARAM wParam,
    LPARAM lParam)
{
    HDC hdc;          
    PAINTSTRUCT ps;   
    POINT ptClientUL; 
    POINT ptClientLR; 
    static HDC hdcCompat; 
    static POINT pt;      
    static RECT rcTarget; 
    static RECT rcClient; 
    static BOOL fSizeEllipse; 
    static BOOL fDrawEllipse;   
    static BOOL fDrawRectangle; 
    static BOOL fSizeRectangle; 
    static BOOL fSizeRoundRect; 
    static BOOL fDrawRoundRect; 
    static int nEllipseWidth;   
    static int nEllipseHeight;  

    switch (uMsg)
    {
    case WM_COMMAND:
        switch (wParam)
        {

        case IDM_ELLIPSE:
            fSizeEllipse = TRUE;
            break;

        case IDM_RECTANGLE:
            fSizeRectangle = TRUE;
            break;

        case IDM_ROUNDRECT:
            fSizeRoundRect = TRUE;
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam,
                lParam);
        }
        break;


    case WM_CREATE:
        nEllipseWidth = 20;
        nEllipseHeight = 20;

        return 0;

    case WM_PAINT:


        BeginPaint(hwnd, &ps);

        SelectObject(ps.hdc, GetStockObject(GRAY_BRUSH));

        if (fDrawEllipse)
        {
            Ellipse(ps.hdc, rcTarget.left, rcTarget.top,
                rcTarget.right, rcTarget.bottom);
            fDrawEllipse = FALSE;
            rcTarget.left = rcTarget.right = 50;
            rcTarget.top = rcTarget.bottom = 10;
        }

        if (fDrawRectangle)
        {
            Rectangle(ps.hdc, rcTarget.left, rcTarget.top,
                rcTarget.right, rcTarget.bottom);
            fDrawRectangle = FALSE;
            rcTarget.left = rcTarget.right = 20;
            rcTarget.top = rcTarget.bottom = 10;
        }

        if (fDrawRoundRect)
        {
            RoundRect(ps.hdc, rcTarget.left, rcTarget.top,
                rcTarget.right, rcTarget.bottom,
                nEllipseWidth, nEllipseHeight);
            fDrawRectangle = FALSE;
            rcTarget.left = rcTarget.right = 50;
            rcTarget.top = rcTarget.bottom = 10;
        }

        EndPaint(hwnd, &ps);
        break;

    case WM_SIZE:

        GetClientRect(hwnd, &rcClient);
        ptClientUL.x = rcClient.left;
        ptClientUL.y = rcClient.top;
        ptClientLR.x = rcClient.right;
        ptClientLR.y = rcClient.bottom;
        ClientToScreen(hwnd, &ptClientUL);
        ClientToScreen(hwnd, &ptClientLR);
        SetRect(&rcClient, ptClientUL.x, ptClientUL.y,
            ptClientLR.x, ptClientLR.y);
        return 0;

    case WM_LBUTTONDOWN:

        ClipCursor(&rcClient);

        pt.x = (LONG)LOWORD(lParam);
        pt.y = (LONG)HIWORD(lParam);

        if (fDrawEllipse)
            fSizeEllipse = TRUE;

        return 0;

    case WM_MOUSEMOVE: 

        if ((wParam && MK_LBUTTON)
            && (fSizeEllipse || fSizeRectangle
                || fSizeRoundRect))
        {

            hdc = GetDC(hwnd);
            SetROP2(hdc, R2_NOTXORPEN);

            if (!IsRectEmpty(&rcTarget))
            {
                Rectangle(hdc, rcTarget.left, rcTarget.top,
                    rcTarget.right, rcTarget.bottom);
            }

            if ((pt.x < (LONG)LOWORD(lParam)) &&
                (pt.y > (LONG) HIWORD(lParam)))
            {
                SetRect(&rcTarget, pt.x, HIWORD(lParam),
                    LOWORD(lParam), pt.y);
            }

            else if ((pt.x > (LONG)LOWORD(lParam)) &&
                (pt.y > (LONG)HIWORD(lParam)))
            {
                SetRect(&rcTarget, LOWORD(lParam),
                    HIWORD(lParam), pt.x, pt.y);
            }

            else if ((pt.x > (LONG)LOWORD(lParam)) &&
                (pt.y < (LONG)HIWORD(lParam)))
            {
                SetRect(&rcTarget, LOWORD(lParam), pt.y,
                    pt.x, HIWORD(lParam));
            }
            else
            {
                SetRect(&rcTarget, pt.x, pt.y, LOWORD(lParam),
                    HIWORD(lParam));
            }  

            Rectangle(hdc, rcTarget.left, rcTarget.top,
                rcTarget.right, rcTarget.bottom);
            ReleaseDC(hwnd, hdc);
        }
        return 0;

    case WM_LBUTTONUP:

        if (fSizeEllipse)
        {
            fSizeEllipse = FALSE;
            fDrawEllipse = TRUE;
        }

        if (fSizeRectangle)
        {
            fSizeRectangle = FALSE;
            fDrawRectangle = TRUE;
        }

        if (fSizeRoundRect)
        {
            fSizeRoundRect = FALSE;
            fDrawRoundRect = TRUE;
        }

        if (fDrawEllipse || fDrawRectangle || fDrawRoundRect)
        {
            InvalidateRect(hwnd, &rcTarget, TRUE);
            UpdateWindow(hwnd);
        }
        ClipCursor((LPRECT)NULL);
        return 0;

    case WM_DESTROY:
        DeleteDC(hdcCompat);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return (LRESULT)NULL;
}