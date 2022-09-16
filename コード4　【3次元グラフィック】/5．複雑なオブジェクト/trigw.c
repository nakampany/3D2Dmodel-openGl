/* 3次元ワイヤーフレームモデルの三角形  */
#include <stdio.h>
#include <opengl.ft>
void trigon(double h);
void draw_gx(void);
void key_press(unsigned char key,int mpx,int mpy);
int rotx=0,roty=0,rotz=0;
double h=10.0;
void trigon(double h){
	gline3d(-h,0.0,0.0,h,0.0,0.0);
	gline3d(h,0.0,0.0,0.0,2*h,0.0);
	gline3d(0.0,2*h,0.0,-h,0.0,0.0);
	
	gline3d(-h,0.0,-h,h,0.0,-h);
	gline3d(h,0.0,-h,0.0,2*h,-h);
	gline3d(0.0,2*h,-h,-h,0.0,-h);

	gline3d(h,0.0,0.0,h,0.0,-h);
	gline3d(0.0,2*h,0.0,0.0,2*h,-h);
	gline3d(-h,0.0,0.0,-h,0.0,-h);
}

void draw_gx(void){
	glclear(gl_color_buffer_bit);		/* or gclearbuffers(); */
	glpushmatrix();
		glrotated((double)rotx, 1.0, 0.0, 0.0);  
		glrotated((double)roty, 0.0, 1.0, 0.0);
		glrotated((double)rotz, 0.0, 0.0, 1.0);

		glcolor3d(1.0, 1.0, 1.0);
		trigon(1.0);
	glpopmatrix();
	glutswapbuffers();
	glflush();
}
void key_press(unsigned char key,int mpx,int mpy){
	if(key=='x')rotx+=3;rotx%=360;draw_gx();
	if(key=='y')roty+=3;roty%=360;draw_gx();
	if(key=='z')rotz+=3;rotz%=360;draw_gx();
}

int main(){
    ginit(2);
	window_size(1.0);
	reshapefunc(2);
	glutkeyboardfunc(key_press);
	glutdisplayfunc(draw_gx);
	glutmainloop();
	return 0;
}
