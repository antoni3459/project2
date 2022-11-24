#pragma once
#include "Window.h"
#include <vector>

namespace Core
{
	class ElipseGraph
	{
	private:
		int x = 0,
			y = 0;

		std::vector<int> position = std::vector<int>();
		bool isOpen = true;
		HDC hdc = HDC();
		PAINTSTRUCT paintSruct = PAINTSTRUCT();
		HWND windowInstance = nullptr;
	public:
		ElipseGraph() = default;
		ElipseGraph(const std::vector<int> _position, const int _x, const int _y);
		ElipseGraph(ElipseGraph& _copy);
	public:
		LRESULT __stdcall Draw(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		void Close();
	};

}