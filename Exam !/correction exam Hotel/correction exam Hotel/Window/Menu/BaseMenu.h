#pragma once
#include "../../Object/Object.h"

#include <vector>
#include "../../Booking/Booking.h"

class WindowControl;
class Windows;
class ButtonControl;
class LabelControl;
class TextField;
class ButtonBookingControl;
struct Rect;

class BaseMenu:public Object
{
	DECLARE_CLASS_INFO(Object)

protected:
	static inline int currentControlID = 0;
	const char* name = "";
	bool isInitialized = false;
	Windows* owner = nullptr;
	std::vector<WindowControl*> controls = std::vector<WindowControl*>();
	LabelControl* titleControl = nullptr;

public:
	BaseMenu() = default;
	BaseMenu(Windows* _owner, const char* _name);
	BaseMenu(const BaseMenu& _copy);

public:
	bool IsInitialized()const;
	virtual void Open();
	virtual void Close();
	virtual void Initialize();
	std::string Name();

protected :
	class ButtonControl* CreateButton(const Rect& _rect, const wchar_t* _text);
	class LabelControl* CreateLabel(const Rect& _rect, const wchar_t* _text);
	class TextField* CreateTextField(const Rect& _rect, const wchar_t* _defaultText);
	class ButtonBookingControl* CreateBookingButton(const Rect& _rect, const wchar_t* _text, Booking* _booking);
	class CalendarControl* CreateCalendar(const Rect& _rect);
};

