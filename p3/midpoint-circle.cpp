#include<graphics.h>
void drawcircle(int x0, int y0, int R) {
  int x = R;
  int y = 0;
  int err = 0;
  while(x>=y) {
    putpixel(x0 + x, y0 + y, 15);
    putpixel(x0 + y, y0 + x, 15);
    putpixel(x0 - y, y0 + x, 15);
    putpixel(x0 - x, y0 + y, 15);
    putpixel(x0 - x, y0 - y, 15);
    putpixel(x0 - y, y0 - x, 15);
    putpixel(x0 + y, y0 - x, 15);
    putpixel(x0 + x, y0 - y, 15);
    if(err <= 0) {
      y += 1;
      err += 2 * y + 1;
    }
    if(err >0) {
      x -= 1;
      err -= 2 * x +1;
    }
  }
}
main() {
  int gd= DETECT, gm, error, x = 100, y = 150, r = 80;
  initgraph(&gd,&gm, NULL /*"C:\\TC\\BGI"*/);
  drawcircle(x, y, r);
  getch();
  closegraph();
  return 0;
}
