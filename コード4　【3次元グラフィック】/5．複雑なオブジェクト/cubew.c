/* ワイヤーフレームモデルの立方体の平行投影と回転  */
#include <stdio.h>
#include <opengl.ft>
static int rotx=0,roty=0,rotz=0;

void draw_gx(void){
	gclearbuffer();
	
	glpushmatrix();
		glrotated((double)rotx, 1.0, 0.0, 0.0);  
		glrotated((double)roty, 0.0, 1.0, 0.0);
		glrotated((double)rotz, 0.0, 0.0, 1.0);
        glcolor3d(1.0, 1.0, 1.0);
		glutWireCube(1.0);  
	glpopmatrix();
	glutswapbuffers();
	glflush();
}

void xrotation(void){	rotx+=3;	rotx%=360;	draw_gx(); }

void yrotation(void){	roty+=3;	roty%=360;	draw_gx(); }

void  zrotation(void){	rotz+=3;	rotz%=360;	draw_gx();	}

void key_press(unsigned char key,int mpx,int mpy){
	if(key=='x') xrotation();
	if(key=='y') yrotation();
	if(key=='z') zrotation();
}

int main(){
    ginit(2);
	window_size(1.0);
	reshapefunc(1);     
	glutkeyboardfunc(key_press);
	glutdisplayfunc(draw_gx);
	glutmainloop();
	return 0;
}
