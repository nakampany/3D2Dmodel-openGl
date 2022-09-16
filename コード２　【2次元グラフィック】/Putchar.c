/*  文字をビットマップで描画　*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opengl.ft>
#define lazy "the quick brown fox jumps over a lazy dog."
#define LAZY "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG."
void put_char(void)
{
    int j;
	gclearbuffer();
	for(j=0; j<5; j++){
		color16(j+1);
		glrasterpos2i(-200,j*20);	
		printstring(lazy);
	}
	for(j=1;j<6; j++){
		color16(j+8);	
		glrasterpos2i(-200,-j*20);
		printstring(LAZY);
	}	
	glflush();
}
int main(void)
{
	ginit(1);
	window_size(256);
	enablebitmapfont();
	reshapefunc(1);
	glutdisplayfunc(put_char);
	glutmainloop();
	return 0;
}