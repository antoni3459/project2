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
	class Window :public Object
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
		O3DLIBRAIRY_API Window(const PrimitiveType::FString& _name, const int _width, const int _height);
		O3DLIBRAIRY_API ~Window()override;
#pragma endregion constructeur

#pragma region method

	private:
		O3DLIBRAIRY_API LRESULT __stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		O3DLIBRAIRY_API static LRESULT __stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);

	public:
		O3DLIBRAIRY_API int MenusCount() const;
		O3DLIBRAIRY_API void RegisterMenu(WindowMenu* _menu);

	protected:
		O3DLIBRAIRY_API virtual void Update();
		O3DLIBRAIRY_API virtual void AddMenu(HWND _hwnd);
		O3DLIBRAIRY_API WindowMenu* CreateWindowMenu(const char* _name);
		O3DLIBRAIRY_API void Register(Shape* _shapes);
	public:
		O3DLIBRAIRY_API void Open();
		O3DLIBRAIRY_API void Close();
#pragma endregion method

	};
}
