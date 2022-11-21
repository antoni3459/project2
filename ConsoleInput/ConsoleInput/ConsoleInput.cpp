#include <iostream>
#include "App.h"
#include "Button.h"
#include "Rect.h"
#include "EventSystem.h"

int main()
{
    Rect* rect = new Rect(30, 20, 10, 10);
    Button* button1 = new Button("Test ", rect);
    EventSystem::Instance()->Register(button1);

    App app;
    app.Open();
}
