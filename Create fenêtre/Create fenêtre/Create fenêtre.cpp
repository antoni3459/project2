#include <iostream>
#include "App.h"

HINSTANCE  hInstance = HINSTANCE();
HINSTANCE  hPrevInstance = HINSTANCE();
LPSTR  lpCmdLine = LPSTR();
int nCmdShow = 10;

int main()
{
    App app;
    app.Wind(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
