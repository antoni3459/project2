#include <iostream>
#include "Window/Windows.h"
#include "Window/Menu/MainMenu/MainMenu.h"
#include "Utils/Interfarce/MenuInterfarce.h"
#include "Window/Menu/BookinkMenu/BookingMenu.h"

int main()
{
    Windows _window = Windows(L"Hotel Objecif3D", 1920, 1080);
    _window.RegisterMenu(new BookingMenu(&_window));
    _window.SetCurrentMenu(BOOKINGMENU);
    _window.Open();
}