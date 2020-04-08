#include <graphics.h>
#include<iostream>
#define TRUE 1
#define FALSE 0
typedef unsigned int outcode;
int CompOutCode(float x,float y);
enum { TOP = 1,
BOTTOM = 2,
RIGHT = 4,
LEFT = 8
};
const int xmax = 400;
const int ymax = 300;
const int xmin = 100;
const int ymin = 100;
void clip(float x0,float y0,float x1,float y1)
{
	int outcode0,outcode1,outcodeOut;
	int accept = FALSE,done = FALSE;
	outcode0 = CompOutCode(x0,y0);
	outcode1 = CompOutCode(x1,y1);
	do
	{
		if(!(outcode0|outcode1))
		{
			accept = TRUE;
			done = TRUE;
		}
		else if(outcode0 & outcode1) done = TRUE;
		else
		{
			float x,y;
			outcodeOut = outcode0?outcode0:outcode1;
			if(outcodeOut & TOP)
			{
				x = x0+(x1-x0)*(ymax-y0)/(y1-y0);
				y = ymax;
			}
			else if(outcodeOut & BOTTOM)
			{
				x = x0+(x1-x0)*(ymin-y0)/(y1-y0);
				y = ymin;
			}
			else if(outcodeOut & RIGHT)
			{
				y = y0+(y1-y0)*(xmax-x0)/(x1-x0);
				x = xmax;
			}
			else
			{
				y = y0+(y1-y0)*(xmin-x0)/(x1-x0);
				x = xmin;
			}
			if(outcodeOut==outcode0)
			{
				x0 = x;
				y0 = y;
				outcode0 = CompOutCode(x0,y0);
			}
			else
			{
				x1 = x;
				y1 = y;
				outcode1 = CompOutCode(x1,y1);
			}
		}
	} while(done==FALSE);
	if(accept) line(x0,y0,x1,y1);
	rectangle(xmin,ymin,xmax,ymax);
}
int CompOutCode(float x,float y)
{
	outcode code = 0;
	if(y>ymax) code|=TOP;
	else if(y<ymin) code|=BOTTOM;
	if(x>xmax) code|=RIGHT;
	else if(x<xmin) code|=LEFT;
	return code;
}
main()
{
	float x1,y1,x2,y2;
	int gd = DETECT, gm, n,poly[14],i;
	n=3;
	poly[0] = 20; poly[1] = 20;
	poly[2] = 200; poly[3] = 200;
	poly[4] = 300; poly[5] = 20;
	poly[2*n]=poly[0];
	poly[2*n+1]=poly[1];
	initgraph(&gd, &gm, /*"c:\\tc\\bgi"*/ NULL);
	drawpoly(n+1,poly);
	rectangle(xmin,ymin,xmax,ymax);
	getch();
	closegraph();
	initgraph(&gd, &gm, /*"c:\\tc\\bgi"*/ NULL);
	for(i=0;i<n;i++)
	clip(poly[2*i],poly[(2*i)+1],poly[(2*i)+2],poly[(2*i)+3]);
	getch();
	closegraph();
	return 0;
}