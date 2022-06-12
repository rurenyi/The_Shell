
#include"framework.h"
#include <ShlObj.h>


void Adddetails(HWND hwnd, TCHAR Path[]) {
    OPENFILENAME file;
    TCHAR szFileext[100] = TEXT("*.exe;*.dll;*.scr;*.drv;*.sys");
    memset(Path, 0, 256);
    memset(&file, 0, sizeof(OPENFILENAME));
    file.lStructSize = sizeof(OPENFILENAME);
    file.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    file.hwndOwner = hwnd;
    file.lpstrFilter = szFileext;
    file.lpstrFile = Path;
    file.nMaxFile = MAX_PATH;
    GetOpenFileName(&file);
//    MessageBox(0, Path, 0, 0);
}
void Adddetails2(HWND hwnd, TCHAR Path[]) {
     BROWSEINFO bInfo={0};  
     bInfo.hwndOwner=GetForegroundWindow();
     bInfo.lpszTitle=TEXT("ä¯ÀÀÎÄ¼þ¼Ð");  
     bInfo.ulFlags=BIF_RETURNONLYFSDIRS |BIF_USENEWUI|BIF_UAHINT|BIF_NONEWFOLDERBUTTON ;  
      LPITEMIDLIST lpDlist;  
     lpDlist=SHBrowseForFolder(&bInfo);  
     if (lpDlist!=NULL)
     {  
      SHGetPathFromIDList(lpDlist, Path);
//      MessageBox(0, Path, 0, 0);
     }
}