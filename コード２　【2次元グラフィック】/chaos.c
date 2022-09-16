/*  カオス :  gpoint()の例	*/
/*  x(t+1)=1.0+a*y(t)+b*|x(t)|,  y(t+1)=x(t)　基本式 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <opengl.ft>

static double sh=128.0;
static double m=250;
double bdf=0.0075;

void cal_non_linear(double a,double b,double m,double x,double y);

void draw_chaos(void)
{
    double	a,b,x,y;
	a=-0.999;	 x=0.001;	y=0.001;
    gclearbuffer();

 	for(b=0.0; b<=1.0; b+=bdf){
		gclearbuffer();
		cal_non_linear(a,b,m,x,y);
		glutswapbuffers();
	}	
}	

double  absolute(double x)
{ 
	if (x<0.0) return(-x);
	else return(x);
}

void cal_non_linear(double a,double b,double m,double x,double y)
{  
	double  tx,ty;
    int     j,k;
 	for(j=0;  j<=100;  j++) {
 		for(k=0;  k<=100;  k++){
	 		glcolor3d(1.0,1.0,1.0);
 			tx=1.0+a*y+b*absolute(x);
 			ty=x;
			x=tx;
			y=ty;
 			gpoint(m*tx-sh,-m*ty+sh);
 		}
 	}
 }

int main()
{
	ginit(2);	
	window_size(512.0);
	reshapefunc(1);
	glutdisplayfunc(draw_chaos);
	glutmainloop();
	return 0;
} 	
