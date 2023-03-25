#include "pch.h"
#include "directinput.h"
#include <commctrl.h>

BOOL CALLBACK DlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
void OpenDialog(HINSTANCE hinst, HWND parent);
void getEditBoxContent(HWND hWndDlg, int nIDDlgItem, byte* returnVariable);
void getConfigKey(HWND hwndDlg, int nIDDlgItem, byte* returnVariable);
void setButtonLabel(HWND hwndDlg, int nIDDlgItem, byte* returnVariable);
void setEditBoxContent(HWND hwndDlg, int nIDDlgItem, byte* returnVariable);
void resetButtonLabels(HWND hwndDlg);

DIPROPHEADER diph;
DIPROPSTRING dips;

LVITEMA LvItem;
LVCOLUMNA LvColumn;