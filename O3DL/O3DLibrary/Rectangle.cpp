#include "Rectangle.h"

Core::Rectangle::Rectangle(const std::vector<int> _position, const int _x, const int _y)
{
	x=_x;
	y = _y;
	position = _position;
}

LRESULT __stdcall Core::Rectangle::WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	switch (_msg)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(_hWindow, &paintSruct);
		//paint
		Gdiplus::Graphics _graphics(hdc);
		Gdiplus::Color _color = Gdiplus::Color(255, 255, 0, 0);
		Gdiplus::Pen _pen(Gdiplus::Color::White);
		Gdiplus::Rect _rect = Gdiplus::Rect( position[0], position[1] , 200, 100);
		_graphics.DrawRectangle(&_pen, _rect);
		_graphics.FillRectangle(new Gdiplus::SolidBrush(_color), _rect);
		EndPaint(_hWindow, &paintSruct);
		break;
	}
	case WM_DESTROY:
	{
		Close();
		break;
	}
	default :
		return DefWindowProcW(_hWindow, _msg, _wp, _lp);
	}
}

void Core::Rectangle::Close()
{
	CloseWindow(windowInstance);
	isOpen = false;
}