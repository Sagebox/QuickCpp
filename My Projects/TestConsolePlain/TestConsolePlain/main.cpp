// ------------------------
// TestConsolePlain Project
// -------------------------
//
// This is an example of adding Sagebox Quick C++ (or Sagebox) to a Console Mode (main()) or Windows (WinMain) 
// project ad-hoc style, without formalizing it as a project. 
//
// This file started as a raw Win32 Console Mode project from the default Visual Studio Template.  Sagebox is
// added in below, showing how it can be adde to any existing project (Console or Windows)
//
// The "CQuickCpp.h" file is included, and then the library needed is specified with the $pragma. 
// 
// That is all that is needed to bring int the environment.  With Sagebox, you can replace "CQuickCpp.h" with "CSagebox.h",
// and "QuickCpp.lib" with "Sagebox.lib"
//
// *** Note: The current .lib path is for Win32/x32.  For x64, simply replace "x32" with "x64" below. 
//           This project should come up as an x32 project by default, but supports both x32 and x64.
//           If you get a "conflict" message, then either change the project to x32 or change "x32" to "x64"
//           below.

// Change paths to where Sagebox is located (the paths used are the ones on my system)

#include "c:\SageBox\QuickCpp\release\include\CQuickCpp.h"

#pragma comment(lib,"c:\\Sagebox\\quickcpp\\release\\lib\\x32\\QuickCpp.lib")

int main()
{
    CreateQuickCpp();
    win.DrawCircle(400,400,100,win.GetColor("Red"));

    int iValue = win.GetInteger("Enter a Number...",Range(50,100) | NoCancel());
    
    cout << "Number is " << iValue << "\n";

    win.ExitButton();

}