#include<iostream>
#include<graphics.h>
class operations
{
	int x1,x2,x3,x4,y1,y2,y3,y4,s,r,x5,y5,x6,y6,x7,y7,x8,y8;
	public:
	void draw()
	{
		int gd=DETECT,gm,op;
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		cout<<"Enter the coordinates for the polygon: ";
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		x1 = 100; y1 = 100;
		x2 = 100; y2 = 200;
		x3 = 200; y3 = 200;
		x4 = 200; y4 = 100;
		line(x1,y1,x2,y2);
		line(x3,y3,x2,y2);
		line(x3,y3,x4,y4);
		line(x1,y1,x4,y4);
	}
	void refl()
	{
		// int gd=DETECT,gm,op;
		line(y1,x1,y2,x2);
		line(y3,x3,y2,x2);
		line(y3,x3,y4,x4);
		line(y1,x1,y4,x4);
	}
	void shear()
	{
		int gd=DETECT,gm,op;
		cout<<"Enter the shearing axis 1:x-axis 2:y-axis : ";
		cin>>s;
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		cout<<"Enter the coordinates for the polygon: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
		cout<<"Enter the shearing axis 1:x-axis 2:y-axis : "<<s;
		if(s==1)
		{
			line(x1+(1.25*y1),y1,x2+(1.25*y2),y2);
			line(x3+(1.25*y3),y3,x2+(1.25*y2),y2);
			line(x3+(1.25*y3),y3,x4+(1.25*y4),y4);
			line(x1+(1.25*y1),y1,x4+(1.25*y4),y4);
		}
		else{
			line(x1,y1+(1.25*x1),x2,y2+(1.25*x2));
			line(x3,y3+(1.25*x3),x2,y2+(1.25*x2));
			line(x3,y3+(1.25*x3),x4,y4+(1.25*x4));
			line(x1,y1+(1.25*x1),x4,y4+(1.25*x4));
		}
	}
};
int main(){
int op;
cout<<"Enter 1:Reflection 2:Shear: ";
cin>>op;
//initgraph(&gd,&gm,"C:\\TC\\BGI");
operations o;
clrscr();
o.draw();
switch(op)
{
case 1:
o.refl();
break;
case 2:
o.shear();
break;
}
getch();
closegraph();
return 0;
}