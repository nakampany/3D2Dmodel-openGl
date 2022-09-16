/* Openglの関数だけを使った線の描画 							*/
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void draw_line(void){
	glClear(GL_COLOR_BUFFER_BIT);		 /* 描画バッファのクリア */
	glColor3d(1.0,1.0,1.0);			   /* 描画する絵の色：(r,g,b)*/
	glBegin(GL_LINES);								 /* 線を指定 */
		glVertex2d(0.0,0.0);						 /* 線の始点 */
		glVertex2d(100.0,100.0);					 /* 線の終点 */
	glEnd();								   /* 線指定の終わり */
	glFlush();					   /* すべてのバッファ内容を描画 */
}

void ginit(void){
	glClearColor(0.0,0.0,0.0,0.0);	   /* 描画バッファを黒にする */
	glMatrixMode(GL_PROJECTION);   /* 変換行列を射影モードにする */
	glLoadIdentity();			/* 変換行列に単位行列を設定する。*/
	glOrtho(-256.0,256.0,-256.0,256.0,-1.0,1.0);
					 /* 正射影の指定							 */
					 /* 左=-256.0  右=256.0  下=-256.0  上=256.0 */
					 /*	手前=-1.0  奥行=1.0（二次元）			 */
}

int main(int argc,char **argv){
	
glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);/*描画画面はRGB一枚*/
	glutInitWindowSize(512,512);		/* 画面サイズ：512 x 512 */
	glutInitWindowPosition(280,0);		  /* 画面の初期位置(x,y) */
	glutCreateWindow("Opengl_Window");		   /* 描画画面の名前 */
	ginit();
	glutDisplayFunc(draw_line);
	glutMainLoop();
	return 0;
}
