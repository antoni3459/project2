#pragma once

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <string>

class App
{
private :

	HINSTANCE  hInstance = HINSTANCE();
	HINSTANCE  hPrevInstance = HINSTANCE();
	PWSTR  pCmdLine = PWSTR();
	int nCmdShow = 10;
public:

	static TCHAR szWindowClass[]; 
	static TCHAR szTitle[]; 
	HINSTANCE hInst;
public:
	App() = default;
	~App() = default;

public:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void WINAPI Wind(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	BOOL CALLBACK WndProci(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
};

