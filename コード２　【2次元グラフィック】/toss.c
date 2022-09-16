/* @{[Ěú¨Oš@*/
#include <stdio.h>
#include <math.h>
#include <opengl.ft>
double  vh=140.0;	
double 	g=9.8;		
double  zero=200.0;
void  calc_ball(void)
{
	double  t,x,y,theta,v;
	int		u,w,col=7;
	v=vh/3.6;                	
	glClearColor(1.0,1.0,1.0,0.0);
	gclearbuffer();
    glcolor3d(0.0,0.0,1.0);
	grectangle(-255.0,255.0,255.0,-255.0);
	glcolor3d(0.0,1.0,0.0);
	gline(-zero,-zero/2,256.0,-zero/2);
	for(theta=5.0; theta<85.0;  theta+=15.0){
		color16(col);		
		for(t=0.0; t<20.0; t+=0.05){
			for(u=0; u<100; u++){ 
			    x=v*cos(theta*M_PI/180.0)*t;	
			    y=v*sin(theta*M_PI/180.0)*t-g*t*t/2.0;
			    if(y>=0.0){	gpoint(x*2-zero,y*2-zero/2);} 
			}
			glflush();
		}	
		col++;
	}	
}
int main(void)
{
	ginit(1);
	reshapefunc(1);
	glutdisplayfunc(calc_ball);
	glutmainloop();
	return 0;
}