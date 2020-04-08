#include<iostream>
using namespace std;
#include<math.h>
class operations
{
int x1,y1,z1;
int tx,ty,tz,sh,r,sx,sy,sz;
public:
void rot()
{
	int i, j, k,x;
	float ang,r,mult[1][4],b[1][4],a[4][4];
	cout<<"Enter x1,y1,z1: ";
	cin>>x1>>y1>>z1;
	cout<<"Enter the angle: ";
	cin>>r;
	ang=(float)(r*0.0174533);
	cout<<"Enter 1:about x-axis 2:about y-axis 3:about z-axis: ";
	cin>>x;
	if(x==1){
	a[0][0]=1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
	a[1][0]=0; a[1][1]=cos(ang); a[1][2]=-sin(ang); a[1][3]=0;
	a[2][0]=0; a[2][1]=sin(ang); a[2][2]=cos(ang); a[2][3]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
	}
	else if(x==2)
	{
	a[0][0]=cos(ang); a[0][1]=0; a[0][2]=sin(ang); a[0][3]=0;
	a[1][0]=0; a[1][1]=1; a[1][2]=0; a[1][3]=0;
	a[2][0]=-sin(ang); a[2][1]=0; a[2][2]=cos(ang); a[2][3]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
	}
	else if(x==3)
	{
	a[0][0]=cos(ang); a[0][1]=-sin(ang); a[0][2]=0; a[0][3]=0;
	a[1][0]=sin(ang); a[1][1]=cos(ang); a[1][2]=0; a[1][3]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=1; a[2][3]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
	}
	b[0][0]=x1; b[0][1]=y1; b[0][2]=z1; b[0][3]=1;
	for(i = 0; i < 1; i++)
	{
		for(j = 0; j < 4; j++)
		{
			 mult[i][j]=0;
		}
	}

	for(i = 0; i < 1; i++)
		for(j = 0; j < 4; j++)
				for(k = 0; k < 4; k++)
				{
			mult[i][j] += (float)(b[i][k] * a[k][j]);
				}
	cout<<"The new coordinates are: "<<mult[0][0]<<" ,"<<mult[0][1]<<" ,"<<mult[0][2];
}
void trans()
{
int a[4][4], b[1][4], mult[1][4], i, j, k;
cout<<"Enter x1,y1,z1: ";
cin>>x1>>y1>>z1;
cout<<"Enter values of tx,ty,tz: ";
cin>>tx>>ty>>tz;
a[0][0]=1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
a[1][0]=0; a[1][1]=1; a[1][2]=0; a[1][3]=0;
a[2][0]=0; a[2][1]=0; a[2][2]=1; a[2][3]=0;
a[3][0]=tx; a[3][1]=ty; a[3][2]=tz; a[3][3]=1;

b[0][0]=x1; b[0][1]=y1; b[0][2]=z1; b[0][3]=1;

for(i = 0; i < 1; i++)
{
	for(j = 0; j < 4; j++)
	{
	    mult[i][j]=0;
	}
}

for(i = 0; i < 1; i++)
	for(j = 0; j < 4; j++)
	    for(k = 0; k < 4; k++)
	    {
		mult[i][j] += b[i][k] * a[k][j];
	    }
cout<<"The new coordinates are: "<<mult[0][0]<<" ,"<<mult[0][1]<<" ,"<<mult[0][2];
}
void scale()
{
	int a[4][4], b[1][4], mult[1][4], i, j, k;
	cout<<"Enter x1,y1,z1: ";
	cin>>x1>>y1>>z1;
	cout<<"Enter values of sx,sy,sz: ";
	cin>>sx>>sy>>sz;
	a[0][0]=sx; a[0][1]=0; a[0][2]=0; a[0][3]=0;
	a[1][0]=0; a[1][1]=sy; a[1][2]=0; a[1][3]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=sz; a[2][3]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;

	b[0][0]=x1; b[0][1]=y1; b[0][2]=z1; b[0][3]=1;

	for(i = 0; i < 1; i++)
	{
		for(j = 0; j < 4; j++)
		{
		    mult[i][j]=0;
		}
	}

	for(i = 0; i < 1; i++)
		for(j = 0; j < 4; j++)
		    for(k = 0; k < 4; k++)
		    {
			mult[i][j] += b[i][k] * a[k][j];
		    }
	cout<<"The new coordinates are: "<<mult[0][0]<<" ,"<<mult[0][1]<<" ,"<<mult[0][2];

}
void refl()
{
	int a[4][4], b[1][4], mult[1][4], i, j, k;
	cout<<"Enter x1,y1,z1: ";
	cin>>x1>>y1>>z1;
	cout<<"Enter 1:about x-axis 2:about y-axis 3:about z-axis: ";
	cin>>r;
	if(r==1){
	a[0][0]=1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
	a[1][0]=0; a[1][1]=-1; a[1][2]=0; a[1][3]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=-1; a[2][3]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
}
else if(r==2)
{
a[0][0]=-1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
a[1][0]=0; a[1][1]=1; a[1][2]=0; a[1][3]=0;
a[2][0]=0; a[2][1]=0; a[2][2]=-1; a[2][3]=0;
a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
}
else if(r==3)
{
a[0][0]=-1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
a[1][0]=0; a[1][1]=-1; a[1][2]=0; a[1][3]=0;
a[2][0]=0; a[2][1]=0; a[2][2]=1; a[2][3]=0;
a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
}
	b[0][0]=x1; b[0][1]=y1; b[0][2]=z1; b[0][3]=1;

	for(i = 0; i < 1; i++)
	{
		for(j = 0; j < 4; j++)
		{
		    mult[i][j]=0;
		}
	}

	for(i = 0; i < 1; i++)
		for(j = 0; j < 4; j++)
		    for(k = 0; k < 4; k++)
		    {
			mult[i][j] += b[i][k] * a[k][j];
		    }
	cout<<"The new coordinates are: "<<mult[0][0]<<" ,"<<mult[0][1]<<" ,"<<mult[0][2];

}
void shear()
{
	int a[4][4], b[1][4], mult[1][4], i, j, k;
	cout<<"Enter x1,y1,z1: ";
	cin>>x1>>y1>>z1;
	cout<<"Enter values of sh: ";
	cin>>sh;
	cout<<"Enter 1:about x-axis 2:about y-axis 3:about z-axis: ";
	cin>>r;
	if(r==1){
	a[0][0]=1; a[0][1]=sh; a[0][2]=sh; a[0][3]=0;
	a[1][0]=0; a[1][1]=1; a[1][2]=0; a[1][3]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=1; a[2][3]=0;
	a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
}
else if(r==2)
{
a[0][0]=1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
a[1][0]=sh; a[1][1]=1; a[1][2]=sh; a[1][3]=0;
a[2][0]=0; a[2][1]=0; a[2][2]=1; a[2][3]=0;
a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
}
else if(r==3)
{
a[0][0]=1; a[0][1]=0; a[0][2]=0; a[0][3]=0;
a[1][0]=0; a[1][1]=1; a[1][2]=0; a[1][3]=0;
a[2][0]=sh; a[2][1]=sh; a[2][2]=1; a[2][3]=0;
a[3][0]=0; a[3][1]=0; a[3][2]=0; a[3][3]=1;
}

	b[0][0]=x1; b[0][1]=y1; b[0][2]=z1; b[0][3]=1;

	for(i = 0; i < 1; i++)
	{
		for(j = 0; j < 4; j++)
		{
		    mult[i][j]=0;
		}
	}
	for(i = 0; i < 1; i++)
		for(j = 0; j < 4; j++)
		    for(k = 0; k < 4; k++)
		    {
			mult[i][j] += b[i][k] * a[k][j];
		    }
	cout<<"The new coordinates are: "<<mult[0][0]<<" ,"<<mult[0][1]<<" ,"<<mult[0][2];
}};
main(){
// clrscr();
int op;
cout<<"Enter your choice:\n1:Translation \n2:Rotation \n3:Scaling \n4:Reflection \n5:Shear:\n\n";
cin>>op;
operations o;
switch(op)
{
case 1:
o.trans();
break;
case 2:
o.rot();
break;
case 3:
o.scale();
break;
case 4:
o.refl();
break;
case 5:
o.shear();
break;
}
cout << endl;
// getch();
return 0;
}