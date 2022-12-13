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
	ButtonControl* _createControle = CreateButton(Rect(60, 50, 200, 20), TEXT("Create Booking"));
	_createControle->OnClick.SetDynamic(this, &MainMenu::OpenBookingMenu);
	ButtonControl* _viewControle = CreateButton(Rect(60, 80, 200, 20), TEXT("View Booking"));
	_viewControle->OnClick.SetDynamic(this, &MainMenu::OpenBookingViewMenu);
	isInitialized = true;
	Close();
}

void MainMenu::OpenBookingMenu()
{
	owner->SetCurrentMenu(BOOKINGMENU);
}

void MainMenu::OpenBookingViewMenu()
{
	owner->SetCurrentMenu(BOOKINGVIEWMENU);
}

