
// ---------------------------------------------------------
// Sagebox Quick C++ Hello World Example (WinMain() version)
// ---------------------------------------------------------
//
// This is a Windows Hello World example, which prints Hello world to the console and Sagebox
// Window.  It then displays a circle in the Sagebox Window.
//
// This example is a Pure Windows version, starting at WinMain().
//
// See the Windows Project Template and "Windows" template for an example that uses main() but is also a
// pure Windows Program -- execution from WinMain() is simply transferred to main() for convenience.
//
// About using Sagebox Quick C++ with WinMain()
// --------------------------------------------
//
//      Once CreateQuickCpp() is called, a WinMain() program can run procedurally just like a console-mode (main()) program,
//      but with no console window. 
//
//      A WinMain() program must have a window, which is provided by Sagebox Quick C++ automatically (as initially hidden).
//
//      A traditional WinMain() program is usually responsible for setting up a thread and a window structure and callbacks. 
//      This is done automatically so you can just start programming procedurally and don't have to do any of this yourself.
//
//      However, Sagebox works well with traditional WinMain() programs and can initiated with CreateQuickCpp() any time
//      during a traditional WinMain program.
//
//      Sagebox features heavy use and support of traditional events, with the Windows MessageHandler class easily implemented
//      to support event-driven uses (or a hybrid of events and procedural programming) with Sagebox.
//
// This is a pure Windows program without a Console Mode. 
//
// When CreateQuickCpp() is called, a Sagebox window is created as hidden and then can be used as a global "win"
// variable.  The Sagebox Window is not visible until it is used for something that causes a display, and may
// be permanently hidden with win.Hide(), and then shown when you're ready with win.Show(). 
//
// In terms of project settings, this is the same project as the Console version of "Hello World", just with the 
// Windows Debug (or Windows Debug optimized) setting selected in the project settings.

#include "CQuickCpp.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLineA,_In_ int nCmdShow)
{    
    // Set Window title. This is optional. Here, it is helpful to have a display of
    // the differences with version.  CString() is used in Sagebox as stack-and-heap-based
    // string() replacement, for quick string operations with easier usage.
    //
    // It is passed to SetWindowTitle() as a "const char *"

    win.SetWindowTitle(CString() << "Windows (WinMain) Quick C++ Hello World -- " << win.GetVersionInfo()); 

    // Show some different ways to print out the console window and the Sagebox Window
    // Note these comments between Console, Windows, and Sandbox versions. 

    printf("Hello World (printf)\n");       // This will be ignored, since we have no Console Window
    win << "Hello World (win)\n";           // Output to the Sagebox window like cout
    cout << "Hello World (cout)\n";         // This will be ignored, since we have no Console Window

    win.SetFont(100);               // A Shortcut for SetFont("Arial,100");
    win.printf("Hello World\n");    // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // {255,0,0}, a Windows COLORREF, or RgbColor type value may also be used. 

    win.DrawCircle(300,200,100,SageColor::Red);  

    return win.ExitButton();    // We use the exit button (or win.WaitforClose()) to prevent the program from 
                                // terminating and destroying the window since we don't have any other user input.
}