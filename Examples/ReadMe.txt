
---------------------------------------------
Sagebox Quick C++ Example Project Directories
---------------------------------------------

There are two types of project example directories:

    1. Basic Examples.  These are "Hello-World" level examples, or a little above, 
       to show basic Sagebox Quick C++ code without creating an entire program. 

    2. Examples. Meant for standard C++ programming, where main() and
       WinMain() are called directly by the OS.  The Sagebox Quick C++ enviroment is
       called manually from main() or WinMain()

    3. Sandbox Examples.  Meant more for beginning and easygoing programming, with the 
       Sagebox Quick C++ environment setup before main() or Winmain() is called.  

       Also, the Windows Sandbox combines into the main window, using Sagebox functions for
       printf(), cin(), cin.getline(), etc.

See the documentation below for more information.

---------------------
Standard C++ Examples
---------------------

The Standard C++ examples are meant for more general programming, and are no different than
any other C++ Console mode or Windows program.  

Your main() or WinMain() is called directly by the OS, and the Sagebox Quick C++ environment
must be started manully with a StartQuickCpp() call. 

The Process Control Window is started, but remains hidden.  This can also be shut off entirely. 
Standard C++ projects are regular C++ programs, and with these projects, you can add Sagebox
Quick C++ (or Sagebox) to your program by simply referencing the QuickCpp.lib library and QuickCpp.h. 
See the "TestConsolePlain" project in the "My Projects" directory.


----------------
Sandbox Examples
----------------

The Sagebox Quick C++ projects are meant more for beginners and hobbyists, to put
you right into an easy-going C++ environment, where the GUI and other things are
set up for you automatically. 

In the Windows Sandbox mode, there is only one window (no console window) and all
stdio (printf, cout, in, etc.) is combined with the the output of the main window. 

This can be nice to use since it uses the GUI and doesn't have some of the drawbacks of
C++ stdio.

These are source examples using the Sandbox, which sets up the Sagebox Quick C++ environment
before calling your main(), and then either presents an "Exit Button" (for applications
without a console window) or a "press return" message for applications that have a console window. 

The Sagebox Quick C++ Sandbox also starts the Process Monitor as a visible thumbnail in the
upper-right corner, so you can easily stop your pgoram, even if it is hidden. 


-------------------------------------------------------------
Difference Between Standard C++ Examples and Sandbox Examples
-------------------------------------------------------------

The main difference is that the Standard C++ programs contain the following in main()

// Standard C++ 
int main()
{
	StartQuickCpp();
	<program goes here>
	win.WaitforClose();
}

Where the Sagebox Quick C++ environment is already started and the pause before the program
terminates is automatic in the Sandbox mode. 

Note: StartQuickCpp() is all you need to add the Sagebox Quick C++ functionality to an
existing console-mode or Windows program.

The Sandbox mode provides other things (such as the Process Control Window) that are
meant to make programming easier for beginners and more fun.  Much of this is still TBD. 

