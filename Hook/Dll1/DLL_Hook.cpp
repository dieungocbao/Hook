// MyDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DLL_Hook.h"


LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode < 0) // không xử lý message 
		return CallNextHookEx(hHook, nCode, wParam, lParam);
	if (wParam == WM_LBUTTONDOWN && GetAsyncKeyState(VK_CONTROL) <0)
	{
		SwapMouseButton(TRUE);
		TCHAR szBuf[128];
		MOUSEHOOKSTRUCT *mHookData = (MOUSEHOOKSTRUCT *)lParam;
		wsprintf(szBuf, L"Phải trái - Trái Phải");
		MessageBox(mHookData->hwnd, szBuf, L"Thông báo", MB_OK);
		return TRUE;
	}

	return CallNextHookEx(hHook, nCode, wParam, lParam);
}

void InstallHook(HWND hWnd)
{
	if (hHook != NULL) return;

	hHook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)MouseHookProc, hinstLib, 0);
	if (hHook)
		MessageBox(hWnd, L"Setup hook successfully", L"Thông báo", MB_OK);
	else
		MessageBox(hWnd, L"Setup hook fail", L"Thông báo", MB_OK);
}

void RemoveHook(HWND hWnd)
{
	SwapMouseButton(FALSE);
	if (hHook == NULL) return;
	UnhookWindowsHookEx(hHook);
	hHook = NULL;
	MessageBox(hWnd, L"Remove hook successfully", L"Thông báo", MB_OK);
}
