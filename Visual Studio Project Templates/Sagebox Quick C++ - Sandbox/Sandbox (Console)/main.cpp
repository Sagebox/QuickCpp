
// --------------------------------------
// Sagebox Quick C++ Console Mode Sandbox
// --------------------------------------
//
// This project is the Console Mode Sandbox.  It creates a Console Window and a Sagebox Window
// that is initially hidden until used. 
//
// The Sandbox projects start the Sagebox Quick C++ environment before entering WinMain, and present an 
// exit message at the end of the program.   This is not much different than the standard C++ projects, 
// except that the ProcessWindow is started as visible.  In the future, there will be more elements
// geared towards aiding program learning and development.
//
// This project is aimed at learning, beginning and intermediate programming, and is used a lot for
// examples to remove the preamble end exit code needed with the regular Console and Windows Sagebox Quick C++ projects
//
// This project differs slightly from the regular Console project in the following ways:
//
//      1. The Sagebox Quick C++ environment is already created when main() is called, so there is no CreateQuickCpp() call.
//      2. On exit, the Console window is brought to the foreground, and an exit message is printed asking you to press a key. 
//         This is similar to the regular console mode, except that it is printed by Sagebox, and using exit() by passes it.
//         You can also call or return with NoExitMsg() to bypass this.
//      3. The Process Window is opened as visible in the upper-right-hand corner, where it is normally hidden until used. 
//      4. In the future, there may be more differences to aid programming and learning to program C++ in a safe environment.
//
// This project can be an excellent way to learn programming with a Console Window and also using a separate GUI window together.

#include "CQuickCpp.h"

int main()
{
    // Set Window title.  That can be removed or set to something else specific to your program
    // This version sets the template name and shows Sagebox Version information, using CString(),
    // similar to using string/streamstring, etc, but simpler overall. 

    win.SetWindowTitle(CString() << "Quick C++ Windows Console-Mode Sandbox Template -- " << win.GetVersionInfo()); 
    
    // Show some different ways to print out the console window and also the Sagebox Window
    // Since this is a Windows/Mixed sandbox, all I/O goes out to the main window (since there is no Console Window)

    printf("Hello World (printf)\n");       // This will go out to the Console Window
    win << "Hello World (win)\n";           // Output to the window like cout
    cout << "Hello World (cout)\n";         // This will also go to the Console Window

    win.SetFont(100);               // A shortcut for SetFont("Arial,100")
    win.printf("Hello World\n");    // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // {255,0,0}, a Windows COLORREF (i.e. RGB() macro), or RgbColor type value may also be used. 

    win.DrawCircle(300,200,50,win.GetColor("red")); 

    // on program end, an ExitButton() will appear automatically, unless NoExitMsg() is called first. 
}