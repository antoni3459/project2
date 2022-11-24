#include "WindowMenu.h"
#include "Window.h"


Core::WindowMenu::WindowMenu(Window* _handle, const char* _name)
{
	handle = _handle;
	menu = CreateMenu();
	name = _name;

}

Core::WindowMenu::WindowMenu(const WindowMenu& _copy)
{
	handle = _copy.handle;
	menu = _copy.menu;
	name = _copy.name;

}

Core::PrimitiveType::FString Core::WindowMenu::Name() const
{
	return name;
}

void Core::WindowMenu::CreateButonMenu(const PrimitiveType::FString& _name)
{
	const int _key = handle->MenusCount() + 1;
	AppendMenu(menu, MF_STRING, _key, _name.ToWString().c_str());
	handle->RegisterMenu(this);
}



void Core::WindowMenu::CreateSeparator() const
{
	AppendMenu(menu, MF_SEPARATOR, -1, nullptr);
}

void Core::WindowMenu::CreatePopupMenu(const WindowMenu* _subMenu) const
{
	const int _key = reinterpret_cast<UINT_PTR> (_subMenu->menu);
	AppendMenu(menu, MF_POPUP, _key, _subMenu->Name().ToWString().c_str());
}

Core::WindowMenu::operator HMENU() const
{
	return menu;
}
