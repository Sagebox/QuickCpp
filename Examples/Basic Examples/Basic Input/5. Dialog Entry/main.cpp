
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
//      4.     Sagebox-Based Windows-Based Console Input
//      5. --> One-Item Dialog Entry                        -- Uses a Sagebox GetInteger() dialog to get a single Radius value.
//
//             Uses one of many Sagebox one-line dialog functions.  GetInteger() brings up a dialog box to get an integer from the 
//             user.  This can have many forms, such as  Modal Window, a window without a cancel button, and -- as used here -- validaiton
//             of the input range. 
//
//             Note the the last example, we used console.GetInteger(), which is a console/terminal form of entering an Integer.
//             This is win.GetInteger(), but also "dialog.GetInteger()", which is the GUI form. 
//
//      6.     Two-Item Dialog Entry                        -- Uses Sagebox Quick Dialog to get both radius values (with validation)
//      7.     Sagebox-Based Two Items and a Checkbox       -- Adds a checkbox to the previous example to select filled/non-filled ellipse. 
//
// The first two examples include a console window.  The others do not use the Console Window.
//
// Note: Example 2 includes an example that can cause an infinite loop in regular C++ using cin. 
//

#include "CQuickCpp.h"

// This example also uses the regular, standard C++ main() entry (set as a Windows program in the project settings), so we need to call
// CreateQuickCpp() to set up the Sagebox Quick C++ environment. 
//

int main()
{
    constexpr int iRadiusMin = 1;
    constexpr int iRadiusMax = 100;

    RgbColor rgbColor = SageColor::Red;  // We could use {255,0,0}
                                         // We can also use a standard Windows COLORREF RGB(255,0,0); 

    // In this case, we're showing how to get one number, so we draw a circle instead. 
    // We added "NoCancel()" so the user must enter a value (unless the window is close)

    int iRadius = win.GetInteger("Enter a Radius",Range(1,100));

    // We can stil get a 0 in iRadius if the window was closed or canceled.  
    // Since we don't have the main window showing, we can just set "NoCancel()" as an option to 
    // make sure user enter anumber.  NoClose() can also be used to disallow closing the window.
    //
    // The next example will show the use of "NoCancel()" to remove the cancel button.
  
    win.DrawCircle(400,400,iRadius,rgbColor);       // If the user canceled, this will just fall through with iRadius = 0

    // Only show the exit button if we haven't canceled.

    if (iRadius) win.ExitButton();      // Since we're not in a sandbox project, we want to wait for the user to press
                                        // a button or close the window.
}
