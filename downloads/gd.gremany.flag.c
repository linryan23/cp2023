#include <stdio.h>
#include <gd.h>

int main() {
    // Create a new GD image (German flag dimensions: 900x600)
    gdImagePtr im = gdImageCreateTrueColor(900, 600);

    // Define colors (RGB format)
    int black = gdImageColorAllocate(im, 0, 0, 0);
    int red = gdImageColorAllocate(im, 255, 0, 0);
    int gold = gdImageColorAllocate(im, 255, 206, 0);

    // Draw horizontal stripes (3 equal-height stripes)
    int stripeHeight = 600 / 3;
    gdImageFilledRectangle(im, 0, 0, 899, stripeHeight - 1, black);
    gdImageFilledRectangle(im, 0, stripeHeight, 899, 2 * stripeHeight - 1, red);
    gdImageFilledRectangle(im, 0, 2 * stripeHeight, 899, 599, gold);

    // Save the image to a file
    FILE *outputFile = fopen("german_flag.png", "wb");
    gdImagePng(im, outputFile);
    fclose(outputFile);

    // Free the GD image
    gdImageDestroy(im);

    return 0;
}
