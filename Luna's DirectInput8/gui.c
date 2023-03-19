#include "pch.h"
#include "gui.h"
#include "resource.h"

BOOL CALLBACK DlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

        // Place message cases here. 

    default:
        return FALSE;
    }

}

void OpenDialog(HINSTANCE hinst, HWND parent)
{
    DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG1), parent, DlgProc);
}
