
// ----------------------------------------
// SageBox Quick C++ -- Visual Sort Example
// ----------------------------------------
//
// This is an example of a sizeable, object-oriented, and experienced level of programming.
//
// This is a set of sort algorithms copied directly from internet sources and unmodified, with only
// a couple insertion points to show them visually.
//
// *** This is a direct copy of a Sagebox example (meant for more OO-based programs), with the only change
// *** that it uses CreateQuickCpp() and passes in the object for the main window.
//
// This example shows how larger applications can be written using the Sagebox tools.  In this case, it is completely procedural,
// written, with two variations:
//
//     1. Console Mode -- In the Console Mode version (see project settings), the program shows the algorithms it is using as it uses them,
//                        and prints other messages out to the screen.  When the user quits the program in the middle of an operation,
//                        a message is printed to the console window telling the user to wait.
//
//    2. Windows       -- In the Windows project setting, this is a pure Windows program with no console mode.  The messages to the console window
//                        are still written, but are simply ignored, requiring no code changes. 
//
//                        When the user closes the window, instead of writing a message to the console mode, CSagebox::isConsoleApp() is called to 
//                        determine it's a Windows program, and the program puts up a button-less information window telling the user to wait.
//
// *** See the notes in CVisualSort.cpp, which are the same notes for the Sagebox version **
//
// Note: This program can run as a console-mode program with a Console Window (and Sagebox Window) or a pure Windows program. Use the project settings
// to select between them.  Doing so requires no code changes. 

#include "CQuickCpp.h"          // The Sagebox version includes "CSagebox.h"
#include "CVisualSort.h"

int main(int argc,char * argv[])
{
    CreateQuickCpp();               // The Sagebox version uses "CSagebox cSagebox" to create the Sagebox class, and must
                                    // then create its own Window.  CreateQuickCpp() creates it for you.  See CVisualSort::InitWindow()
                                    // for more comments, as there are 3-4 lines that changes, leaving the rest of the program exactly the same
                                    // as the Sagebox version.
    CVisualSort cSort;        

    // Since we're passing in the window object, the rest of the program doesn't need to know or care which one we are.

    cSort.main(win.GetWindow());    // Pass in the Window object -- In the Sagebox version, this passes in the Sagebox object, but it could
                                    //                               also create window and pass it in.
}

