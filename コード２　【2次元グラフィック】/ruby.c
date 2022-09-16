/* ルビーの輪 : an exmaple of gline */
#include <stdio.h>
#include <math.h>
#include <opengl.ft>

void draw_diamond(void)
{    
    int    k,j;
	double dv;
    int    nb=15;
	double x1,y1,x2,y2;
	double s=150.0;					
	double rd=M_PI/180.0;
    dv=360.0/nb; 
	gclearbuffer();
	for (k=0; k<=nb; k++){
		glcolor3d(1.0,0.0,0.0);
        x1=cos(k*dv*rd);
        y1=sin(k*dv*rd);
        for(j=k+1; j<=nb; j++){
        	x2=cos(j*dv*rd);
           	y2=sin(j*dv*rd);
           	gline(s*x1,s*y1,s*x2,s*y2);
        }
     }
	glflush();
 }
int main()
{           
 	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(draw_diamond);
	glutmainloop();
	return 0;
}	
