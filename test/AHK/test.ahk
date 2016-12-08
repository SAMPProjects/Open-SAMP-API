#SingleInstance, force
#NoEnv
#IfWinActive, GTA:SA:MP 
#include ..\..\include\AHK\SAMP_API.ahk
#include classes\GamePrintAdapter.ahk

; Test cases
#include tests\SAMPFunctions.ahk
#include tests\OverlayFunctions.ahk

; Set the API's parameters
SetParam("use_window", "1")
SetParam("window", "GTA:SA:MP")

; Create GUI
Gui, Show, w250 h50, Tests
return

GuiClose:
ExitApp

; Factory for executing Tests
executeTest(class_name) {
	test := new class_name(new GamePrintAdapter())
	test.main()
	test := 0
}

1::executeTest(SAMPFunctions)
2::executeTest(OverlayFunctions)

