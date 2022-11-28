#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include <vector>
#include "FString.h"
#include <map>

#pragma comment(lib,"Gdiplus.lib")
namespace Core
{
	class WindowMenu;
	class O3DLIBRAIRY_API Window :public Object
	{
#pragma region f/P
	private:
		std::vector<class Shape*> shapes = std::vector<class Shape*>();
		HWND windowInstance = nullptr;
		PrimitiveType::FString name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true;
		std::map<const char*, WindowMenu*> menus = std::map<const char*, WindowMenu*>();

		HDC hdc = HDC();
		PAINTSTRUCT paintSruct = PAINTSTRUCT();
		Gdiplus::GdiplusStartupInput gdiplusStartupInput = Gdiplus::GdiplusStartupInput();
		ULONG_PTR gdiplusToken = 0;
#pragma endregion f/P

#pragma region constructeur

	public:
		Window() = default;
		 Window(const PrimitiveType::FString& _name, const int _width, const int _height);
		 ~Window()override;
#pragma endregion constructeur

#pragma region method

	private:
		 LRESULT __stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		 static LRESULT __stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);

	public:
		 int MenusCount() const;
		 void RegisterMenu(WindowMenu* _menu);

	protected:
		 virtual void Update();
		 virtual void AddMenu(HWND _hwnd);
		 WindowMenu* CreateWindowMenu(const char* _name);
		 void Register(Shape* _shapes);
	public:
		 void Open();
		 void Close();
#pragma endregion method

	};
}
