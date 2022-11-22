#pragma once
#include <Windows.h>
#include "FString.h"
#include "WindowMenu.h"
#include <map>

namespace Core
{
	class WindowMenu;
	class Window:public Object
	{
#pragma region f/P
	private :
		HWND windowInstance = nullptr;
		PrimitiveType::FString name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true;
		std::map<const char*, WindowMenu*> menus = std::map<const char*, WindowMenu*>();
#pragma endregion f/P
		public:
		Window() = default;
		O3DLIBRAIRY_API Window(const PrimitiveType::FString& _name, const int _width, const int _height);
		~Window()override;
		
	private:
		O3DLIBRAIRY_API LRESULT __stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		O3DLIBRAIRY_API static LRESULT __stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		WindowMenu* CreateWindowMenu(const char* _name);
	public:
		int MenusCount() const;
		void RegisterMenu(WindowMenu* _menu);
	protected:
		O3DLIBRAIRY_API virtual void Update();
		O3DLIBRAIRY_API virtual void AddMenu(HWND _hwnd);
	public:
		O3DLIBRAIRY_API void Open();
		O3DLIBRAIRY_API void Close();
	};
}
