#SingleInstance, force
#NoEnv
#include ..\..\include\AHK\SAMP_API.ahk

text_overlay :=- 1

; Set the API's parameters
SetParam("use_window", "1")
SetParam("window", "GTA:SA:MP")

; Create GUI
Gui, Show, w237 h52, Health-Overlay

SetTimer, Timer, 50
return

; Delete the overlay if the application will be closed by the user
GuiClose:
if(text_overlay != -1)
	TextDestroy(text_overlay)
ExitApp

; Timer callback
Timer:
if(text_overlay == -1)
	text_overlay := TextCreate("Arial", 6, false, false, 720, 91, 0xFFFFFFFF, "100", true, true)

if(text_overlay == -1)
	return

health := GetPlayerHealth()

if(TextSetString(text_overlay, health) == 0)
{
	TextDestroy(text_overlay)
	text_overlay := -1
}
return
