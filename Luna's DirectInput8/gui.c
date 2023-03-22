#include "pch.h"
#include "gui.h"
#include "resource.h"
#include "config.h"
#include <windowsx.h>

HWND hDlgItem;

BOOL CALLBACK DlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        break;

    case WM_CLOSE:
        loadConfig();
        EndDialog(hwndDlg, 0);
        break;

    case WM_COMMAND:
        switch (wParam)
        {
        case IDCANCEL:
            loadConfig();
            EndDialog(hwndDlg, 0);
            break;
        case IDOK:
            saveConfig();
            EndDialog(hwndDlg, 0);
            break;
        case IDC_RESTOREDEFAULTS:
            restoreDefaults();
            break;

        case IDC_CARDINALX:
            getEditBoxContent(hwndDlg, IDC_CARDINALX, &config.rangeCardinalX);
            break;

        case IDC_CARDINALY:
            getEditBoxContent(hwndDlg, IDC_CARDINALY, &config.rangeCardinalY);
            break;

        case IDC_DIAGONALX:
            getEditBoxContent(hwndDlg, IDC_DIAGONALX, &config.rangeDiagonalX);
            break;

        case IDC_DIAGONALY:
            getEditBoxContent(hwndDlg, IDC_DIAGONALY, &config.rangeDiagonalY);
            break;
        }

    default:
        return FALSE;
    }
    return TRUE;
}

void OpenDialog(HINSTANCE hinst, HWND parent)
{
    DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG1), parent, DlgProc);
}

void getEditBoxContent(HWND hwndDlg, int nIDDlgItem, byte* returnVariable) {
    hDlgItem = GetDlgItem(hwndDlg, nIDDlgItem);
    if (Edit_GetModify(hDlgItem)) {
        char lpch[4];
        Edit_GetText(hDlgItem, &lpch, sizeof(lpch));
        returnVariable = atoi(lpch);
    }
}