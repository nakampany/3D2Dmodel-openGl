/* タートルグラフィクスで木を描く */
#include <stdio.h>
#include <opengl.ft>

int	   ord=8;		
double scale=100.0, ratio=0.7, angle=20.0;
double x=0.0,y=-200.0;



void stem(int ord, double scale){
  double xd,yd;
	if(ord>1) color16(2); 	else color16(12);
	xd=getxturt();   yd=getyturt();
	move(scale);
	if(ord>0){
		left(angle);
		stem(ord-1,scale*ratio);
		right(2.0*angle);
		stem(ord-1,scale*ratio);
		left(angle);
	}
	moveto(xd,yd);
	glflush();
}

void draw_tree(void){
	glClearColor(0.0,0.0,0.9,0.0);
	gclearbuffer();
	moveto(x,y);
	stem(ord,scale);
}


int main(void){
	ginit(1);
	window_size(256.0);
	left(90.0);  
	reshapefunc(1);
	glutdisplayfunc(draw_tree);
	glutmainloop();
	return 0;
}
