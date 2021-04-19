
// ---------------------------------
// Sagebox Quick C++ Windows Sandbox
// ---------------------------------
//
// This project is the Sagebox Quick C++ Sandbox, which combines the stdio with the Sagebox/Quick C++ window, without
// the use of a Console Window. 
//
// The Sandbox projects start the Sagebox Quick C++ environment before entering WinMain, and present an 
// exit message at the end of the program.   This is not much different than the standard C++ projects, 
// except that the ProcessWindow is started as visible.  In the future, there will be more elements
// geared towards aiding program learning and development.
//
// The main idea for this Windows-only version is that, for many programs, we don't need the Console Window, 
// but some of the functionality is useful, and is now put into the Sagebox Window rather than the Console Mode Window.
//
// For learning and beginning programming, this can make programming easier and more interesting, since most of 
// the time when using a GUI, we don't really use stdio much, so there is no reason for a Console Window. 
// 
// To aid programming -- and as a prototype of a future version of Sagebox -- the stdio is combined with the 
// Sagebox window, allowing basic printf(), cin, cout, and other stdio functions mixed with basic graphic GUI functions.
//
// For debugging purposes (which the Console Window can provide as a separate window), the "debug" functions (i.e. debug.printf())
// Quick Dev Controls, or just creating  another output window with win.NewWindow() can be used instead. 
//


#include "CQuickCpp.h"

int main()
{
    // Set Window title.  That can be removed or set to something else specific to your program
    // This version sets the template name and shows Sagebox Version information, using CString(),
    // similar to using string/streamstring, etc, but simpler overall. 

    win.SetWindowTitle(CString() << "Sagebox Quick C++ Windows Sandbox Template -- " << win.GetVersionInfo()); 
    
    // Show some different ways to print out the console window and also the Sagebox Window
    // Since this is a Windows/Mixed sandbox, all I/O goes out to the main window (since there is no Console Window)

    printf("Hello World (printf)\n");       // This will go out to the window (i.e. stdio goes to window)
    win << "Hello World (win)\n";           // Output to the window like cout
    cout << "Hello World (cout)\n";         // cout also goes to window in the Win Sandbox

    win.SetFont(100);               // A shortcut for SetFont("Arial,100")
    printf("Hello World\n");    // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // "{255,0,0}", a Windows COLORREF (RGB() macro), or RgbColor type value may also be used. 

    win.DrawCircle(300,200,50,win.GetColor("red")); 

    // on program end, an ExitButton() will appear automatically, unless NoExitMsg() is called first. 
}