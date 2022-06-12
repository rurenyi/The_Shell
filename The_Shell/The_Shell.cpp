// The_Shell.cpp : 定义应用程序的入口点。
//

// PE.cpp : 定义应用程序的入口点。
//

#include"framework.h"
#include"resource1.h"
#include"FilePath.h"
#include"main.h"


HINSTANCE hInstance;
HWND hdlg;
TCHAR FilePath[MAX_PATH] ;
TCHAR NewFilePath[MAX_PATH];
TCHAR TSrcPath[MAX_PATH];

char SetPath = 0;
char SetNewPath = 0;

BOOL CALLBACK MainDlgProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    BOOL bret = FALSE;

    switch (uMsg)
    {
    case WM_INITDIALOG:

        GetCurrentDirectory(MAX_PATH, TSrcPath);

        return TRUE;

        case WM_CLOSE:
        {
            EndDialog(hdlg, 0);
            break;
        }
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDC_BUTTON_Select:
                {
                    Adddetails(hdlg, FilePath);
                    SetWindowText(GetDlgItem(hdlg,IDC_FilePath),FilePath);
                    SetPath = 1;
                    break;
                }
                case IDC_BUTTON_SelectNewPath:
                {
                    Adddetails2(hdlg, NewFilePath);
                    SetWindowText(GetDlgItem(hdlg, IDC_NewFilePath), NewFilePath);
                    SetNewPath = 1;
                    break;
                }

                case OK:
                {
                    if ((SetPath == 0) || (SetNewPath == 0))
                    {
                        MessageBox(0, TEXT("Please Select All Paths"), 0, 0);
                        break;
                    }
                    THE(FilePath, NewFilePath, TSrcPath);
                    MessageBox(0, TEXT("Success!"), 0, 0);
                    EndDialog(hdlg, 0);
                    break;
                }

                case Exit:
                {
                    EndDialog(hdlg, 0);
                    return true;
                }
            }
        }
    break;
    }
    return bret;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDlgProc);

    return 1;
}