/* タートルグラフィクスでタンポポを描く */
#include <stdio.h>
#include <opengl.ft>

int	   ord=2;		
double scale=200.0, ratio=0.5, angle=20.0;
double hfbr=5.0;					  
double x0=0.0, ys=-150.0;	

void stem(int ord, double scale){
  int j;
  double xd,yd;
  
	if(ord>1) color16(2); 	else color16(15);
	xd=getxturt(); yd=getyturt();
	move(scale);
	if(ord>0){
		left(angle*hfbr);
		stem(ord-1,scale*ratio);
		for(j=0; j<hfbr*2; j++){
			right(angle);
			stem(ord-1,scale*ratio);
		}	
		left(angle*hfbr);
	}
	moveto(xd,yd);		
	glflush();
}

void  draw_tree(void){ 
	glClearColor(0.0,0.0,0.9,0.0);
	gclearbuffer();
	moveto(x0,ys);
	stem(ord,scale);	
}

int  main(void){
	ginit(1);
	window_size(255.0);
	left(90.0);
	
	reshapefunc(1);
	glutdisplayfunc(draw_tree);
	glutmainloop();
	return 0;
}
