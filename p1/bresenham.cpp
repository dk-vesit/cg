#include<graphics.h>
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,15);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            putpixel(x,y,15);
            p=p+2*dy;}
            x=x+1;
        }
}
int main()
{
    int gdriver=DETECT, gmode, /*error,*/ x0=100, y0=200, x1=400, y1=400;
    initgraph(&gdriver, &gmode, NULL /*"C:\\TC\\BGI"*/);
    drawline(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}
