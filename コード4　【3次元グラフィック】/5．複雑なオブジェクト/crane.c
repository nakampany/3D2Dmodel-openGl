/*  二つの自由度を持つクレーン　*/
#include <stdio.h>
#include <opengl.ft>
double  rotarm=0.0,rotfing=0.0;
static int 	 xdev=5, ydev=5, zdev=5, rotx=30, roty=-90, rotz=0;
static float scaldev=1.2, sscale=1.0;
static float xtrans=0.0, ztrans=0.0, ytrans=0.0, devtrans=0.2;

float obj_diffuse[]={0.5,1.0,0.5,1.0};
float obj_ambient[]={0.0,0.5,0.0,1.0};

float light_shine[]={50.0};
float light_post[]={1.0, 1.0, 1.0, 1.0};

void crane(void){
	glpushmatrix();
		glrotated(-90.0,1.0,0.0,0.0);
		glpushmatrix();
	 		gcylind3d(0.12,0.1,1.0,30); 		    /* 1st arm */
			gcylind3d(0.5,0.5,0.1,30);			/* bottom base */
			glpushmatrix();
				glrotated(-180.0,1.0,0.0,0.0);
				gdisc3d(0.0,0.5,30);			 /* bottom cap */
			glpopmatrix();
			glpushmatrix();
				gltranslated(0.0,0.0,0.1);
				gdisc3d(0.0,0.5,30);			/* cap of base */
			glpopmatrix();	
			glpushmatrix();
				gltranslated(0.0,0.0,1.0);
				glutSolidSphere(0.1,30,30);		  /* 1st joint */
			glpopmatrix();

			glpushmatrix();
				gltranslated(0.0,0.0,1.0);
				glrotated(rotarm,1.0,0.0,0.0);
				gcylind3d(0.1,0.07,1.5,30); 	    /* 2nd arm */
				glpushmatrix();
					gltranslated(0.0,0.0,1.5);
					glutSolidSphere(0.07,30,30);  /* 2nd joint */
				glpopmatrix();

				glpushmatrix();
					gltranslated(0.0,0.0,1.5);
					glrotated(rotfing,1.0,0.0,0.0);
					gcylind3d(0.07,0.05,0.6,30); 	/* 3rd arm */
					glpushmatrix();
						gltranslated(0.0,0.0,0.6);
						gdisc3d(0.0,0.05,30);		/* 3rd cap */
					glpopmatrix();	
				glpopmatrix();
			glpopmatrix();	
		glpopmatrix();
	glpopmatrix();	
}

void set_light(void){
  	glEnable(GL_LIGHTING);		glEnable(0);	
	glDepthFunc(GL_LEQUAL);		glEnable(GL_DEPTH_TEST);
	lightenable(0);	
	glLightfv(0,GL_POSITION,light_post);
	glLightfv(0,GL_SHININESS,light_shine);
}

void set_object(void){
	glMaterialfv(GL_FRONT,GL_DIFFUSE,obj_diffuse);		
	glMaterialfv(GL_FRONT,GL_AMBIENT,obj_ambient);		
}

void rotate(void){
	glrotatef((float)rotx, 1.0, 0.0, 0.0);
	glrotatef((float)roty, 0.0, 1.0, 0.0);
	glrotatef((float)rotz, 0.0, 0.0, 1.0);
	glscaled(sscale,sscale,sscale);
	gltranslated(xtrans,ytrans,ztrans); 		/* shift x,y,z */
}


void modeldraw(void){
	glpushmatrix();
		gclearbuffers();
		rotate();
		ground_mesh();
		glpushmatrix();
			crane();
		glpopmatrix();	
	glpopmatrix();	
	glutswapbuffers();
	glflush();
}

void key_press(unsigned char key, int xk, int yk){
	switch(key){
		case 'x':	rotx=(rotx+xdev) % 360; break;
		case 'X':	rotx=(rotx-xdev) % 360; break;
		case 'y':	roty=(roty+ydev) % 360; break;
		case 'Y':	roty=(roty-ydev) % 360; break;
		case 'z':	rotz=(rotz+zdev) % 360; break;
		case 'Z':	rotz=(rotz-zdev) % 360; break;
		case 'S':	sscale=sscale*scaldev;  break;
		case 's':	sscale=sscale/scaldev;  break;
		case 'q':	rotarm+=4.0; 			break;
		case 'Q':	rotarm-=4.0; 			break;
		case 'p':	rotfing+=3.0;			break;
		case 'P':	rotfing-=3.0;			break;
		case 'a':   xtrans+=devtrans;		break;
		case 'A':	xtrans-=devtrans;		break;
		case 'b':   ztrans+=devtrans;		break;
		case 'B':   ztrans-=devtrans;		break;	
		case 'c':	ytrans+=devtrans;		break;
		case 'C':	ytrans-=devtrans;		break;

	}
	modeldraw();
}

int main(){
	ginit(3);
	glshademodel(gl_smooth);
	set_light();
	set_object();	
	reshapefunc(2);
	glutkeyboardfunc(key_press);
	glutdisplayfunc(modeldraw);
	glutmainloop();
	return 0;
}
