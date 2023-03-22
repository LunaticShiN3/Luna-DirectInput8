#include "pch.h"
#include "gui.h"
#include "resource.h"
#include "config.h"
#include <windowsx.h>

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
            if (Edit_GetModify(hwndDlg)) {
                char lpch;
                Edit_GetText(hwndDlg, &lpch, 4);
                config.rangeCardinalX = atoi(lpch);
            }
            break;

        case IDC_CARDINALY:
            if (Edit_GetModify(hwndDlg)) {
                char lpch;
                Edit_GetText(hwndDlg, &lpch, 4);
                config.rangeCardinalY = atoi(lpch);
            }
            break;

        case IDC_DIAGONALX:
            if (Edit_GetModify(hwndDlg)) {
                char lpch;
                Edit_GetText(hwndDlg, &lpch, 4);
                config.rangeDiagonalX = atoi(lpch);
            }
            break;

        case IDC_DIAGONALY:
            if (Edit_GetModify(hwndDlg)) {
                char lpch;
                Edit_GetText(hwndDlg, &lpch, 4);
                config.rangeDiagonalY = atoi(lpch);
            }
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
