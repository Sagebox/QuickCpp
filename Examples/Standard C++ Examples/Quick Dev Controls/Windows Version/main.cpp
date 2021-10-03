// -------------------------------------------------------------
// Quick Dev Control Example - Sagebox Quick C++ Windows project
// -------------------------------------------------------------
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
// *** Differences between the Windows version and Console Version ***
//
//      Window version does not have a Console Window, and re-routes stdio functions (such as printf)
//      to the main window.
//
//      In the console version, the main window is hidden initially because we don't need it and don't
//      want it to show automatically when we use GetEvent().  See notes in the console version.
//
//      Otherwise, the two versions are identical.

// Note: This is a Standard C++ program.  For Sandbox usage, the CreateQuickCpp() is not necessary.

#include "CQuickCpp.h"

int main()
{   

    // Get a slider.  We keep the control object reference here because we want to use it in
    // the GetEvent() loop below.

    auto & cSlider = CSagebox::DevSlider("Value");  // You can also use win.DevSlider(), which will create the main window

    CSagebox::DevAllowClose(true);  // Add a generic close button to the Dev Window --> When false, it just adds the 'x' in the upper-right 

    // Main Event Loop -- go until someone close the window (or press the button, since we set it to
    // send a Window Close event
    //
    // As noted, in Sagebox Quick C++, GetEvent() will show the window if it is hidden, unless we used Hide() to
    // purposely keep it from view. 

    while(CSagebox::GetEvent())     // if using "win.DevSlider", then also use win.GetEvent()
    {
        // If the sloder moved, then print the position.  We can get the position
        // inside a variable on the Moved() call. Here, we just call to get the position.

        if (cSlider.Moved()) printf("Slider Pos = %d\n",cSlider.GetPos()); 
    }
}