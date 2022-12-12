#pragma once
#include "../Object/Object.h"
#include "Menu/BaseMenu.h"
#include <Windows.h>
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>
#include <map>

class BaseMenu;

class Windows : public Object
{
	DECLARE_CLASS_INFO(Object)

private:
	HWND windowsInstance = nullptr;
	HINSTANCE hInstance = HINSTANCE();
	const wchar_t* title = TEXT("default Window");
	int width = 1920;
	int height = 1080;
	bool isOpen = false;
	std::map<std::string, BaseMenu*> menu = std::map<std::string, BaseMenu*>();
	BaseMenu* currentMenu = nullptr;

public:
	Windows() = default;
	Windows(const wchar_t* _title, int _width = 1920, int _height = 1080);
	~Windows()override;

private:
	static LRESULT __stdcall WindowsProcInternal(HWND _hdwindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	 LRESULT __stdcall WindowsProc(HWND _hdwindow, UINT _msg, WPARAM _wp, LPARAM _lp);

public:
	void RegisterMenu(BaseMenu* _menu);
	void SetCurrentMenu(const char* _menuName);
	void Open();
	void Close();
	void Update();
	HWND WindowInstance();
	int Width()const;
};

