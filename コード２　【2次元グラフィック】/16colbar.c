/* １６色カラーバー　*/
#include <stdio.h>
#include <opengl.ft>
void draw_bar(void){
  int j;
	gclearbuffer();
	
	for(j=0; j<16; j++){
		color16(j);
		gquad(32.0*j-256.0,-256.0,32.0*(j+1)-256.0,256.0);
	}
	glflush();
}
int main(){
	ginit(1);
	window_size(256.0);
	reshapefunc(1);
	glutdisplayfunc(draw_bar);
	glutmainloop();
	return 0;
}
