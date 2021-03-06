
#include "CQuickCPP.h"
#include <ccomplex>

// ---------------------------
// 3D-Mandelbrot Basic Example
// ---------------------------
// 
// This is a simple implementation of a 3-D mandelbrot. 
//
// This just a basic example, showing how to use standard C++ and Sagebox graphics at the same time.
//
// See the other Sagebox Mandelbrot examples for much faster code (up to 20x-50x faster!) that alters things a little, but
// not too much.
//
// In the "10-Liners" directory of Sagebox Examples is a faster version (though still using the slow DrawPixel()) 
// that prints much larger and uses a type called CComplex, which is much faster than std::complex, and
// In the main Examples directory, the "Mandelbrot (Faster)" example is very fast in comparison.
//
//  Slowness Factors
//  ----------------
//
//      Because this example uses std::complex and prints one pixel at a time, much sloer than need be.
//
//      There are two main slowness factors in this program:
//
//          1. Using std::complex, which can be slow.  Other examples use a type called CComplex for faster execution
//          2. DrawPixel.  DrawPixel simply calls Windows::SetPixel(), which is notoriously slow.  Other examples show 
//             how to speed this up by 20x or more by sending one line at a time (or the entire Mandelbrot), rather than 
//             setting a pixel for each point.
//
// For information on the 3-D Mandelbrot, see documentation in the Sagebox 10-Liner "3D Mandelbrot" project.
//
// *** Note: This can be a Console Program with a Console Window or a Pure Windows program.  See the Build->Configuration settings.

int main()
{
    // We want our window of a specific size.  We also want to set a title.

    win.SetWindowSize(866,665,true);    // true = Set as client/canvas size, not including frame
    win.SetWindowTitle("3-D Mandelbrot (Basic) Example"); 

    for (int i=-333;i<333;i++)
        for (int j=-600;j<266;j++)
        { 
            
            std::complex<double> z,dz(0,1),c((double)j/(266),(double) i/(266));
            int iIter = 0;
            while (abs(z = z*z + c) < 256 && ++iIter < 100) dz *= z + z;
            std::complex<double> cVec = (z/dz); ;     // Get the light angle 
            cVec /= abs(cVec);  // Normalize it. 

            win.DrawPixel(j+600,i+333,iIter == 100 ? 0 :  
                RGBColor_t().fromGray((int) (90*(cVec.real() + cVec.imag()) + 128)));   // Calculate the diffusion
        }

    return win.ExitButton(); // Wait for the user to press a button or close the window
}
