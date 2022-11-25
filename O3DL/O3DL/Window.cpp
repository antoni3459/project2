#include "Window.h"
#include "WindowMenu.h"
#include "Shape.h"
#include <Windows.h>
#include <gdiplus.h>
#include <iostream>

Core::Window::Window(const PrimitiveType::FString& _name, const int _width, const int _height)
{
	name = _name;
	width = _width;
	height = _height;

	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	const LPCWSTR _className = L"Default Window";
	HINSTANCE _instance = HINSTANCE();
	WNDCLASS _wnclass = {};
	_wnclass.lpszClassName = _className;
	_wnclass.hInstance = _instance;
	//TODO Window Proc
	_wnclass.cbClsExtra = 0;
	_wnclass.style = CS_HREDRAW | CS_VREDRAW;
	_wnclass.lpfnWndProc = WindowProc_Internal;
	_wnclass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	_wnclass.hCursor = LoadCursor(_instance, IDC_HAND);
	RegisterClass(&_wnclass);
	windowInstance = CreateWindowEx(WS_EX_TOOLWINDOW, _className, _name.ToWString().c_str(),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZE, CW_USEDEFAULT, CW_USEDEFAULT,
		width, height, nullptr, nullptr, _instance, this);

}

Core::Window::~Window()
{
	for (std::pair<const char*, WindowMenu*> _p : menus)
		delete _p.second;
	menus.clear();
	delete windowInstance;
}

LRESULT __stdcall Core::Window::WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_hWindow == nullptr) return 0;
	switch (_msg)
	{
	case WM_CREATE:
	{
		AddMenu(_hWindow);
		break;
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(_hWindow, &paintSruct);

		for (Shape* _shape : shapes)
			_shape->Draw(hdc);

		EndPaint(_hWindow, &paintSruct);
		break;
	}
	case WM_DESTROY:
	{
		Close();
		break;
	}
	default:
		return DefWindowProcW(_hWindow, _msg, _wp, _lp);
	}
}

LRESULT __stdcall Core::Window::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_msg == WM_NCCREATE)
	{
		SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
}

Core::WindowMenu* Core::Window::CreateWindowMenu(const char* _name)
{
	WindowMenu* _menu = new WindowMenu(this, _name);
	menus.insert(std::pair<const char*, WindowMenu*>(_name, _menu));
	return _menu;
}

O3DLIBRAIRY_API void Core::Window::Register(Shape* _shapes)
{
	shapes.push_back(_shapes);
}

int Core::Window::MenusCount() const
{
	return menus.size();
}

void Core::Window::RegisterMenu(WindowMenu* _menu)
{
	menus.insert(std::pair<const char*, WindowMenu*>(_menu->Name(), _menu));
}

void Core::Window::Update()
{
	MSG _msg = {};
	while (isOpen)
	{
		while (PeekMessage(&_msg, windowInstance, 0, 0, PM_REMOVE))
		{
			if (!TranslateAccelerator(_msg.hwnd, nullptr, &_msg))
			{
				TranslateMessage(&_msg);
				DispatchMessage(&_msg);
			}
		}
		Gdiplus::GdiplusShutdown(gdiplusToken);
	}
}

O3DLIBRAIRY_API void Core::Window::AddMenu(HWND _hwnd)
{
	const WindowMenu* _menu = CreateWindowMenu("");
	WindowMenu* _fileMenu = CreateWindowMenu("File");
	WindowMenu* _newMenu = CreateWindowMenu("New");
	WindowMenu* _editMenu = CreateWindowMenu("Edit");
	_editMenu->CreateButonMenu("Copy");
	_newMenu->CreateButonMenu("Project");
	_fileMenu->CreatePopupMenu(_newMenu);
	_fileMenu->CreateButonMenu("Close");
	_menu->CreatePopupMenu(_fileMenu);
	_menu->CreatePopupMenu(_editMenu);
	SetMenu(_hwnd, *_menu);
}

void Core::Window::Open()
{
	if (windowInstance == nullptr)return;
	isOpen = true;
	ShowWindow(windowInstance, SW_SHOWDEFAULT);
	UpdateWindow(windowInstance);
	Update();
}

void Core::Window::Close()
{
	CloseWindow(windowInstance);
	isOpen = false;
}
