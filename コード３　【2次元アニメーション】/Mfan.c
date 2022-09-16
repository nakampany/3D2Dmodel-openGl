/*  ˝­łńĚÔ@*/
#include <stdio.h>
#include <stdlib.h>
#include <opengl.ft>
static float spinval=0.0;
static double pic_siz=4.0;
void wind_mill(double sz)
{
  glcolor3d(1.0, 0.0, 0.0);
  gtri(50.0/sz,150.0/sz,50.0/sz,50.0/sz,-50.0/sz,50.0/sz);
  gtri(50.0/sz,50.0/sz,150.0/sz,-50.0/sz,50.0/sz,-50.0/sz);
  gtri(50.0/sz,-50.0/sz,-50.0/sz,-150.0/sz,-50.0/sz,-50.0/sz);
  gtri(-50.0/sz,-50.0/sz,-150.0/sz,50.0/sz,-50.0/sz,50.0/sz);
  glcolor3d(0.5, 1.0, 0.0);
  gquad(-50.0/sz, 50.0/sz, 50.0/sz, -50.0/sz);
}
void draw_mult_fan(double x, double y)
{
	glpushmatrix();
	gltranslated(x,y,0.0);
		
			glrotated(spinval, 0.0, 0.0, 1.0);  
			wind_mill(pic_siz);
		
	glpopmatrix();
	glflush();
}	
void  modeldraw(void)
{
    double x,y;
    gclearbuffer();
	for(x=-200; x<200; x+=100.0){
		for(y=-200; y<200; y+=100.0){	
			draw_mult_fan(x+50.0,y+50.0);
		}	
	}	glutswapbuffers();
}	
void  modelspin(void)
{
	spinval+=6.0;
	if(spinval > 360.0) spinval-=360.0;
	modeldraw();
}
int main()
{  
    ginit(2);  
	window_size(256.0);
	reshapefunc(1);
	glutidlefunc(modelspin);
	glutdisplayfunc(modelspin);
	glutmainloop();
	return 0;
}