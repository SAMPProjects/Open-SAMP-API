#include classes/TestBase.ahk

class OverlayFunctions extends TestBase {
	runTest() {
		this.setSleep(2000)
		this.compare(1, DestroyAllVisual(), "Destroy all visuals")
		
		this.runTextTests()
		this.runBoxTests()
	}
	
	__Delete() {
		if(this.text != -1)
			TextDestroy(this.text)
		
		if(this.box != -1)
			BoxDestroy(this.box)
	}
	
	runTextTests() {
		this.text := TextCreate("Arial", 6, false, false, 720, 91, 0xFFFFFFFF, "100", true, true)
		this.verify(this.text != -1, "Create a text")
		this.compare(1, TextSetShadow(this.text, true), "Set text shadow to true")
		this.compare(1, TextSetShadow(this.text, false), "Set text shadow to false")
		this.compare(1, TextSetShown(this.text, false), "Set text shown to false")
		this.compare(1, TextSetShown(this.text, true), "Set text shown to true")
		this.compare(1, TextSetColor(this.text, 0xFFFF0000), "Set text color to red")
		this.compare(1, TextSetPos(this.text, 200, 200), "Set text position to (200|200)")
		this.compare(1, TextSetString(this.text, "test"), "Set string to test")
		this.compare(1, TextUpdate(this.text, "Arial", 30, true, true), "Update text")
		if(TextDestroy(this.text))
			this.text := -1

		this.compare(-1, this.text, "Destroyed the text")
	}
	
	runBoxTests() {
		this.box := BoxCreate(200, 200, 200, 200, 0xFFFF0000, true)
		this.verify(this.box != -1, "Create a box")
		
		this.compare(1, BoxSetShown(this.box, false), "Set box shown to false")
		this.compare(1, BoxSetShown(this.box, true), "Set box shown to true")
		this.compare(1, BoxSetBorder(this.box, 5, true), "Enable box border")
		this.compare(1, BoxSetBorderColor(this.box, 0xFF00FF00), "Set box border color to green")
		this.compare(1, BoxSetBorder(this.box, 5, false), "Disable box border")
		this.compare(1, BoxSetColor(this.box, 0xFF0000FF), "Set box color to blue")
		this.compare(1, BoxSetHeight(this.box, 300), "Set box height to 300")
		this.compare(1, BoxSetPos(this.box, 400, 400), "Set box position to (400|400)")
		this.compare(1, BoxSetWidth(this.box, 300), "Set box with to 300")
		if(BoxDestroy(this.box))
			this.box := -1
		
		this.compare(-1, this.box, "Destroyed the box")
	}
}
