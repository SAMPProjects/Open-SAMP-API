#include classes\PrintAdapter.ahk

class TestBase {
	__New(printAdapter) {
		this.printAdapter := printAdapter
		this.verified := 0
		this.failed := 0
		this.sleepAmount := 0
	}

	_verified(text) {
		this.printAdapter.print("{0000ff}TEST:{ffffff} " . text . ": {00ff00}Verified")
		this.verified++
	}
	
	_failed(text) {
		this.printAdapter.print("{0000ff}TEST:{ffffff} " . text . ": {ff0000}Failed")
		this.failed++
	}

	setSleep(ms) {
		this.sleepAmount := ms
	}

	verify(func, text) {
		if(func)
			this._verified(text)
		else
			this._failed(text)
		Sleep, % this.sleepAmount
	}
	
	compare(expected, actual, text) {
		if(expected == actual)
			this._verified(text)
		else
			this._failed(text . "(" . expected . " != " . actual . ")")
		Sleep, % this.sleepAmount
	}
	
	printSummary() {
		this.printAdapter.print("{0000ff}-----------------------SUMMARY------------------------------")
		if(this.failed == 0) {
			this.printAdapter.print("Verified " . this.verified . " tests")
		} else {
			this.printAdapter.print("Failed: {ff0000}" + this.failed . "{ffffff} test(s), Verified: {00ff00}" . this.verified . "{ffffff} test(s)")
		}
		this.printAdapter.print("{0000ff}------------------------------------------------------------")
	}
	
	main() {
		this.runTest()
		this.printSummary()
	}
}
