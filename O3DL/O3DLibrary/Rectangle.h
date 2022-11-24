#pragma once
#include "Window.h"
#include <vector>

namespace Core
{
	class Rectangle
	{
	private :
		int x = 0,
			y = 0;

		std::vector<int> position = std::vector<int>();
		bool isOpen = true;
		HDC hdc = HDC();
		PAINTSTRUCT paintSruct = PAINTSTRUCT();
		HWND windowInstance = nullptr;
	public:
		Rectangle() = default;
		Rectangle(const std::vector<int> _position,const int _x,const int _y);

	public:
		LRESULT __stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		void Close();
	};
}
