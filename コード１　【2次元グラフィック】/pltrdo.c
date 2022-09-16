/* 基本グラフィクス描画関数を全部使ったプログラム。	 */
#include <stdio.h>
#include <opengl.ft>
void draw_figures(void)
{
    int j;
	gclearbuffer();
	for(j=10; j<100; j++) {
	    glcolor3d(0.0,10.0/(double)j,0.0);
	    gpoint((double)j,200.0);	
	}	
	glcolor3d(1.0,0.0,0.0);
	gline(50.0,150.0,-100.0,200.0);

	glcolor3d(0.0,0.0,1.0);
	gtri(100.0,100.0,100.0,-100.0,-100.0,0.0);
	
	glcolor3d(0.5,0.0,1.0);
	gtriangle(-200.0,200.0,-175.0,150.0,-180.0,100.0);

	glcolor3d(1.0,0.0,1.0);
	grectangle(50.0,50.0,-50.0,-50.0);

	glcolor3d(0.5,1.0,0.5);
	gquad(200.0,200.0,160.0,160.0);

	glcolor3d(0.5,0.5,1.0);
	gcircle(100.0,100.0,20);
	
	glcolor3d(0.7,0.7,0.0);
	gdisc(-100.0,-100.0,15);
	
	glcolor3d(0.0,0.7,0.7);
	gellipse(200.0,0.0,20.0,30.0);	
	
	glcolor3d(0.8,0.5,0.3);
	goval(-200.0,0.0,20.0,30.0);
	
	glflush();
}
int  main(void){
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(draw_figures);
	glutmainloop();
	return 0;
}
