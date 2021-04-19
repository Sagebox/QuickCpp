// ------------------------------------------------------------------
// Quick Dev Control Example - Sagebox Quick C++ Console Mode project
// ------------------------------------------------------------------
//
// This project shows using the Quick Dev Controls, which can be very useful
// in Creative Development and other areas where ad-hoc and quick control creation
// can be useful.  
//
// Quick Dev Controls are useful as a design tool, as the can be temporary until you
// know which controls you want to keep, or in using the controls just for development.
//
// In many cases, the Quick Dev Controls can just be kept as the main user-interface, separate
// from the main window.
//
// The Dev Controls are more focused on prototyping and rapid development with Sagebox, but 
// are also a very useful tool in Sagebox Quick C++.
//
// note:  The window is initially hidden because the GetEvent() will show the pre-created
//        global Quick C++ Window, and in this console version we don't really need it.
//
//        In Sagevbox (as opposed to Sagebox Quick C++), this does not happen as there is no 
//        global window, and without a window, you can use CSagebox::GetEvent() to handle 
//        the Dev Controls when there is no window. 
//

#include "CQuickCpp.h"

int main()
{
    CreateQuickCpp();   // Create our Quick C++ environment, which is initially hidden.
    
    win.Hide();         // Hide the window so we don't see it when we poll for events (see notes above)

    // Get a Quick Dev Button.  We don't need to save the object reference because
    // we are just using it to automatically close the program down by sending a CloseWindow()
    // message when it is pressed.
    //
    // This is a little advanced, in a way.  Put the mouse over "SendCloseMessage" for a description

    win.DevButton("Press Me to Close Program").SendCloseMessage();

    // Get a slider.  We keep the control object reference here because we want to use it in
    // the GetEvent() loop below.

    auto & cSlider = win.DevSlider("Value"); 

    // Main Event Loop -- go until someone close the window (or press the button, since we set it to
    // send a Window Close event
    //
    // As noted, in Sagebox Quick C++, GetEvent() will show the window if it is hidden, unless we used Hide() to
    // purposely keep it from view. 

    while(win.GetEvent())
    {
        int iPos;
        
        // If the sloder moved, then print the position.  iPos only changes when the slider has been moved.
        // when cSlider.Moved() returns false, it does not change iPos

        if (cSlider.Moved(iPos)) printf("Slider Pos = %d\n",iPos); 
    }

    return 0;
}