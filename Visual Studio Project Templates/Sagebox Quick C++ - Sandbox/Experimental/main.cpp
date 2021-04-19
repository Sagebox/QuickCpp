
// -------------------------
// Sagebox Quick C++ Sandbox
// -------------------------
//
// This project is the Sagebox Quick C++ Sandbox, which combines the stdio with the Sagebox/Quick C++ window, without
// the use of a Console Window. 
//
// This is the same as the regular "Sandbox" project, and provides the windows functions as 
// global C++ functions.  For example, instead of win.DrawCircle(), DrawCircle() may be called.
//
// The main idea behind making functions global is to make the Sandbox more like a C-version of Basic; easy 
// and understandable for beginning programming.
//
// To aid programming -- and as a prototype of a future version of Sagebox -- the stdio is combined with the 
// Sagebox window, allowing basic printf(), cin, cout, and other stdio functions mixed with basic graphic GUI functions.
//
// For debugging purposes (which the Console Window can provide as a separate window), the "debug" functions (i.e. debug.printf())
// Quick Dev Controls, or just creating  another output window with win.NewWindow() can be used instead. 
//

#include "Sandbox.h"

int main()
{
    // Set Window title.  That can be removed or set to something else specific to your program
    // This version sets the template name and shows Sagebox Version information, using CString(),
    // similar to using string/streamstring, etc, but simpler overall. 

    SetWindowTitle(CString() << "Sagebox Quick C++ Prototype Sandbox Template (Experimental) -- " << win.GetVersionInfo()); 
    
    // Show some different ways to print out the console window and also the Sagebox Window
    // Since this is a Windows/Mixed sandbox, all I/O goes out to the main window (since there is no Console Window)

    printf("Hello World (printf)\n");       // This will go out to the window (i.e. stdio goes to window)
    win << "Hello World (win)\n";           // Output to the window like cout
    cout << "Hello World (cout)\n";         // cout also goes to window in the Win Sandbox

    SetFont(100);               // A shortcut for SetFont("Arial,100")
    printf("Hello World\n");    // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // "{255,0,0}", a Windows COLORREF (RGB() macro), or RgbColor type value may also be used. 

    DrawCircle(300,200,50,win.GetColor("red")); 

    // on program end, an ExitButton() will appear automatically, unless NoExitMsg() is called first. 
}