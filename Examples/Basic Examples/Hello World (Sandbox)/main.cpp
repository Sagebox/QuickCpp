
// -------------------------------------------------------
// Sagebox Quick C++ Hello World Example (Windows Sandbox)
// -------------------------------------------------------
//
// This is a Windows Hello World example, which prints Hello world to the console and Sagebox
// Window.  It then displays a circle in the Sagebox Window.
//
// This example is a Sandbox version, which combines stdio with the Sagebox Window.
//
// The Sandbox version combines stdio with the Sagebox window and can be useful in writing 
// general C++ programs where you want to use console function as well as a mix of gui functions.
//
// The general input "cin" and "scanf" functions are duplicated with inline console-style input boxes, without
// the low-level issues with C++ stdio. 
//
// The Sandbox mode is meant for learning and beginning program, but can be useful for general programming, as well.
//
// The Sandbox Mode has the following differences from a standard C++ program using Sagebox Quick C++ 
//
//      1. Calling CreateQuickCpp() is not necessary.  The Sagebox Quick C++ enviroment is created before main() is called.
//      2. Programs can be written as standard C++ without setup or exit code, which makes it easier to write smaller, beginning-level
//         programs.  It also makes it easier to show short examples, so many Sagebox C++ examples appear in this form.
//      3. There is no need to pause the program (i.e. using ExitButton(), WaitforClose(), etc.) on certain programs: 
//         the Quick C++ Sandbox performs this automatically (unless NoExitMsg()) is called beforehand.
//      4. The Process Window is created as visible in the upper-right-hand corner.  This is to aid beginning/learning programming
//         in C++ to help exit when unending loops occur or the main window is hidden and the program cannot be seen.
//         (note that pressing ^C during the execution of the program will exit, but only if the window is visible).
//      5. In the future, there is more programming help expected, such as more control with automatic exception handling,
//         proces monitoring, and so-forth. 
//
// Otherwise, the program is exacly the same as the other Hello World examples (except the stdio goes to the Sagebox Window)

#include "CQuickCpp.h"

int main()
{
    // CreateQuickCpp() is not needed here.

    // Set Window title. This is optional. Here, it is helpful to have a display of
    // the differences with version.  CString() is used in Sagebox as stack-and-heap-based
    // string() replacement, for quick string operations with easier usage.
    //
    // It is passed to SetWindowTitle() as a "const char *"

    win.SetWindowTitle(CString() << "Sagebox Quick C++ (Windows Sandbox) Hello World -- " << win.GetVersionInfo()); 

    // Show some different ways to print out the console window and the Sagebox Window
    // Note these comments between Console, Windows, and Sandbox versions. 

    printf("Hello World (printf)\n");   // This will go to the main window (Sandbox version)
    win << "Hello World (win)\n";       // Output to the Sagebox window like cout
    cout << "Hello World (cout)\n";     // This will go to the main window (Sandbox version)

    win.SetFont(100);                   // A Shortcut for SetFont("Arial,100");
    win.printf("Hello World\n");        // This prints "Hello World" much larger in the Quick C++ Window

    // Draw a red circle to show how we can do it.  Instead of GetColor("Red)", rgb value
    // {255,0,0}, a Windows COLORREF, or RgbColor type value may also be used. 

    win.DrawCircle(300,250,100,SageColor::Red);  

    // We don't need to pause the program, as the Sandbox will put up an exit button (unless win.NoExitMsg() is called first)
}