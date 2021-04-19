A description of each library: 

------------
Quickcpp.lib
------------

This is the main Quick C++ library containing the Sagebox library and the interface to Quick C++. 

This is used when adding Quick C++ to your Console-Mode or Windows program.

Once QuickCpp.lib is included, the include of "CQuickCpp.h" and "CreateQuickCpp()" is all that is needed.  

For example, a full program:

#include "CQuickCpp.h"      // or specify path 

    int main()
    {
        CreateQuickCpp();
        win.SetFont(100);
        win.printf("Hello World");
        win.ExitButton();       // So window won't close when program ends.  Can also use win.WaitforClose();
    }

This can be added to any windows or console-mode program


-----------
Sandbox.lib
-----------

This is the library used for the Sandbox project that pre-creates Quick C++ and the calls main(), creating a console window 
and Sagebox/Quick C++ Window (which is initially hidden until used).

--------------
WinSandbox.lib
--------------

This is the library used for the Windows (No console window) Basic Level project that creates a Sagebox/Quick C++ window with all stdio
using the window. 


-----------
WinMain.lib
-----------

This can be included in any console mode program using QuickCpp.lib to provide a WinMain() that will call your main(). 

This allows moving between Console Mode and Windows easily, such as developing in console mode (for the console mode window debug output)
and then re-compiling into a Windows program. 

When used, this is a Windows project (not a console-mode project), with WinMain() calling your main() directly. 