#include classes/TestBase.ahk

class SAMPFunctions extends TestBase {
	runTest() {
		this.compare(1, AddChatMessage("Hello world"), "Add chat message")
		this.compare(1, AddChatMessage("{ff0000}Hello {00ff00}world"), "Add chat with colors")
		this.compare(1, SendChat("hello"), "send hello to chat")
		this.compare(1, SendChat("/hello"), "send command to chat")
		this.compare(1, ShowGameText("Hello world", 1000, 3), "show gametext")
	}
}
