/* vOđŔsˇéĆÔŞń]ˇéB*/
#include <stdio.h>
#include <opengl.ft>
static float spinval=0.0;
void wind_mill(){
	glcolor3d(1.0, 0.0, 0.0);
	gtri(50.0, 150.0, 50.0,50.0, -50.0,50.0);
	glcolor3d(0.0,1.0,0.0);
	gtri(50.0, 50.0, 150.0, -50.0, 50.0, -50.0);
	glcolor3d(0.0,0.0,1.0);
	gtri(50.0, -50.0,-50.0, -150.0, -50.0, -50.0);
	glcolor3d(1.0,0.0,1.0);
	gtri(-50.0, -50.0, -150.0, 50.0, -50.0, 50.0);
	glcolor3d(0.0, 1.0, 1.0);
	gquad(-50.0, 50.0, 50.0, -50.0);
}
void  modeldraw(void){
	gclearbuffer();
	glpushmatrix();	   
		glrotated(spinval, 0.0, 0.0, 1.0);  
		wind_mill();
	glpopmatrix();
	glutswapbuffers();
	glflush();
}
void spin_left(void){
	spinval+=2.0;
	if(spinval > 360.0) spinval-=360.0;
	modeldraw();
}
int main(){
    ginit(2);
    window_size(256.0);
	reshapefunc(1);
	glutidlefunc(spin_left);
	glutdisplayfunc(modeldraw);
	glutmainloop();
	return 0;
}        
