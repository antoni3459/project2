#pragma once
#include "FString.h"
#include <Windows.h>

namespace Core
{
	class Window;
	class WindowMenu
	{
#pragma region f/p

	private:
		Window* handle = nullptr;
		HMENU menu = nullptr;
		std::string name = "";
#pragma endregion f/p

#pragma region constructeur

	public:
		WindowMenu() = default;
		WindowMenu(Window* _handle, std::string _name);
		WindowMenu(const WindowMenu& _copy);
#pragma endregion constructeur

#pragma region method

	public:
		std::string  Name()const;
		void CreateButonMenu(const std::string& _name);
		void CreateSeparator() const;
		void CreatePopupMenu(const WindowMenu* _subMenu)const;
#pragma endregion method

#pragma region operator

	public:
		operator HMENU()const;
#pragma endregion operator

	};
}
