--------------
About Examples
--------------

This directory has larger example programs than the Basic Examples directory, showing Sagebox being used
for real projects. 

Some programs are written more in an OO, class-based structure, and others are written as more plain C/C++. 

For example, the Basic Mandelbrot and 10-liner examples (and others) are small programs that do a lot.  Other programs,
such as the Visual Sort, and Interactive Mandelbrot are written more as larger projects for extensiibility and
future expansion.

In some cases, these examples come directly from existing projects, and the reason for creating Sagebox,
such as the Neural Networking 7-Bit Counter example. 

See the Basic Examples directory for example of specific usage of Sagebox, such as input. drawing, Widgets, etc. 

----------------------------------

The examples were brought over from Sagebox, and this directory is still being filled. 

With the more complex examples, the global window "win." is converted to a CWindow pointer and passed to
the example that uses Sagebox (and not Sagebox Quick C++), since Sagebox Quick C++ is simply a layer on top
of Sagebox.

When this happens, its a sign that moving to Sagebox is probably a good idea, since Sagebox Quick C++ is meant
more for ad-hoc, C-style programming, where Sagebox is more for larger programs and more experienced developers. 


