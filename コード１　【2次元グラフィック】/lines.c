/* 画面の中心から外に向かって直線を引く。線の色は１６色とする */
#include <stdio.h>
#include <opengl.ft>
int w=256,h=256,i;
void draw_rand_line(void)
{
	int i;
	gclearbuffer();
	for(i=0;i<600;i++){
   		      color16(random(15));
		      gline(0,0,random(w*2)-w,random(h*2)-h);
	}
	glflush();
}
int main()
{
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(draw_rand_line);
	glutmainloop();
	return 0;
}
