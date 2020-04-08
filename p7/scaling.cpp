#include<iostream>
#include<graphics.h>
void scaling(int x1,int x2,int y1,int y2,int x3,int y3,int sx,int sy){
	int xd1,xd2,yd1,yd2,xd3,yd3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
	xd1=x1*sx;
	yd1=y1*sy;
	xd2=x2*sx;
	yd2=y2*sy;
	xd3=x3*sx;
	yd3=y3*sy;
	line(xd1,yd1,xd2,yd2);
	line(xd2,yd2,xd3,yd3);
	line(xd3,yd3,xd1,yd1);
}
main(){
	int gm,gd=DETECT;
	initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
	int x1 = 100,x2 = 100,y1 = 100,y2 = 200,x3 = 150,y3 = 150, sx = 2, sy = 2;
	scaling(x1, x2, y1, y2, x3, y3, sx, sy);
	getch();
	closegraph();
	return 0;
}