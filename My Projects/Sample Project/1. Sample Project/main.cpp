// ---------------------------
// My Projects Sample Project
// ---------------------------
//
// This is a sample project int the My Projects directory. 
//
// Here, you can load and use any Quick C++ project template (either through the project templates and exporting them) or by 
// installing and loading the .ZIP templates through the Microsoft Studio Load Project interface. 
//
// The project templates have the following directory structure:
//
// Project Root (i.e. "My Projects")
//    \include -- All Quick C++ includes
//    \lib     -- All Quick C++ libraries (with x32 and x64 sub-directories)
//    \widgets -- All Quick C++ Widgets (not needed if you don't use any widgets)
//
// The Project templates work directly with any top-level project directory that follows this structure.
// For example, if you have the directory:
//
// My Source Code\Quick C++ Projects"
//
// you just need "My Source Code\Quick C++ Projects\include", "My Source Code\Quick C++ Projects\lib" and (optionally) 
// "My Source Code\Quick C++ Projects\widgets"
//
// ----------------------------------------------------------------------------------------------
// Using Quick C++ (or Sagebox) in your existing projects or your own project/directory structure
// ----------------------------------------------------------------------------------------------
//
// The only requirements are that "QuickCpp.h" be included and that the path to the QuickCpp.lib library is either
// in the project settings or included as a "comment(lib, "<path>\Quickcpp.lib") in your source code, which tells the 
// linker where to find the library.
//
// That is all that is needed for either a Console Mode (main) or Windows (WinMain) program.  
//
// To convert your Console Mode (main) program into a Windows program easily, where you do not need to change any code, and
// WinMain() calls your main() (i.e. this is the "Windows" project setting in the Console project), you can do the following:
//
//     1. Include WinMain.lib as well as QuickCpp.lib. 
//     2.  Either use the Windows settings for your project, or change two items in your project settings:
//              a. In "C/C++ -> Preprocessor", define "_WINDOWS" instead of "_CONSOLE"
//              b. In "Linker -> System", change "SubSystem" to WINDOWS rather than CONSOLE (select it from the listbox provided)
//              c. That's it!  You've just turned your Console program into a Windows program -- it's exactly the same, just without the console window.
//                             All console output will now simply be ignored with no errors.
//
// ---------------
// Console Version
// ---------------
//
// This project is initially set as a Console version, with a Windows-provided Console Windows and a Sagebox Window. 
// Some elements will print to the Sagebox Window, and others to the Console Window (see the code below).
//
// You can set this as a Windows program in the project settings.  As a Windows project, the printf() and cout below 
// will simply just not be seen.  
//
// For a version that mixes both stdio and Window output, see the "Sandbox Version" of this project. 

#include "CQuickCpp.h"

int main()
{
    CreateQuickCpp();       // Create out Quick C++ environment. 

    // Set Window title.  That can be removed or set to something else specific to your program
    // This version sets the template name and shows Sagebox Version information, using CString(),
    // similar to using string/streamstring, etc, but simpler overall. 

    CString csVersion = CString() << "My Projects Example -- " << win.GetVersionInfo();

    win.SetWindowTitle(csVersion); 

    win << csVersion << "\n\n";   // Also print it to the window. 

    // Show some different ways to print out the console window and also the Sagebox Window
    // The Sagebox window does not appear until first used. 


    printf("Hello World (printf)\n");       // This will go out to the window (i.e. stdio goes to window)
    win << "Hello World (win)\n";           // Output to the window like cout
    cout << "Hello World (cout)\n";         // cout also goes to window in the Win Sandbox

  
    // We need to pause the output so the program won't just exit back to windows and close down. 

    return win.ExitButton();    // win.WaitforClose() can be used here to look for the window close without setting up a button.
                                //
                                // If you are not using the Window, you can also use cSagebox.ExitButton() which will provide a butto window. 
                                // With Sagebox Quick C++, you can use win.GetSagebox() to get the Sagebox object, i.e. win.GetSagebox().ExitButton();
                                // 
                                // Also, a simple console mode input (when not windows only), such as cin.getline(), or win.conio.getline(); 
                                // example: 
                                //
                                //          cout << "Press Return to continue..."; 
                                //          conio.getline();        // using conio since we don't need the result.
                                //                                  // We can also use win.ClearCin() to clear the input buffer first.
}