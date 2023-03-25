#include "pch.h"
#include "directinput.h"
#include <commctrl.h>

BOOL CALLBACK DlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
void OpenDialog(HINSTANCE hinst, HWND parent);
void getEditBoxContent(HWND hWndDlg, int nIDDlgItem, byte* returnVariable);
void getFloatEditBoxContent(HWND hwndDlg, int nIDDlgItem, float* returnVariable);
void getConfigKey(HWND hwndDlg, int nIDDlgItem, byte* returnVariable);
void setButtonLabel(HWND hwndDlg, int nIDDlgItem, byte* returnVariable);
void setEditBoxContent(HWND hwndDlg, int nIDDlgItem, byte* returnVariable);
void setFloatEditBoxContent(HWND hwndDlg, int nIDDlgItem, float* returnVariable);
void resetButtonLabels(HWND hwndDlg);
void setListRow(HWND hwndDlg, int Index, int Key, float multX, float multY);

DIPROPHEADER diph;
DIPROPSTRING dips;

LVITEMA LvItem;
LVCOLUMNA LvColumn;