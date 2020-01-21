#include <iostream>
#include <graphics.h>
// #include <conio>
main() {
	// clrscr();

	int gd = DETECT, gm;
	int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
	initgraph(&gd, &gm, NULL);

	// Calculate dx, dy
	int dx = x2 - x1;
	int dy = y2 - y1;

	// Calculate step
	int step;
	if (abs(dx) > abs(dy)) step = dx;
	else step = dy;

	// Calculate x-increment, y-increment
	double xinc = dx/step, yinc = dy/step;
	double x = x1, y = y1;
	putpixel(x1, y1, 15);

	// Plot pixels to form line
	while ((int)(x) < x2 || (int)(y) < y2) {
		x += xinc;
		y += yinc;
		putpixel((int)(x), (int)(y), 15);
	}

	getch();
	closegraph();

	return 0;
}
