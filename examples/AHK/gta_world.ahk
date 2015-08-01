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
if(text_overlay == -1) {
	text_overlay := TextCreate("Arial", 30, false, false, -1, -1, 0xFFFF0000, "X", true, true)
	
	; Every overlay object is rendered for a resolution of 800 x 600
	; If you want to disable this kind of calculation, you can do this via "SetOverlayCalculationEnabled"
	; We've to do this here because WorldToScreen returns the physical pixel coordinates on your screen
	SetOverlayCalculationEnabled(text_overlay, false)
}

if(text_overlay == -1)
	return

; Draw the overlay at the farm in Redwood
if(WorldToScreen(0, 0, 0, x, y)) {
	if(TextSetPos(text_overlay, x, y) == 0) {
		TextDestroy(text_overlay)
		text_overlay := -1
	}
}
return
