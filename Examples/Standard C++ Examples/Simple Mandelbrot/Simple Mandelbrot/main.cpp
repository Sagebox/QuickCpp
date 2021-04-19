
#include "CQuickCpp.h"
#include <ccomplex>

int main()
{
    CreateQuickCpp();

    SIZE cWinSize      = { 800, 600 };     // Initial Window Size
    CfPoint cfWinSize   = cWinSize;         // Get a floating-point version of window size
 
    // Initial Mandelbrot Values (Center, Range and Iterations)

    CfPoint cfCenter    = { -.6, 0 };       // Initial Mandelbrot Center
    double fRange       = 3.5;              // Initial Range (i.e. "zoom" factor)
    int iMaxIter        = 50;               // Max Mandelbrot Iterations

    CfPoint cfRange     = { fRange, fRange*cfWinSize.y/cfWinSize.x };   // Range based on X-axis

    CfPoint cfD         = cfRange/cfWinSize;                            // Unit Increment for each pixel
    CfPoint cfStart     = cfCenter - cfD*cfWinSize/2;                   // Upper-left X,Y position to start

    // Color Table based on Wikipedia Mandelbrot Colors

    static RGBColor_t rgbColors[16] = 
    {
        { 0, 0, 0       }, { 25, 7, 26     }, { 9, 1, 47      }, { 4, 4, 73      }, 
        { 0, 7, 100     }, { 12, 44, 138   }, { 24, 82, 177   }, { 57, 125, 209  },
        { 134, 181, 229 }, { 211, 236, 248 }, { 241, 233, 191 }, { 248, 201, 95  },
        { 255, 170, 0   }, { 204, 128, 0   }, { 153, 87, 0    }, { 106, 52, 3    },
    }; 
    
    win.SetWindowSize(cWinSize); 

    // note: AutoUpdate is on, so the window updates automatically every 10-20ms. When ExitButton() is called, it 
    // performs any pending updates finishing any part of the Mandelbrot output that may not have updated to the window
    // in the last 10-20ms of output.

    for (int i=0;i<cWinSize.cy;i++)
    {
        double fy = (double) i*cfD.y + cfStart.y;
        for (int j=0;j<cWinSize.cx;j++)
        {
            double fx = (double) j*cfD.x + cfStart.x;

            int iIter = 0;

            // For Julia Set, set z = { fx, fy } and c to a static value, such as (.285, 0) or (-4.,.6) (and set cfCenter to (0,0);

            std::complex<double> c = { fx, fy };
            auto z = c;
            while (abs(z) < 2 && iIter++ < iMaxIter-1) z = z*z + c;

            int iColor = (iIter == iMaxIter) ? 0 : iIter % 16; //iIter*15/(iMaxIter-1);

            // Note: Windows DrawPixel() is slow! See next version ("Faster Mandelbrot") for a better method using
            // a bitmap output that prints a line at a time (using CSageBitmap)

            win.DrawPixel(j,i,rgbColors[iColor]); 
        }
    }
    return win.ExitButton();
}