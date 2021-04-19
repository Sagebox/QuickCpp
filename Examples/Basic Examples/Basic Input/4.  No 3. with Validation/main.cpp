
// --------------------------------------
// Sagebox Quick C++ Basic Input Examples
// --------------------------------------
//
// This is a set of 7 examples showing basic input, from basic stdio input/output to using console-based
// Sagebox functions, to using one-line Sagebox dialogs and quick dialogs with multiple input controls. 
//
// The program simply asks for two numbers, Radius1 and Radius 2, and puts an ellipse with using the two 
// radius values in a Sagebox window.
//
// The examples slowly start adding validation and filled vs. non-filled ellipse selections.
//
//      Examples Description
//      --------------------
//
//      1.     Basic stdio input/output                     -- using cin/cout  (non-Sagebox)
//      2.     Basic stdio input/output                     -- using validation with cin/out (non-Sagebox)
//      3.     Sagebox-Based Windows-Based Console Input    -- uses the Sagebox Window's console-like input/output 
//      4. --> Windows-Based Console Input
//             With Validation                              -- Adds Sagebox Options to add quick-and-easy validation to the previous version
//
//             This version adds validation to the last example, but does so in some interesting ways:
//
//                  1. Uses the Sagebox Options format to automatically validate input
//                  2. Use console.getInteger(), which is what "win >> MyInteger" ultimately calls, we just do it directly here.
//                     This adds the opt::Range() option, will tells Sagebox to validate the input
//                  3. in the "cin" replacement "win" (i.e. the class object for any Sagebox Window), we insert
//                     the opt::Range() in the stream to tell Sagebox to validate the input.  This can be useful for ad-hoc
//                     adding things quickly without having to convert to console.GetInteger() or a dialog box. 
//
//             See more notes above the main() function
//
//      5.     One-Item Dialog Entry                        -- Uses a Sagebox GetInteger() dialog to get a single Radius value.
//      6.     Two-Item Dialog Entry                        -- Uses Sagebox Quick Dialog to get both radius values (with validation)
//      7.     Sagebox-Based Two Items and a Checkbox       -- Adds a checkbox to the previous example to select filled/non-filled ellipse. 
//
// The first two examples include a console window.  The others do not use the Console Window.
//
// Note: Example 2 includes an example that can cause an infinite loop in regular C++ using cin. 
//

#include "CQuickCpp.h"

// Note: This example moves to the regular, standard C++ project template, where Windows will call your main()
// directly (either as a console mode program or Windows program). 
//
// In this case, this is a Windows program (using the Windows project setting in the Sagebox Console and Windows project), which includes
// WinMain.lib, so we can use main() even in a Windows program.
//
// Since we're being called directly from Windows, we are in complete control and must call CreateQuickCpp() ourselves, as well
// as pause the program on the way out to make sure the window doesn't close until the user closes it. 
//
// As an exercise, try removing CreateQuickCpp() -- this will bring up a message box telling you that Sagebox is not initialized. 
//
// Note: the project setting to switch from Windows-to-Console (and vice-versa) has been removed for this example -- Microsoft Visual C++
//       environment doesn't seem to have a way to specify a project setting default, so it tends to come up as random.  So, the 
//       Windows project setting was the only one kept here to ensure the project uses it.
//
// ** Try entering values out of range (i.e. -10, 500, etc.)

int main()
{   
    CreateQuickCpp();                   // Initialize Sagebox Quick C++
                           
    constexpr int iRadiusMin = 1;
    constexpr int iRadiusMax = 100;

    RgbColor rgbColor = { 255,0,0 };  // We could use win.GetColor("Red'); 
                                      // We can also use a standard Windows COLORREF RGB(255,0,0); 

    int iRadius1, iRadius2;

    // Use the window's console i/o versions for input/output.  If the user closes the window the entry falls through with 
    // a return of 0 -- if the user presses control-C, the program exits as in a console program (this can be turned off).

    // Here, we are using console.GetInteger(), which is what "win >> iRadius2" below eventually calls. 
    // In this case, we specify "opt::Range" (we do not need to the opt:: part, but typing opt:: will cause the editor to show all options)
    // to tell the GetInteger() routine the acceptable range, and to bring up a message box.
   
    win << "Enter Radius 1: ";
    iRadius1 = console.GetInteger(opt::Range(iRadiusMin,iRadiusMax));

    // Use the C++ stream format like "cin" -- here, we can add the same opt::Range() function (this time without specifying "opt::")
    // to tell Sagebox we want to validate the value entered. 
    
    win << "Enter Radius 2: ";
    win >> Range(iRadiusMin,iRadiusMax) >> iRadius2;

    // If we get here, then we know we have some good values. 

    win.DrawEllipse(400,400,iRadius1,iRadius2,rgbColor); 

    win.ExitButton();   // Now we really need an ExitButton() or WaitforClose() (or some method to pause exit),
                        // because the program is done, and everything will close on exit. 
}