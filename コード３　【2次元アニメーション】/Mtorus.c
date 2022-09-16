/*　たくさんのトーラス　*/
#include <stdio.h>
#include <stdlib.h>
#include <opengl.ft>
static int spinval=0;
static int rotval=0;
void draw_multi_figs(void);

void modeldraw(void){
	gclearbuffer();
	draw_multi_figs();
	glutswapbuffers();
}	
void draw_multi_figs(void){	
  int	x,y;
	for(x=-15; x<20; x+=10)for(y=-15; y<20; y+=10){
		glpushmatrix();
			gltranslated(x,y,0.0);
				glpushmatrix(); 	
				glrotated((double)rotval, 1.0, 1.0,  0.0);
				glutWireTorus(0.5,2.0,8,10);
			    glpopmatrix();     	 
		glpopmatrix();	
	}
	glflush();
}
void modelrot(void){
	rotval=(rotval+5) % 360;
	modeldraw();
}	
int main(){ 
   ginit(2); 
    window_size(20.0);
	reshapefunc(1);
	glutidlefunc(modelrot);
	glutdisplayfunc(modeldraw);
	glutmainloop();
	return 0;
}	                 
