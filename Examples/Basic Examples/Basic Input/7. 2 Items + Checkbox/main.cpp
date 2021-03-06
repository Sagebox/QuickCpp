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
//      5.     Sagebox-Based One-Item Dialog Entry          -- Uses a Sagebox GetInteger() dialog to get a single Radius value.
//      6.     Sagebox-Based Two-Item Dialog Entry          -- Uses Sagebox Quick Dialog to get both radius values (with validation)
//      7. --> Sagebox-Based Two Items and a Checkbox       -- Adds a checkbox to the previous example to select filled/non-filled ellipse.
//
//             This example adds a checkbox.  Since we already have the Quick Dialog, its easy to add another element. 
//             The user can check "filled" of they want the circle a solid color, or leave it as-is for outlined.
//
//             Now we can get more specific with more options, something harder to do on the command-line with console
//             input, since it all has to be answered even when we just want to mostly go with defaults. 
//
//             For this dialog, for example, the user can just press "OK" with no input to go with all defaults. 
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
    constexpr int iRadiusMin    = 1;
    constexpr int iRadiusMax    = 100;
    constexpr int iDefault1     = 100;      // Now we have some defaults we want to add.
    constexpr int iDefault2     = 50;       // (we could have done it with the windows-based console version, too)

    RgbColor rgbColor = SageColor::Red;  // We could use {255,0,0}
                                         // We can also use a standard Windows COLORREF RGB(255,0,0); 
    int iRadius1,iRadius2;

    // Use a Quick Dialog so we can get the number of edit boxes we want. 
    //
    // NoCancel() is added to remove the Cancel button from the dialog (the user can still close the window,
    // will return the defaults (or 0 without defaults) for the editboxes -- Add NoClose() to disable main window close.
    //
    // The user can press ^C to exit the entire program (this can also be disabled)
    //

    auto& cDialog = win.QuickDialog("Enter two radius values\n(values should be between 1 and 100)",NoCancel()); 

    auto& cRadius1 = cDialog.AddEditbox("Radius 1",Range(iRadiusMin,iRadiusMax) | Default(iDefault1));
    auto& cRadius2 = cDialog.AddEditbox("Radius 2",Range(iRadiusMin,iRadiusMax) | Default(iDefault2));

    auto& cFilled = cDialog.AddCheckbox("Fill Circle",Checked());   // Add a checkbox, with "Fill Circle" checked as default


    // There are two ways to work with the dialog box.
    //
    // 1. WaitforClose()                -- Let the user input and close the dialog box.  
    //                                     Then read the values from each control.
    // 2. Through the GetEvent() loop   -- We can watch the input as it happens and validate, react to it, or whatever
    //                                     we want to do, looking for the Close() event on the dialog, and then read the 
    //                                     control values. 

    cDialog.WaitforClose();         // Wait for the user to press OK (or Cancel, but we disabled  it)
                                 
    // Read the dialog box values -- Since they're validated, we can assume they are either correct or 0 in the case of a cancel or widow close.
    //                               WaitforClose() returned the status of Ok or Canceled, we don't check it here and draw the ellipse based on the 
    //                               values in the edit boxes (which are 0 if invalid, or valid values even if canceled).

    iRadius1 = cRadius1.GetInteger();
    iRadius2 = cRadius2.GetInteger();

    bool bFilled = cFilled.Checked();       // See if the filled checkbox is checked.  We could just use it in the if() below. 

    // Draw open or filled ellipse, depending on the checkbox value.

    bFilled ? win.DrawEllipse(400,400,iRadius1,iRadius2,rgbColor)
            : win.DrawOpenEllipse(400,400,iRadius1,iRadius2,rgbColor);

    win.ExitButton();               // Wait for user input so the whole program doesn't close down, since we have no input loop or event structure.
}