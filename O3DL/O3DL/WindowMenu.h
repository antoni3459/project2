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
		PrimitiveType::FString name = "";
#pragma endregion f/p

	public:
		WindowMenu() = default;
		WindowMenu(Window* _handle, const char* _name);
		WindowMenu(const WindowMenu& _copy);

	public:
		PrimitiveType::FString Name()const;
		void CreateButonMenu(const PrimitiveType::FString& _name);
		void CreateSeparator() const;
		void CreatePopupMenu(const WindowMenu* _subMenu)const;

	public:
		operator HMENU()const;
	};
}
