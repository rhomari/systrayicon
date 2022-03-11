#include <windows.h>
#include "winGUI.h"
#include <stdbool.h>
#include <stdio.h>
LRESULT CALLBACK WinProc(HWND   hWnd, UINT   message, WPARAM wParam, LPARAM lParam){
   switch(message)
    {
        case WM_CREATE:
            CreateTrayIcon();
            break;
        case WM_CLOSE:
            DestroyTrayIcon();
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case  WM_USER +5  :
     
           
                    OnMouseClickEvent((int)lParam);
        break;
        case WM_SHOWWINDOW :
            ShowWindow(hWnd,1);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

HWND CreateForm(){
    WNDCLASSEX winclassex;
    HINSTANCE hModule= GetModuleHandleW(0);
    winclassex.cbSize = sizeof(winclassex);
    winclassex.style = CS_HREDRAW | CS_VREDRAW;
    winclassex.lpfnWndProc = WinProc;
    winclassex.cbClsExtra=0;
    winclassex.cbWndExtra=0;
    winclassex.hInstance = hModule;
    winclassex.hIcon = LoadIcon(winclassex.hInstance, IDI_APPLICATION);
    winclassex.hIconSm = LoadIcon(winclassex.hInstance, IDI_APPLICATION);
    winclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
    winclassex.hbrBackground =(HBRUSH)(COLOR_WINDOW+1);
    winclassex.lpszMenuName = NULL;
    winclassex.lpszClassName = "goApp";

    if (!RegisterClassEx(&winclassex)){
        

        return NULL;	   

    }
    HWND hwnd=CreateWindowEx(WS_EX_CLIENTEDGE,"goApp", "GoAPP", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT,200,200,NULL,NULL,hModule,NULL);
    if (hwnd==NULL){
        return NULL;

    }
    ShowWindow(hwnd,0);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return hwnd;

}

bool CreateTrayIcon(){
    NOTIFYICONDATAA LpData = {};
    HWND hWnd=FindWindowA("goApp","GoApp");
    LpData.cbSize = sizeof(LpData);
    LpData.hWnd=hWnd;
    LpData.uFlags = NIF_ICON | NIF_MESSAGE;
    LpData.uCallbackMessage = WM_USER + 5;
    
    LpData.hIcon = (HICON)LoadImageA(NULL,"icon.ico", IMAGE_ICON,0,0,LR_LOADFROMFILE | LR_SHARED);
    if (Shell_NotifyIcon(NIM_ADD,&LpData)){
        return true;
        
    }
    return false;
}
bool DestroyTrayIcon(){
    NOTIFYICONDATAA LpData = {};
    HWND hWnd=FindWindowA("goApp","GoApp");
 
    LpData.cbSize = sizeof(LpData);
    LpData.hWnd=hWnd;
    return Shell_NotifyIcon(NIM_DELETE, &LpData);
}
void OnMouseClickEvent(int lParam){
    GoOnMouseClickEvent(lParam);
}