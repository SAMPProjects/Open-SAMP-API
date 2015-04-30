#NoEnv 

PATH_SAMP_API := RelToAbs(A_ScriptDir, "..\..\bin\Open-SAMP-API.dll")

hModule := DllCall("LoadLibrary", Str, PATH_SAMP_API)
if(hModule == -1 || hModule == 0)
{
	MsgBox, 48, Error, The dll-file couldn't be found!
	ExitApp
}


Init_func := DllCall("GetProcAddress", UInt, hModule, Str, "Init")
SetParam_func := DllCall("GetProcAddress", UInt, hModule, Str, "SetParam")

; Overlay functions
TextCreate_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextCreate")
TextDestroy_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextDestroy")
TextSetShadow_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextSetShadow")
TextSetShown_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextSetShown")
TextSetColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextSetColor")
TextSetPos_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextSetPos")
TextSetString_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextSetString")
TextUpdate_func := DllCall("GetProcAddress", UInt, hModule, Str, "TextUpdate")

BoxCreate_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxCreate")
BoxDestroy_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxDestroy")
BoxSetShown_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetShown")
BoxSetBorder_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetBorder")
BoxSetBorderColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetBorderColor")
BoxSetColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetColor")
BoxSetHeight_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetHeight")
BoxSetPos_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetPos")
BoxSetWidth_func := DllCall("GetProcAddress", UInt, hModule, Str, "BoxSetWidth")

LineCreate_func := DllCall("GetProcAddress", UInt, hModule, Str, "LineCreate")
LineDestroy_func := DllCall("GetProcAddress", UInt, hModule, Str, "LineDestroy")
LineSetShown_func := DllCall("GetProcAddress", UInt, hModule, Str, "LineSetShown")
LineSetColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "LineSetColor")
LineSetWidth_func := DllCall("GetProcAddress", UInt, hModule, Str, "LineSetWidth")
LineSetPos_func := DllCall("GetProcAddress", UInt, hModule, Str, "LineSetPos")

ImageCreate_func := DllCall("GetProcAddress", UInt, hModule, Str, "ImageCreate")
ImageDestroy_func := DllCall("GetProcAddress", UInt, hModule, Str, "ImageDestroy")
ImageSetShown_func := DllCall("GetProcAddress", UInt, hModule, Str, "ImageSetShown")
ImageSetAlign_func := DllCall("GetProcAddress", UInt, hModule, Str, "ImageSetAlign")
ImageSetPos_func := DllCall("GetProcAddress", UInt, hModule, Str, "ImageSetPos")
ImageSetRotation_func := DllCall("GetProcAddress", UInt, hModule, Str, "ImageSetRotation")

DestroyAllVisual_func := DllCall("GetProcAddress", UInt, hModule, Str, "DestroyAllVisual")
ShowAllVisual_func := DllCall("GetProcAddress", UInt, hModule, Str, "ShowAllVisual")
HideAllVisual_func := DllCall("GetProcAddress", UInt, hModule, Str, "HideAllVisual")

GetFrameRate_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetFrameRate")
GetScreenSpecs_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetScreenSpecs")

SetCalculationRatio_func:= DllCall("GetProcAddress", UInt, hModule, Str, "SetCalculationRatio")

SetOverlayPriority_func := DllCall("GetProcAddress", UInt, hModule, Str, "SetOverlayPriority")

; SAMP functions
SendChat_func := DllCall("GetProcAddress", UInt, hModule, Str, "SendChat")
ShowGameText_func := DllCall("GetProcAddress", UInt, hModule, Str, "ShowGameText")
AddChatMessage_func := DllCall("GetProcAddress", UInt, hModule, Str, "AddChatMessage")
GetPlayerNameByID_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerNameByID")
GetPlayerIDByName_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerIDByName")

; Player functions
GetPlayerCPed_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerCPed")
GetPlayerHealth_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerHealth")
GetPlayerArmor_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerArmor")
GetPlayerMoney_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerMoney")
IsPlayerInAnyVehicle_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsPlayerInAnyVehicle")
IsPlayerDriver_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsPlayerDriver")
IsPlayerPassenger_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsPlayerPassenger")
IsPlayerInInterior_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsPlayerInInterior")
GetPlayerX_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerX")
GetPlayerY_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerY")
GetPlayerZ_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerZ")
GetPlayerPosition_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetPlayerPosition")
IsPlayerInRange2D_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsPlayerInRange2D")
IsPlayerInRange3D_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsPlayerInRange3D")

; Vehicle functions
GetVehiclePointer_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehiclePointer")
GetVehicleSpeed_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleSpeed")
GetVehicleHealth_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleHealth")
GetVehicleModelId_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleModelId")
GetVehicleModelName_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleModelName")
GetVehicleModelNameById_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleModelNameById")
GetVehicleType_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleType")
GetVehicleFreeSeats_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleFreeSeats")
GetVehicleFirstColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleFirstColor")
GetVehicleSecondColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleSecondColor")
GetVehicleColor_func := DllCall("GetProcAddress", UInt, hModule, Str, "GetVehicleColor")
IsVehicleSeatUsed_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleSeatUsed")
IsVehicleLocked_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleLocked")
IsVehicleHornEnabled_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleHornEnabled")
IsVehicleSirenEnabled_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleSirenEnabled")
IsVehicleAlternateSirenEnabled_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleAlternateSirenEnabled")
IsVehicleEngineEnabled_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleEngineEnabled")
IsVehicleLightEnabled_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleLightEnabled")
IsVehicleCar_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleCar")
IsVehiclePlane_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehiclePlane")
IsVehicleBoat_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleBoat")
IsVehicleTrain_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleTrain")
IsVehicleBike_func := DllCall("GetProcAddress", UInt, hModule, Str, "IsVehicleBike")

Init()
{
	global Init_func
	res := DllCall(Init_func)
	return res
}

SetParam(str_Name, str_Value)
{
	global SetParam_func
	res := DllCall(SetParam_func, Str, str_Name, Str, str_Value)
	return res
}

TextCreate(Font, fontsize, bold, italic, x, y, color, text, shadow, show)
{
	global TextCreate_func
	res := DllCall(TextCreate_func,Str,Font,Int,fontsize,UChar,bold,UChar,italic,Int,x,Int,y,UInt,color,Str,text,UChar,shadow,UChar,show)
	return res
}

TextDestroy(id)
{
	global TextDestroy_func
	res := DllCall(TextDestroy_func,Int,id)
	return res
}

TextSetShadow(id, shadow)
{
	global TextSetShadow_func
	res := DllCall(TextSetShadow_func,Int,id,UChar,shadow)
	return res
}

TextSetShown(id, show)
{
	global TextSetShown_func
	res := DllCall(TextSetShown_func,Int,id,UChar,show)
	return res
}

TextSetColor(id,color)
{
	global TextSetColor_func
	res := DllCall(TextSetColor_func,Int,id,UInt,color)
	return res
}

TextSetPos(id,x,y)
{
	global TextSetPos_func
	res := DllCall(TextSetPos_func,Int,id,Int,x,Int,y)
	return res
}

TextSetString(id,Text)
{
	global TextSetString_func
	res := DllCall(TextSetString_func,Int,id,Str,Text)
	return res
}

TextUpdate(id,Font,Fontsize,bold,italic)
{
	global TextUpdate_func
	res := DllCall(TextUpdate_func,Int,id,Str,Font,int,Fontsize,UChar,bold,UChar,italic)
	return res
}

BoxCreate(x,y,width,height,Color,show)
{
	global BoxCreate_func
	res := DllCall(BoxCreate_func,Int,x,Int,y,Int,width,Int,height,UInt,Color,UChar,show)
	return res
}

BoxDestroy(id)
{
	global BoxDestroy_func
	res := DllCall(BoxDestroy_func,Int,id)
	return res
}

BoxSetShown(id,Show)
{
	global BoxSetShown_func 
	res := DllCall(BoxSetShown_func,Int,id,UChar,Show)
	return res
}
	
BoxSetBorder(id,height,Show)
{
	global BoxSetBorder_func
	res := DllCall(BoxSetBorder_func,Int,id,Int,height,Int,Show)
	return res
}


BoxSetBorderColor(id,Color)
{
	global BoxSetBorderColor_func 
	res := DllCall(BoxSetBorderColor_func,Int,id,UInt,Color)
	return res
}

BoxSetColor(id,Color)
{
	global BoxSetColor_func
	res := DllCall(BoxSetColor_func,Int,id,UInt,Color)
	return res
}

BoxSetHeight(id,height)
{
	global BoxSetHeight_func
	res := DllCall(BoxSetHeight_func,Int,id,Int,height)
	return res
}

BoxSetPos(id,x,y)
{
	global BoxSetPos_func	
	res := DllCall(BoxSetPos_func,Int,id,Int,x,Int,y)
	return res
}

BoxSetWidth(id,width)
{
	global BoxSetWidth_func
	res := DllCall(BoxSetWidth_func,Int,id,Int,width)
	return res
}

LineCreate(x1,y1,x2,y2,width,color,show)
{
	global LineCreate_func
	res := DllCall(LineCreate_func,Int,x1,Int,y1,Int,x2,Int,y2,Int,Width,UInt,color,UChar,show)
	return res
}

LineDestroy(id)
{
	global LineDestroy_func
	res := DllCall(LineDestroy_func,Int,id)
	return res
}

LineSetShown(id,show)
{
	global LineSetShown_func
	res := DllCall(LineSetShown_func,Int,id,UChar,show)
	return res
}

LineSetColor(id,color)
{
	global LineSetColor_func
	res := DllCall(LineSetColor_func,Int,id,UInt,color)
	return res
}

LineSetWidth(id, width)
{
	global LineSetWidth_func
	res := DllCall(LineSetWidth_func,Int,id,Int,width)
	return res
}

LineSetPos(id,x1,y1,x2,y2)
{
	global LineSetPos_func
	res := DllCall(LineSetPos_func,Int,id,Int,x1,Int,y1,Int,x2,Int,y2)
	return res
}

ImageCreate(path, x, y, rotation, align, show)
{
	global ImageCreate_func
	res := DllCall(ImageCreate_func, Str, path, Int, x, Int, y, Int, rotation, Int, align, UChar, show)
	return res
}

ImageDestroy(id)
{
	global ImageDestroy_func
	res := DllCall(ImageDestroy_func,Int,id)
	return res
}

ImageSetShown(id,show)
{
	global ImageSetShown_func
	res := DllCall(ImageSetShown_func,Int,id,UChar,show)
	return res
}

ImageSetAlign(id,align)
{
	global ImageSetAlign_func
	res := DllCall(ImageSetAlign_func,Int,id,Int,align)
	return res
}

ImageSetPos(id, x, y)
{
	global ImageSetPos_func
	res := DllCall(ImageSetPos_func,Int,id,Int,x, Int, y)
	return res
}

ImageSetRotation(id, rotation)
{
	global ImageSetRotation_func
	res := DllCall(ImageSetRotation_func,Int,id,Int, rotation)
	return res
}

DestroyAllVisual()
{
	global DestroyAllVisual_func
	res := DllCall(DestroyAllVisual_func)
	return res 
}

ShowAllVisual()
{
	global ShowAllVisual_func
	res := DllCall(ShowAllVisual_func)
	return res
}

HideAllVisual()
{
	global HideAllVisual_func
	res := DllCall(HideAllVisual_func )
	return res
}

GetFrameRate()
{
	global GetFrameRate_func
	res := DllCall(GetFrameRate_func )
	return res
}

GetScreenSpecs(ByRef width, ByRef height)
{
	global GetScreenSpecs_func
	res := DllCall(GetScreenSpecs_func, IntP, width, IntP, height)
	return res
}

SetCalculationRatio(width, height)
{
	global SetCalculationRatio_func
	res := DllCall(SetCalculationRatio_func, Int, width, Int, height)
	return res
}

SetOverlayPriority(id, priority)
{
	global SetOverlayPriority_func
	res := DllCall(SetOverlayPriority_func, Int, id, Int, priority)
	return res
}

SendChat(msg)
{
	global SendChat_func
	res := DllCall(SendChat_func, Str, msg)
	return res
}

ShowGameText(msg, time, style)
{
	global ShowGameText_func
	res := DllCall(ShowGameText_func, Str, msg, Int, time, Int, style)
	return res
}

AddChatMessage(msg)
{
	global AddChatMessage_func
	res := DllCall(AddChatMessage_func, Str, msg)
	return res
}

GetPlayerNameByID(id, ByRef name)
{
	global GetPlayerNameByID_func
	VarSetCapacity(name, 32, 0)
	res := DllCall(GetPlayerNameByID_func, Int, id, StrP, name)
	return res
}

GetPlayerIDByName(name)
{
	global GetPlayerIDByName_func
	res := DllCall(GetPlayerIDByName_func, Str, name)
	return res
}

GetPlayerCPed()
{
	global GetPlayerCPed_func
	res := DllCall(GetPlayerCPed_func)
	return res
}

GetPlayerHealth()
{
	global GetPlayerHealth_func
	res := DllCall(GetPlayerHealth_func)
	return res
}

GetPlayerArmor()
{
	global GetPlayerArmor_func
	res := DllCall(GetPlayerArmor_func)
	return res
}

GetPlayerMoney()
{
	global GetPlayerMoney_func
	res := DllCall(GetPlayerMoney_func)
	return res
}

IsPlayerInAnyVehicle()
{
	global IsPlayerInAnyVehicle_func
	res := DllCall(IsPlayerInAnyVehicle_func)
	return res
}

IsPlayerDriver()
{
	global IsPlayerDriver_func
	res := DllCall(IsPlayerDriver_func)
	return res
}

IsPlayerPassenger()
{
	global IsPlayerPassenger_func
	res := DllCall(IsPlayerPassenger_func)
	return res
}

IsPlayerInInterior()
{
	global IsPlayerInInterior_func
	res := DllCall(IsPlayerInInterior_func)
	return res
}

GetPlayerX(ByRef posX)
{
	global GetPlayerX_func
	res := DllCall(GetPlayerX_func, FloatP, posX)
	return res
}

GetPlayerY(ByRef posY)
{
	global GetPlayerY_func
	res := DllCall(GetPlayerY_func, FloatP, posY)
	return res
}

GetPlayerZ(ByRef posZ)
{
	global GetPlayerZ_func
	res := DllCall(GetPlayerZ_func, FloatP, posZ)
	return res
}

GetPlayerZ(ByRef posZ)
{
	global GetPlayerZ_func
	res := DllCall(GetPlayerZ_func, FloatP, posZ)
	return res
}

GetPlayerPosition(ByRef posX, ByRef posY, ByRef posZ)
{
	global GetPlayerPosition_func
	res := DllCall(GetPlayerPosition_func, FloatP, posX, FloatP, posY, FloatP, posZ)
	return res
}

IsPlayerInRange2D(posX, posY, radius)
{
	global IsPlayerInRange2D_func
	res := DllCall(ShowGameText_func, Float, posX, Float, posY, Float, radius)
	return res
}

IsPlayerInRange3D(posX, posY, posZ, radius)
{
	global IsPlayerInRange3D_func
	res := DllCall(ShowGameText_func, Float, posX, Float, posY, Float, posZ, Float, radius)
	return res
}

GetVehiclePointer()
{
	global GetVehiclePointer_func
	res := DllCall(GetVehiclePointer_func)
	return res
}

GetVehicleSpeed(factor)
{
	global GetVehicleSpeed_func
	res := DllCall(GetVehicleSpeed_func, Float, factor)
	return res
}

GetVehicleHealth()
{
	global GetVehicleHealth_func
	res := DllCall(GetVehicleHealth_func)
	return res
}

GetVehicleModelId()
{
	global GetVehicleModelId_func
	res := DllCall(GetVehicleModelId_func)
	return res
}

GetVehicleModelName(ByRef name, len)
{
	global GetVehicleModelName_func
	VarSetCapacity(name, 32, 0)
	res := DllCall(GetVehicleModelName_func, StrP, name, Int, len)
	return res
}

GetVehicleModelNameById(vehicleID, ByRef name, len)
{
	global GetVehicleModelNameById_func
	VarSetCapacity(name, 32, 0)
	res := DllCall(GetVehicleModelNameById_func, Int, vehicleId, StrP, name, Int, len)
	return res
}

GetVehicleType()
{
	global GetVehicleType_func
	res := DllCall(GetVehicleType_func)
	return res
}

GetVehicleFreeSeats(ByRef seatFL, ByRef seatFR, ByRef seatRL, ByRef seatRR)
{
	global GetVehicleFreeSeats_func
	res := DllCall(GetVehicleFreeSeats_func, IntP, seatFL IntP, seatFR IntP, seatRL IntP, seatRR)
	return res
}

GetVehicleFirstColor()
{
	global GetVehicleFirstColor_func
	res := DllCall(GetVehicleFirstColor_func)
	return res
}

GetVehicleSecondColor()
{
	global GetVehicleSecondColor_func
	res := DllCall(GetVehicleSecondColor_func)
	return res
}

GetVehicleColor(ByRef color1, ByRef color2)
{
	global GetVehicleColor_func
	res := DllCall(GetVehicleColor_func, IntP, color1, IntP, color2)
	return res
}

IsVehicleSeatUsed(seat)
{
	global IsVehicleSeatUsed_func
	res := DllCall(IsVehicleSeatUsed_func, Int, seat)
	return res
}

IsVehicleLocked()
{
	global IsVehicleLocked_func
	res := DllCall(IsVehicleLocked_func)
	return res
}

IsVehicleHornEnabled()
{
	global IsVehicleHornEnabled_func
	res := DllCall(IsVehicleHornEnabled_func)
	return res
}

IsVehicleSirenEnabled()
{
	global IsVehicleSirenEnabled_func
	res := DllCall(IsVehicleSirenEnabled_func)
	return res
}

IsVehicleAlternateSirenEnabled()
{
	global IsVehicleAlternateSirenEnabled_func
	res := DllCall(IsVehicleAlternateSirenEnabled_func)
	return res
}

IsVehicleEngineEnabled()
{
	global IsVehicleEngineEnabled_func
	res := DllCall(IsVehicleEngineEnabled_func)
	return res
}

IsVehicleLightEnabled()
{
	global IsVehicleLightEnabled_func
	res := DllCall(IsVehicleLightEnabled_func)
	return res
}

IsVehicleCar()
{
	global IsVehicleCar_func
	res := DllCall(IsVehicleCar_func)
	return res
}

IsVehiclePlane()
{
	global IsVehiclePlane_func
	res := DllCall(IsVehiclePlane_func)
	return res
}

IsVehicleBoat()
{
	global IsVehicleBoat_func
	res := DllCall(IsVehicleBoat_func)
	return res
}

IsVehicleTrain()
{
	global IsVehicleTrain_func
	res := DllCall(IsVehicleTrain_func)
	return res
}

IsVehicleBike()
{
	global IsVehicleBike_func
	res := DllCall(IsVehicleBike_func)
	return res
}

RelToAbs(root, dir, s = "\") {
	pr := SubStr(root, 1, len := InStr(root, s, "", InStr(root, s . s) + 2) - 1)
		, root := SubStr(root, len + 1), sk := 0
	If InStr(root, s, "", 0) = StrLen(root)
		StringTrimRight, root, root, 1
	If InStr(dir, s, "", 0) = StrLen(dir)
		StringTrimRight, dir, dir, 1
	Loop, Parse, dir, %s%
	{
		If A_LoopField = ..
			StringLeft, root, root, InStr(root, s, "", 0) - 1
		Else If A_LoopField =
			root =
		Else If A_LoopField != .
			Continue
		StringReplace, dir, dir, %A_LoopField%%s%
	}
	Return, pr . root . s . dir
}
