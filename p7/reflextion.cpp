#include<iostream>
#include<graphics.h>
class operations
{
	int x1,x2,x3,x4,y1,y2,y3,y4,s,r,x5,y5,x6,y6,x7,y7,x8,y8;
	public:
	void draw()
	{
		int gd=DETECT,gm,op;
		initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
		x1 = 110; y1 = 100;
		x2 = 100; y2 = 210;
		x3 = 210; y3 = 200;
		x4 = 200; y4 = 110;
		line(x1,y1,x2,y2);
		line(x3,y3,x2,y2);
		line(x3,y3,x4,y4);
		line(x1,y1,x4,y4);
	}
	void refl()
	{
		line(y1,x1,y2,x2);
		line(y3,x3,y2,x2);
		line(y3,x3,y4,x4);
		line(y1,x1,y4,x4);
	}
};
main(){
	operations o;
	o.draw();
	o.refl();
	getch();
	closegraph();
	return 0;
}