# Form/Window View - Generated Source Code File 
# Generated by the Ring 1.4.1 Form Designer
# Date : 07/08/2017
# Time : 23:20:09

Load "stdlib.ring"
Load "guilib.ring"

import System.GUI

if IsMainSourceFile() { 
	new App {
		StyleFusion()
		new windowflagsView { win.show() } 
		exec()
	}
}

class windowflagsView from WindowsViewParent
	win = new MainWindow() { 
		move(64,40)
		resize(395,376)
		setWindowTitle("Window Flags")
		setstylesheet("background-color:;") 
		LabelType = new label(win) {
			move(10,13)
			resize(31,26)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			oFont.delete()
			setText("Type")
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		LabelHints = new label(win) {
			move(9,143)
			resize(32,27)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			oFont.delete()
			setText("Hints")
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ListType = new listwidget(win) {
			move(56,13)
			resize(321,113)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			oFont.delete()
			AddItem("Window")
			AddItem("Dialog")
			AddItem("Sheet")
			AddItem("Drawer")
			AddItem("Popup")
			AddItem("Tool")
			AddItem("Tooltip")
			AddItem("Splash Screen")
			setcurrentItemChangedEvent("")
			setcurrentRowChangedEvent("")
			setcurrentTextChangedEvent("")
			setitemActivatedEvent("")
			setitemChangedEvent("")
			setitemClickedEvent("")
			setitemDoubleClickedEvent("")
			setitemEnteredEvent("")
			setitemPressedEvent("")
			setitemSelectionChangedEvent("")
			
		}
		ListHints = new listwidget(win) {
			move(56,143)
			resize(321,163)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			oFont.delete()
			AddItem("Window title")
			AddItem("Window system menu")
			AddItem("Window minimize button")
			AddItem("Window maximize button")
			AddItem("Window close button")
			AddItem("Window context help button")
			AddItem("Window shade button")
			AddItem("Window stays on top")
			AddItem("Window stays on bottom")
			AddItem("Customize window")
			setcurrentItemChangedEvent("")
			setcurrentRowChangedEvent("")
			setcurrentTextChangedEvent("")
			setitemActivatedEvent("")
			setitemChangedEvent("")
			setitemClickedEvent("")
			setitemDoubleClickedEvent("")
			setitemEnteredEvent("")
			setitemPressedEvent("")
			setitemSelectionChangedEvent("")
			
		}
		BtnOk = new pushbutton(win) {
			move(236,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			oFont.delete()
			setText("Ok")
			setClickEvent(Method(:okAction))
			setBtnImage(BtnOk,"")
			
		}
		BtnCancel = new pushbutton(win) {
			move(309,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			oFont.delete()
			setText("Cancel")
			setClickEvent(Method(:CancelAction))
			setBtnImage(BtnCancel,"")
			
		}
	}

# End of the Generated Source Code File...