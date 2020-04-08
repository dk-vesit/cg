#include <graphics.h>
#include <iostream>
main(){
	int n = 4,i,j,k,gd,gm,dy,dx;
	int x,y,temp;
	int a[20][2],xi[20];
	float slope[20];

	// set coordinates for a quadrilateral
	a[0][0] = 100; a[0][1] = 100;
	a[1][0] = 200; a[1][1] = 100;
	a[2][0] = 200; a[2][1] = 200;
	a[3][0] = 100; a[3][1] = 200;
	a[n][0]=a[0][0];
	a[n][1]=a[0][1];

	// start program
	initgraph(&gd,&gm,/* "C:\\TC\\BGI" */ NULL);
	for(i=0;i<n;i++) line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	for(i=0;i<n;i++) {
		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];
		if(dy==0) slope[i]=1.0;
		if(dx==0) slope[i]=0.0;
		if((dy!=0)&&(dx!=0)) slope[i]=(float) dx/dy;
	}
	for(y=0;y< 480;y++){
	k=0;
	for(i=0;i<n;i++) {
			if( ((a[i][1]<=y)&&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y))) {
				xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
				k++;
			}
		}
		for(j=0;j<k-1;j++)
			for(i=0;i<k-1;i++) {
				if(xi[i]>xi[i+1]){
						temp=xi[i];
					xi[i]=xi[i+1];
					xi[i+1]=temp;
				}
			}
			setcolor(12);
			for(i=0;i<k;i+=2){
			line(xi[i],y,xi[i+1]+1,y);
		}
	}
	getch();
	return 0;
}