
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
//      2. --> Basic stdio input/output                     -- using validation with cin/out
//
//             This example adds onto the previous example using stdio by adding validation to the input. 
//             The validation works by looping until a valid number is entered on each radius input.
//
//             cin.getline() is used instead of "cin >> value" to avoid an infinite loop (or adding a lot more code) when
//             bad input is entered.
//
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
    constexpr int iRadiusMin = 1;
    constexpr int iRadiusMax = 100;

    RgbColor rgbColor = SageColor::Red;  // We could use {255,0,0}
                                         // We can also use a standard Windows COLORREF RGB(255,0,0); 

    int iRadius1 = 0,iRadius2 = 0;  

    char sInput[20];

    // A small lambda to help us check a radius and print an error, since we use it in two places

    auto CheckRadius = [&](int r) 
    { 
        if (r >= iRadiusMin && r <= iRadiusMax) return true;
        printf("\nEnter a radius between %d and %d.\n\n",iRadiusMin,iRadiusMax); 
        return false; 
    };

    // Loop until we get a valid number between 1 and 100
    
    do
    {
        cout << "Enter Radius 1: ";
        cin.getline(sInput,20);         // Do this instead of "cin >> iRadius1" to avoid issues
        iRadius1 = atoi(sInput);
    }
    while (!CheckRadius(iRadius1));

    // Loop again until we get a valid number between 1 and 100

    do
    {
        cout << "Enter Radius 2: "; 
        cin.getline(sInput,20);     // Do this instead of "cin >> iRadius2" to avoid issues
        iRadius2 = atoi(sInput);
    }
    while (!CheckRadius(iRadius2)); 
  
    win.DrawEllipse(400,400,iRadius1,iRadius2,rgbColor); 

    // In the previous example, we didn't use win.ExitButton().  Here we do this to stop
    // the console window from showing the end message before we click the button.

    win.ExitButton();           // We can also use win.WaitforClose() to wait for the window to close, but with
                                // no button at the bottom.  Here, the user can press the button or close the window.
}