#include<graphics.h>
#include<iostream>
void boundary_fill(int x,int y,int f_color,int b_color) {
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color) {
		putpixel(x,y,f_color);
		boundary_fill(x+1,y,f_color,b_color);
		boundary_fill(x-1,y,f_color,b_color);
		boundary_fill(x,y+1,f_color,b_color);
		boundary_fill(x,y-1,f_color,b_color);
	}
}
main() {
	int gd=DETECT,gm,x = 170,y = 120,r = 70;
	initgraph(&gd, &gm , /*"C:\\TC\\BGI"*/ NULL);
	circle(x,y,r);
	boundary_fill(x,y,6,15);
	getch();
	closegraph();
	return 0;
}