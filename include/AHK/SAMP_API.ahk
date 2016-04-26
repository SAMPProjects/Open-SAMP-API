#NoEnv 

PATH_SAMP_API := PathCombine(A_ScriptDir, "..\..\bin\Open-SAMP-API.dll")

hModule := DllCall("LoadLibrary", Str, PATH_SAMP_API)
if(hModule == -1 || hModule == 0)
{
	MsgBox, 48, Error, The dll-file couldn't be found!
	ExitApp
}

;Client.hpp
Init_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "Init")
SetParam_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "SetParam")

;GTAFunctions.hpp
GetGTACommandLine_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetGTACommandLine")
IsMenuOpen_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsMenuOpen")
ScreenToWorld_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ScreenToWorld")
WorldToScreen_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "WorldToScreen")

;PlayerFunctions.hpp
GetPlayerCPed_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerCPed")
GetPlayerHealth_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerHealth")
GetPlayerArmor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerArmor")
GetPlayerMoney_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerMoney")
GetPlayerSkinID_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerSkinID")
IsPlayerInAnyVehicle_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsPlayerInAnyVehicle")
IsPlayerDriver_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsPlayerDriver")
IsPlayerPassenger_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsPlayerPassenger")
IsPlayerInInterior_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsPlayerInInterior")
GetPlayerX_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerX")
GetPlayerY_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerY")
GetPlayerZ_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerZ")
GetPlayerPosition_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerPosition")
IsPlayerInRange2D_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsPlayerInRange2D")
IsPlayerInRange3D_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsPlayerInRange3D")
GetCityName_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetCityName")
GetZoneName_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetZoneName")

;RenderFunctions.hpp
TextCreate_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextCreate")
TextDestroy_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextDestroy")
TextSetShadow_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextSetShadow")
TextSetShown_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextSetShown")
TextSetColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextSetColor")
TextSetPos_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextSetPos")
TextSetString_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextSetString")
TextUpdate_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "TextUpdate")
BoxCreate_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxCreate")
BoxDestroy_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxDestroy")
BoxSetShown_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetShown")
BoxSetBorder_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetBorder")
BoxSetBorderColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetBorderColor")
BoxSetColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetColor")
BoxSetHeight_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetHeight")
BoxSetPos_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetPos")
BoxSetWidth_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "BoxSetWidth")
LineCreate_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "LineCreate")
LineDestroy_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "LineDestroy")
LineSetShown_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "LineSetShown")
LineSetColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "LineSetColor")
LineSetWidth_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "LineSetWidth")
LineSetPos_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "LineSetPos")
ImageCreate_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ImageCreate")
ImageDestroy_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ImageDestroy")
ImageSetShown_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ImageSetShown")
ImageSetAlign_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ImageSetAlign")
ImageSetPos_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ImageSetPos")
ImageSetRotation_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ImageSetRotation")
DestroyAllVisual_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "DestroyAllVisual")
ShowAllVisual_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ShowAllVisual")
HideAllVisual_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "HideAllVisual")
GetFrameRate_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetFrameRate")
GetScreenSpecs_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetScreenSpecs")
SetCalculationRatio_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "SetCalculationRatio")
SetOverlayPriority_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "SetOverlayPriority")
SetOverlayCalculationEnabled_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "SetOverlayCalculationEnabled")

;SAMPFunctions.hpp
SendChat_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "SendChat")
ShowGameText_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "ShowGameText")
AddChatMessage_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "AddChatMessage")
GetPlayerNameByID_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerNameByID")
GetPlayerIDByName_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerIDByName")
GetPlayerName_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerName")
GetPlayerId_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerId")
IsChatOpen_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsChatOpen")
IsDialogOpen_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsDialogOpen")

;VehicleFunctions.hpp
GetVehiclePointer_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehiclePointer")
GetVehicleSpeed_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleSpeed")
GetVehicleHealth_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleHealth")
GetVehicleModelId_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleModelId")
GetVehicleModelName_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleModelName")
GetVehicleModelNameById_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleModelNameById")
GetVehicleType_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleType")
GetVehicleFreeSeats_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleFreeSeats")
GetVehicleFirstColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleFirstColor")
GetVehicleSecondColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleSecondColor")
GetVehicleColor_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetVehicleColor")
IsVehicleSeatUsed_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleSeatUsed")
IsVehicleLocked_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleLocked")
IsVehicleHornEnabled_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleHornEnabled")
IsVehicleSirenEnabled_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleSirenEnabled")
IsVehicleAlternateSirenEnabled_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleAlternateSirenEnabled")
IsVehicleEngineEnabled_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleEngineEnabled")
IsVehicleLightEnabled_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleLightEnabled")
IsVehicleCar_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleCar")
IsVehiclePlane_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehiclePlane")
IsVehicleBoat_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleBoat")
IsVehicleTrain_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleTrain")
IsVehicleBike_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "IsVehicleBike")

;WeaponFunctions.hpp
GetPlayerWeaponID_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponID")
GetPlayerWeaponType_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponType")
GetPlayerWeaponSlot_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponSlot")
GetPlayerWeaponName_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponName")
GetPlayerWeaponClip_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponClip")
GetPlayerWeaponTotalClip_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponTotalClip")
GetPlayerWeaponState_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponState")
GetPlayerWeaponAmmo_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponAmmo")
GetPlayerWeaponAmmoInClip_func := DllCall("GetProcAddress", "UInt", hModule, "Str", "GetPlayerWeaponAmmoInClip")

Init()
{
	global Init_func
	return DllCall(Init_func)
}

SetParam(_szParamName, _szParamValue)
{
	global SetParam_func
	return DllCall(SetParam_func, "Str", _szParamName, "Str", _szParamValue)
}

GetGTACommandLine(ByRef line, max_len)
{
	global GetGTACommandLine_func
	VarSetCapacity(line, max_len, 0)
	return DllCall(GetGTACommandLine_func, "StrP", line, "Int", max_len)
}

IsMenuOpen()
{
	global IsMenuOpen_func
	return DllCall(IsMenuOpen_func)
}

ScreenToWorld(x, y, ByRef worldX, ByRef worldY, ByRef worldZ)
{
	global ScreenToWorld_func
	return DllCall(ScreenToWorld_func, "Float", x, "Float", y, "FloatP", worldX, "FloatP", worldY, "FloatP", worldZ)
}

WorldToScreen(x, y, z, ByRef screenX, ByRef screenY)
{
	global WorldToScreen_func
	return DllCall(WorldToScreen_func, "Float", x, "Float", y, "Float", z, "FloatP", screenX, "FloatP", screenY)
}

GetPlayerCPed()
{
	global GetPlayerCPed_func
	return DllCall(GetPlayerCPed_func)
}

GetPlayerHealth()
{
	global GetPlayerHealth_func
	return DllCall(GetPlayerHealth_func)
}

GetPlayerArmor()
{
	global GetPlayerArmor_func
	return DllCall(GetPlayerArmor_func)
}

GetPlayerMoney()
{
	global GetPlayerMoney_func
	return DllCall(GetPlayerMoney_func)
}

GetPlayerSkinID()
{
	global GetPlayerSkinID_func
	return DllCall(GetPlayerSkinID_func)
}

IsPlayerInAnyVehicle()
{
	global IsPlayerInAnyVehicle_func
	return DllCall(IsPlayerInAnyVehicle_func)
}

IsPlayerDriver()
{
	global IsPlayerDriver_func
	return DllCall(IsPlayerDriver_func)
}

IsPlayerPassenger()
{
	global IsPlayerPassenger_func
	return DllCall(IsPlayerPassenger_func)
}

IsPlayerInInterior()
{
	global IsPlayerInInterior_func
	return DllCall(IsPlayerInInterior_func)
}

GetPlayerX(ByRef posX)
{
	global GetPlayerX_func
	return DllCall(GetPlayerX_func, "FloatP", posX)
}

GetPlayerY(ByRef posY)
{
	global GetPlayerY_func
	return DllCall(GetPlayerY_func, "FloatP", posY)
}

GetPlayerZ(ByRef posZ)
{
	global GetPlayerZ_func
	return DllCall(GetPlayerZ_func, "FloatP", posZ)
}

GetPlayerPosition(ByRef posX, ByRef posY, ByRef posZ)
{
	global GetPlayerPosition_func
	return DllCall(GetPlayerPosition_func, "FloatP", posX, "FloatP", posY, "FloatP", posZ)
}

IsPlayerInRange2D(posX, posY, radius)
{
	global IsPlayerInRange2D_func
	return DllCall(IsPlayerInRange2D_func, "Float", posX, "Float", posY, "Float", radius)
}

IsPlayerInRange3D(posX, posY, posZ, radius)
{
	global IsPlayerInRange3D_func
	return DllCall(IsPlayerInRange3D_func, "Float", posX, "Float", posY, "Float", posZ, "Float", radius)
}

GetCityName(ByRef cityName, max_len)
{
	global GetCityName_func
	VarSetCapacity(cityName, max_len, 0)
	return DllCall(GetCityName_func, "StrP", cityName, "Int", max_len)
}

GetZoneName(ByRef zoneName, max_len)
{
	global GetZoneName_func
	VarSetCapacity(zoneName, max_len, 0)
	return DllCall(GetZoneName_func, "StrP", zoneName, "Int", max_len)
}

TextCreate(Font, FontSize, bBold, bItalic, x, y, color, text, bShadow, bShow)
{
	global TextCreate_func
	return DllCall(TextCreate_func, "Str", Font, "Int", FontSize, "UChar", bBold, "UChar", bItalic, "Int", x, "Int", y, "UInt", color, "Str", text, "UChar", bShadow, "UChar", bShow)
}

TextDestroy(ID)
{
	global TextDestroy_func
	return DllCall(TextDestroy_func, "Int", ID)
}

TextSetShadow(id, b)
{
	global TextSetShadow_func
	return DllCall(TextSetShadow_func, "Int", id, "UChar", b)
}

TextSetShown(id, b)
{
	global TextSetShown_func
	return DllCall(TextSetShown_func, "Int", id, "UChar", b)
}

TextSetColor(id, color)
{
	global TextSetColor_func
	return DllCall(TextSetColor_func, "Int", id, "UInt", color)
}

TextSetPos(id, x, y)
{
	global TextSetPos_func
	return DllCall(TextSetPos_func, "Int", id, "Int", x, "Int", y)
}

TextSetString(id, str)
{
	global TextSetString_func
	return DllCall(TextSetString_func, "Int", id, "Str", str)
}

TextUpdate(id, Font, FontSize, bBold, bItalic)
{
	global TextUpdate_func
	return DllCall(TextUpdate_func, "Int", id, "Str", Font, "Int", FontSize, "UChar", bBold, "UChar", bItalic)
}

BoxCreate(x, y, w, h, dwColor, bShow)
{
	global BoxCreate_func
	return DllCall(BoxCreate_func, "Int", x, "Int", y, "Int", w, "Int", h, "UInt", dwColor, "UChar", bShow)
}

BoxDestroy(id)
{
	global BoxDestroy_func
	return DllCall(BoxDestroy_func, "Int", id)
}

BoxSetShown(id, bShown)
{
	global BoxSetShown_func
	return DllCall(BoxSetShown_func, "Int", id, "UChar", bShown)
}

BoxSetBorder(id, height, bShown)
{
	global BoxSetBorder_func
	return DllCall(BoxSetBorder_func, "Int", id, "Int", height, "UChar", bShown)
}

BoxSetBorderColor(id, dwColor)
{
	global BoxSetBorderColor_func
	return DllCall(BoxSetBorderColor_func, "Int", id, "UInt", dwColor)
}

BoxSetColor(id, dwColor)
{
	global BoxSetColor_func
	return DllCall(BoxSetColor_func, "Int", id, "UInt", dwColor)
}

BoxSetHeight(id, height)
{
	global BoxSetHeight_func
	return DllCall(BoxSetHeight_func, "Int", id, "Int", height)
}

BoxSetPos(id, x, y)
{
	global BoxSetPos_func
	return DllCall(BoxSetPos_func, "Int", id, "Int", x, "Int", y)
}

BoxSetWidth(id, width)
{
	global BoxSetWidth_func
	return DllCall(BoxSetWidth_func, "Int", id, "Int", width)
}

LineCreate(x1, y1, x2, y2, width, color, bShow)
{
	global LineCreate_func
	return DllCall(LineCreate_func, "Int", x1, "Int", y1, "Int", x2, "Int", y2, "Int", width, "UInt", color, "UChar", bShow)
}

LineDestroy(id)
{
	global LineDestroy_func
	return DllCall(LineDestroy_func, "Int", id)
}

LineSetShown(id, bShown)
{
	global LineSetShown_func
	return DllCall(LineSetShown_func, "Int", id, "UChar", bShown)
}

LineSetColor(id, color)
{
	global LineSetColor_func
	return DllCall(LineSetColor_func, "Int", id, "UInt", color)
}

LineSetWidth(id, width)
{
	global LineSetWidth_func
	return DllCall(LineSetWidth_func, "Int", id, "Int", width)
}

LineSetPos(id, x1, y1, x2, y2)
{
	global LineSetPos_func
	return DllCall(LineSetPos_func, "Int", id, "Int", x1, "Int", y1, "Int", x2, "Int", y2)
}

ImageCreate(path, x, y, rotation, align, bShow)
{
	global ImageCreate_func
	return DllCall(ImageCreate_func, "Str", path, "Int", x, "Int", y, "Int", rotation, "Int", align, "UChar", bShow)
}

ImageDestroy(id)
{
	global ImageDestroy_func
	return DllCall(ImageDestroy_func, "Int", id)
}

ImageSetShown(id, bShown)
{
	global ImageSetShown_func
	return DllCall(ImageSetShown_func, "Int", id, "UChar", bShown)
}

ImageSetAlign(id, align)
{
	global ImageSetAlign_func
	return DllCall(ImageSetAlign_func, "Int", id, "Int", align)
}

ImageSetPos(id, x, y)
{
	global ImageSetPos_func
	return DllCall(ImageSetPos_func, "Int", id, "Int", x, "Int", y)
}

ImageSetRotation(id, rotation)
{
	global ImageSetRotation_func
	return DllCall(ImageSetRotation_func, "Int", id, "Int", rotation)
}

DestroyAllVisual()
{
	global DestroyAllVisual_func
	return DllCall(DestroyAllVisual_func)
}

ShowAllVisual()
{
	global ShowAllVisual_func
	return DllCall(ShowAllVisual_func)
}

HideAllVisual()
{
	global HideAllVisual_func
	return DllCall(HideAllVisual_func)
}

GetFrameRate()
{
	global GetFrameRate_func
	return DllCall(GetFrameRate_func)
}

GetScreenSpecs(ByRef width, ByRef height)
{
	global GetScreenSpecs_func
	return DllCall(GetScreenSpecs_func, "IntP", width, "IntP", height)
}

SetCalculationRatio(width, height)
{
	global SetCalculationRatio_func
	return DllCall(SetCalculationRatio_func, "Int", width, "Int", height)
}

SetOverlayPriority(id, priority)
{
	global SetOverlayPriority_func
	return DllCall(SetOverlayPriority_func, "Int", id, "Int", priority)
}

SetOverlayCalculationEnabled(id, enabled)
{
	global SetOverlayCalculationEnabled_func
	return DllCall(SetOverlayCalculationEnabled_func, "Int", id, "UChar", enabled)
}

SendChat(msg)
{
	global SendChat_func
	return DllCall(SendChat_func, "Str", msg)
}

ShowGameText(msg, time, style)
{
	global ShowGameText_func
	return DllCall(ShowGameText_func, "Str", msg, "Int", time, "Int", style)
}

AddChatMessage(msg)
{
	global AddChatMessage_func
	return DllCall(AddChatMessage_func, "Str", msg)
}

GetPlayerNameByID(id, ByRef playername, max_len)
{
	global GetPlayerNameByID_func
	VarSetCapacity(playername, max_len, 0)
	return DllCall(GetPlayerNameByID_func, "Int", id, "StrP", playername, "Int", max_len)
}

GetPlayerIDByName(name)
{
	global GetPlayerIDByName_func
	return DllCall(GetPlayerIDByName_func, "Str", name)
}

GetPlayerName(ByRef playername, max_len)
{
	global GetPlayerName_func
	VarSetCapacity(playername, max_len, 0)
	return DllCall(GetPlayerName_func, "StrP", playername, "Int", max_len)
}

GetPlayerId()
{
	global GetPlayerId_func
	return DllCall(GetPlayerId_func)
}

IsChatOpen()
{
	global IsChatOpen_func
	return DllCall(IsChatOpen_func)
}

IsDialogOpen()
{
	global IsDialogOpen_func
	return DllCall(IsDialogOpen_func)
}

GetVehiclePointer()
{
	global GetVehiclePointer_func
	return DllCall(GetVehiclePointer_func)
}

GetVehicleSpeed(factor)
{
	global GetVehicleSpeed_func
	return DllCall(GetVehicleSpeed_func, "Float", factor)
}

GetVehicleHealth()
{
	global GetVehicleHealth_func
	return DllCall(GetVehicleHealth_func, "Cdecl float")
}

GetVehicleModelId()
{
	global GetVehicleModelId_func
	return DllCall(GetVehicleModelId_func)
}

GetVehicleModelName(ByRef name, max_len)
{
	global GetVehicleModelName_func
	VarSetCapacity(name, max_len, 0)
	return DllCall(GetVehicleModelName_func, "StrP", name, "Int", max_len)
}

GetVehicleModelNameById(vehicleID, ByRef name, max_len)
{
	global GetVehicleModelNameById_func
	VarSetCapacity(name, max_len, 0)
	return DllCall(GetVehicleModelNameById_func, "Int", vehicleID, "StrP", name, "Int", max_len)
}

GetVehicleType()
{
	global GetVehicleType_func
	return DllCall(GetVehicleType_func)
}

GetVehicleFreeSeats(ByRef seatFL, ByRef seatFR, ByRef seatRL, ByRef seatRR)
{
	global GetVehicleFreeSeats_func
	return DllCall(GetVehicleFreeSeats_func, "IntP", seatFL, "IntP", seatFR, "IntP", seatRL, "IntP", seatRR)
}

GetVehicleFirstColor()
{
	global GetVehicleFirstColor_func
	return DllCall(GetVehicleFirstColor_func)
}

GetVehicleSecondColor()
{
	global GetVehicleSecondColor_func
	return DllCall(GetVehicleSecondColor_func)
}

GetVehicleColor(ByRef color1, ByRef color2)
{
	global GetVehicleColor_func
	return DllCall(GetVehicleColor_func, "IntP", color1, "IntP", color2)
}

IsVehicleSeatUsed(seat)
{
	global IsVehicleSeatUsed_func
	return DllCall(IsVehicleSeatUsed_func, "Int", seat)
}

IsVehicleLocked()
{
	global IsVehicleLocked_func
	return DllCall(IsVehicleLocked_func)
}

IsVehicleHornEnabled()
{
	global IsVehicleHornEnabled_func
	return DllCall(IsVehicleHornEnabled_func)
}

IsVehicleSirenEnabled()
{
	global IsVehicleSirenEnabled_func
	return DllCall(IsVehicleSirenEnabled_func)
}

IsVehicleAlternateSirenEnabled()
{
	global IsVehicleAlternateSirenEnabled_func
	return DllCall(IsVehicleAlternateSirenEnabled_func)
}

IsVehicleEngineEnabled()
{
	global IsVehicleEngineEnabled_func
	return DllCall(IsVehicleEngineEnabled_func)
}

IsVehicleLightEnabled()
{
	global IsVehicleLightEnabled_func
	return DllCall(IsVehicleLightEnabled_func)
}

IsVehicleCar()
{
	global IsVehicleCar_func
	return DllCall(IsVehicleCar_func)
}

IsVehiclePlane()
{
	global IsVehiclePlane_func
	return DllCall(IsVehiclePlane_func)
}

IsVehicleBoat()
{
	global IsVehicleBoat_func
	return DllCall(IsVehicleBoat_func)
}

IsVehicleTrain()
{
	global IsVehicleTrain_func
	return DllCall(IsVehicleTrain_func)
}

IsVehicleBike()
{
	global IsVehicleBike_func
	return DllCall(IsVehicleBike_func)
}

GetPlayerWeaponID()
{
	global GetPlayerWeaponID_func
	return DllCall(GetPlayerWeaponID_func)
}

GetPlayerWeaponType()
{
	global GetPlayerWeaponType_func
	return DllCall(GetPlayerWeaponType_func)
}

GetPlayerWeaponSlot()
{
	global GetPlayerWeaponSlot_func
	return DllCall(GetPlayerWeaponSlot_func)
}

GetPlayerWeaponName(dwWeapSlot, ByRef _szWeapName, max_len)
{
	global GetPlayerWeaponName_func
	VarSetCapacity(_szWeapName, max_len, 0)
	return DllCall(GetPlayerWeaponName_func, "Int", dwWeapSlot, "StrP", _szWeapName, "Int", max_len)
}

GetPlayerWeaponClip(dwWeapSlot)
{
	global GetPlayerWeaponClip_func
	return DllCall(GetPlayerWeaponClip_func, "Int", dwWeapSlot)
}

GetPlayerWeaponTotalClip(dwWeapSlot)
{
	global GetPlayerWeaponTotalClip_func
	return DllCall(GetPlayerWeaponTotalClip_func, "Int", dwWeapSlot)
}

GetPlayerWeaponState()
{
	global GetPlayerWeaponState_func
	return DllCall(GetPlayerWeaponState_func)
}

GetPlayerWeaponAmmo(weaponType)
{
	global GetPlayerWeaponAmmo_func
	return DllCall(GetPlayerWeaponAmmo_func, "Int", weaponType)
}

GetPlayerWeaponAmmoInClip(weaponType)
{
	global GetPlayerWeaponAmmoInClip_func
	return DllCall(GetPlayerWeaponAmmoInClip_func, "Int", weaponType)
}


PathCombine(abs, rel) {
    VarSetCapacity(dest, (A_IsUnicode ? 2 : 1) * 260, 1) ; MAX_PATH
    DllCall("Shlwapi.dll\PathCombine", "UInt", &dest, "UInt", &abs, "UInt", &rel)
    Return, dest
}
