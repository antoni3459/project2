#include "BaseMenu.h"
#include "../Control/WindowControl.h"
#include "../Control/Button/ButtonControl.h"
#include "../Control/Label/LabelControl.h"
#include "../Windows.h"
#include "../Control/TextField/TextField.h"
#include "../Control/Calandar/CalendarControl.h"

BaseMenu::BaseMenu(Windows* _owner, const char* _name)
{
	owner = _owner;
	name = _name;

}

BaseMenu::BaseMenu(const BaseMenu& _copy)
{
	name=_copy.name;
	owner = _copy.owner;

}

bool BaseMenu::IsInitialized() const
{
	return isInitialized;
}

void BaseMenu::Open()
{
	if (!isInitialized)return;
	for (WindowControl* _control : controls)
		_control->Show();
}

void BaseMenu::Close()
{
	if (!isInitialized)return;
	for (WindowControl* _control : controls)
		_control->Hide();
}

void BaseMenu::Initialize()
{
	std::string _str = name;
	const int _width = (owner->Width() / 2);
	const std::wstring _wName(_str.begin(), _str.end());
	CreateLabel(Rect(_width, 0, 255, 2), _wName.c_str());
}

std::string BaseMenu::Name() 
{
	return name;
}

void BaseMenu::CreateButton(const Rect& _rect, const wchar_t* _text)
{
	ButtonControl* _button =new ButtonControl(currentControlID++, owner->WindowInstance(), _rect, _text);
	_button->Create();
	controls.push_back(_button);
}

void BaseMenu::CreateLabel(const Rect& _rect, const wchar_t* _text)
{
	LabelControl* _button =new LabelControl(currentControlID++, owner->WindowInstance(), _rect, _text);
	_button->Create();
	controls.push_back(_button);
}

void BaseMenu::CreateTextField(const Rect& _rect, const wchar_t* _defaultText)
{
	TextField* _textField = new TextField(currentControlID++, owner->WindowInstance(), _rect, _defaultText);
	_textField->Create();
	controls.push_back(_textField);
}

CalendarControl* BaseMenu::CreateCalendar(const Rect& _rect)
{
	CalendarControl* _calendar = new CalendarControl(currentControlID++, owner->WindowInstance(), _rect);
	_calendar->Create();
	controls.push_back(_calendar);
	return _calendar;
}
