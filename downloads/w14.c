void draw_star(gdImagePtr img, int x, int y, int size, int color) {
gdPoint points[10];
double deg = M_PI/180.;

for (int i = 0; i < 10; i++) {
double angle = M_PI/2 + i* 2 * M_PI / 10;
int radius = (i % 2 == 0) ? size : size*sin(18*deg)/cos(36*deg);
points[i].x = x + radius * cos(angle);
points[i].y = y - radius * sin(angle);
}

// Fill the star with color
//gdImageFilledPolygon(img, points, 10, color);
// Draw the star with line
gdImagePolygon(img, points, 10, color);
}