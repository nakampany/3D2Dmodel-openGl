/* ’n‹…‚Æ‰q¯‚ÌƒAƒjƒ[ƒVƒ‡ƒ“ */
#include <stdio.h>
#include <opengl.ft>

static double  earthrot=0.0;   					  /* ’n‹…©“] */
static double  satelrot=0.0;					  /* ‰q¯©“] */
static double  satelrevol=0.0;					  /* ‰q¯Œö“] */

double  spacex=0.0, spacey=0.0, spacez=0.0;		  /* ‹óŠÔ‹“_ */
void planet_draw(void){
	gclearbuffers();
	glpushmatrix();
		glrotatef(spacex, 1.0, 0.0, 0.0);  
		glrotatef(spacey, 0.0, 1.0, 0.0);
		glrotatef(spacez, 0.0, 0.0, 1.0);

		glcolor3d(0.0,0.0,1.0);						  /* ’n‹… */
		glrotated(90.0, 1.0, 0.0, 0.0);
		glrotated(earthrot, 0.0, 0.0, 1.0);
	    glrotated(0.0, 1.0, 0.0, 0.0);
		glutWireSphere(1.0,20,15);
        glcolor3d(1.0,1.0,0.0);			
		glrotated(90.0, 1.0, 0.0, 0.0);			  /* Ô“¹ã‚É */
		glrotated(satelrevol,0.0,1.0,0.0);	  /* Ô“¹ã‚ÌŒö“] */
	    gltranslated(2.0, 0.0, 0.0);		/* ’n‹…‚©‚ç‚Ì‹——£ */
		glrotated(90.0,0.0,1.0,0.0);		/* ’n‹…‚ÉŒü‚¯‚é–Ê */
		glrotated(satelrot, 0.0, 0.0,1.0);		/* ‰q¶‚Ì©“] */
		glutWireTorus(0.05,0.1,10,8);
		

	glpopmatrix();
	glutswapbuffers();
	glflush();
}

void  modelspin(void){
	earthrot+=0.1;		if(earthrot>360.0)	 earthrot  -=360.0;
	satelrevol+=2.0;   	if(satelrevol>360.0) satelrevol-=360.0;	
    satelrot+=10.0;		if(satelrot>360.0)   satelrot  -=360.0;	
	planet_draw();
}

void key_press(unsigned char key,int mpx,int mpy){
	if(key=='x')		spacex+=3.0; 
	else if(key=='y')   spacey+=3.0;
	else if(key=='z') 	spacez+=3.0;
	planet_draw();
}

int main(){
    ginit(2);                
	window_size(1.0);
	reshapefunc(2);
	glutidlefunc(modelspin);
	glutdisplayfunc(planet_draw);
	glutkeyboardfunc(key_press);
	glutmainloop();
	return 0;
}
