#include "pch.h"
#include <dinput.h>

BOOL CALLBACK DlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
void OpenDialog(HINSTANCE hinst, HWND parent);
void getEditBoxContent(HWND hWndDlg, int nIDDlgItem, byte* returnVariable);