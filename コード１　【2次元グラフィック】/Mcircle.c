/* ˘ë˘ëČFĹ~đ`­       */
#include <stdio.h>
#include <opengl.ft>
void pict_circles(void)
{
  int j;
  double r,x,y;
  gclearbuffer();
  for(j=0; j<200;j++){
	  	r=(double)random(50);	
		x=(double)random(300);
		y=(double)random(300);
		color16(random(16)+1);
		gcircle(x-150.0,y-150.0,r);
	}	
	glflush();
}
int main(void)
{
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(pict_circles);
	glutmainloop();
	return 0;
}