#include classes\PrintAdapter.ahk
#include ..\..\include\AHK\SAMP_API.ahk

class GamePrintAdapter extends PrintAdapter {
	print(text) {
		AddChatMessage(text)
	}
}
