#include "MainMenu.h"
#include "../../../Utils/Interfarce/MenuInterfarce.h"
#include "../../Control/Label/LabelControl.h"
#include "../../Windows.h"
#include "../../Control/Button/ButtonControl.h"


MainMenu::MainMenu(Windows* _owner):super(_owner, MAINMENU)
{
}

void MainMenu::Initialize()
{
	super::Initialize();

	CreateLabel(Rect(60, 50, 200, 20), TEXT("Create Booking"));
	CreateLabel(Rect(60, 80, 200, 20), TEXT(MAINMENU));

	isInitialized = true;
}
