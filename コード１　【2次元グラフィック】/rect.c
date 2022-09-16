/* ˘üĚlpĆÂĹhčÂÔľ˝lpđć­ */
#include <stdio.h>
#include <opengl.ft>
void pict_rectd(void){
	gclearbuffer();
	grectangle(0.0,0.0,200.0,150.0);
	glcolor3d(0.0,0.0,1.0);
	gquad(0.0,0.0,-200.0,-150.0);
	glflush();
}
int main(void){
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(pict_rectd);
	glutmainloop();
	return 0;
}