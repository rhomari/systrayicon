package main

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"systrayicon/systrayicon"
)

func main() {
	systrayicon.OnMouseClick = func(lparm int) {
		switch lparm {
		case systrayicon.WM_LBUTTONUP:
			fmt.Println("Left mouse button click")
			break
		case systrayicon.WM_RBUTTONUP:

			break

		}
	}

	systrayicon.AddMenuItem(1, "Open Calc")
	systrayicon.AddMenuItem(2, "Navigate to google.com")
	systrayicon.AddMenuItem(3, "Exit application")
	systrayicon.BuildPopupMenu()
	systrayicon.OnMenuItemClick = MenuItemClickHanlder
	systrayicon.CreateSystrayIcon()

}
func MenuItemClickHanlder(menuitemid int) {
	switch menuitemid {
	case 1:
		err := exec.Command("calc").Run()

		if err != nil {
			log.Println(err.Error())
		}
		break
	case 2:
		err := exec.Command("cmd", "/C", "start", "www.google.com").Run()

		if err != nil {
			log.Println(err.Error())
		}
		break
	case 3:
		fmt.Printf("Exiting App")
		os.Exit(0)
		break

	}
}
