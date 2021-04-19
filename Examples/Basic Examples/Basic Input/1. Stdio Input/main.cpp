
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
//      1. --> Basic stdio input/output                     -- using cin/cout  
//
//             This example shows basic cin/cout to get the to radius values and prints the ellips to the
//             Sagebox Quick C++ Window (which is hidden until the ellipse is drawn). 
//
//      2.     Basic stdio input/output                     -- using validation with cin/out
//      3.     Windows-Based Console Input                  -- uses the Sagebox Window's console-like input/output 
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
    RgbColor rgbColor = { 255,0,0 };  // We could use win.GetColor("Red'); 
                                      // We can also use a standard Windows COLORREF RGB(255,0,0); 

    int iRadius1 = 0,iRadius2 = 0;

    cout << "Enter Radius 1: ";
    cin >> iRadius1;

    cout << "Enter Radius 2: "; 
    cin >> iRadius2; 

    win.DrawEllipse(400,400,iRadius1,iRadius2,rgbColor); 

    // We can use win.ExutBitton() or win.WaitforClose() here to wait for the 
    // user to press a button (or close the window), so the exit message in the 
    // console window doesn't overlap the Sagebox Window after it draws the ellipse.
}