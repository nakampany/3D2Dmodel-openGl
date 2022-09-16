/* ソリッドモデルのラグビーボールのような球の表示と照明 */
#include <stdio.h>
#include <opengl.ft>
int rot_x=0;
int rot_y=0;
int rot_z=0;
float sscale=2.0;
float 	obj_diffuse0[]={0.0,0.5,0.0,1.0};
float	obj_ambient[]={0.0,0.5,0.0,1.0}; 
float   obj_specular[]={0.2,0.5,0.2,1.0};
float	obj_shininess[]={20.0};
float lite_spec[]={1.0, 1.0, 1.0, 1.0};	
float lite_shine[]={50.0};
float lite_post[]={1.0, 1.0, 1.0, 1.0}; 

void light_enable(void){
	glenable(GL_LIGHTING);
	glenable(GL_LIGHT0);				
	glenable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);	
}
void set_light(void){
	light_enable();
	glMaterialfv(GL_FRONT,GL_SPECULAR,lite_spec);
	glMaterialfv(GL_FRONT,GL_SHININESS,lite_shine);
	glLightfv(GL_LIGHT0,GL_POSITION,lite_post);
}
void set_object(void){	
	glMaterialfv(GL_FRONT,GL_DIFFUSE,obj_diffuse0);
  	glMaterialfv(GL_FRONT,GL_AMBIENT,obj_ambient);
  	glMaterialfv(GL_FRONT,GL_SPECULAR,obj_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,obj_shininess);
}
void modeldraw(void){
	glpushmatrix();	
	    gclearbuffers();
		glrotatef((float)rot_x, 1.0, 0.0, 0.0);
		glrotatef((float)rot_y, 0.0, 1.0, 0.0);
		glrotatef((float)rot_z, 0.0, 0.0, 1.0);
		glscaled(sscale*1.0,sscale*0.5,sscale*0.5);  
		glutSolidSphere(1.0,40,50);
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
	set_light();
	set_object();
	window_size(2.0);
	reshapefunc(2);
	glutkeyboardfunc(key_press);
	glutdisplayfunc(modeldraw);
	glutmainloop();
	return 0;
}
