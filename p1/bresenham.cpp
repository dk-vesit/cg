#include<graphics.h>
main() {
  int gd=DETECT, gm;
  int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
  initgraph(&gd, &gm, NULL /*"C:\\TC\\BGI"*/);

  

  getch();
  closegraph();
  return 0;
}
