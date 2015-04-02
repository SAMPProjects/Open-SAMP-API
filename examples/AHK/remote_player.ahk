#SingleInstance, force
#NoEnv
#include ..\..\include\AHK\SAMP_API.ahk

1::
loop, 20
{
	res:=GetPlayerNameByID(A_Index, name)
	id := GetPlayerIDByName(name) ; id MUST BE A_Index
	
	AddChatMessage("Name of ID " A_Index "(" id "): " name ", result: " res)
}
return