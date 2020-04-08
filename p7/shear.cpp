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
		x1 = 100; y1 = 100;
		x2 = 100; y2 = 200;
		x3 = 200; y3 = 200;
		x4 = 200; y4 = 100;
		line(x1,y1,x2,y2);
		line(x3,y3,x2,y2);
		line(x3,y3,x4,y4);
		line(x1,y1,x4,y4);
	}
	void shear()
	{
		int gd=DETECT,gm,op;
		s = 1;
		initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
		if(s==1)
		{
			line(x1+(1.025*y1),y1,x2+(1.025*y2),y2);
			line(x3+(1.025*y3),y3,x2+(1.025*y2),y2);
			line(x3+(1.025*y3),y3,x4+(1.025*y4),y4);
			line(x1+(1.025*y1),y1,x4+(1.025*y4),y4);
		}
		else{
			line(x1,y1+(1.025*x1),x2,y2+(1.025*x2));
			line(x3,y3+(1.025*x3),x2,y2+(1.025*x2));
			line(x3,y3+(1.025*x3),x4,y4+(1.025*x4));
			line(x1,y1+(1.025*x1),x4,y4+(1.025*x4));
		}
	}
};
main(){
	operations o;
	o.draw();
	o.shear();
	getch();
	closegraph();
	return 0;
}