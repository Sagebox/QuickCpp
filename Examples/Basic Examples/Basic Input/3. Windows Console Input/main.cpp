
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
//      3. --> Windows-Based Console Input                  -- uses the Sagebox Window's console-like input/output 
//
//             This uses the Sagebox version of console input.  It is very similar to console input and output, using the 
//             same form as cin and cout, but with the window name.
//
//             We can also use "console." functions -- try typing "console." or "win.console." to see the list of functions.
//
//             The console window isn't needed, so we could have used the Windows version of the Console project, but it was left
//             showing to show that we're still technically in a Console mode program, though it might as well be a pure Windows program, which 
//             is adjustable as a project setting in the regular console project (it was removed here to show the console project as an example_
//
//
//             Note there is no validation here: this is done in the next example
//
//      4.     Windows-Based Console Input
//             With Validation                              -- Adds Sagebox Options to add quick-and-easy validation to the previous version
//      5.     One-Item Dialog Entry                        -- Uses a Sagebox GetInteger() dialog to get a single Radius value.
//      6.     Two-Item Dialog Entry                        -- Uses Sagebox Quick Dialog to get both radius values (with validation)
//      7.     Sagebox-Based Two Items and a Checkbox       -- Adds a checkbox to the previous example to select filled/non-filled ellipse. 
//
// The first two examples include a console window.  The others do not use the Console Window.
//
// Note: Example 2 includes an example that can cause an infinite loop in regular C++ using cin. 
//

#include "CQuickCpp.h"

// Note: This example is using the "Sandbox" project, so it doesn't call "CreateQuickCpp()" and doesn't
//       need to pause the output (i.e. by getting input) to keep the program from closing down automatically.
//
//       The Sandbox form is used on smaller examples to highlight the example code. 
//

int main()
{   
    RgbColor rgbColor = { 255,0,0 };  // Or we could use win.GetColor("Red'); 
                                      // We can also use a standard Windows COLORREF RGB(255,0,0); 

    int iRadius1 = 0,iRadius2 = 0;  // We don't need to set them to 0, since we get a guaranteed numeric result. 
                                    // (which is 0 when the number is invalid, such as non-numeric entry)

    // Use the window's console i/o versions for input/output.  If the user closes the window the entry falls through with 
    // a return of 0 -- if the user presses control-C, the program exits as in a console program (this can be turned off).

    win << "Enter Radius 1: ";          // Simple i/o, as in C++, but without the "cin >> integer" issue. 
    win >> iRadius1;

    win << "Enter Radius 2: "; 
    win >> iRadius2; 

    win.DrawEllipse(400,400,iRadius1,iRadius2,rgbColor); 

    win.WaitforClose();             // Before, we used win.ExitButton().  Now, this waits for the window to close
                                    // before exiting.  
    
    // Since we're in a console sandbox, the console mode will print an exit message, too.
    // In the next example, the non-sandbox Console/Windows version is used as a pure window program, and
    // the program will exit as soon as the user closes the window. This also means it will need to call
    // CreateQuickCpp() itself.
}