/* ３次元トーラスの表示とトーラスの回転					  */
#include <stdio.h>
#include <stdlib.h>
#include <opengl.ft>

float	obj_ambient[]={1.0,0.5,0.0,1.0}; 	  /* トーラスの色 */
float	obj_specular[]={1.0,1.0,1.0,1.0};
float	obj_shininess[]={50.0};

float	light_position[]={1.0,1.0,-1.0,0.0};/*照明の方向x,y,z */
float	light_ambient[]={0.5,0.5,0.5,1.0};

int		rot_x=0;								/* 物体の回転 */
int		rot_y=0;
int		rot_z=0;
float	sscale=1.0;							/* 物体の拡大縮小 */

void set_object(void){
  	glMaterialfv(GL_FRONT,GL_AMBIENT,obj_ambient);
  	glMaterialfv(GL_FRONT,GL_SPECULAR,obj_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,obj_shininess);
}

void set_light(void){
  	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_ambient);
	glenable(GL_LIGHTING);
	glenable(GL_LIGHT0);				/* ０番目の光源をｏｎ */
	glenable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);		/* スムースシェイディング */
}

void modeldraw(void){
	gclearbuffers();
	glpushmatrix();
		glrotatef((float)rot_x, 1.0, 0.0, 0.0);
		glrotatef((float)rot_y, 0.0, 1.0, 0.0);
		glrotatef((float)rot_z, 0.0, 0.0, 1.0);
		glscaled(sscale,sscale,sscale);			/* xyz : 縮尺 */
		glutSolidTorus(0.5,0.75,30,40);
	glpopmatrix();	
	glutswapbuffers();
	glflush();
}

void key_press(unsigned char key, int xk, int yk){
	if(key=='x')	  rot_x=(rot_x+5) % 360;
	else if(key=='y') rot_y=(rot_y+5) % 360;
	else if(key=='z') rot_z=(rot_z+5) % 360;
	else if(key=='S') sscale=sscale*1.2;       
	else if(key=='s') sscale=sscale/1.2;
	modeldraw();
}

int main(){
	ginit(3);
	window_size(4.0);
	set_object();
	set_light();

	reshapefunc(1);
	glutdisplayfunc(modeldraw);
	glutkeyboardfunc(key_press);
	glutmainloop();
	return 0;
}
