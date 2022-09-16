/*  タートルグラフィクス用のコマンドを使って螺旋を画く */
#include <stdio.h>
#include <opengl.ft>

void draw_rasen(void){
  int j;
  double ang=65.0, leng=0.0;
  for(j=0;j<200;j++ ){
		color16((j % 15)+1);
		move(leng);							/* move: length */
	  	right(ang);						  /* turn right ang */
	  	leng+=1.0;
	}
	glflush();
}

int main(void){
	ginit(1);
	window_size(256.0);
	
	reshapefunc(1);
	glutdisplayfunc(draw_rasen);
	glutmainloop();
	return 0;
}