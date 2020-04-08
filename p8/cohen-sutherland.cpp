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

void cohenSutherlandClip(double x1, double y1, double x2, double y2)
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
	else if (code1 & code2)
	{
	    break;
	}
	else
	{
	    int code_out;
	    double x, y;
	    if (code1 != 0)
		code_out = code1;
	    else
		code_out = code2;
	    if (code_out & TOP)
	    {
		x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
		y = y_max;
	    }
	    else if (code_out & BOTTOM)
	    {
		x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
		y = y_min;
	    }
	    else if (code_out & RIGHT)
	    {
		y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
		x = x_max;
	    }
	    else if (code_out & LEFT)
	    {
		y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
		x = x_min;
	    }
	    if (code_out == code1)
	    {
		x1 = x;
		y1 = y;
		code1 = computeCode(x1, y1);
	    }
	    else
	    {
		x2 = x;
		y2 = y;
		code2 = computeCode(x2, y2);
	    }
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
    cohenSutherlandClip(200, 200, 350, 270);
    cohenSutherlandClip(300, 200, 300, 400);
    cohenSutherlandClip(10, 50, 40, 10);
    getch();
	closegraph();
	return 0;
}