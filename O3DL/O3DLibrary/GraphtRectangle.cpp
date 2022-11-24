#include "GraphtRectangle.h"

void GraphtRectangle::Open()
{
	WindowProc(hWindow);
}

O3DLIBRAIRY_API LRESULT __stdcall GraphtRectangle::WindowProc(HWND _hWindow)
{
	hdc = BeginPaint(_hWindow, &paintSruct);
	//paint
	Gdiplus::Graphics _graphics(hdc);
	Gdiplus::Color _color = Gdiplus::Color(255, 255, 0, 0);
	Gdiplus::Pen _pen(Gdiplus::Color::White);
	Gdiplus::Rect _rect = Gdiplus::Rect(10, 10, 100, 100);
	_graphics.DrawRectangle(&_pen, _rect);
	_graphics.FillRectangle(new Gdiplus::SolidBrush(_color), _rect);
	EndPaint(_hWindow, &paintSruct);
}
