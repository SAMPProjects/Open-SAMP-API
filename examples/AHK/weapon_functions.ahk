#SingleInstance, force
#NoEnv
#include ..\..\include\AHK\SAMP_API.ahk

; Set the API's parameters
SetParam("use_window", "1")
SetParam("window", "GTA:SA:MP")

; Create GUI
Gui, Show, w237 h52, SAMP weapon test
return

1::
AddChatMessage("ID: " GetPlayerWeaponID())
slot := GetPlayerWeaponSlot()
AddChatMessage("Slot " slot)
AddChatMessage("State " GetPlayerWeaponState())
AddChatMessage("Type " GetPlayerWeaponType())

if(slot != -1) {
	AddChatMessage("Clip: " GetPlayerWeaponClip(slot))
	AddChatMessage("Total-Clip: " GetPlayerWeaponTotalClip(slot))
	
	returnValue := GetPlayerWeaponName(slot, wname, 32)
	AddChatMessage("Weapon " wname " return val " returnValue)
}
return