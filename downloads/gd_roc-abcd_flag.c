// ROC Flag Drawing Program using gd library
// Reference: https://en.wikipedia.org/wiki/Flag_of_the_Republic_of_China
// Ministry of the Interior Flag Reference: https://www.moi.gov.tw/cp.aspx?n=10621
// Compile with: cc roc_flag_in_gd.c -lgd -lm

#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int x, int y, int size, int color);

int main() {
    // Define flag dimensions (width:height = 3:2)
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    // Create an image with gd
    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    // Draw the ROC flag
    draw_roc_flag(img);

    // Save the image to a file
    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);

    // Free memory used by gdImage
    gdImageDestroy(img);

    return 0;
}

// Function to draw the ROC flag using gd
void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;

    // Colors for the flag
    red = gdImageColorAllocate(img, 255, 0, 0);    // Red
    white = gdImageColorAllocate(img, 255, 255, 255);  // White
    blue = gdImageColorAllocate(img, 0, 0, 149);   // Blue

    // Draw a red rectangle covering the entire flag
    gdImageFilledRectangle(img, 0, 0, width, height, red);

    // Draw a blue rectangle representing the upper-left corner (1/4 of the flag)
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    // Draw three white lines connecting specific points
    gdImageLine(img, 429, 125, 279, 165, white);
    gdImageLine(img, 170, 274, 279, 165, white);
    gdImageLine(img, 170, 274, 429, 125, white);

    // Draw a blue circle and a white circle to create a blue ring
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;

    gdImageFilledEllipse(img, center_x, center_y, blue_circle_dia, blue_circle_dia, blue);
    gdImageFilledEllipse(img, center_x, center_y, white_circle_dia, white_circle_dia, white);

    // Calculate circle-line intersections for specific points
    double circle_x = (int)(width / 4);
    double circle_y = (int)(height / 4);
    double radius = white_circle_dia + white_circle_dia * 2 / 15;

    circleLineIntersection(circle_x, circle_y, radius, 279, 165, 170, 274);
    circleLineIntersection(circle_x, circle_y, radius, 429, 125, 279, 165);
}
