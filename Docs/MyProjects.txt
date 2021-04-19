---------------------------
About My Projects Directory
---------------------------
 
The My Projects Directory can be used to instantly create and run programs using Sagebox Quick C++.

You can load any of the Sagebox Quick C++ templates and use them in a project created in this directory.  
There is a sample project included in the directory. 

You can use this directory for your projects, or as a quick way to try out and get used to using the
Sagebox Quick C++ library tools.

From the "Visual Studio Projects" directory .zip files (or by exporting any of the projects there), you can
 create a project in this directory with all of the paths and libraries already set up for usage. 

--> Basic Directory Structure

    The basic structure for the provided project templates is to have the Sagebox Quick C++ include, lib, 
    and optionally, the Widgets directory at the same level as your main project or solution directory, 
    such as in this diagram:

 	Top Directory (Where your projects' parent directory is located), with directories:

            --> include                    (Sagebox Quick C++ Includes)
            --> lib                        (Sagebox Quick C++ libraries) 
            --> Widgets                    (Sagebox Quick C++ Widgets) (optional)
            --> My Projects
                    └─── Your Project #1   (Your project directory)
                    └─── Your Project #2   (Your project directory)

    The directories "My Projects\Your Project #1" and "My Projects\Your Project #2" are where your solution 
    (.sln) or project (.vcxproj) files reside.  "My Projects" is the parent directory at the same directory
    level as the Sagebox Quick C++  include, lib, and Widgets directories.

---------------------------------------------------------
Using Sagebox Quick C++ in other directories and projects
---------------------------------------------------------

As noted in the ReadMe files for the projects, you can also do one of the following:

    1. Use the SagboxRoot macro in the provided property page, setting SageboxRoot to the path of the where 
       Sagebox Qiuck C++ was downloaded (i.e. the directories that have the "include" and "lib" directories

       Imporant Note: Make sure to set the property page in "WIndows->Other->Property Pages" rather than editing
                      the propery page in the project directly.

    2. use "#include "<path to Sagebox>\CQuickCpp.h", and then specify the library QuickCpp.lib (x32 or x64) with
       "#pragma comment(lib,<path>). 

        See the documentation on Adding Sagebox Quck C++ to Existing or New Projects for more information.

--------------------------------------------------------------
Include, Lib, and Widgets directories in My Projects Directory
--------------------------------------------------------------

The include, lib, and Widgets directories in the My Project Directory are direct copies of the same directories in the
Sagebox Quick C++ project root directory.  They are duplicated here to make the project templates work correctly.   

	
