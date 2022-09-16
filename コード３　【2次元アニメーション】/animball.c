/*  ボールのアニメーション　*/
#include <stdio.h>
#include <opengl.ft>
void modeldraw(void)
{
	int j=0,k=2;
		while(1){
			gclearbuffers();
			j+=k;
			glcolor3d(1.0,0.0,0.0);
			gdisc(-50.0+j,0.0,50.0);
			if(j>250) k=-2;
			else if (j<-150) k=2;
			glutswapbuffers();
		}	
		glflush();     
}
int main(){
    ginit(2);
	reshapefunc(1);
	glutdisplayfunc(modeldraw);
	glutmainloop();
	return 0;
}	                 
