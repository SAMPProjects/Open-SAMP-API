#SingleInstance, force
#NoEnv
#include ..\..\include\AHK\SAMP_API.ahk

text_overlay :=- 1

Gui, Show, w200 h50, World functions

SetTimer, Timer, 10
return

; Delete the overlay if the application will be closed by the user
GuiClose:
if(text_overlay != -1)
	TextDestroy(text_overlay)
ExitApp

; Timer callback
Timer:
if(text_overlay == -1)
	text_overlay := TextCreate("Arial", 30, false, false, 9999, 9999, 0xFFFF0000, "X", true, true)

if(text_overlay == -1)
	return

; Draw the overlay at the farm in Redwood
SetOverlay3DPosition(text_overlay, 0, 0, 0)

return
