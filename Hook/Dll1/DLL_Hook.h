#pragma once
#include "stdafx.h"
#include <Windowsx.h>
#ifdef HOOKDLL_EXPORTS
#define HOOKDLL_API __declspec(dllexport) 
#else
#define HOOKDLL_API __declspec(dllimport) 
#endif

HHOOK hHook = NULL;
HINSTANCE hinstLib;

HOOKDLL_API LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
HOOKDLL_API void InstallHook(HWND hWnd);
HOOKDLL_API void RemoveHook(HWND hWnd);
