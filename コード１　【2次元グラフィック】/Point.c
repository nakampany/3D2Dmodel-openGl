/* ”’‚¢“_‚ð20ŒÂ‘Å‚Â */
#include <stdio.h>
#include <opengl.ft>
void pict_point(void)
{
    int j;
	gclearbuffer();
	for(j=0; j<200; j+=10){
		gpoint(j,0);
	}
	glflush();
}
int main(void)
{
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(pict_point);
	glutmainloop();
	return 0;
}
