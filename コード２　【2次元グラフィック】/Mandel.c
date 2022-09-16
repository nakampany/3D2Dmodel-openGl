/* マンデルブロー集合 */
#include <stdio.h>
#include <opengl.ft>
#define		M	  50
#define		XYSIZ 512
#define     sf   -255.0
void draw_mandel(void)
{
	int 	j,k,jmax,kmax,maxiter,count;
	double	xmin,xmax,ymin,ymax,x,y,a,b,a2,b2,dx,dy;
	static	int color[M+1];
	double  col;
	xmin=-1.0;	xmax=2.1;	ymin=-1.5;	ymax=1.6; maxiter=50;	
	dx=xmax-xmin;	dy=ymax-ymin;
	if(dx*XYSIZ > dy*XYSIZ){
		jmax=XYSIZ;	kmax=(int)(XYSIZ*dy/dx);
	}
	else {
		jmax=(int)(XYSIZ*dx/dy ); 
		kmax=XYSIZ;
	}
	dx/=jmax;	dy/=kmax;
	color[0]=0;	k=15;
	for(j=maxiter; j>0; j--){
		color[j]=k;
		if(k>1){
			k--;
		}
	}
	for(j=0; j<=jmax; j++){
		x=xmin + j*dx;
		for(k=0; k<=kmax; k++){
			y=ymax - k*dy;	a=x;	b=y;
			a2=a*a;	b2=b*b; count=maxiter;
			while ( a2+b2 <=4 && count){
				b=2*a*b - y;	a=a2 - b2 - x;
				a2=a*a;	b2=b*b;	count--;
			}
			col=color[count] % 16;
			color16((int)col+1);
			gpoint(sf+j,sf+k);
		}
	}
	glflush();
}	
int main()
{
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(draw_mandel);
	glutmainloop();
	return 0;
}
