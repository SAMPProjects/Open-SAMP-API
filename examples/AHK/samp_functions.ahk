#SingleInstance, force
#NoEnv
#include ..\..\include\AHK\SAMP_API.ahk

; Set the API's parameters
SetParam("use_window", "1")
SetParam("window", "GTA:SA:MP")

; Create GUI
Gui, Show, w237 h52, SAMP functions test

return

GuiClose:
ExitApp

~1::
AddChatMessage("Hello world")
AddChatMessage("{ff0000}Hello {00ff00}world")
return