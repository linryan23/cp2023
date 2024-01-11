#include <stdio.h>
#include <gd.h>

int main() {
    // Create a new GD image (Singapore flag dimensions: 900x600)
    gdImagePtr im = gdImageCreateTrueColor(900, 600);

    // Define colors (RGB format)
    int red = gdImageColorAllocate(im, 213, 43, 30);
    int white = gdImageColorAllocate(im, 255, 255, 255);

    // Draw horizontal stripes (2 equal-height stripes)
    int stripeHeight = 600 / 2;
    gdImageFilledRectangle(im, 0, 0, 899, stripeHeight - 1, red);
    gdImageFilledRectangle(im, 0, stripeHeight, 899, 599, white);

    // Draw a white crescent moon on the red stripe
    gdImageFilledEllipse(im, 450, stripeHeight / 2, 300, 300, white);

    // Save the image to a file
    FILE *outputFile = fopen("singapore_flag.png", "wb");
    gdImagePng(im, outputFile);
    fclose(outputFile);

    // Free the GD image
    gdImageDestroy(im);

    return 0;

  
}
#include <stdio,h>
#include <gd.h>

int main() {
    // Create a stripe surface and context
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 100, 100);
    cairo_t *context = cairo_create(surface);

    // Set the arc parameters
    double centerX = 50, centerY = 50, radius = 50;
    double startAngle = 270 * (M_PI / 180);  // Convert degrees to radians
    double endAngle = 90 * (M_PI / 180);
    int clockwise = 1;  // 1 for clockwise, 0 for counterclockwise

    // Draw the arc
    cairo_arc(context, centerX, centerY, radius, startAngle, endAngle);
    cairo_line_to(context, centerX, centerY);  // Connect the end point to the center
    cairo_close_path(context);

    // Set the quadratic Bezier curve parameters
    double controlX = 80, controlY = 50;
    double toX = 50, toY = 0;

    // Draw the quadratic Bezier curve
    cairo_curve_to(context, centerX, centerY, controlX, controlY, toX, toY);

    // Set the color and fill the path
    cairo_set_source_rgb(context, 1.0, 0.0, 0.0);  // Red color
    cairo_fill(context);

    // Save the result to an image file (optional)
    cairo_surface_write_to_png(surface, "output.png");

    // Cleanup
    cairo_destroy(context);
    cairo_surface_destroy(surface);

    return 0;
}



