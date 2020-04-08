#include<iostream>
#include<graphics.h>
void fillx(int x,int y,int oldcolor,int newcolor) {
	if(getpixel(x,y) == oldcolor) {
		putpixel(x,y,newcolor);
		fillx(x+1,y,oldcolor,newcolor);
		fillx(x,y+1,oldcolor,newcolor);
		fillx(x-1,y,oldcolor,newcolor);
		fillx(x,y-1,oldcolor,newcolor);}
}
main() {
	int gm,gd=DETECT,x=110,y=210, radius = 70;
	initgraph(&gd,&gm,/* "c:\\TC\\BGI" */ NULL);
	circle(x,y,radius);
	fillx(x,y,0,15);	// temporary fill with white
	fillx(x,y,15,10);	// flood-fill with desired color
	getch();
	closegraph();
	return 0;
}