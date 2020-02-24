#include <iostream>
#include <graphics.h>
main() {
  double t;
  int gd=DETECT,gm,x[4],y[4],i;
  x[0] = y[0] = 100; x[3] = y[3] = 200;
  x[1] = 200, y[1] = 100; x[2] = 100; y[2] = 200;
  float px,py;
  initgraph(&gd, &gm, /*"C:\\TC\\BGI"*/ NULL);
  for(t=0;t<1;t=t+0.001)
  {
    px=((1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3]);
    py=((1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3]);
    putpixel(px, py, 15);
  }
  getch();
  closegraph();
  return 0;
}
