#include<iostream>
#include<graphics.h>

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int x_max = 400;
const int y_max = 300;
const int x_min = 100;
const int y_min = 100;

int computeCode(double x, double y)
{
    int code = INSIDE;
    if (x < x_min)       // to the left of rectangle
	code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
	code |= RIGHT;
    if (y < y_min)       // below the rectangle
	code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
	code |= TOP;
    return code;
}

void subdivisionClip(double x1, double y1, double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;
    while (1)
    {
		if ((code1 == 0) && (code2 == 0))
		{
		    accept = 1;
		    break;
		}
		else if (code1 & code2) break;
		else
		{
		    int code_out; double midx,midy;
		    double x, y;
		    midx = x1 + (x2-x1)/2;
		    midy = y1 + (y2-y1)/2;
		    computeCode(x1,y1);
		    computeCode(midx,midy);
		    subdivisionClip(x1,y1,midx,midy);
		    midx = midx+1;
		    midy = midy+1;
		    computeCode(x2,y2);
		    computeCode(midx,midy);
		    subdivisionClip(x2,y2,midx,midy);
		    break;
	    }
	}
    if (accept)
    {
		rectangle(x_min,y_min,x_max,y_max);
		line(x1,y1,x2,y2);
    }
}
main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
	rectangle(x_min,y_min,x_max,y_max);
	line(200,200,350,270);
	line(300, 200, 300, 400);
	line(10, 50, 40, 10);
	getch();
	closegraph();
	initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
    subdivisionClip(200, 200, 350, 270);
    subdivisionClip(300, 200, 300, 400);
    subdivisionClip(10, 50, 40, 10);
    getch();
	closegraph();
	return 0;
}