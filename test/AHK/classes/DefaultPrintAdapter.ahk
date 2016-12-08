#include PrintAdapter.ahk

class DefaultPrintAdapter extends PrintAdapter {
	print(text) {
		MsgBox, %text%
	}
}
