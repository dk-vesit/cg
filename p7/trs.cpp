#include<iostream>
#include<graphics.h>
#include<math.h>
void translation(int x1,int x2,int y1,int y2,int x3,int y3,int tx, int ty){
	clrscr();
	int xd1,xd2,yd1,yd2,xd3,yd3;
	line(10,200,520,200);
	line(260,0,260,400);
	line(x1+260,200-y1,x2+260,200-y2);
	line(x2+260,200-y2,x3+260,200-y3);
	line(x1+260,200-y1,x3+260,200-y3);
	xd1=x1+tx;
	yd1=y1+ty;
	xd2=x2+tx;
	yd2=y2+ty;
	xd3=x3+tx;
	yd3=y3+ty;
	line(xd1+260,200-yd1,xd2+260,200-yd2);
	line(xd2+260,200-yd2,xd3+260,200-yd3);
	line(xd3+260,200-yd3,xd1+260,200-yd1);
}
void rotation(int x1,int x2,int y1,int y2,int x3,int y3,int r){
	clrscr();
	int xd1,xd2,yd1,yd2,xd3,yd3;
	line(10,200,520,200);
	line(260,0,260,400);
	line(x1+260,200-y1,x2+260,200-y2);
	line(x2+260,200-y2,x3+260,200-y3);
	line(x1+260,200-y1,x3+260,200-y3);
	float rd=(r*3.14)/180;
	float co=cos(rd);
	float si=sin(rd);
	xd1=x1*co-y1*si;
	yd1=x1*si+y1*co;
	xd2=x2*co-y2*si;
	yd2=x2*si+y2*co;
	xd3=x3*co-y3*si;
	yd3=x3*si+y3*co;
	line(xd1+260,200-yd1,xd2+260,200-yd2);
	line(xd2+260,200-yd2,xd3+260,200-yd3);
	line(xd3+260,200-yd3,xd1+260,200-yd1);
}
void scaling(int x1,int x2,int y1,int y2,int x3,int y3,int sx,int sy){
	// clrscr();
	int xd1,xd2,yd1,yd2,xd3,yd3;
	line(10,200,520,200);
	line(260,0,260,400);
	line(x1+260,200-y1,x2+260,200-y2);
	line(x2+260,200-y2,x3+260,200-y3);
	line(x1+260,200-y1,x3+260,200-y3);
	xd1=x1*sx;
	yd1=y1*sy;
	xd2=x2*sx;
	yd2=y2*sy;
	xd3=x3*sx;
	yd3=y3*sy;
	line(xd1+260,200-yd1,xd2+260,200-yd2);
	line(xd2+260,200-yd2,xd3+260,200-yd3);
	line(xd3+260,200-yd3,xd1+260,200-yd1);
}
main(){
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	int x1,x2,y1,y2,x3,y3,ch;
	cout<<"1. Translation\n2. Rotation\n3. Scaling\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	cout<<"\nEnter the three vertex of triangle:";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	switch(ch){
		case 1:
			int tx, ty;
			cout<<"Enter the x,y value of translation:";
			cin>>tx>>ty;
			translation(x1, x2, y1, y2, x3, y3, tx,ty);
			break;
		case 2:
			int r;
			cout<<"Enter the angle of rotaction:";
			cin>>r;
			rotation(x1, x2, y1, y2, x3, y3, r);
			break;
		case 3:
			int sx,sy;
			cout<<"Enter the scaling points:";
			cin>>sx>>sy;
			scaling(x1, x2, y1, y2, x3, y3, sx,sy);
			break;
		default:
			cout<<"Please enter proper choice";
			break;
	}
	getch();
	closegraph();
	return 0;
}