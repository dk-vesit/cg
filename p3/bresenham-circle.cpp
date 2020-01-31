#include <graphics.h>
void circlebres(int,int,int);
void drawcircle(int,int,int,int);
main() {
  int xc = 200,yc = 300,r = 100;
  int gd= DETECT, gm;
  initgraph(&gd,&gm, NULL /*"C:\\TC\\BGI"*/);
  circlebres(xc,yc,r);
  getch();
  closegraph();
  return 0;
}
void circlebres( int xc, int yc, int r) {
  int x=0,y=r;
  int p=3-2*r;
  while(x<y)
  {
    drawcircle(xc,yc,x,y);
    x++;
    if(p<0) p=p+4*x+6;
    else {
      y--;
      p=p+4*(x-y)+10;
    }
    drawcircle(xc,yc,x,y);
    // delay(100);
  }
}
void drawcircle( int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, WHITE);

putpixel(xc-x, yc+y, WHITE);
putpixel(xc+x, yc-y, WHITE);
putpixel(xc-x, yc-y, WHITE);
putpixel(xc+y, yc+x, WHITE);
putpixel(xc-y, yc+x, WHITE);
putpixel(xc+y, yc-x, WHITE);
putpixel(xc-y, yc-x, WHITE);
}
