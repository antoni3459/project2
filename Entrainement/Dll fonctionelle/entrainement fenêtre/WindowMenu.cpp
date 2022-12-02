#include "WindowMenu.h"
#include "Window.h"
#include "FString.h"
#include "Interger.h"
#include "Boolean.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <ranges>


Core::WindowMenu::WindowMenu(Window* _handle, std::string _name)
{
	handle = _handle;
	name = _name;
	menu = CreateMenu();
}

Core::WindowMenu::WindowMenu(const WindowMenu& _copy)
{
	handle = _copy.handle;
	name = _copy.name;
	menu = _copy.menu;

}

std::string Core::WindowMenu::Name() const
{
	return name;
}

void Core::WindowMenu::CreateButonMenu(const std::string& _name)
{
	const int _key = handle->MenusCount();
	std::wstring Wname = std::wstring(_name.begin(), _name.end());
	AppendMenu(menu, MF_STRING, _key, Wname.c_str());
}

void Core::WindowMenu::CreateSeparator() const // separe les différent menu
{
	AppendMenu(menu, MF_SEPARATOR, -1, nullptr);
}

void Core::WindowMenu::CreatePopupMenu(const WindowMenu* _subMenu) const // les menu déroulement 
{
	std::string _name = _subMenu->Name();

	std::wstring Wname = std::wstring(_name.begin(), _name.end());
	const int _key = reinterpret_cast<UINT_PTR>(_subMenu->menu);
	AppendMenu(menu, MF_POPUP, _key, Wname.c_str());
}

Core::WindowMenu::operator HMENU() const
{
	return menu;
}
