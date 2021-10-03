// --------------------------------------
// Sagebox Quick C++ Console Mode project
// --------------------------------------
//
// This project is an example of Quick C++ in a Console Mode. 
// This is a pure console mode program, with the entry point at main()
//
#include "CQuickCpp.h"

// We want to include the Dial Widget.  Rather than including the library in the project
// configuration, we can just include it here.  The Project configuration already has the correct
// libary path for x32 and x64 Widgets. 

#pragma comment(lib,"CDialWidget.lib")          // Specify the library we want

#include "..\Widgets\include\CDialWidget.h"     // Include the Dial Widget file, relative to the Quick C++/Sagebox main include path


// Main program: Demonstration of the Dial Widget and quick usage of debug output.
// 
// This program doesn't use the Console mode, but it kept anyway.  Use the Windows project configuration to make it a
// Pure Window Program (i.e. no native console mode window)

int main()
{
    // Create a Dial Widget and put it at (25,25) in the window.

    CDialWidget cDial(win.GetWindow(),25,25 + 25); 


    // We want to center the widget, so add (50,50) to center it since it's at (25,25)
    // The "-5" is to compensate for the shadow on the right edge (this is kind of an oversight in the widget)

    auto szSize = CPoint{ 50-5,50 + 15 } + cDial.GetWindowSize();       // GetWindowSize() returns a SIZE, but we use CPoint so we can 
                                                                        // do some easy math.
    
    win.SetWindowSize(szSize,true);                             // Set the window size to about 50 pixels larger than the widget itself,
                                                                // so it looks centered.  The "true" options tells SetWindowSize() 
                                                                // to make the client size the size given (otherwise it's the entire window size,
                                                                // including borders and top bar).

    // Let's add a label.  It's done after the window size, because CenterX() centers it in the visible window
    // (which was much wider before).  We can also use Write() or printf(), but the TextWidget is overall more useful for labels
    // and persistent text. 

    win.TextWidget(0,15,"Dial Widget",opt::CenterX() | Font("arial,23")); 

    // Look for any events.  We only want the dial event, so that's all we look for.
    // GetEvent() returns false (and the while loop exits) when the window is closed (this action can be disabled)

    while(win.GetEvent())
    {
        // If the value is changed, put the value out to the debug window.
        // This is an example of using the debug window, which is in the Process Control Window,
        // --> The debug window provides a very quick way to get out debugging info that doesn't
        //     get in the way of the output, and doesn't need to be set up.
        //
        // note: when debug is first used, it creates the Process Control Window, so no initialization is required.

        if (cDial.ValueChanged()) debug.printf("Value = {g}%d\n",(int) cDial.GetValue());
    }

    // We don't need an exit button or WaitforClose() since we waited for the window close with the GetEvent() loop

    return 0;   // not strictly necessary in main()
}