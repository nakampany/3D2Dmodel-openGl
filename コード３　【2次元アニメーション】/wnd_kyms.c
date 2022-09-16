/* 風車をキーを押すことによって回転させるプログラム	*/
#include <stdio.h>
#include <opengl.ft>
static float spinval=0.0;
void wind_mill();

void modeldraw(void){
	glpushmatrix();	   
		gclearbuffer();
		glrotated(spinval, 0.0, 0.0, 1.0);  
		wind_mill();
	glpopmatrix();
	glutswapbuffers();
	glflush();
}
void wind_mill(void){
	glcolor(255,0,0);
	gtri(50.0, 150.0, 50.0,50.0, -50.0,50.0);
	glcolor(0,255,0);
	gtri(50.0, 50.0, 150.0, -50.0, 50.0, -50.0);
	glcolor(0,0,255);
	gtri(50.0, -50.0,-50.0, -150.0, -50.0, -50.0);
	glcolor(255,0,255);
	gtri(-50.0, -50.0, -150.0, 50.0, -50.0, 50.0);
	glcolor(0,255,255);
	gquad(-50.0, 50.0, 50.0, -50.0);
}
void spin_left(void){
	spinval+=6.0;
	if(spinval > 360.0) spinval-=360.0;
	modeldraw();
}
void  spin_right(void){
	spinval-=6.0;
	if(spinval > 360.0) spinval-=360.0;
	modeldraw();
}
void key_press(unsigned char key,int x,int y){
	if(key=='r') spin_right();
	else if(key=='l') spin_left();
}
void mouse(int butt,int state,int x,int y){
	if(butt==glut_left_button){
		if(state==glut_down) spin_left();
	}
	else if(butt==glut_right_button){
		if(state==glut_down) spin_right();
	}
	modeldraw();
}
int main(){
    ginit(2);
	reshapefunc(1);
	glutkeyboardfunc(key_press);
	glutmousefunc(mouse);
	glutdisplayfunc(modeldraw);
	glutmainloop();
	return 0;
}          
          
