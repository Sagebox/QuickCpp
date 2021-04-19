
#include "CQuickCpp.h"

void Error(const char * sError)
{
    win.WinMessageBox(CString().printf("Error: %s",sError),"Error",MB_OK); 
    exit(-1);
}

// A simple assert to exit back to the Command Window on error 
// That's the nice thing about using a console mode program, it's easy to just abort.
//
#define conAssert(_x,_Msg) { if (!(_x)) Error(_Msg); }


int Sobel()
{

    // Get a file from the user. If the file comes back blank, it was aborted.
    // an stFileOpenStruct_t can be used for more control, such as labels.
    //
    // Alternatively, since this is a console-mode application, we could also just send in a file name from the command line, 
    // but this is nice because the user can browse thumbnails.

    auto csFile = win.GetOpenFile("*.jpg");                // Get the file from the user, listing only jpegs
    conAssert(!csFile.isEmpty(),"No File Specified.");          // Error-out if the user entered no file.

    // Read the JPEG.  if it comes back invalid or empty, then it either was not a JPEG, not found, or there
    // was an error reading it.  You can get the specific Jpeg error by calling  GetJpegError() -- in this case we don't 
    // care about the actual error, just that we didn't get a bitmap in memory from loading the file.

    auto cBitmap = win.ReadJpegFile(csFile);                                   // Get the JPEG
    conAssert(cBitmap.isValid(),"JPEG not found or not a valid JPEG file.");        // Error-out if something didn't happen correctly

    printf("FileName: %s\nOriginal Size = %dx%d\nResizing...",*csFile,cBitmap.GetWidth(),cBitmap.GetHeight());

    // Use two thumbnail/resize tools. The default for both are "BestFit" (it is shown in the QuickThumbnail call for reference, but not required),
    // Which will size the image to the smallest dimension in the Width/Height given while keeping the proportions of the image. 
    // If the image is smaller than this, then it will return the image without resizing it. 
    // "ExactBestFit" will resize the image to the lowest Width/Height value (keeping the image the same proportion), even of the image is smaller.
    // There are also a number of other options.

    win.QuickThumbnail(cBitmap,350,350,ThumbType::BestFit);            // Get a Best Fit thumbnail and display it on the screen
    auto cNewBitmap = win.QuickResize(cBitmap,1200,800);               // Get a best fit, no more than 1200X, 800Y, if the image is larger than this.

    printf("\nDone Resizing.\n");

    int iWidth  = cNewBitmap.GetWidth();
    int iHeight = cNewBitmap.GetHeight();
     
    auto cBitmapOut = win.CreateBitmap(cNewBitmap.GetSize());          // Get an output bitmap of the same size of the one we resized. 

    // ** Note: There is no error-checking on the bitmap.  If it is assumed there are no memory allocation errors in their creation.  This is safe, since 
    //           we've already verified we have a valid bitmap (i.e. we errored-out back to the command window if we didn't get a valid bitmap in memory
    //           from loading a JPEG)
    //
    // This generally falls under the assumption that if you have a memory problem here, something is systemically wrong in the system.
    //
    // In release-level software and huge memory allocations (such as a 200 Megapixel image), etc., The return bitmaps can be checked
    // for a valid or empty state to determine if a memory error has occured, or exception handling can also be installed.
    
    cBitmapOut.FillColor({0,0,0});    // Clear the bitmap with black since we don't fill in the edges.

    // Arrays for the convolution on the Sobel Matrix:  X,Y, and Multiplier (Where X and Y or offsetts from the current pixel)
    
    int iArrayV[6][3] = {   { -1,-1, 1 },
                            { -1, 0, 2 },
                            { -1, 1, 1 },
                            {  1,-1,-1 },
                            {  1, 0,-2 },
                            {  1, 1,-1 } };

    int iArrayH[6][3] = {   { -1,-1, 1 },
                            {  0,-1, 2 },
                            {  1,-1, 1 },
                            { -1, 1,-1 },
                            {  0, 1,-2 },
                            {  1, 1,-1 } };


    double fDiv = sqrt(2);    // Divide by sqrt(2) since we're doing y = sqrt(a^2 + b^2)

    // Get the pixel from the array (X,Y, multiplier), multiply it and return it as a Gray value
    // Normally I would use a lambda here, but MSVC lambdas do not yet support __inline, which 
    // makes it twice as slow as need be -- so an old-fashion define lets us do it inline.

    #define GetGray(ipInd) (ipInd[2]*(int) cNewBitmap.GetPixel(j+ipInd[0],i+ipInd[1]).Gray())
    
    // The main loop -- go through each pixel and get the values of the two convolutions for each pixel. 
    // Then get the magnitude and put it out as a pixel in our new bitmap.
      
    for (int i=1;i<iHeight-1;i++)
    {
        for (int j=1;j<iWidth-1;j++)
        {
            double fGrayV = 0,fGrayH = 0;
            for (int k=0;k<6;k++) fGrayV += GetGray(iArrayV[k]);
            for (int k=0;k<6;k++) fGrayH += GetGray(iArrayH[k]);

            int iMag = (int) min(255,sqrt(fGrayV*fGrayV + fGrayH*fGrayH)/fDiv);

            // Put out the edge using the color of the pixel 
            // 
            // In the previous version, the next line was:
            //
            //     cBitmapOut.SetPixel(j,i,{iMag,iMag,iMag });
            //
            // Now two lines are added, where we get the pixel of the current location and multiply it against the 
            // magnitude.  This could be done in one line as before, but it was separated into two lines to amke
            // code more legible.

            auto rgbColor = cNewBitmap.GetPixel(j,i)*RGBColor_t{iMag,iMag,iMag };    // Get Pixel*Mag

            cBitmapOut.SetPixel(j,i,rgbColor);    // Put the new color out to the bitmap
        }
    }

    auto & cWin = win.BitmapWindow(cBitmapOut,Title("Sobel Result"));    // Show the new bitmap
    
    win.InfoWindow("Sobel Color Edge Detection Completed");        // Tell the user we've completed the sobel process. 
                                                                    // The menu was added first so it just didn't "pop up" after the user clicked the 
                                                                    // OK button in the info dialog.
    return 0; 
}

int main()
{
    return Sobel();
}