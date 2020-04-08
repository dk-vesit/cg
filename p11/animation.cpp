#include<iostream>
#include<graphics.h>
class anime
{
public:
  int m1x,m2x,m3x,m4x,m5x,m1y,m2y,m3y,m4y,m5y,cx,cy,r;
  anime()
  {
  cx=getmaxx()/2; cy=getmaxy();
  }
  void floodFill(int x,int y,int oldcolor,int newcolor)
  {
      if(getpixel(x,y) == oldcolor)
      {
	  putpixel(x,y,newcolor);
	  floodFill(x+1,y,oldcolor,newcolor);
	  floodFill(x,y+1,oldcolor,newcolor);
	  floodFill(x-1,y,oldcolor,newcolor);
	  floodFill(x,y-1,oldcolor,newcolor);
      }
  }
  void dmount()
  {
    m1x=1; m1y=getmaxy()-1;
    m2x=getmaxx()/4; m2y=getmaxy()/2;
    m3x=getmaxx()/2; m3y=getmaxy()/2+getmaxy()/4;
    m4x=getmaxx()/2+getmaxx()/4; m4y=getmaxy()/2;
    m5x=getmaxx()-1; m5y=getmaxy()-1;
    setcolor(BROWN);
    line(m1x,m1y,m2x,m2y);
    line(m1x,m1y,m5x,m5y);
    line(m3x,m3y,m2x,m2y);
    line(m3x,m3y,m4x,m4y);
    line(m5x,m5y,m4x,m4y);
    floodfill(getmaxx()/4,getmaxy()/2+50,6);
  }
  void dsun()
  {
    cy--; r=30;
    setcolor(YELLOW);
    fillellipse(cx,cy,r,r);
    floodFill(cx,cy,0,14);
  }
};
main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,/*"C:\\TC\\BGI"*/ NULL);
	anime a;
	for(int i=0;i<300;i++)
	{
	  cleardevice();
	  a.dsun();
	  a.dmount();
	  delay(5);
	}
	getch();
	closegraph();
	return 0;
}