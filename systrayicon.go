package systrayicon

// #include "winGUI.h"
import "C"

var OnMouseClick func(lparam int)

const (
	WM_MOUSEFIRST    = 0x0200
	WM_MOUSEMOVE     = 0x0200
	WM_LBUTTONDOWN   = 0x0201
	WM_LBUTTONUP     = 0x0202
	WM_LBUTTONDBLCLK = 0x0203
	WM_RBUTTONDOWN   = 0x0204
	WM_RBUTTONUP     = 0x0205
	WM_RBUTTONDBLCLK = 0x0206
	WM_MBUTTONDOWN   = 0x0207
	WM_MBUTTONUP     = 0x0208
	WM_MBUTTONDBLCLK = 0x0209
)

func CreateSystrayIcon() {
	C.CreateForm()
}

//export GoOnMouseClickEvent
func GoOnMouseClickEvent(lparam C.int) {

	OnMouseClick(int(lparam))

}
