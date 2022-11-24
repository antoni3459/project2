#include <iostream>
#include "App.h"
#include "Button.h"
#include "Event.h"
#include "EventSystem.h"
#include "Rect.h"
HINSTANCE  hInstance = HINSTANCE();
HINSTANCE  hPrevInstance = HINSTANCE();
LPSTR  lpCmdLine = LPSTR();
int nCmdShow = 10;

HWND hwnd = HWND();
UINT uMsg = UINT();
WPARAM wParam = WPARAM();
LPARAM lParam = LPARAM();

int main()
{
    App app;
    app.WndProci(hwnd, uMsg, wParam, lParam);
    app.Wind(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
