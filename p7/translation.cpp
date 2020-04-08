#include<iostream>
#include<graphics.h>
void translation(int x1,int x2,int y1,int y2,int x3,int y3,int tx, int ty){
	int xd1,xd2,yd1,yd2,xd3,yd3;
	line(x1+0,y1,x2+0,y2);
	line(x2+0,y2,x3+0,y3);
	line(x1+0,y1,x3+0,y3);	
	xd1=x1+tx;
	yd1=y1+ty;
	xd2=x2+tx;
	yd2=y2+ty;
	xd3=x3+tx;
	yd3=y3+ty;
	line(xd1,yd1,xd2,yd2);
	line(xd2,yd2,xd3,yd3);
	line(xd3,yd3,xd1,yd1);
}
main(){
	int gm,gd=DETECT;
	initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
	int x1 = 100,x2 = 100,y1 = 100,y2 = 200,x3 = 150,y3 = 150,ch;
	int tx = 20, ty = 30;
	translation(x1, x2, y1, y2, x3, y3, tx,ty);
	getch();
	closegraph();
	return 0;
}