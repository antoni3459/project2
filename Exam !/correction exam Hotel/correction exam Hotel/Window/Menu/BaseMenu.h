#pragma once
#include "../../Object/Object.h"
#include <vector>

class WindowControl;
class Windows;
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
	void CreateButton(const Rect& _rect, const wchar_t* _text);
	void CreateLabel(const Rect& _rect, const wchar_t* _text);
	void CreateTextField(const Rect& _rect, const wchar_t* _defaultText);
	class CalendarControl* CreateCalendar(const Rect& _rect);
};

