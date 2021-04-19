// ---------------------------------------------
// My Projects Sample Project -- Sandbox Version
// ---------------------------------------------
//
// *** See notes in main.cpp of "1. Sample Project" in this solution (just click to it in the Solution Explorer")
//
// ---------------
// Sandbox Version
// ---------------
//
// This is a sandbox version of the "Sample Project". 
//
// The Sandbox project merges stdio with the Window.  The Sandbox is still a little experimental, and the idea is to 
// allow basic C++ I/O in the window for learning purposes. 
//
// Differences with this version:
//
//      1. CreateQuickCpp() is no longer needed, as it is performed automatically.
//      2. ExitButton() is also removed, as this is also performed automatically.
//      3. Note the appearance of the Process Control Window in the upper-right (when the program is running)
//         This is created with the non-sandbox projects, but are initially visible unless "debug" is used to print out a
//         debug statement.
//      4. The Sandbox version does not create a Console Window.
//
//  Otherwise, the code is exactly the same. 
//
#include "CQuickCpp.h"

int main()
{
//    CreateQuickCpp();      // Not needed for Sandbox projects.

    // Set Window title.  That can be removed or set to something else specific to your program
    // This version sets the template name and shows Sagebox Version information, using CString(),
    // similar to using string/streamstring, etc, but simpler overall. 

    CString csVersion = CString() << "My Projects Example (Sandbox version)  -- " << win.GetVersionInfo();

    win.SetWindowTitle(csVersion); 

    win << csVersion << "\n\n";   // Also print it to the window.  -- we can use "cout" in the sandbox version.

    // Show some different ways to print out the console window and also the Sagebox Window
    // The Sagebox window does not appear until first used. 

    // ** Sandbox note: All output will now go to the main window, even stdio. 

    printf("Hello World (printf)\n");       // This will go out to the window (i.e. stdio goes to window)
    win << "Hello World (win)\n";           // Output to the window like cout
    cout << "Hello World (cout)\n";         // cout also goes to window in the Win Sandbox

  
    // We need to pause the output so the program won't just exit back to windows and close down. 

  //  return win.ExitButton();  -- We don't need this any longer (we also don't need a return since we're in main()
     
}