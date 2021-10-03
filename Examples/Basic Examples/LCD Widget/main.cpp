// ------------------------------------
// Sagebox Quick C++ LCD Widget Example
// ------------------------------------
//
// This is an example of using an external Widget that may be written and provided by anyone to link
// with Sagebox, and included easily into your program. 
//
// This example shows a simple use of an "LCD Widget", which is really just a simple counter that looks like an LCD.
//
// The library for the LCD widget is included as part of the project setup.  See the "Dial Widget" for an example where the 
// library is explicitly included in the source code so that the project does not need to be changed. 
//
// About the LCD Widget
// --------------------
//
// The LCD widget has a few different modes, but, right now, is basically just a counter. 
// The intention is to expand this widget into an LCD emulator, what can have various forms, depending on how much
// you want to emulate, from simple counting, to piecing together numbers and letters, all the way down to 
// communicating with the hardware device and the I/O level.
//
// This example just shows counting to focus on how to install and use a widget easily.
//
// Notes:
//
//    1. This example shows an imporant issue: showing the main widow. 
//
//       In most examples, the Window is shown automatically, even though it starts off as hidden.
//       Any direct output to the window (i.e. win.printf(), win.write(), win.DrawCircle(), etc.) will show
//       the window. 
//
//       However, in this example, we don't do any of that, and all Widgets need to work with the window whether its
//       visible or not.
//
//       win.Show() is used to explicitly show the window whether or not it is hidden. 
//
//   2. Try removing the Sleep() and running the demo with and without calling cLcd.SetFastMode()
//      This is a mode where the LCD will only display when necessary.
//
//      This is an example of creating fast and efficient program with a little extra effort. 
//
//      Note: SetFastMode() requires an additional cLcd.UpdateLast() afer the main loop exits. 
//
// ** Note: This project may come up as Windows or Console Mode as default.  Use the Build Configuration to select
//          Console Mode version (i.e. with Console Mode Window) or Windows (i.e. Pure Windows program with no Console Window)
//

#include "CQuickCpp.h"
#include "Widgets\include\CLCDDisplayWidget.h"     // Include the LCD Widget file

int main()
{
    // Bring up the LCD Widget.  Since we're using the global Sagebox Quick C++ window "win.", we need it's CWindow object pointer.  
    // win.GetWindow() returns the pointer.  With Sage::CWindow objects, you can just use "&cWin" to send the pointer. 
    //
    // Put it at (50,50) with a value of 1234
   
    CLcdDisplayWidget cLcd(win.GetWindow(),50,50,1234); 

    // Count until the user presses a dev button to stop the program.

    auto& cStopButton   = win.DevButton("Stop Counting");      // A quick way of creating development controls
                                                                // with just one line of code.

    win.Show();     // We need to show the window here because it is initially hidden, and we haven't done any output to it, 
                    // and it won't show until we do.  The LCD widget doesn't need the window to be showing when it is used. 

    int iCount = 0;

    while (!cStopButton.Pressed() && !win.WindowClosing())
    {
        // Once the LCD reaches its maximum, it will stop counting, but we'll still be in the loop.
 
        cLcd.SetValue(iCount++); 
        Sleep(1);       
    }

    // Put cLcd.UpdateLast() when cLcd.FastMode() is used.

    win.ExitButton();   // Put up a button on the bottom of the window so we know we got the stop button message.
}