#include "Window.h"
#include "WindowMenu.h"
#include "Shape.h"
#include <Windows.h>
#include <gdiplus.h>
#include <iostream>
#include <string>

#define IDM_ELLIPSE    1100
#define IDM_RECTANGLE  1200
#define IDM_ROUNDRECT  1300

Core::Window::Window(const std::string& _name, const int _width, const int _height)
{
	name = _name;
	width = _width;
	height = _height;

	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
	
	// toute cette partie permet d'initialiser la fenêtre 
	const LPCWSTR _className = L"Default Window";
	HINSTANCE _instance = HINSTANCE();
	WNDCLASS _wnclass = {};
	_wnclass.lpszClassName = _className;
	_wnclass.hInstance = _instance;
	_wnclass.cbClsExtra = 0;
	_wnclass.style = CS_HREDRAW | CS_VREDRAW;
	_wnclass.lpfnWndProc = WindowProc_Internal;
	_wnclass.hbrBackground = CreateSolidBrush(RGB(0, 0, 250)); // regle la couleur 
	_wnclass.hCursor = LoadCursor(_instance, IDC_HAND);
	RegisterClass(&_wnclass);

	//cette partie la permet de faire apparaitre la fenêtre 
	std::wstring _wName = std::wstring(_name.begin(), _name.end());
	windowInstance = CreateWindowEx(0, _className, _wName.c_str(),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZE, CW_USEDEFAULT, CW_USEDEFAULT,
		width, height, nullptr, nullptr, _instance, this);

	SetWindowTextA(windowInstance, _name.c_str());// ça permet d'afficher le nom de la fenêtre 
}

Core::Window::~Window() // il clear le menu
{
	for (std::pair<std::string, WindowMenu*> _p : menus)
		delete _p.second;
	menus.clear();
}

LRESULT _stdcall Core::Window::WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)//cette fonction permet d'initialiser les sous menu 
{
	if (_hWindow == nullptr) return 0;
	switch (_msg)// le switch permet d'initialiser les sous menu 
	{
	case WM_CREATE:
	{
		AddMenu(_hWindow);
		break;
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(_hWindow, &paintStruct);

		for (Shape* _shape : shapes)
			_shape->Draw(hdc);

		EndPaint(_hWindow, &paintStruct);
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

LRESULT __stdcall Core::Window::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)// il permet notament a définir WNDCLASS (a chercher plus tard 
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
	menus.insert(std::pair<std::string, WindowMenu*>(_name, _menu));
	return _menu;
}

 void Core::Window::Register(Shape* _shapes)
{
	shapes.push_back(_shapes);
}

int Core::Window::MenusCount() const
{
	return menus.size();
}

void Core::Window::RegisterMenu(WindowMenu* _menu)
{
	menus.insert(std::pair<std::string, WindowMenu*>(_menu->Name(), _menu));
}

void Core::Window::Update()// il permet d'ajpiter ou enlever les différente chose qu'on choisi 
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
	}
	Gdiplus::GdiplusShutdown(gdiplusToken);
}

void Core::Window::AddMenu(HWND _hwnd)
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
