// -----------------------------------------------
// Sagebox Quick C++ Hello World Example (Console)
// -----------------------------------------------
//
// This is a Console-Mode Hello World example, which prints Hello world to the console and Sagebox
// Window.  It then displays a circle in the Sagebox Window.
//
// This uses the Console Mode project with the standard QuickCpp.lib library to create
// a standard C++ console mode program.
//
// When CreateQuickCpp() is called, a Sagebox window is created as hidden and then can be used as a global "win"
// variable.  The Sagebox Window is not visible until it is used for something that causes a display, and may
// be permanently hidden with win.Hide(), and then shown when you're ready with win.Show(). 
//

#include "CQuickCpp.h"

int main()
{
    CreateQuickCpp();   // Create the Sagebox Quick C++ environment.  If we use the Console Sandbox
                        // version (Sandbox.lib instead of QuickCpp.lib), we don't need to do this, as it is done automatically.
    
    // Set Window title. This is optional. Here, it is helpful to have a display of
    // the differences with version.  CString() is used in Sagebox as stack-and-heap-based
    // string() replacement, for quick string operations with easier usage.
    //
    // It is passed to SetWindowTitle() as a "const char *"

    win.SetWindowTitle(CString() << "Console-Mode Quick C++ Template -- " << win.GetVersionInfo()); 

    // Show some different ways to print out the console window and the Sagebox Window
    // Note these comments between Console, Windows, and Sandbox versions. 


    printf("Hello World (printf)\n");       // This will go out to Console Window (stdio)
    win << "Hello World (win)\n";           // Output to the Sagebox window like cout
    cout << "Hello World (cout)\n";         // cout also goes to the Console Window (stdio)

    win.SetFont(100);               // A Shortcut for SetFont("Arial,100");
    win.printf("Hello World\n");    // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // {255,0,0}, a Windows COLORREF, or RgbColor type value may also be used. 

    win.DrawCircle(300,200,100,win.GetColor("red"));  

    return win.ExitButton();    // We use the exit button (or win.WaitforClose()) to prevent the program from 
                                // terminating and destroying the window since we don't have any other user input.
}