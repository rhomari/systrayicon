#include <Windows.h>
#include <stdbool.h>

HWND CreateForm();
bool CreateTrayIcon();
bool DestroyTrayIcon();
void OnMouseClickEvent(int);
extern void GoOnMouseClickEvent(int);