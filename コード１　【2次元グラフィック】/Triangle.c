/* ˘üĚOp`ĆÎFĹhčÂÔľ˝Op`đ`­                 */
#include <stdio.h>
#include <opengl.ft>
void pict_tris(void)
{
	gclearbuffer();
	gtriangle(0.0,0.0,200.0,150.0,230.0,-50.0);
	glcolor3d(0.0,1.0,0.0);
	gtri(0.0,0.0,-200.0,-150.0,-230.0,50.0);
	glflush();
}
int main(void)
{
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(pict_tris);
	glutmainloop();
	return 0;
}