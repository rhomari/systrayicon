#include <Windows.h>
#include <stdbool.h>

HWND CreateForm();
bool CreateTrayIcon();
bool DestroyTrayIcon();
void OnMouseClickEvent(int);
HMENU createPopupMenu(HWND, char*);
extern void GoOnMouseClickEvent(int);
extern  char* GogetMenus();
extern void GoOnMenuItemClickEvent(int);