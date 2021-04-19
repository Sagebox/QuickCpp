// -------------------------------------------
// Sagebox Quick C++ Windows (WinMain) project
// -------------------------------------------
//
// This project is an template for using Quick C++ as a Windows Program.
//
// This is a pure Windows program, with the entry point at WinMain(). 
//
// Once CreateQuickCpp() is created, you do not need to create a window or thread to support
// the Windows program. 
// 
// However, this does not preclude using a typical event-driven Windows program, either through the 
// Sagebox Quick C++ library functions, or with the Sagebox Quick C++ library functions as a set of utilities. 
// 
// CreateQuickCpp() can be called to use the WinMain() as a regular procedural program (i.e. like a console-mode program),
// or in conjunction with regular/canonical window program. 
// 
// You can use win.StopThread() to stop the thread execution transfer to solely even-driven programming, using 
// Sagebox events, Windows Events, or a combination.   Use win.ResumeThread() when ending the program in an event.
// 
// Note: The Console template contains a Windows Project setting that can move between Console Mode and Windows without any code changes.  In
//       that project, the Windows mode includes WinMain.lib which has a WinMain() that calls the same main() as the Console Mode project setting.
//
// Read "WindowsTemplate-readme.rtf" (or .txt) in the Project Templates directory for more information.

#include "CQuickCpp.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLineA,_In_ int nCmdShow)
{
    CreateQuickCpp();       // Instantiate Quick C++ for Windows

    // Set Window title.  That can be removed or set to something else specific to your program
    // This version sets the template name and shows Sagebox Version information, using CString(),
    // similar to using string/streamstring, etc, but simpler overall. 

    win.SetWindowTitle(CString() << "Windows Quick C++ Template -- " << win.GetVersionInfo()); 

    // Show some different ways to print out the console window and also the Sagebox Window
    // The Sagebox window does not appear until first used. 

    // Since this is a Windows program, all output to the console window (i.e. stdio) is ignored.

    printf("Hello World (printf)\n");       // This will be ignored since there is no Console Window
    win << "Hello World (win)\n";           // Output to the window like cout
    cout << "Hello World (cout)\n";         // This will also be ignored with no console window.

    win.SetFont(100);               // A Shortcut for SetFont("Arial,100");
    win.printf("Hello World\n");    // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // "{255,0,0}, a Windows COLORREF (i.e. RGB() macro), or RgbColor type value may also be used. 

    win.DrawCircle(300,200,50,win.GetColor("red"));  

    return win.ExitButton();    // We need the exit button (or win.WaitforClose()) to prevent the program from 
                                // terminating and destroying the window since we don't have any other user input.
}
