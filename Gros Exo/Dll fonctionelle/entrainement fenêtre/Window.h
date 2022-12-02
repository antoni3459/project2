#pragma once
#include "Object.h"
#include <Windows.h>
#include <gdiplus.h>
#include <vector>
#include <string>
#include <map>

#pragma comment(lib,"Gdiplus.lib")

namespace Core
{
	class WindowMenu;
	class Window :public Object
	{
#pragma region f/P
	// varible pour windows et menu
	private:
		HWND windowInstance = nullptr;
		std::string name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true;
		std::map<std::string, WindowMenu*> menus = std::map<std::string, WindowMenu*>();
		HDC hdc = HDC();

		//varaible pour Shape
		std::vector<class Shape*> shapes = std::vector<Shape*>();
		PAINTSTRUCT paintStruct = PAINTSTRUCT();
		Gdiplus::GdiplusStartupInput gdiplusStartupInput = Gdiplus::GdiplusStartupInput();
		ULONG_PTR gdiplusToken = 0;
	public:
		Gdiplus::Color color = Gdiplus::Color(255, 255, 0, 0);
		Gdiplus::Rect pos = Gdiplus::Rect(10, 10, 100, 100);
#pragma endregion f/P

#pragma region constructeur

	public:
		Window() = default;
		Window(const std::string& _name, const int _width, const int _height);
		~Window()override;
#pragma endregion constructeur

#pragma region method

	private:
		LRESULT _stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);

	protected:
		virtual void Update();
		virtual void AddMenu(HWND _hwnd);
		WindowMenu* CreateWindowMenu(const char* _name);
	public:
		void Register(Shape* _shapes);
		void Open();
		void Close();
		int MenusCount() const;
		void RegisterMenu(WindowMenu* _menu);
#pragma endregion method

	};
}
