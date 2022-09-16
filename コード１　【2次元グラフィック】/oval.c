/* ˘üĚČ~ĆÎFĚČ~đ`­                         */
#include <stdio.h>
#include <opengl.ft>
void pict_circ(void)
{
	gclearbuffer();
	gellipse(-100.0,-10.0,100.0,50.0);
	glcolor3d(0.0,1.0,0.0);
	goval(100.0,10.0,100.0,50.0);
	glflush();
}
int main(void)
{
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(pict_circ);
	glutmainloop();
	return 0;
}